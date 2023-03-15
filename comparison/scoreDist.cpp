#include <iostream>
#include <fstream>
#include <string>

#include "scoreDist.hpp"
#include "openCL_tools.hpp"


void setArgOpenCLScoreDist(cl_kernel kernel, int *numGrp)
{
  cl_int err;

  err = clSetKernelArg(kernel, 5, sizeof(int), &(numGrp[0]));
  checkError_openCL(err,"Couldn't create kernel (scoreLocalPatch) arguments");
}


void allocateBufferOutScoreDist(float **distPartial, cl_uint numGrpMult)
{
  *distPartial = new float[numGrpMult];


}

void createBufferScoreDistOpenCL(cl_context context, cl_mem *distBufPartial, cl_mem *minBuf, cl_uint numGrpMult, long long sizeMinBuf)
{
  cl_int err;

  *distBufPartial = clCreateBuffer(context, CL_MEM_WRITE_ONLY, numGrpMult*sizeof(float), NULL, &err);
  checkError_openCL(err,"Couldn't create buffer : distBufPartial");

  /*CHECKEZ SI C4EST BON !! */
  *minBuf = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeMinBuf*sizeof(float), NULL, &err);	
  checkError_openCL(err,"Couldn't create buffer : minBuf");
}
