#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <ctime>
#include <sys/time.h>
#include <opencv2/highgui/highgui.hpp>

#include "gradient.hpp"
#include "arrDeriv.hpp"
#include "utilTool.hpp"
#include "scoreDistCvxLocal.hpp"
#include "openCLTools.hpp"
#include "stats.hpp"
#include "visualizeImages.hpp"
#include "openCL_tools.hpp"
#include "scoreDist.hpp"
#include "findMinimum.hpp"

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#ifdef __APPLE__	
#include <OpenCL/opencl.h>	
#else	
#include <CL/cl.h>	
#endif
 
#include <thread>         
#include <chrono>

#include "sys/types.h"
#include "sys/sysinfo.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "sys/times.h"
#include "sys/vtimes.h"

#define COEF_MIN 1
#define COEF_MAX 8.0
#define THRESH_DISS 0.10
#define THRESH_ABSOLUTE 121 //10 = (7*7)(<-patch) * 2(<-value range) * 0.10(<-pourcent) 
#define SIZE_PATCH 25
#define SIZE_DESC 10
#define NB_DESC 1
#define WKSDESC false
#define NB_MVIEW 18


#define GPU false
#define LWS_SIZE 32 //64 CPU  // 16 GPU
#define MAX_SOURCE_SIZE (0x100000)
#define DIV_FINDMIN 2 //Permet d eviter des erreurs du a des tailles d objet trop grandes chargé
#define STEP_FINDMIN 20 // /!\ AJOUTER CETTE VALEUR DANS LE .cl lors de get_global_id |||| diviseur de la taille maximum de FINDMIN et permet d'augmenter le pas des fenetres coulissantes 

static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;


/*int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getCurrentValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}


void init(){
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

double getCurrentValue(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
            (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
    }*/

int main(int argc, char** argv)
{
  int i;
  char **fnamesIn;
  char **fnamesWKS;

  if(argc < 2)
    return 1;


 
     fnamesIn = (char**)malloc(((argc-2)/2) * sizeof(char*));
     fnamesWKS = (char**)malloc(((argc-2)/2) * sizeof(char*));
 
  /*les n premiers arguments de argv sont les noms d'entrées
   * le dernier est le nom de sortie generique des deux matrices de scores
   */
     for(i = 1; i < (argc/2); i++)
    {
      fnamesIn[i-1] = argv[i];
    }
  for(i = argc/2; i < argc - 1; i++)
    {
      fnamesWKS[i-(argc/2)] = argv[i];
    }

  std::cout << "fds "  << (argc-2)/2 << " " << argv[(argc-2)/2]<< "\n";
  std::cout << "fds2 "  << (argc-2) << " " << argv[4858]<< "\n";
  scoreDistCvx(fnamesIn, fnamesWKS, argv[argc-1], (argc-2)/2);

  free(fnamesIn);
  free(fnamesWKS);
  
  return 0;
}


	


int computeHist(float *cPatch, float *cHist, int size, int size_patch)
 {
   int i,k;
   int sizeDesc = SIZE_DESC;
   int hist[SIZE_DESC] = {0,0,0};

   for(i = 0; i < size; i++)
     {
       for(k = 0; k < size_patch; k++)
	 {
	   hist[static_cast<int>(cPatch[i*size_patch + k])+1]++;
	 }
       cHist[i*sizeDesc + 0] = hist[0];
       cHist[i*sizeDesc + 1] = hist[1];
       cHist[i*sizeDesc + 2] = hist[2];
     }
   return sizeDesc;

 }

int computeHist_float(float *cPatch, float *cHist, float *binVal, int size, int size_patch)
 {
   int i,k,l,r;
   int sizeDesc = SIZE_DESC;
   int hist[SIZE_DESC];
   int size_patch_sqr = size_patch*size_patch;
   int sumHist, coefNorm;

 
   // printf("Computing histogram  \n");
   for(i = 0; i < size; i++)
     {
       for(l = 0; l < SIZE_DESC; l++)
	 {
	   hist[l] = 0;
	 }

       sumHist = 0;
         for(k = 0; k < size_patch_sqr; k++)
	   {

	     if(cPatch[i*size_patch_sqr + k] != 0.0)
	       {
		 sumHist++;
		 
		 r = 0;
		 while(r < SIZE_DESC && cPatch[i*size_patch_sqr+k] >= binVal[r])
		   r++;

		 if(r <= 0)
		   printf("Error (computeHist_float) r value inferior to 0, : %d, cPatch : %f %f, (%d %d, i*k : %d) avec %d %d   \n", r, cPatch[i*size_patch_sqr+k],  binVal[r], i, k, i*size_patch_sqr+k, size, size_patch_sqr);
		 else
		   {
		     hist[r-1]++;
		   }

		 /* printf("%d %d, (i,k) : %d %d cpatch : %f, binVal : %f %f  \n", r, hist[r-1], i, k, cPatch[i*size_patch_sqr+k], binVal[0],binVal[SIZE_DESC]);*/
	       }

	     
	   }

	 //permet de normaliser : si trop peu de valeur dans l'histogram, on va les agumenter
	 //ne permet pas une normalisation exact, il restera toujours le modulo de sumHist par size_patch_square 
	 coefNorm = size_patch_sqr / sumHist;

	 for(l = 0; l < SIZE_DESC; l++)
	   {
	     cHist[i*sizeDesc + l] = hist[l];
	   }
  
     }
   //  printf("End computing histograms \n");

   return sizeDesc;

 } 

void computeCoefs(float *z, float *coefs, float maxZ, float minZ, int size)
{
  int i;
  

  for(i = 0; i < size; i++)
    {
      coefs[i] = 1-(z[i] - minZ)/(maxZ - minZ);
      /* if(coefs[i] < 0.9)
	 printf("coef : %f \n", coefs[i]);*/
    }
    
}

void addCoefToDesc(float *desc, float *coefs, int size, int sizeDesc)
{
  int i,k;

  for(i = 0; i < size; i++)
    {
      for(k = 0; k < sizeDesc; k++)
	{
	  desc[i*sizeDesc+k] *= coefs[i];
	}
    }

}

void createDescriptors(float **ac, float **acHist, int sizeac, int *size, int size_patch)
{
  int i,j,k,l;
  int sizeDesc;
  int allSize;
  int nbNonNul = 0;
  int size_patch_sqr = size_patch*size_patch;
  float *acNonNul;
  float *coefs;
  float minC, maxC;
  float binVal[SIZE_DESC+1];
  

  std::clock_t begin_time_CPU_1Img;
  float delta_time_CPU;

  printf("Creating descriptors \n");
  minC = minFloat2D(ac, sizeac, size);
  maxC = maxFloat2D(ac, sizeac, size);

  for(i = 0; i < sizeac; i++)
    {
      for(j = 0; j < size[i]; j++)
	{
	  if(ac[i][j*size_patch_sqr + size_patch_sqr/2] != 0.0)
	    {
	      nbNonNul++;
	    }
	}

    }

  acNonNul = (float*)malloc(nbNonNul*sizeof(float));

  l=0;
  for(i = 0; i < sizeac; i++)
    {
      for(j = 0; j < size[i]; j++)
	{
	  if(ac[i][j*size_patch_sqr + size_patch_sqr/2] != 0.0)
	    {
	      acNonNul[l] = ac[i][j*size_patch_sqr + size_patch_sqr/2];
	      l++;
	    }
	}

    }
  
  qsort (acNonNul, nbNonNul, sizeof(*acNonNul), comp);


  
  for(k = 0; k < SIZE_DESC+1; k++)
    {
      binVal[k] = acNonNul[static_cast<int>(((nbNonNul-1)*((k*1.0)/(SIZE_DESC))))];
      //  binVal[k] = minC + (k*1.0)*(maxC - minC)/(SIZE_DESC);
      printf("binval : %lf (size_patch : %d) \n", binVal[k], size_patch);
    }
  
  
  for(i = 0; i < sizeac; i++)
    {
      acHist[i] = (float*)malloc(SIZE_DESC*size[i]*sizeof(float));

      begin_time_CPU_1Img = std::clock();
      
      sizeDesc = computeHist_float(ac[i], acHist[i], binVal, size[i], size_patch);

      delta_time_CPU = float( clock () - begin_time_CPU_1Img ) /  CLOCKS_PER_SEC;
      std::cout << "time in sec CPU for computing histograms : " << delta_time_CPU << "\n";

	       
       delete[] ac[i];
    }
  free(acNonNul);

}




/*
create a descriptor by initializing it (acHist) and put value of the histogram in it with the function computeHist_float
 */
void createDescriptors(float *ac, float **acHist, float *binVal,  int size, int size_patch)
{
  int i,j,k,l;
  int sizeDesc;
  int allSize;
  int nbNonNul = 0;
  int size_patch_sqr = size_patch*size_patch;
  

  std::clock_t begin_time_CPU_1Img;
  float delta_time_CPU;

  // printf("Creating descriptors \n");
  
 
  *acHist = new float[SIZE_DESC*size];

  begin_time_CPU_1Img = std::clock();

  sizeDesc = computeHist_float(ac, *acHist, binVal, size, size_patch);

  delta_time_CPU = float( clock () - begin_time_CPU_1Img ) /  CLOCKS_PER_SEC;
  //  std::cout << "time in sec CPU for computing histograms : " << delta_time_CPU << "\n";

}


void creatingScaleDescriptors(char **filenamesIn, float *binVal, int sizeac, int size_patch_sqr)
{

  int i,j,k,l;
  int size, sizeXY[2];
  float *ac;
  int nbNonNul = 0;
  float *acNonNul;
  

  printf("Computing descriptors bins \n");
  
  for(i = 0; i < sizeac; i++)
    {
      //LE probleme semble venir du fait que l'on delete ac (mais je souhaite le réutilisser plusieurs fois)
      //err :  _int_malloc: Assertion `(unsigned long) (size) >= (unsigned long) (nb)' failed.

      loadFile_mapCvx_mView_desc(filenamesIn[i], &ac, &size);
      for(j = 0; j < size; j++)
	{
	  if(ac[j] != 0.0)
	    {
	      nbNonNul++;
	    }
	}
      delete[] ac;
    }

  acNonNul = (float*)malloc(nbNonNul*sizeof(float));

  l=0;
  
  for(i = 0; i < sizeac; i++)
    {
      loadFile_mapCvx_mView_desc(filenamesIn[i], &ac, &size);
	    
      for(j = 0; j < size; j++)
	{
	  if(ac[j] != 0.0)
	    {
	      acNonNul[l] = ac[j];
	      l++;
	    }
	}
      delete[] ac;
    }

  
  qsort (acNonNul, nbNonNul, sizeof(*acNonNul), comp);


  
  for(k = 0; k < SIZE_DESC+1; k++)
    {
      binVal[k] = acNonNul[static_cast<int>(((nbNonNul-1)*((k*1.0)/(SIZE_DESC))))];
      //  binVal[k] = minC + (k*1.0)*(maxC - minC)/(SIZE_DESC);
      printf("binval : %lf (size_patch : %d) \n", binVal[k], size_patch_sqr);
    }
  
  free(acNonNul);

}



/**********************************
 *
 * scoreDist : fait la carte de score avec une distance, des cartes de gradients
 * 
********************************/

void scoreDistCvx(char **filenamesCvxIn, char **filenamesWKS, char *filenameCvxOut, int sizeac)
 {
   int i,j,a,d,d1,d2,l1,l2;
   unsigned int k,l,m;
   float *matDist = new float[(sizeac*sizeac)/(NB_MVIEW*NB_MVIEW)];
   float *matDist_hist = new float[(sizeac*sizeac)/(NB_MVIEW*NB_MVIEW)];
   float *matDist_wks = new float[(sizeac*sizeac)/(NB_MVIEW*NB_MVIEW)];
   int *matNbPatchSelec = new int[(sizeac*sizeac)/(NB_MVIEW*NB_MVIEW)];
   //  int *nbPatchNotCount = new int[(sizeac*sizeac)/(NB_MVIEW*NB_MVIEW)];
   int nbPatchAboveThresh;
   float *distPartial;
   float *minPartial1, *minPartial2;
   int *coordMinPartialImg1_in1, *coordMinPartialImg1_in2, *coordMinPartialImg2_in1, *coordMinPartialImg2_in2;
   int *coordMin1_jvsi, *coordMin2_jvsi;
   float *minMat1_ivsj, *minMat2_ivsj;
   float *coefs = new float[sizeac];
   float coefMatDist;
   float binVal[SIZE_DESC+1];
   int coefGPGPUtoNormal1;
   int coefGPGPUtoNormal2;
     
   int maxSize, minSize_matDist, maxSize_all;

   int nbImg = sizeac/NB_MVIEW;
   
   char *fnameout_mat;

   std::string filenamePatch_txt;
   
   float **ac = new float*[2];
   float **acTmp = new float*[2];
   float **acHist = new float*[2];
   int **pos_patch = new int*[2];
   int **revPos_patch = new int*[2];
   float **wks = new float*[sizeac];
   int *size_curv = new int[2];
   int *size_curv_ac = new int[nbImg];
   int **sizeXY = new int*[2];
   int **sizeAllXY = new int*[sizeac];
   int size_patch = SIZE_PATCH, size_desc = SIZE_DESC;
   int size_patch_sqr;
   int *size_WKS = new int[sizeac];
   int *size_descWKS = new int[sizeac];
   int nbPtsSelec1, nbPtsSelec2;

   FILE *fileBackUp;
   
   /*generic variables */
   float **desc_gen;
   float sum_gen[2];
   int *size_gen;

   /*Var for the stats*/
   float **timeAll = new float*[sizeac];
   float **timeAll_CPU = new float*[sizeac];
   int *nbPtsAll=NULL;
   std::string filenameStatsPts_txt;
   std::string filenameStatsPts;
   std::string filenameStatsPts_txt_CPU;
   std::string filenameStatsPts_CPU;
   int sizeTmp;

  /*calculate the CPU time */
   std::clock_t begin_time_CPU_glob;
   float delta_time_glob;
   std::clock_t begin_time_CPU_1Img;
   float delta_time_CPU;

   /*calculate the REAL time */
   struct timeval start_time_REAL, end_time_REAL;
   struct timeval start_time_REAL_glob, end_time_REAL_glob;
   struct timeval time1, time2;
   float delta_time_REAL, delta_time_REAL_glob, delta_time;
	   
   /* OpenCL structures and variables use by OpenCL */
   cl_context context;
   cl_program program;
   cl_command_queue queue;
   cl_kernel localDist_kernel = NULL;
   cl_kernel minLocalPatch_kernel = NULL;

	
   cl_device_id device_id;

    
	
   cl_uint numGrpMult_sum, numGrpMult_min;

   size_t lws_sum[3] = {LWS_SIZE,LWS_SIZE,1};
   size_t lws_min[3] = {LWS_SIZE,LWS_SIZE,1};

   size_t group_ws_prefered;
   size_t gws_sum[3], gws_min[3];
   int numGrp_sum[3], numGrp_min[3];
    
   cl_int err;	
	
   cl_mem c1Buf, c2Buf, distBufPartial;
   cl_mem minBuf,minBufPartial1, minBufPartial2;
   cl_mem coordMinBufPartialImg1_in1, coordMinBufPartialImg1_in2, coordMinBufPartialImg2_in1, coordMinBufPartialImg2_in2;
  

				

   ///////////////////////////////

   // init();
   
   
  /*init variable des stats et histogram images*/
   for(i=0; i < sizeac; i++)
     {
        timeAll[i] = new float[sizeac];
        timeAll_CPU[i] = new float[sizeac];

     }
   
   readBinaryHeader_mapCvx_mView_allView(filenamesCvxIn, size_curv_ac, &size_patch, sizeAllXY, sizeac, NB_MVIEW);
   size_patch = SIZE_PATCH; // AJOUT POUR WKS
   size_patch_sqr = size_patch*size_patch;
   readVectorFile_int("nbPts.txt", &nbPtsAll, &sizeTmp);

   //A ETE ENLEVER POUR WKS
   // creatingScaleDescriptors(filenamesCvxIn, binVal, sizeac, size_patch_sqr);
   
   begin_time_CPU_glob = std::clock();
   gettimeofday(&start_time_REAL_glob, NULL);



   ///////////////////////////////////////////////////////////////
 

   /* Initialization of OpenCL */
   initOpenCL(&device_id, &context, &queue);
   
   getInfoOpenCLEnvironment(device_id);
   
   loadKernels(&program, context, device_id); 

   fileBackUp = fopen("scoreBackUp.txt", "w");

   printf("Debut du calcul du score \n");
   for(a = 0; a < NB_DESC; a++)
     {
       if(a == 0)
	 {
	   std::cout << "\n Curvature comparison \n \n";
	   size_gen = size_curv_ac;
	 }
       else if (a == 1) // /!\ ne fonctionne pasp our le moment => changer la representation des donnees
	 {
	   std::cout << "\n WKS comparison \n \n";
	   size_gen = size_WKS;
	 }
       else
	 {
	   exit(1);
	 }
       
      
     
       /* Create OpenCL Kernels */	
       createKernel("scoreDistLocalPatch", &program, &localDist_kernel);	   
       createKernel("findMin", &program, &minLocalPatch_kernel);
       

       std::cout << "Info for minLocal kernel : \n";
       getInfoOpenCLKernel(device_id, minLocalPatch_kernel);
       std::cout << "Info for distLocal kernel : \n";
       getInfoOpenCLKernel(device_id, localDist_kernel);
       std::cout << "\n";


       maxSize = maxInt(size_gen, nbImg);
       
       /* Compute the global work size, we need to get a mutiple of the local work size to work*/

       computingSizesOpenCL(gws_sum, maxSize, lws_sum, numGrp_sum, &numGrpMult_sum, 1); //Div par 2 maxsize : "/2" permet de calculer plus rapidement la sum (cf .cl). "trick"
       computingSizesOpenCL(gws_min, ((maxSize/STEP_FINDMIN)+DIV_FINDMIN-1)/DIV_FINDMIN, lws_min, numGrp_min, &numGrpMult_min, 2);

       std::cout << "global work size (sum) : " << gws_sum[0] << " " << gws_sum[1] << ", GWS (min) : " << gws_min[0] << " " << gws_min[1] << "\n"; //rajouter static_cast<int>() si ne fonctionne pas								
       std::cout << "local work size (sum) : " << lws_sum[0] << " " << lws_sum[1] << ", LWS (min) : " << lws_min[0] << " " << lws_min[1] << "\n"; //rajouter static_cast<int>() si ne fonctionne pas
				    
       std::cout << "Number of group (sum) : " << numGrp_sum[0] << " * " << numGrp_sum[1] << " = " << numGrpMult_sum << "\n";
       std::cout << "Number of group (min) : " << numGrp_min[0] << " * " << numGrp_min[1] << " = " << numGrpMult_min << "\n";
       



       allocateBufferOutFindMin(&minPartial1, &minPartial2, &coordMinPartialImg1_in1, &coordMinPartialImg1_in2, &coordMinPartialImg2_in1, &coordMinPartialImg2_in2, lws_min, numGrpMult_min, DIV_FINDMIN*NB_MVIEW);

       /*A ALLOUER DANS UN AUTRE FICHIER CAR VALERUR UTILISER POUR SCORING ! */
       minMat1_ivsj = new float[maxSize];
       minMat2_ivsj = new float[maxSize];
       coordMin1_jvsi = new int[maxSize];
       coordMin2_jvsi = new int[maxSize];
       
       allocateBufferOutScoreDist(&distPartial, numGrpMult_sum);
      
       /* Create Buffer Objects */
       createBufferFindMinOpenCL(context, &c1Buf, &c2Buf, &minBufPartial1, &coordMinBufPartialImg1_in1, &coordMinBufPartialImg1_in2, &minBufPartial2, &coordMinBufPartialImg2_in1, &coordMinBufPartialImg2_in2, lws_min, numGrpMult_min, ((maxSize+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc, DIV_FINDMIN*NB_MVIEW);
      
       createBufferScoreDistOpenCL(context, &distBufPartial, &minBuf, numGrpMult_sum, size_patch_sqr*((maxSize+DIV_FINDMIN-1)/DIV_FINDMIN) );
    

       
       printf("%d %d \n",  ((maxSize+DIV_FINDMIN-1)/DIV_FINDMIN), ((maxSize+DIV_FINDMIN-1)/DIV_FINDMIN)*size_desc);

       
       // /!\/!\/!\ N'EST PAS ENCORE VALABLE POUR LE TRAITEMENT FICHIER A FICHIER
       if(WKSDESC)
	 loadFiles_WKS(filenamesWKS, wks, size_WKS, size_descWKS, sizeac);


       // /!\/!\/!\ N'EST PAS ENCORE VALABLE, POUR LE MOMENT SEULEMENT acHist EST UTILISE
       if(a == 0)
	 {
	   desc_gen = acHist;
	 }
       else if (a == 1)
	 {
	   desc_gen = wks;
	 }
       else
	 {
	   exit(1);
	 }


       //??????? faut il changer
       for(int t = 0; t < (sizeac*sizeac)/(NB_MVIEW*NB_MVIEW); t++)
	 {
	   matNbPatchSelec[t] = 0;
	   //  nbPatchNotCount[t] = 0;
	 }
       
       int divFindMin = DIV_FINDMIN;

       sizeXY[0] = new int[2*NB_MVIEW];
       sizeXY[1] = new int[2*NB_MVIEW];
       
       printf("size : %d \n", lws_min[0]*numGrpMult_min);
       for(i = 0; i < nbImg; i++)
	 {
	   setArgOpenCLFindMin_vs_imgJ(minLocalPatch_kernel, &(size_gen[i]), numGrp_min, &divFindMin);
	   
	   setArgOpenCLScoreDist(localDist_kernel, &(numGrp_sum[0]));

	   for(j = 0; j <= i; j++)
	     {
	       filenameStatsPts_txt = std::string(filenameCvxOut) + "_" + std::to_string(i+1) + "_vs_" + std::to_string(j+1) +  "_patch.txt";

	       begin_time_CPU_1Img = std::clock();
	   
	       gettimeofday(&start_time_REAL, NULL);



	       for(k=0; k < maxSize; k++)
		 {
		   minMat1_ivsj[k] = -2;
		   coordMin1_jvsi[k] = -2;
		   
		   minMat2_ivsj[k] = -2;
		   coordMin2_jvsi[k] = -2;
		 }
	         

	       printf("image %d compare to image %d, taille du patch : %d, taille i : %d (%d %d) taille j : %d (%d %d)  \n", i, j, size_patch, size_gen[i], sizeAllXY[i*NB_MVIEW][0], sizeAllXY[i*NB_MVIEW][1], size_gen[j],  sizeAllXY[j*NB_MVIEW][0], sizeAllXY[j*NB_MVIEW][1]);

	       //  std::cout << "A1 : " << getCurrentValue() << "\n";
	       
	       gettimeofday(&time1, NULL);                                   
	       loadBinaryFile_mapCvx_mView_allView_WKS(&(filenamesCvxIn[i*NB_MVIEW]), &(acHist[0]), &(size_curv[0]), sizeXY[0], &size_patch, NB_MVIEW);
	       gettimeofday(&time2, NULL);

	       delta_time = ((time2.tv_sec  - time1.tv_sec) * 1000000u + time2.tv_usec - time1.tv_usec) / 1.e6;
	       std::cout << "Loading one file binary : " << delta_time << " sec \n"; 
	       //loadFile_mapCvx_mView_allView(&(filenamesCvxIn[i*NB_MVIEW]), &(acTmp[0]), &(size_curv[0]), sizeXY[0], &size_patch, NB_MVIEW);
	       //computePatches_withMalloc_allView(acTmp[0], &(ac[0]), size_curv[0], sizeXY[0], size_patch, NB_MVIEW);
	       //delete[] acTmp[0];
	       //createDescriptors(ac[0], &(acHist[0]), binVal, size_curv[0], size_patch);
	       //delete[] ac[0];
	       // std::cout << "A2 : " << getCurrentValue() << "\n";
	       size_patch = SIZE_PATCH; // AJOUT WKS
	       size_patch_sqr = size_patch*size_patch;

			 
		   // std::cout << "B1 : " << getCurrentValue() << "\n";
			 
	       loadBinaryFile_mapCvx_mView_allView_WKS(&(filenamesCvxIn[j*NB_MVIEW]), &(acHist[1]), &(size_curv[1]), sizeXY[1], &size_patch, NB_MVIEW);


		   //loadFile_mapCvx_mView_allView(&(filenamesCvxIn[j*NB_MVIEW]), &(acTmp[1]), &(size_curv[1]), sizeXY[1], &size_patch, NB_MVIEW);
		   //computePatches_withMalloc_allView(acTmp[1], &(ac[1]), size_curv[1], sizeXY[1], size_patch, NB_MVIEW);
		   // delete[] acTmp[1];
		   // createDescriptors(ac[1], &(acHist[1]), binVal, size_curv[1], size_patch);
		   // delete[] ac[1];
	       size_patch = SIZE_PATCH; //ajout WKS
		   //   std::cout << "B2_4 : " << getCurrentValue() << "\n";

	       // std::cout << "A3 : " << getCurrentValue() << "\n";

	       float scoreFinal = 0;
	       for(d1 = 0; d1 < sizeXY[0][0] * sizeXY[0][1]; d1++)
		 {
		   float valTmp = 0.0;
		   float score = 10000.0;
		  
		   for(d2 = 0; d2 < sizeXY[1][0] * sizeXY[1][1]; d2++)
		     {
		       
		     for(k = 0; k < SIZE_DESC; k++)
		       {
			 valTmp += fabs(acHist[0][d1*SIZE_DESC + k] - acHist[1][d2*SIZE_DESC + k]); 
		       }
		     if(score > valTmp)
		       score = valTmp;
		     }
		   std::cout << "scoreTmp : " << score << "\n";
		   scoreFinal += score;
		 }

	       std::cout << "SCORE FINAL : " << scoreFinal << "\n";
	       
	       delete[] acHist[0];
	       delete[] acHist[1];
		   // std::cout << "A4 : " << getCurrentValue() << "\n";



	       
	       printf("End of find minimum kernel execution \n");

	       
	       printf("Applying constraints (threshold + bijectivness of patch association) \n"); 

	       /*Threshold*/
	       nbPatchAboveThresh = 0;
	       nbPtsSelec1 = 0;
		   
	       for(k=0; k < maxSize; k++)
		 {	  
		   if(coordMin1_jvsi[k] == -2 /*PERMET L ALLER RETOUR || k != coordMin2_jvsi[coordMin1_jvsi[k]] */)
		     {
		     
		       //Ce if ne sert qu'a compter les mauvais match, mais prend en compte les points inexistant de base ("les points noirs")
		       /*  if(coordMin1_jvsi[k] != -2)
			 {
			  
			   //nbPatchNotCount[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)]++; //????????? faut il changer
			   }*/
		       
		       nbPatchAboveThresh++; //tout les patchs exclus
		       minMat1_ivsj[k]=0;
		       coordMin1_jvsi[k] = -2;
		       
		     }
		   else
		     {
		       matNbPatchSelec[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)]++;//????????? faut il changer
		       nbPtsSelec1++;
		     }

		   if(minMat1_ivsj[k] == -1.0)
		     {
		       printf("Error : minMat1_ivsj has a -1 value \n");
		     }
		 }

	       
	       printf("End of applying constraints  \n");
	       std::cout << "Saving file patch " << filenameStatsPts_txt << "\n";
	       // saveCoordPatch_desc_allView((char*)filenameStatsPts_txt.c_str(), coordMin1_jvsi, minMat1_ivsj, sizeAllXY, maxSize, NB_MVIEW, i*NB_MVIEW, j*NB_MVIEW);

	       printf("End of saving file patch \n");

	       printf("Visualization of patches \n");
	       // /!\ /!\ /!\ les pos patch et rev post patch sont pas chargé (utilisation d'un fonction differente pour laodFile_.. !!!! si on decommente ca, il faut changer de fonction
	       //  displayImagesPatches(ac[i], ac[j], pos_patch[i], pos_patch[j], revPos_patch[j], coordMin1_jvsi, sizeXY[i], sizeXY[j], std::sqrt(size_patch));
	       printf("End visualization \n");
	       
	       printf("Starting kernel score local patch \n");
	       
	       /* Transfer data to memory buffer */	
	       err = clEnqueueWriteBuffer(queue, minBuf, CL_TRUE, 0, size_gen[i]*sizeof(float), minMat1_ivsj, 0, NULL, NULL);
	       checkError_openCL(err,"Couldn't enqueue minBuf");
	   


	       /* Create kernel arguments */
	       err = clSetKernelArg(localDist_kernel, 0, sizeof(cl_mem), &distBufPartial);
	       err |= clSetKernelArg(localDist_kernel, 1, sizeof(cl_mem), &minBuf);
	       err |= clSetKernelArg(localDist_kernel, 2, lws_sum[0]*lws_sum[1]* sizeof(float),NULL);
	       err |= clSetKernelArg(localDist_kernel, 3, sizeof(int), &(size_gen[i]));
	       err |= clSetKernelArg(localDist_kernel, 4, sizeof(int), &(size_patch_sqr));
	       checkError_openCL(err,"Couldn't create kernel (scoreLocalPatch) arguments");



	       err = clEnqueueNDRangeKernel(queue, localDist_kernel, 1, NULL, gws_sum, lws_sum, 0, NULL, NULL);
	       checkError_openCL(err,"Couldn't enqueue NDrange kernel (scoreLocalPatch) ");

	       /* Read the kernel's output */
	       err = clEnqueueReadBuffer(queue, distBufPartial, CL_TRUE, 0, numGrpMult_sum*sizeof(float), distPartial, 0, NULL, NULL);
	       checkError_openCL(err,"Couldn't read the buffer (distBufPartial)");


	       printf("NbPtsSelec1 (nombre de patch selectionne) : %d \n", nbPtsSelec1);
	       
	       if(a == 0)
		 {

		   matDist_hist[j*nbImg+i] = 0;
		   for(k = 0; k < numGrpMult_sum; k++)
		     {
		       matDist_hist[j*nbImg+i] += distPartial[k];
		     }
		   
		   if(size_gen[i] < size_gen[j])
		     minSize_matDist = size_gen[i];
		   else
		     minSize_matDist = size_gen[j];

		   
		   /*Ajout des coefs et completion de la seconde partie triangulaire de la matrice */
		   coefMatDist = 1.0;
	       
		   matDist_hist[j*nbImg+i] *= coefMatDist;
		   if(i == 365 || j == 365 || i == 510 || j == 510)
                     matDist_hist[j*nbImg+i] += 1000;  
		   matDist_hist[i*nbImg+j]  = matDist_hist[j*nbImg+i];
		   matNbPatchSelec[i*nbImg+j] =  matNbPatchSelec[j*nbImg+i];
		   //  nbPatchNotCount[i*nbImg+j] =  nbPatchNotCount[j*nbImg*i];


		   printf("Numéro image : %d %d  score courbure : %f, taille(i,j) : (%d,%d) , nbPatchExcluded : %d, coef : %f  \n", i,j, matDist_hist[j*nbImg+i],size_gen[i], size_gen[j] , nbPatchAboveThresh,coefMatDist);
		 }
	       else if(a == 1) //NE FONCTIONNE PAS POUR LE MOMENT
		 {
		   matDist_wks[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)] = 0;
		   for(k = 0; k < numGrpMult_sum; k++)
		     {
		       matDist_wks[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)] += distPartial[k];
		       //printf("%f \n", distPartial[k]);
		     }
		   printf("Numéro image : %d %d (image réel : %d %d) score WKS : %f, taille(i,j) : (%d,%d)  \n", i, j, i / NB_MVIEW, j / NB_MVIEW, matDist_wks[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)],size_gen[i], size_gen[j]);
		 }
	       else
		 {
		   exit(1);
		 }
	       

	   
	       delta_time_CPU = float( clock () - begin_time_CPU_1Img ) /  CLOCKS_PER_SEC;
	       std::cout << "time in sec CPU for 1 image : " << delta_time_CPU << "\n";
	       timeAll_CPU[j*NB_MVIEW][i*NB_MVIEW] = delta_time_CPU;
	   
	       gettimeofday(&end_time_REAL, NULL);
	       delta_time_REAL = ((end_time_REAL.tv_sec  - start_time_REAL.tv_sec) * 1000000u + 
				  end_time_REAL.tv_usec - start_time_REAL.tv_usec) / 1.e6;
	       std::cout << "time in REAL sec for 1 image : " << delta_time_REAL << "\n";
	       timeAll[j*NB_MVIEW][i*NB_MVIEW] = delta_time_REAL;

	       std::cout << "\n";

	       fprintf(fileBackUp, "%f ", matDist_wks[(j/NB_MVIEW)*(sizeac/NB_MVIEW)+(i/NB_MVIEW)]); 
	       
	     }
	 } 
     }
   fclose(fileBackUp);
   std::cout << "Normalize \n";
   
   normalizeFloatArr(matDist_hist, nbImg*nbImg);
   if(WKSDESC)
     normalizeFloatArr(matDist_wks, (sizeac*sizeac)/(NB_MVIEW*NB_MVIEW));
   
   /*usueless delete later */
   for(k = 0; k < nbImg*nbImg; k++)
     {
       std::cout << "Value of matrix after normalization : " << k << " " <<  matDist_hist[k] << "\n";
     }

  
   for(k = 0; k < nbImg; k++)
     {
       
       matDist[k] = matDist_hist[k]; // * (10.0/(matNbPatchSelec[k]+1)); // + matDist_wks[k];
       //   std::cout << "Value of final matrix : " << k << " " <<  matDist[k] << " nbPatch : " << (matNbPatchSelec[k]+1) <<  "\n";
     }


  

   delta_time_glob =  float( clock () - begin_time_CPU_glob ) /  CLOCKS_PER_SEC;

   gettimeofday(&end_time_REAL_glob, NULL);
   delta_time_REAL_glob = ((end_time_REAL_glob.tv_sec  - start_time_REAL_glob.tv_sec) * 1000000u + 
			   end_time_REAL_glob.tv_usec - start_time_REAL_glob.tv_usec) / 1.e6;
    
   /*Stats on number of points*/
   /*  for(j = 0; j < sizeac; j++)
     {
       filenameStatsPts =  std::string(filenameCvxOut) + "_" + std::to_string(j+1) + "_nbPts";
       filenameStatsPts_txt = std::string(filenameCvxOut) + "_" + std::to_string(j+1) + "_nbPts.txt";
       filenameStatsPts_CPU = std::string(filenameCvxOut) +  "_" + std::to_string(j+1) + "_nbPts_CPU";
       filenameStatsPts_txt_CPU =  std::string(filenameCvxOut) + "_" + std::to_string(j+1) + "_nbPts_CPU.txt";

       print_nbPts_vs_time(timeAll[j*NB_MVIEW], nbPtsAll, sizeac, filenameStatsPts);
       print_nbPts_vs_time(timeAll_CPU[j*NB_MVIEW], nbPtsAll, sizeac, filenameStatsPts_CPU);
       
       saveGraphValuesXY_int_float((char*)filenameStatsPts_txt.c_str(), nbPtsAll, timeAll[j*NB_MVIEW], sizeac);
       saveGraphValuesXY_int_float((char*)filenameStatsPts_txt.c_str(), nbPtsAll, timeAll_CPU[j*NB_MVIEW], sizeac);
       }

   filenameStatsPts = std::string(filenameCvxOut) + "_nbPts";
   filenameStatsPts_CPU = std::string(filenameCvxOut) + "_nbPts_CPU";

   print_MULTI_nbPts_vs_time(timeAll, nbPtsAll, sizeac, filenameStatsPts);
   print_MULTI_nbPts_vs_time(timeAll_CPU, nbPtsAll, sizeac, filenameStatsPts_CPU);
   */
    
   std::cout << "time in sec CPU global : " << delta_time_glob << "\n";


 
   std::cout << "time in REAL sec global: " << delta_time_REAL_glob << "\n";
    
   /* normalizeFloatArr(matDist, nbImg*nbImg); 

   for(k = 0; k < nbImg*nbImg; k++)
     {
       //(useless step if there is not at least two distance added together)
       std::cout << "Value of final matrix after normalization  : " << k << " " <<  matDist[k] << "\n";
     }
     
   std::cout << "Normalization done \n";
   */

   fnameout_mat = (char*)malloc(strlen(filenameCvxOut)+strlen("_score.txt")+1);

   strcpy(fnameout_mat,filenameCvxOut);
   strcat(fnameout_mat,"_score.txt");

   std::cout << "Saving image : " << fnameout_mat << " \n";
   
   saveMatrixScore(fnameout_mat, matDist, nbImg);

     
   std::cout << "Image saved. Freeing space \n";
    
    
   /* Deallocate resources */
   clReleaseKernel(localDist_kernel);
   clReleaseCommandQueue(queue);
   clReleaseProgram(program);
   clReleaseContext(context);
   
   clReleaseMemObject(distBufPartial);
 
   clReleaseMemObject(minBufPartial1);
   clReleaseMemObject(minBufPartial2);
   clReleaseMemObject(coordMinBufPartialImg1_in1);
   clReleaseMemObject(coordMinBufPartialImg1_in2);
   clReleaseMemObject(coordMinBufPartialImg2_in1);
   clReleaseMemObject(coordMinBufPartialImg2_in2);
	
   clReleaseMemObject(c1Buf);
   clReleaseMemObject(c2Buf);
 
   clReleaseMemObject(minBuf);
     
   
   free(fnameout_mat);
   free(nbPtsAll);

   std::cout << "Delete 1 \n";
   delete[] minPartial1;
   delete[] minPartial2;
   delete[] coordMinPartialImg1_in1;
   delete[] coordMinPartialImg1_in2;
   delete[] coordMinPartialImg2_in1;
   delete[] coordMinPartialImg2_in2;

   std::cout << "Delete 2 \n";
   
   delete[] minMat1_ivsj;
   delete[] minMat2_ivsj;
   delete[] coordMin1_jvsi;
   delete[] coordMin2_jvsi;
   delete[] distPartial;

   std::cout << "Delete 3 \n";
   
   delete[] matDist;
   delete[] matDist_hist;
   delete[] matDist_wks;
   delete[] matNbPatchSelec;
   // delete[] nbPatchNotCount;

   std::cout << "Delete 4 \n";
   
   delete[] size_curv;
   delete[] size_curv_ac;
   delete[] size_WKS;
   delete[] size_descWKS;
   delete[] coefs;

   std::cout << "Delete 5 \n";
   
   for(i = 0; i < sizeac; i++)
     {
       delete[] timeAll[i];
       delete[] timeAll_CPU[i];
       delete[] wks[i];
       delete[] sizeAllXY[i];
     }


   std::cout << "Delete 6 \n";
   
   delete[] timeAll;
   delete[] timeAll_CPU;
   delete[] wks;
   delete[] sizeAllXY;

   std::cout << "Delete 7 \n";
   
   for(d = 0; d < 2; d++)
     {
       delete[] ac[d];
       //  delete[] acHist[d]; inutile car delete[] dans les boucles de creation de descripteurs
       delete[] acTmp[d];

       delete[] pos_patch[d];
       delete[] revPos_patch[d];

       delete[] sizeXY[d];
     }

   std::cout << "Delete 8 \n";
   
   delete[] ac;
   delete[] acHist;
   delete[] acTmp;

   delete[] pos_patch;
   delete[] revPos_patch;

   delete[] sizeXY;
   

   
 }
