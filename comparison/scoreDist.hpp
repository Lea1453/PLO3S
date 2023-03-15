#ifndef _SCOREDIST_H_
#define _SCOREDIST_H_

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#ifdef __APPLE__	
#include <OpenCL/opencl.h>	
#else	
#include <CL/cl.h>	
#endif

void setArgOpenCLScoreDist(cl_kernel kernel, int *numGrp);
void allocateBufferOutScoreDist(float **distPartial, cl_uint numGrpMult);
void createBufferScoreDistOpenCL(cl_context context, cl_mem *distBufPartial, cl_mem *minBuf, cl_uint numGrpMult, long long sizeMinBuf);

#endif
