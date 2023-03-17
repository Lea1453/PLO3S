/*////////////////////////////////////////////////////////////////
Permission to use, copy, modify, and distribute this program for
any purpose, with or without fee, is hereby granted, provided that
the notices on the head, the reference information, and this
copyright notice appear in all copies or substantial portions of
the Software. It is provided "as is" without express or implied
warranty.
*////////////////////////////////////////////////////////////////


#include <pcl/io/ply_io.h>


#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

//from project inliers 


#include <pcl/filters/project_inliers.h>

#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/vtk_smoothing/vtk_utils.h>
#include <vtkSmartPointer.h>
#include <vtkSmoothPolyDataFilter.h>
#include <pcl/io/vtk_io.h>

/////////////////////////////
//:vtk plotter
#include<pcl/visualization/pcl_plotter.h>


//////////////////

#include <vtkGenericDataObjectReader.h>
#include <vtkStructuredGrid.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include<vtkPolyDataReader.h>
#include <string>

#include <vtkPolyDataMapper.h>
#include <vtkSphereSource.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPLYReader.h>
#include <vtkPLYWriter.h>

#include <vtkExtractEdges.h>
#include <vtkLine.h>
#include <vtkIdList.h>
#include <vtkDecimatePro.h>

//#include "TriCall_CD.h"
#include "itkConformal.h"

// for mesh quality

#include <vtkVersion.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkDataSet.h>
#include <vtkMeshQuality.h>
#include <vtkTriangleFilter.h>
#include <vtkWindowedSincPolyDataFilter.h>
////////////

/*curvature et normals*/
#include <vtkCurvatures.h>
#include <vtkPolyDataWriter.h>
#include <vtkArrayDataWriter.h>
#include <vtkArrayWriter.h>
#include <vtkWriter.h>
#include <vtkDataArray.h>
#include <vtkDataWriter.h>
#include <vtkPolyDataNormals.h>
#include <vtkDoubleArray.h>

#include "CommonPara.h"
#include "ParsePDB.h"
#include "ProteinSurface.h"
#include <time.h>
#include <ctime>

#include <stdio.h>
#include <iostream>
#include <fstream> 

#include <vtkOBJReader.h>

#include "vtkOFFReader.h"


#define THRESH_NORMAL 0.005

#define ROTATION_VALUE_THETA 90
#define ROTATION_VALUE_PHI 90
#define NB_VIEW 7

// modif 1/02/2015 
// output pour chaque pdb -> pano multi resolution de la form : idx.pgm , stepCoef_idxPano.pgm
// sprintf(filenameImage_OUT_L1,"l_%d_P_%d.pgm", stepCoeff_L1, idxPano);

 

typedef struct {
                char file[200]; 
               } type_file; 
	       

int EDTSurf(/*int argc, char** argv*/char *filenamePDB, char *fileOUT);


// batch processing for the image projection computation 
int main(int argc, char** argv)
{
  if(argc >=1)
    {
      std::clock_t begin_time;
      float delta_time;

      int k;

      int numberFiles = atoi(argv[1]); 

      struct timeval tBegin, tEnd;
  
      for(int idxImage = 0; idxImage<numberFiles; idxImage++)
	{
      
	  char *filename = (char *)malloc(100*sizeof(char));
	  char *filenameOUT = (char *)malloc(100*sizeof(char));
	  char *filenameOUTPLY = (char *)malloc(100*sizeof(char));
	  char *filenameOUTOBJ = (char *)malloc(100*sizeof(char));
	  char *filenameOUTOFF = (char *)malloc(100*sizeof(char));
	  char *filenameVTKSphIn = (char *)malloc(100*sizeof(char));
    
	  char *foldernamein = "in/";
	  char *foldernameout = "out/";
   
	  vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New();
	  vtkSmartPointer<vtkPolyData> polydataCurvature = vtkSmartPointer<vtkPolyData>::New();
      
	  int flagOBJ_inputmesh = 0; 
	  int flagPLY_inputmesh = 0; 
	  int flagOFF_inputmesh = 1;


	  //  vtkSmartPointer<vtkCurvatures> curvaturesFilter = 
	  vtkSmartPointer<vtkCurvatures>::New();
	
	  gettimeofday(&tBegin, NULL);
     
	  if(flagOBJ_inputmesh)
	    {
        
	      sprintf(filenameOUTOBJ, "%sm%d.obj", foldernameout,idxImage);
       
	      char *filenameOBJ = (char *)malloc(100*sizeof(char)); 
	      sprintf(filenameOBJ, "%s%d.obj", foldernamein, idxImage);
     
	      vtkSmartPointer<vtkOBJReader> readerOBJ =    vtkSmartPointer<vtkOBJReader>::New();  
	      readerOBJ->SetFileName(filenameOBJ);
	      readerOBJ->Update();
	      polydata->DeepCopy(readerOBJ->GetOutput());

	      //curvaturesFilter->SetInputConnection(readerOBJ->GetOutputPort());
     
	      free(filenameOBJ);
	    }

	  if(flagOFF_inputmesh)
	    { 
     
	      sprintf(filenameOUTOFF, "%s%d.off", foldernameout, idxImage);
     
	      char *filenameOFF = (char *)malloc(100*sizeof(char));
	      sprintf(filenameOFF, "%s%d.off", foldernamein, idxImage);



     
	      vtkSmartPointer<vtkOFFReader> offReader = vtkSmartPointer<vtkOFFReader>::New();
	      offReader->SetFileName(filenameOFF);
	      offReader->Update();
	      polydata->DeepCopy(offReader->GetOutput());


	      //curvaturesFilter->SetInputConnection(offReader->GetOutputPort());

	      free(filenameOFF);
	    }

	  if(flagPLY_inputmesh){
	    //////////////////////read obj file 
  
	    printf("VIDOCK: convert the SES to vtk ...\n");
	    sprintf(filenameOUTPLY, "%s%d.ply", foldernameout, idxImage);
  
   
	    char *filenamePLYin = (char *)malloc(100*sizeof(char));
	    sprintf(filenamePLYin, "%s%d.ply", foldernamein, idxImage);
   
	    // no need to make the
   
	    ////////////////////////// generalize for ply triangular mesh input  
	    std::cout << "Reading file " << std::string(filenamePLYin) << "..." << std::endl;
 
  
	    vtkSmartPointer<vtkPLYReader> reader = vtkSmartPointer<vtkPLYReader>::New();
	    reader->SetFileName(filenamePLYin );
	    reader->Update();
	    ////////////////////////////////////////////////////////////////////
	    ///// 
	    polydata->DeepCopy(reader->GetOutput());

	    //curvaturesFilter->SetInputConnection(reader->GetOutputPort());

  
	    free(filenamePLYin);
	  } // end if ply  

	  /////////////////////////////////////////////////////



	  char *filenameCurvature = (char *)malloc(100*sizeof(char));
	  sprintf(filenameCurvature, "%s%d_wks.txt", foldernamein, idxImage);
	  std::string filenameCurvStr = filenameCurvature;




   
  
	  printf("Loaded %lu points/vertices.\n",  polydata->GetNumberOfPoints ());
  
  
	  vtkSmartPointer<vtkPolyDataWriter> poly_writer = vtkSmartPointer<vtkPolyDataWriter>::New ();
	  // vtk file for input in the conformal 
	  //poly_writer->SetInputData(polydata);
  
	  begin_time = std::clock();
    
#if VTK_MAJOR_VERSION <= 5
	  poly_writer->SetInputConnection(polydata->GetProducerPort());
#else 
	  poly_writer->SetInputData(polydata);
#endif
  
  
  
	  char *filenameVTK = (char *)malloc(100*sizeof(char));
	  sprintf(filenameVTK, "%s%d.vtk", foldernameout, idxImage);
	  std::string file_name= filenameVTK; //"1brsoutVTK.vtk";
	  poly_writer->SetFileName (file_name.c_str());
	  poly_writer->SetFileTypeToASCII(); 
	  poly_writer->Write ();
  
	  // ce vtk est en binaire, CC ne peut pas le lire 
	  //"VTKSph.vtk"

	  sprintf(filenameVTKSphIn, "%sVTKSph%d.vtk",foldernameout, idxImage);
	  //Fonction de ITK qui permet la projection sur la sphere unitaire
	  int flag=vidock_itkConformal(filenameVTK, filenameVTKSphIn);
	  printf("vidock: end conformalMapping\n");
  
  
  
	  // output for the file .asc with idx file 
	  char *filenameCloudASC = (char *)malloc(100*sizeof(char));
	  sprintf(filenameCloudASC, "%s%d.asc",foldernameout, idxImage);

 
	  int conversionFlagASCRGB=convertFile_VTK2ASC_NoRGB(filenameCloudASC, filenameVTKSphIn,filenameCurvature);
	  // int conversionFlagASCRGB=convertFile_VTK2ASC_RGB(filenameCloudASC, filenameVTKSphIn);

	  /*use for get the curv elev*/
	  char *filenameCloudASC_noConf = (char *)malloc(100*sizeof(char));
	  sprintf(filenameCloudASC_noConf, "%s%d_noConf.asc", foldernameout, idxImage);

	  int conversionFlagASC_NoRGB=convertFile_VTK2ASC_NoRGB(filenameCloudASC_noConf, filenameVTK,filenameCurvature);
  
	  //break;
	  char *filenameImage = (char *)malloc(100*sizeof(char));
	  char *filenameImagePano = (char *)malloc(100*sizeof(char));
	  //sprintf(filenameImage, "%d.pgm", idxImage);

	  for(k = 0; k < NB_VIEW; k++)
	    {
	      sprintf(filenameImage, "%s%d_%d.pgm",foldernameout, idxImage,k);
	      sprintf(filenameImagePano, "%s%d_%d_curveElev.asc",foldernameout, idxImage,k);
  
	      // int SphericalImage = Sphere2ImageProjection_Batch(filenameImage, filenameCloudASC, idxImage);
  
	      int SphericalImage = Sphere2ImageProjection_ElevationBatch(filenameImage, filenameCloudASC, filenameCloudASC_noConf, filenameCurvature, filenameImagePano, filenameVTKSphIn, idxImage,k, NB_VIEW);
  
	    }
	  gettimeofday(&tEnd, NULL);

	  printf("Time computing one maps (all view) (milliseconds) : (%ld - %ld)  %ld  \n",tEnd.tv_usec, tBegin.tv_usec, ((tEnd.tv_usec - tBegin.tv_usec) / 1000));
	  printf("*******image out conformal mapping \n"); 
	  // make multi -resolution 
  
	  /*int SphericalImage = Sphere2ImageProjection();*/
    
	  // pass to image 
    
  
  
	  delta_time = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	  std::cout << "time in sec CPU for 1 DEM : " << delta_time << "\n";
    
	  free(filename);
	  free(filenameOUT);
	  free(filenameOUTPLY);
	  free(filenameOUTOBJ);
	  free(filenameOUTOFF);
	  free(filenameVTK);
	  free(filenameVTKSphIn);
	  free(filenameImage);
	  free(filenameCloudASC);
	  free(filenameCloudASC_noConf );
    
    
    
	} // end looping over pdb files 
    
      // batch image processing and RMSD computation
    
      // either load images from disk , either take the image stack  of the 
      // pdb processing 
    
      // stackImage solution 
  
  
  
      return 1;
    }
  return 0;
}


















//int main(int argc, char** argv)
int EDTSurf(/*int argc, char** argv*/ char * inname, char *fileOUT)
{
  ParsePDB pp;
  ProteinSurface pps;
  int inum[4];
  double fnum[2];
  //char inname[200];
  char tpname[200];



  /*char *namePDB1 = (char *)malloc(30*sizeof(char));
    char *namePDB2 = (char *)malloc(30*sizeof(char));
    char *namePDB3 = (char *)malloc(30*sizeof(char));
    char *namePDB4 = (char *)malloc(30*sizeof(char));
    char *namePDB5 = (char *)malloc(30*sizeof(char));
    char *namePDB6 = (char *)malloc(30*sizeof(char));*/
        
  /*struct name*/ 
         

  // default params in pdb 
        

  char filename[200];
  bool flagopt[7];
  bool bcolor;
  int i;
  clock_t remcstart, remcfinish;
  /*if(argc<3)
    {
    printf("usage: EDTSurf -i pdbname ...\n");
    printf("-o outname\n");
    printf("-t 1-MC 2-VCMC\n");
    printf("-s 1-VWS 2-SAS 3-MS 4-SES\n");
    printf("-c 1-pure 2-atom 3-chain\n");
    printf("-p probe radius [0,2.0]\n");
    printf("-f scale factor (0,20.0]\n");
    printf("-h 1-in and out 2-out 3-in\n");
    printf("output1: outname.ply\n");
    printf("output2: outname.asa\n");
    printf("output3: outname-cav.pdb\n");
    return 0;
    }*/
  for(i=0;i<7;i++)
    {
      flagopt[i]=false;
    }
  //default value
  inum[0]=2;//1-MC 2-VCMC
  inum[1]=3;//1-VWS 2-SAS 3-MS 4-SES // 3 
  inum[2]=2;//1-pure 2-atom 3-chain
  inum[3]=1;//1-in and out 2-out 3-in
  fnum[0]=1.4;//probe radius
  fnum[1]=4.00;//scale factor
  strcpy(tpname, fileOUT);
  //strcpy(tpname,"out");
  i=1;
  //set value
  //char * inname = (char*)malloc(40*sizeof(char)); 
  //
	
  //inname = "1fssA.pdb"; 
  //"1brsD.pdb";
	
  // test here the file to be opened too 
	
	
  //int nbfiles = 4; 
  // pdb1, 2, 3, 4 
  //char **stackfilename = (char **)malloc(nbfiles*sizeof(char *));
	
  //free()
	
  //vector
	

  printf("The specification is: input: %s, ",inname);
  if(inum[0]==1)
    printf("triangulation: MC, ");
  else printf("triangulation: VCMC, ");
  if(inum[1]==1)
    printf("surface: VWS, ");
  else if(inum[1]==2 || inum[1]==0)
    printf("surface: SAS, ");
  else printf("surface: MS, ");
  if(inum[2]==1)
    printf("color: pure, ");
  else if(inum[2]==2)
    printf("color: atom, ");
  else printf("color: chain, ");
  if(inum[3]==1)
    printf("surface: outer+inner, ");
  else if(inum[3]==2)
    printf("surface: outer, ");
  else printf("surface: inner, ");
  printf("radius: %6.3f, ",fnum[0]);
  printf("scale: %6.3f, ",fnum[1]);
  printf("outname: %s\n",tpname);
  printf("Load file...\n");
  bcolor=true;
  pp.loadpdb(inname);
  pp.extractbb(0,-1,1);
  //	pp.PCA();
  pps.proberadius=fnum[0];
  pps.fixsf=fnum[1];
  remcstart=clock(); 
  if(inum[1]==1)
    {
      printf("Initialize...\n");
      pps.initpara(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,false,false);
      printf("actual boxlength %3d, box[%3d*%3d*%3d], scale factor %6.3f\n",
	     pps.boxlength,pps.plength,pps.pwidth,pps.pheight,pps.scalefactor);
      printf("Build van der Waals solid\n");
      pps.fillvoxels(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,false,pp.proseq,bcolor);
      pps.buildboundary();
      printf("Build triangulated surface\n");
      if(inum[0]==1)
	pps.marchingcubeorigin2(1);
      else if(inum[0]==2)
	pps.marchingcube(1);
    }
  else if(inum[1]==2)
    {
      printf("Initialize...\n");
      pps.initpara(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,false,true);
      printf("actual boxlength %3d, box[%3d*%3d*%3d], scale factor %6.3f\n",
	     pps.boxlength,pps.plength,pps.pwidth,pps.pheight,pps.scalefactor);
      printf("Build solvent-accessible solid\n");
      pps.fillvoxels(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,false,pp.proseq,bcolor);
      pps.buildboundary();
      printf("Build triangulated surface\n");
      if(inum[0]==1)
	pps.marchingcubeorigin2(3);
      else if(inum[0]==2)
	pps.marchingcube(3);
    }
  else if(inum[1]==3)
    {
      printf("Initialize...\n");
      pps.initpara(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,true,true);
      printf("actual boxlength %3d, box[%3d*%3d*%3d], scale factor %6.3f\n",
	     pps.boxlength,pps.plength,pps.pwidth,pps.pheight,pps.scalefactor);
      printf("Build solvent-accessible solid\n");
      pps.fillvoxels(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,true,pp.proseq,bcolor);
      pps.buildboundary();
      printf("Euclidean Distance Transform\n");
      pps.fastdistancemap(0);
      printf("Build triangulated surface\n");
      if(inum[0]==1)
	pps.marchingcubeorigin2(4);
      else if(inum[0]==2)
	pps.marchingcube(4);
    }
  else if(inum[1]==4)
    {
      printf("Initialize...\n");
      pps.initpara(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,false,true);
      printf("actual boxlength %3d, box[%3d*%3d*%3d], scale factor %6.3f\n",
	     pps.boxlength,pps.plength,pps.pwidth,pps.pheight,pps.scalefactor);
      printf("Build solvent-accessible solid\n");
      pps.fillvoxels(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,false,pp.proseq,bcolor);
      pps.buildboundary();
      printf("Euclidean Distance Transform\n");
      pps.fastdistancemap(0);
      printf("Build van der Waals solid\n");
      pps.boundingatom(false);
      pps.fillvoxelswaals(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,false,pp.proseq,bcolor);
      printf("Build triangulated surface\n");
      if(inum[0]==1)
	pps.marchingcubeorigin2(2);
      else if(inum[0]==2)
	pps.marchingcube(2);
    }
  else if(inum[1]==0)
    {
      printf("Initialize...\n");
      pps.initpara(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,true,true);
      printf("actual boxlength %3d, box[%3d*%3d*%3d], scale factor %6.3f\n",
	     pps.boxlength,pps.plength,pps.pwidth,pps.pheight,pps.scalefactor);
      printf("Build solvent-accessible solid\n");
      pps.fillvoxels(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,true,pp.proseq,bcolor);
      pps.buildboundary();
      printf("Euclidean Distance Transform\n");
      pps.fastdistancemap(1);
      printf("Calculate Depth\n");
      pps.calcdepth(pp.numbb,pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,pp.bb,true);
    }
  remcfinish=clock(); 
  double duration = (double)(remcfinish - remcstart)/CLOCKS_PER_SEC;
  printf("Total time %.3f seconds\n",duration);
  //depth
  if(inum[1]==0)
    {
      printf("Output atom depth and residue depth\n");
      sprintf(filename,"%s_atom.dep",tpname);
      FILE *file;
      file=fopen(filename,"wt");
      fprintf(file,"index atom# res#   depth\n");
      for(i=pp.promod[0].procha[0].chainseg.init;i<=pp.promod[0].procha[pp.promod[0].nchain].chainseg.term;i++)
	{
	  fprintf(file,"%5d %5d %4d %7.3f\n",i-pp.promod[0].procha[0].chainseg.init+1,pp.proseq[i].seqno,pp.proseq[i].resno,pps.depval[i]);
	}
      fclose(file);
      sprintf(filename,"%s_res.dep",tpname);
      file=fopen(filename,"wt");
      fprintf(file,"indx res# A   depth\n");
      for(i=0;i<pp.numbb;i++)
	{
	  double tsum=0;
	  int tnum=0;
	  for(int k=pp.bb[i].istart;k<=pp.bb[i].iend;k++) 
	    {
	      tsum+=pps.depval[k];
	      tnum++;
	    }
	  tsum/=double(tnum);
	  fprintf(file,"%4d %4d %c %7.3f\n",i+1,pp.bb[i].resind,pp.bb[i].resid,tsum);
	}
      fclose(file);
      return 1;
    }
  //additional functions below
  pps.checkEuler();
  pps.computenorm();
  printf("No. vertices %d, No. triangles %d\n",pps.vertnumber,pps.facenumber);	
  pps.calcareavolume();
  printf("Total area %.3f and volume %.3f\n",pps.sarea,pps.svolume);
  printf("Distinguish inner and outer surfaces\n");
  pps.surfaceinterior();
  printf("Calculate cavity number...\n");
  pps.cavitynumbers();
  printf("Cavity number is %d\n",pps.ncav);
  printf("Calculate cavity area and volume...\n");
  pps.cavitiesareavolume();
  printf("Cavity area %.3f and volume %.3f\n",pps.carea,pps.cvolume);
  printf("Calculate inner and outer atoms\n");
  pps.atomsinout(pp.promod[0].procha[0].chainseg.init,pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq);
  if(pps.ncav>0)
    {	
      printf("Output cavity information\n");
      sprintf(filename,"%s-cav.pdb",tpname);
      pps.outputcavityatoms(pp.promod[0].procha[0].chainseg.init,
			    pp.promod[0].procha[pp.promod[0].nchain].chainseg.term,pp.proseq,filename);
    }
  pps.laplaciansmooth(1);
  pps.computenorm();
  printf("Output 3D model\n");
  pps.checkinoutpropa();
  sprintf(filename,"%s.ply",tpname);	
  pps.outputply(filename,pp.proseq,inum[2]-1,inum[3]-1);	
  if(inum[1]==2)
    {
      printf("Output residue surface area\n");
      sprintf(filename,"%s.asa",tpname);
      pps.outsas(pp.numbb,pp.bb,pp.proseq,filename);
    }

  //29 Oct CD
  //free(inname);
  return 1;

} 

