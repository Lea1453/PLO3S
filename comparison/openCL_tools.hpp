#ifndef _OPENCLTOOLS_INCLUDED_H_
#define _OPENCLTOOLS_INCLUDED_H_

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#ifdef __APPLE__	
#include <OpenCL/opencl.h>	
#else	
#include <CL/cl.h>	
#endif

void getInfoOpenCLEnvironment(cl_device_id device_id);
void getInfoOpenCLKernel(cl_device_id device_id, cl_kernel kernel);
void initOpenCL(cl_device_id *device_id, cl_context *context, cl_command_queue *queue);
void loadKernels(cl_program *program, cl_context context, cl_device_id device_id);
void createKernel(std::string kernelName, cl_program *program, cl_kernel *kernel);
void computingSizesOpenCL(size_t *gws, int sizeGws, size_t *lws, int *numGrp, cl_uint *numGrpTotal, int dim);
void kernelComputation(cl_command_queue queue, cl_kernel kernel, size_t *gws, size_t *lws, int dim);
void checkError_openCL(int nErr, const std::string mErr);

#endif
