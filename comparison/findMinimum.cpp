#include <iostream>
#include <fstream>
#include <string>

#include "findMinimum.hpp"
#include "openCL_tools.hpp"




void setArgOpenCLFindMin_vs_imgJ(cl_kernel kernel, int *size_gen, int *numGrp, int *divFindMin )
{
  cl_int err;

  err |= clSetKernelArg(kernel, 12, sizeof(int), size_gen); // ! NEED TO BE THE jth size_gen adress
  err |= clSetKernelArg(kernel, 14, sizeof(int), &(numGrp[0]));
  err |= clSetKernelArg(kernel, 15, sizeof(int), &(numGrp[1]));
  err |= clSetKernelArg(kernel, 16, sizeof(int), divFindMin);
  checkError_openCL(err,"Couldn't create kernel (findMin) 12-14->16 arguments");

}

void setArgOpenCLFindMin_vs_subArea(cl_kernel kernel, cl_mem *minBufPartial1, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, cl_mem *c1Buf, cl_mem *c2Buf, size_t *lws, int *size_gen)
{
  cl_int err;
  
  
  /* Create kernel arguments */
  err = clSetKernelArg(kernel, 0, sizeof(cl_mem), minBufPartial1);
  err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), minBufPartial2);
  err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), coordMinBufPartialImg1_in1);
  err |= clSetKernelArg(kernel, 3, sizeof(cl_mem), coordMinBufPartialImg1_in2);
  err |= clSetKernelArg(kernel, 4, sizeof(cl_mem), coordMinBufPartialImg2_in1);
  err |= clSetKernelArg(kernel, 5, sizeof(cl_mem), coordMinBufPartialImg2_in2);
  err |= clSetKernelArg(kernel, 6, sizeof(cl_mem), c1Buf);
  err |= clSetKernelArg(kernel, 7, sizeof(cl_mem), c2Buf);
  err |= clSetKernelArg(kernel, 8, lws[0]*lws[1]*sizeof(float),NULL);
  err |= clSetKernelArg(kernel, 9, lws[0]*lws[1]*sizeof(float),NULL);
  err |= clSetKernelArg(kernel, 10, lws[0]*lws[1]*sizeof(int),NULL);
  err |= clSetKernelArg(kernel, 11, lws[0]*lws[1]*sizeof(int),NULL);  
  err |= clSetKernelArg(kernel, 13, sizeof(int), size_gen);
  checkError_openCL(err,"Couldn't create kernel (findMin) 0->11-13 arguments");

}


void allocateBufferOutFindMin(float **minPartial1, float **minPartial2, int **coordMinPartialImg1_in1, int **coordMinPartialImg1_in2, int **coordMinPartialImg2_in1, int **coordMinPartialImg2_in2, size_t *lws, cl_uint numGrpMult, int size)
{
 
  *minPartial1 = new float[lws[0]*numGrpMult];
  *minPartial2 = new float[lws[1]*numGrpMult];

  *coordMinPartialImg1_in1 = new int[lws[0]*numGrpMult];
  *coordMinPartialImg1_in2 = new int[lws[0]*numGrpMult];
  *coordMinPartialImg2_in1 = new int[lws[1]*numGrpMult];
  *coordMinPartialImg2_in2 = new int[lws[1]*numGrpMult];
 

}



void createBufferFindMinOpenCL(cl_context context, cl_mem *c1Buf, cl_mem *c2Buf, cl_mem *minBufPartial1, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, size_t *lws, cl_uint numGrpMult, int sizeCBuf, int sizeDivMview)
{
  cl_int err;
  int d;
  
  *c1Buf = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeCBuf*sizeof(float), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : c1Buf");   
  *c2Buf = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeCBuf*sizeof(float), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : c2Buf");   

 * minBufPartial1 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[0]*numGrpMult*sizeof(float), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : minBufPartial1");

  *coordMinBufPartialImg1_in1 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[0]*numGrpMult*sizeof(int), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : coordMinBufPartial1_i");
  *coordMinBufPartialImg1_in2 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[0]*numGrpMult*sizeof(int), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : coordMinBufPartial1_j");

  *minBufPartial2 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[1]*numGrpMult*sizeof(float), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : minBufPartial2");
   
  *coordMinBufPartialImg2_in1 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[1]*numGrpMult*sizeof(int), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : coordMinBufPartial2_i");
  *coordMinBufPartialImg2_in2 = clCreateBuffer(context, CL_MEM_WRITE_ONLY , lws[1]*numGrpMult*sizeof(int), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : coordMinBufPartial2_j");
    
}




void transferBufferToFindMin_vs_imgJ(cl_command_queue queue, cl_mem c1Buf, int sizeC1Buf, float *desc_gen1)
{
  cl_int err;

  err = clEnqueueWriteBuffer(queue, c1Buf, CL_TRUE, 0, sizeC1Buf*sizeof(float), desc_gen1, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't enqueue c1Buf");

}

void transferBufferToFindMin_vs_subArea(cl_command_queue queue, cl_mem c2Buf, int sizeC2Buf, float *desc_gen2)
{
  cl_int err;


  err = clEnqueueWriteBuffer(queue, c2Buf, CL_TRUE, 0, sizeC2Buf*sizeof(float), desc_gen2, 0, NULL, NULL);
  /* Transfer data to memory buffer */
  /*  if(static_cast<int>(d2*((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc + ((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc) < size_gen[j +k2]*size_desc)
    {
      err = clEnqueueWriteBuffer(queue, c2Buf, CL_TRUE, 0, static_cast<int>((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc*sizeof(float), &(desc_gen[1][static_cast<int>(d2*((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc)]), 0, NULL, NULL);
    }
  else
    {
      err = clEnqueueWriteBuffer(queue, c2Buf, CL_TRUE, 0, static_cast<int>(( (size_gen[j+k2]*size_desc) - static_cast<int>(d2*((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc))*sizeof(float)), &(desc_gen[1][static_cast<int>(d2*((size_gen[j+k2]+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc)]), 0, NULL, NULL);
      }*/
  checkError_openCL(err,"Couldn't enqueue c2Buf");
}


void getArgOpenCLFindMin(cl_command_queue queue, cl_mem *minBufPartial1, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, float *minPartial1, float *minPartial2, int *coordMinPartialImg1_in1, int *coordMinPartialImg1_in2, int *coordMinPartialImg2_in1, int *coordMinPartialImg2_in2, size_t *lws, int numGrpMult)
{
  cl_int err;

  /* Read the kernel's output */
  //FAIRE une association k1,d1,k2,d2 cf dessins 
  err = clEnqueueReadBuffer(queue, *minBufPartial1, CL_TRUE, 0, lws[0]*numGrpMult*sizeof(float), minPartial1, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't read the buffer (minBufPartial1)");
    err = clEnqueueReadBuffer(queue, *minBufPartial2, CL_TRUE, 0, lws[1]*numGrpMult*sizeof(float), minPartial2, 0, NULL, NULL);;
  checkError_openCL(err,"Couldn't read the buffer (minBufPartial2)");
  err = clEnqueueReadBuffer(queue, *coordMinBufPartialImg1_in1, CL_TRUE, 0, lws[0]*numGrpMult*sizeof(int), coordMinPartialImg1_in1, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't read the buffer (coordMinBufPartial1_i)");
  err = clEnqueueReadBuffer(queue, *coordMinBufPartialImg1_in2, CL_TRUE, 0, lws[0]*numGrpMult*sizeof(int), coordMinPartialImg1_in2, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't read the buffer (coordMinBufPartial1_j)");
  err = clEnqueueReadBuffer(queue, *coordMinBufPartialImg2_in1, CL_TRUE, 0, lws[1]*numGrpMult*sizeof(int), coordMinPartialImg2_in1, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't read the buffer (coordMinBufPartial2_i)");
  err = clEnqueueReadBuffer(queue, *coordMinBufPartialImg2_in2, CL_TRUE, 0, lws[1]*numGrpMult*sizeof(int), coordMinPartialImg2_in2, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't read the buffer (coordMinBufPartial2_j)");

  // std::cout << "MAX lws, size of float x*y: " << lws[0] << " " <<  sizeof(float) << " " <<  lws[0]*numGrpMult*sizeof(float) << " sSUM : " << 2*lws[0]*numGrpMult*sizeof(float)+4*lws[0]*numGrpMult*sizeof(int) << "\n";
  clFlush(queue);
  
  /*  clReleaseMemObject(*minBufPartial2);
  clReleaseMemObject(*coordMinBufPartialImg2_in2);
  clReleaseMemObject(*coordMinBufPartialImg2_in1);
  clReleaseMemObject(*minBufPartial1);
  clReleaseMemObject(*coordMinBufPartialImg1_in1);
  clReleaseMemObject(*coordMinBufPartialImg1_in2);*/
  
}
