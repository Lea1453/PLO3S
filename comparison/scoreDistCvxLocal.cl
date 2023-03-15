
__kernel void scoreDistLocalPatch(__global float *distPartial, __global const float* c, __local float *localDist, int size, int size_patch, int numGrp0)	
{	
	unsigned int i = get_global_id(0);	


 	unsigned int lid0 = get_local_id(0);

 	unsigned int gsize0 = get_local_size(0);

	unsigned int stride;

	


	if(i < (size/2))
		localDist[lid0] = c[i] + c[i+(size/2)];
	else
		localDist[lid0] = 0.0;	
 
	/*Perform a reduction */
 	for (stride = (gsize0/2); stride>0; stride /=2)
    	 {
     	 // Waiting for each 2x2 addition into given workgroup
     	 barrier(CLK_LOCAL_MEM_FENCE);

    	  // Divide WorkGroup into 2 parts and add elements 2 by 2
     	 // between local_id and local_id + stride

  	  if (lid0 < stride)
   	  	localDist[lid0] += localDist[lid0 + stride];

  

     	}


 	 // Write result into partialSums[nWorkGroups]
    	if (lid0 == 0)
	 	distPartial[get_group_id(0)] = localDist[0];

	
	
	
}	


/***
* 
* Find the minimum value of each patch of the image "c1" compare to every patch of image "c2"
*
***/
__kernel void findMin(__global float *minDist1, __global float *minDist2, __global int *coordMinDist1_i, __global int *coordMinDist1_j, __global int *coordMinDist2_i, __global int *coordMinDist2_j, __global const float* c1, __global const float* c2, __global const float* z1, __global const float* z2, __local float *minDistLoc1,  __local float *minDistLoc2, __local int *coordMinDistLoc1_j, __local int *coordMinDistLoc2_j, int size1, int size2, int numGrp0, int numGrp1)	
{
	unsigned int k1 = get_global_id(0);	
	unsigned int k2 = get_global_id(1);

	int k;

 	unsigned int lid0 = get_local_id(0);
	unsigned int lid1 = get_local_id(1);
	
	unsigned int gsize0 = get_local_size(0);
	unsigned int gsize1 = get_local_size(1);
	unsigned int gsize = get_local_size(1)*get_local_size(0);

	unsigned int stride;

	// need to make a __local for sumHist ?
	float sumHist1, sumHist2;


	  


	if(k1 < size1 && k2 < size2)
	{
		minDistLoc1[lid0*gsize1+lid1] = 0.0;
		minDistLoc2[lid0*gsize1+lid1] = 0.0;
		sumHist1 = 0;
		sumHist2 = 0;

		for(k = 0; k < SIZE_DESC; k++)
		{
			minDistLoc1[lid0*gsize1+lid1] += fabs(c1[k1*SIZE_DESC + k]/*fabs(z1[k1]-1)*/ - c2[k2*SIZE_DESC + k]/*fabs(z2[k2]-1)*/);
			minDistLoc2[lid0*gsize1+lid1] += fabs(c1[k1*SIZE_DESC + k]/*fabs(z1[k1]-1)*/ - c2[k2*SIZE_DESC + k]/*fabs(z2[k2]-1)*/);		
			if(c1[k1*SIZE_DESC + k] > 0.0)
				sumHist1 += c1[k1*SIZE_DESC + k];
			if(c2[k2*SIZE_DESC + k] > 0.0)
				sumHist2 += c2[k2*SIZE_DESC + k];

			/*sumHist1 += c1[k1*SIZE_DESC + k];
			sumHist2 += c2[k2*SIZE_DESC + k];*/
	
		/*if(k1 == 2508 && k2 == 2508)
			printf("%f %f \n", c1[k1*SIZE_DESC + k], c1[k2*SIZE_DESC + k]);*/
		}
	

	//	minDistLoc1[lid0*gsize1+lid1] *= (exp(fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)));
	//	minDistLoc2[lid0*gsize1+lid1] *= (exp(fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)));

	//	minDistLoc1[lid0*gsize1+lid1] *= (fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)+1);
	//	minDistLoc2[lid0*gsize1+lid1] *= (fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)+1);

		coordMinDistLoc1_j[lid0*gsize1+lid1] = k2;
		coordMinDistLoc2_j[lid0*gsize1+lid1] = k1;

	
	}
		
	else
	{
		minDistLoc1[lid0*gsize1+lid1] = -1.0;
		minDistLoc2[lid0*gsize1+lid1] = -1.0;
	}

	/*gsize1==gsize0 donc interchangeable, mais attention si la taille change !!! */
	for(stride = gsize1/2; stride > 0; stride /=2)
	{
		barrier(CLK_LOCAL_MEM_FENCE);


		if( lid1 < stride )
		{
			/*si les deux sont -1.0 on met -1.0 sinon on met la valeur la plus basse */
			if( minDistLoc1[lid0*gsize1+lid1+stride] == -1.0 )
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1];
				coordMinDistLoc1_j[lid0*gsize1+lid1] = coordMinDistLoc1_j[lid0*gsize1+lid1];
			}
			else if( minDistLoc1[lid0*gsize1+lid1] == -1.0 )
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1+stride];
				coordMinDistLoc1_j[lid0*gsize1+lid1] = coordMinDistLoc1_j[lid0*gsize1+lid1+stride];
			}
			else if( minDistLoc1[lid0*gsize1+lid1] <=  minDistLoc1[lid0*gsize1+lid1+stride] )
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1];
				coordMinDistLoc1_j[lid0*gsize1+lid1] = coordMinDistLoc1_j[lid0*gsize1+lid1];
			}
			else
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1+stride];
				coordMinDistLoc1_j[lid0*gsize1+lid1] = coordMinDistLoc1_j[lid0*gsize1+lid1+stride];
			}
		}


		if( lid0 < stride )
		{
			/*si les deux sont -1.0 on met -1.0 sinon on met la valeur la plus basse */
			if( minDistLoc2[(lid0+stride)*gsize1+lid1] == -1.0 )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[lid0*gsize1+lid1];
				coordMinDistLoc2_j[lid0*gsize1+lid1] = coordMinDistLoc2_j[lid0*gsize1+lid1];
			}
			else if( minDistLoc2[lid0*gsize1+lid1] == -1.0 )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[(lid0+stride)*gsize1+lid1];
				coordMinDistLoc2_j[lid0*gsize1+lid1] = coordMinDistLoc2_j[(lid0+stride)*gsize1+lid1];
			}
			else if( minDistLoc2[lid0*gsize1+lid1] <=  minDistLoc2[(lid0+stride)*gsize1+lid1] )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[lid0*gsize1+lid1];
				coordMinDistLoc2_j[lid0*gsize1+lid1] = coordMinDistLoc2_j[lid0*gsize1+lid1];
			}
			else
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[(lid0+stride)*gsize1+lid1];
				coordMinDistLoc2_j[lid0*gsize1+lid1] = coordMinDistLoc2_j[(lid0+stride)*gsize1+lid1];
			}
		}
	}
	

	if(lid1 == 0)
	{

		minDist1[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = minDistLoc1[lid0*gsize1+0];


		coordMinDist1_i[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = k1;
		coordMinDist1_j[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = coordMinDistLoc1_j[lid0*gsize1+0];
	}

	if(lid0 == 0)
	{
			
		minDist2[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = minDistLoc2[0*gsize1+lid1];


		coordMinDist2_i[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = k2;
		coordMinDist2_j[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = coordMinDistLoc2_j[0*gsize1+lid1];
	}

}




