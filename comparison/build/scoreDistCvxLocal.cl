
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
__kernel void findMin(__global float *minDist1, __global float *minDist2, __global int *coordMinDistImg1_in1, __global int *coordMinDistImg1_in2, __global int *coordMinDistImg2_in1, __global int *coordMinDistImg2_in2, __global const float* c1, __global const float* c2, __local float *minDistLoc1,  __local float *minDistLoc2, __local int *coordMinDistLocImg1_in2, __local int *coordMinDistLocImg2_in1, int size1, int size2, int numGrp0, int numGrp1, int divFindMin)	
{
	//le nombre est le "STEP_FINDMIN" du .cpp avec le mainRESULT TERMINAL 
	unsigned int k1 = 50*get_global_id(0);	
	unsigned int k2 = 50*get_global_id(1);

	//unsigned int k1r = k1 + d*((size1+divFindMin - 1)/divFindMin);
	//unsigned int k2r = k2 + d*((size2+divFindMin - 1)/divFindMin);

	int k;

 	unsigned int lid0 = get_local_id(0);
	unsigned int lid1 = get_local_id(1);
	
	unsigned int gsize0 = get_local_size(0);
	unsigned int gsize1 = get_local_size(1);
	unsigned int gsize = get_local_size(1)*get_local_size(0);

	unsigned int stride;

	float sumHist1, sumHist2;

	float EMD1 = 0;
	float EMD2 = 0;

	//printf(" k1 : %d  %d %d %d k2 : %d %d %d \n", k1, size1, ((size1+divFindMin -1)/divFindMin),divFindMin,k2, size2, ((size2+divFindMin -1)/divFindMin));
	if(k1 < ((size1+divFindMin -1)/divFindMin) && k2 < ((size2+divFindMin-1)/divFindMin))
//if(k1r < size1 && k2r < size2)	
	{
		minDistLoc1[lid0*gsize1+lid1] = 0.0;
		minDistLoc2[lid0*gsize1+lid1] = 0.0;
		sumHist1 = 0;
		sumHist2 = 0;

		for(k = 0; k < SIZE_DESC; k++)
		{
			

			//dist Chi2
			/*if(c1[k1*SIZE_DESC + k] + c2[k2*SIZE_DESC + k] != 0.0)
			{
				minDistLoc1[lid0*gsize1+lid1] += pown(c1[k1*SIZE_DESC + k]- c2[k2*SIZE_DESC + k],2)/(c1[k1*SIZE_DESC + k] + c2[k2*SIZE_DESC + k]);
				minDistLoc2[lid0*gsize1+lid1] += pown(c1[k1*SIZE_DESC + k]- c2[k2*SIZE_DESC + k],2)/(c1[k1*SIZE_DESC + k] + c2[k2*SIZE_DESC + k]);
	
			}*/

			
			//dist MAD			
			//minDistLoc1[lid0*gsize1+lid1] += fabs(c1[k1*SIZE_DESC + k] - c2[k2*SIZE_DESC + k]);
			//minDistLoc2[lid0*gsize1+lid1] += fabs(c1[k1*SIZE_DESC + k] - c2[k2*SIZE_DESC + k]);	

	
			//dist EMD
			EMD1 = (c1[k1*SIZE_DESC + k] + EMD1) - c2[k2*SIZE_DESC + k];
			EMD2 = (c2[k2*SIZE_DESC + k] + EMD2) - c1[k1*SIZE_DESC + k];
			minDistLoc1[lid0*gsize1+lid1] += fabs(EMD1);
			minDistLoc2[lid0*gsize1+lid1] += fabs(EMD2);



			/*if(c1[k1*SIZE_DESC + k] > 0.0)
				sumHist1 += c1[k1*SIZE_DESC + k];
			if(c2[k2*SIZE_DESC + k] > 0.0)
				sumHist2 += c2[k2*SIZE_DESC + k];
			*/

			if( c1[k1*SIZE_DESC + k] != c1[k1*SIZE_DESC + k] || c2[k2*SIZE_DESC + k] != c2[k2*SIZE_DESC + k])
				printf("c1 c2 %f %f\n",c1[k1*SIZE_DESC + k],c2[k2*SIZE_DESC + k]);

			/*sumHist1 += c1[k1*SIZE_DESC + k];
			sumHist2 += c2[k2*SIZE_DESC + k];*/
	
		}

		/*minDistLoc1[lid0*gsize1+lid1] *= 0.5;
		minDistLoc2[lid0*gsize1+lid1] *= 0.5;*/
		/*minDistLoc1[lid0*gsize1+lid1] = sqrt(minDistLoc1[lid0*gsize1+lid1]);
		minDistLoc2[lid0*gsize1+lid1] = sqrt(minDistLoc2[lid0*gsize1+lid1]);*/




	//	minDistLoc1[lid0*gsize1+lid1] *= (exp(fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)));
	//	minDistLoc2[lid0*gsize1+lid1] *= (exp(fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)));

	//	minDistLoc1[lid0*gsize1+lid1] *= (fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)+1);
	//	minDistLoc2[lid0*gsize1+lid1] *= (fabs(sumHist1-sumHist2)*fabs(sumHist1-sumHist2)+1);

		coordMinDistLocImg1_in2[lid0*gsize1+lid1] = k2;
		coordMinDistLocImg2_in1[lid0*gsize1+lid1] = k1;

	
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
				coordMinDistLocImg1_in2[lid0*gsize1+lid1] = coordMinDistLocImg1_in2[lid0*gsize1+lid1];
			}
			else if( minDistLoc1[lid0*gsize1+lid1] == -1.0 )
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1+stride];
				coordMinDistLocImg1_in2[lid0*gsize1+lid1] = coordMinDistLocImg1_in2[lid0*gsize1+lid1+stride];
			}
			else if( minDistLoc1[lid0*gsize1+lid1] <=  minDistLoc1[lid0*gsize1+lid1+stride] )
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1];
				coordMinDistLocImg1_in2[lid0*gsize1+lid1] = coordMinDistLocImg1_in2[lid0*gsize1+lid1];
			}
			else
			{
				minDistLoc1[lid0*gsize1+lid1] = minDistLoc1[lid0*gsize1+lid1+stride];
				coordMinDistLocImg1_in2[lid0*gsize1+lid1] = coordMinDistLocImg1_in2[lid0*gsize1+lid1+stride];
			}
		}


		if( lid0 < stride )
		{
			/*si les deux sont -1.0 on met -1.0 sinon on met la valeur la plus basse */
			if( minDistLoc2[(lid0+stride)*gsize1+lid1] == -1.0 )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[lid0*gsize1+lid1];
				coordMinDistLocImg2_in1[lid0*gsize1+lid1] = coordMinDistLocImg2_in1[lid0*gsize1+lid1];
			}
			else if( minDistLoc2[lid0*gsize1+lid1] == -1.0 )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[(lid0+stride)*gsize1+lid1];
				coordMinDistLocImg2_in1[lid0*gsize1+lid1] = coordMinDistLocImg2_in1[(lid0+stride)*gsize1+lid1];
			}
			else if( minDistLoc2[lid0*gsize1+lid1] <=  minDistLoc2[(lid0+stride)*gsize1+lid1] )
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[lid0*gsize1+lid1];
				coordMinDistLocImg2_in1[lid0*gsize1+lid1] = coordMinDistLocImg2_in1[lid0*gsize1+lid1];
			}
			else
			{
				minDistLoc2[lid0*gsize1+lid1] = minDistLoc2[(lid0+stride)*gsize1+lid1];
				coordMinDistLocImg2_in1[lid0*gsize1+lid1] = coordMinDistLocImg2_in1[(lid0+stride)*gsize1+lid1];
			}
		}
	}
	

	if(lid1 == 0)
	{

		minDist1[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = minDistLoc1[lid0*gsize1+0];

		coordMinDistImg1_in1[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = k1;
		coordMinDistImg1_in2[lid0*numGrp1*numGrp0+numGrp1*get_group_id(0)+get_group_id(1)] = coordMinDistLocImg1_in2[lid0*gsize1+0];
	}

	if(lid0 == 0)
	{
			
		minDist2[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = minDistLoc2[0*gsize1+lid1];

		coordMinDistImg2_in2[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = k2;
		coordMinDistImg2_in1[lid1*numGrp1*numGrp0+numGrp0*get_group_id(0)+get_group_id(1)] = coordMinDistLocImg2_in1[0*gsize1+lid1];
	}
}
