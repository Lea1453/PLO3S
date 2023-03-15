#include <iostream>
#include <fstream>
#include <string>

#include "openCL_tools.hpp"


#define GPU false
#define LWS_SIZE 32 //64 CPU  // 16 GPU
#define SIZE_DESC 100

void getInfoOpenCLEnvironment(cl_device_id device_id)
{
  size_t work_item_max[3];
  size_t group_ws_max;
  size_t memAlloc_device_max;

  cl_int err;

  /*Get the maximum memory allocation size */
  err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(size_t), &memAlloc_device_max, NULL);
  checkError_openCL(err,"Couldn't get device  infos");
  printf("max memory allocated size : %zu \n", memAlloc_device_max);
  
  /*Get the maximum of work items per dimension */
  err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_SIZES, 3*sizeof(size_t), &work_item_max, NULL);
  checkError_openCL(err,"Couldn't get device  infos");
  printf("max work item per group work size (x,y,1) : (%zu,%zu,1) \n", work_item_max[0], work_item_max[1]);

  /*Get the maximum of work group per dimension */
  err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &group_ws_max, NULL);
  checkError_openCL(err,"Couldn't get device  infos");
  printf("max work item in a group work size : %zu \n", group_ws_max);

}

void getInfoOpenCLKernel(cl_device_id device_id, cl_kernel kernel)
{
  size_t group_ws_maxCum;

  cl_int err;
  
  /*Get the maximum of work group cumulate"*/
  err =  clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(size_t), &group_ws_maxCum, NULL);
  checkError_openCL(err,"Couldn't get group infos");
  printf("max group work size cum (multiplication of all dimensions) : %zu \n", group_ws_maxCum);

}

void initOpenCL(cl_device_id *device_id, cl_context *context, cl_command_queue *queue)
{

  cl_platform_id platform_id[2];
  cl_uint ret_num_devices;	
  cl_uint ret_num_platforms;

  cl_int err;
  
  /* Load kernel source code */
  std::cout << "Preparing OpenCL environement \n";
   
  /*Create/get platform/device */	
  err = clGetPlatformIDs(2, platform_id, &ret_num_platforms);
  checkError_openCL(err, "Couldn't load the platform" );
  
  if(GPU)
    err = clGetDeviceIDs(platform_id[1], CL_DEVICE_TYPE_GPU, 1, device_id, &ret_num_devices);
  else
    err = clGetDeviceIDs(platform_id[0], CL_DEVICE_TYPE_CPU, 1, device_id, &ret_num_devices);
  checkError_openCL(err,"Couldn't create device");

  /* Create OpenCL context */	
 *context = clCreateContext(NULL, 1, device_id, NULL, NULL, &err);	
  checkError_openCL(err,"Couldn't create a context");

  /* Create Command queue */	
  *queue = clCreateCommandQueue(*context, *device_id, 0, &err);	
  checkError_openCL(err,"Couldn't create a queue");

}


void loadKernels(cl_program *program, cl_context context, cl_device_id device_id)
{

  std::ifstream fp;
  cl_int err;

  std::string source_str;
  const char *source_char;
  size_t source_size;

  size_t log_size;
  char *log;
    
  const char kernelNameFile[] = "./scoreDistCvxLocal.cl";
     
  std::cout << "Loading OpenCL kernel \n";
  
  fp.open(kernelNameFile, std::ios::in);	
  if (fp.is_open())
    {
      fp.seekg(0, std::ios::end);
      source_str.resize(fp.tellg());
      fp.seekg(0, std::ios::beg);
      fp.read(&source_str[0], source_str.size());
      fp.close();	
    }
  else
    {
      std::cout << "(loadKernel) file " <<  kernelNameFile << " not opened \n";	
      exit(1);
    }

  source_char = source_str.c_str();
  source_size = source_str.size();
  
  /* Create kernel program from source */	
  *program = clCreateProgramWithSource(context, 1, (const char **)&source_char, (const size_t *)&source_size, &err);
  checkError_openCL(err,"Couldn't create program");

  /* Build kernel program */	
  std::string argOpenCL = std::string("-D SIZE_DESC=") + std::to_string(SIZE_DESC);
  err = clBuildProgram(*program, 1, &device_id, argOpenCL.c_str(), NULL, NULL);
  //permet de verifier les erreur dans le code opencl
  if(err < 0) {
    printf("%d \n", err);
    perror("Couldn't build kernel");
    if (err == CL_BUILD_PROGRAM_FAILURE) {
      // Determine the size of the log
      clGetProgramBuildInfo(*program, device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

      // Allocate memory for the log
      log = (char *) malloc(log_size);

      // Get the log
      clGetProgramBuildInfo(*program, device_id, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

      // Print the log
      printf("%s\n", log);

      free(log);
    }
    exit(1);
   }

}

void createKernel(std::string kernelName, cl_program *program, cl_kernel *kernel)
{

  cl_int err;
  
  /* Create OpenCL Kernels */	
  *kernel = clCreateKernel(*program, kernelName.c_str(), &err);	
  checkError_openCL(err,"Couldn't create kernel");
  
}

void computingSizesOpenCL(size_t *gws, int sizeGws, size_t *lws, int *numGrp, cl_uint *numGrpTotal, int dim)
{
  /* Compute the global work size, we need to get a mutiple of the local work size to work*/
  if(dim == 1)
    {
      gws[0] = sizeGws + ( lws[0] - (sizeGws % lws[0]) ); 
      gws[1] = 1;
      gws[2] = 1;
      
      numGrp[0] = gws[0] / lws[0];
      numGrp[1] = 1;
      numGrp[2] = 1;

      *numGrpTotal = numGrp[0];
      
    }
  else  if(dim == 2)
    {
      gws[0] = sizeGws + ( lws[0] - (sizeGws % lws[0]) ); 
      gws[1] = sizeGws + ( lws[1] - (sizeGws % lws[1]) );
      gws[2] = 1;

      numGrp[0] = gws[0] / lws[0];
      numGrp[1] = gws[1] / lws[1];
      numGrp[2] = 1;

      *numGrpTotal = numGrp[0] * numGrp[1];
    }
  else  if(dim == 3)
    {
      gws[0] = sizeGws + ( lws[0] - (sizeGws % lws[0]) ); 
      gws[1] = sizeGws + ( lws[1] - (sizeGws % lws[1]) );
      gws[2] = sizeGws + ( lws[2] - (sizeGws % lws[2]) );

      numGrp[0] = gws[0] / lws[0];
      numGrp[1] = gws[1] / lws[1];
      numGrp[2] = gws[2] / lws[2];

      *numGrpTotal = numGrp[0] * numGrp[1] * numGrp[2];
    }
  else
    {
      std::cout << "(computingSizesOpenCL) number of dimension not valid (" <<  dim << " dimension) \n";	
      exit(1);
    }
}

void kernelComputation(cl_command_queue queue, cl_kernel kernel, size_t *gws, size_t *lws, int dim)
{
  cl_int err;

  err = clEnqueueNDRangeKernel(queue, kernel, dim, NULL, gws, lws, 0, NULL, NULL);
  checkError_openCL(err,"Couldn't enqueue NDrange kernel");
}
 
/**********************************
 *
 * checkError : verifie si une erreur à été declenché avec opencl
 * 
********************************/

void checkError_openCL(int nErr, const std::string mErr)
{
     if(nErr < 0) {
       std::cout << "error n° " << nErr << "\n" << mErr << "\n";
       exit(1);
     }
}
