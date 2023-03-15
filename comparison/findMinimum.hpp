#ifndef _FINDMINIMUM_H_
#define _FINDMINIMUM_H_

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#ifdef __APPLE__	
#include <OpenCL/opencl.h>	
#else	
#include <CL/cl.h>	
#endif

void setArgOpenCLFindMin_vs_imgJ(cl_kernel kernel, int *size_gen, int *numGrp, int *divFindMin );
void setArgOpenCLFindMin_vs_subArea(cl_kernel kernel, cl_mem *minBufPartial1, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, cl_mem *c1Buf, cl_mem *c2Buf, size_t *lws, int *size_gen);

void allocateBufferOutFindMin(float **minPartial1, float **minPartial2, int **coordMinPartialImg1_1, int **coordMinPartialImg1_2, int **coordMinPartialImg2_1, int **coordMinPartialImg2_2, size_t *lws, cl_uint numGrpMult, int size);

void createBufferFindMinOpenCL(cl_context context, cl_mem *c1Buf, cl_mem *c2Buf, cl_mem *minBufPartial1, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, size_t *lws, cl_uint numGrpMult, int sizeCBufn, int sizeDivMview);

void transferBufferToFindMin_vs_imgJ(cl_command_queue queue, cl_mem c1Buf, int sizeC1Buf, float *desc_gen1);
void transferBufferToFindMin_vs_subArea(cl_command_queue queue, cl_mem c2Buf, int sizeC2Buf, float *desc_gen2);

void getArgOpenCLFindMin(cl_command_queue queue, cl_mem *minBufPartial1, cl_mem *coordMinBufPartialImg1_in1, cl_mem *coordMinBufPartialImg1_in2, cl_mem *minBufPartial2, cl_mem *coordMinBufPartialImg2_in1, cl_mem *coordMinBufPartialImg2_in2, float *minPartial1, float *minPartial2, int *coordMinPartialImg1_1, int *coordMinPartialImg1_2, int *coordMinPartialImg2_1, int *coordMinPartialImg2_2, size_t *lws, int numGrpMult);

#endif
