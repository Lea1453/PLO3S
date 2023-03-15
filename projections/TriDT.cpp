#define _USE_MATH_DEFINES
 

// CD 23 Sept 2015 
//modified for pcl path files wrt pcl install in Linux_Office Machine 
// there are several files which are not needed 
#include <math.h>
#include <cstdlib> 
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <opencv2/core/core.hpp>
// #include <opencv2/contrib/contrib.hpp> //:: this is in another version of openCV,
#include <opencv2/calib3d/calib3d.hpp>
#include <pcl/visualization/cloud_viewer.h>

// planar segmentation
//#include <iostream>
#include <pcl/ModelCoefficients.h>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>


//vtk from PCL_smooth
//#include <pcl/surface/vtk.h>
//outforcompiling
//pcl-1.7/pcl/surface/vtk_smoothing
#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
//#include <pcl/surface/vtk_smoothing/vtk_mesh_smoothing_laplacian.h>
#include <pcl/surface/vtk_smoothing/vtk_utils.h>
#include <vtkSmartPointer.h>
#include <vtkSmoothPolyDataFilter.h>
#include <pcl/io/vtk_io.h>


//////////////////

#include <vtkGenericDataObjectReader.h>
#include <vtkStructuredGrid.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <string>

#include <unistd.h>

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
//////////////////

#include "TriCall_CD.h"
#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkTIFFImageIO.h"
#include "itkRGBAPixel.h"

#include "itkIdentityTransform.h"

#include "itkResampleImageFilter.h"

#include <stdio.h>
#include <stdlib.h>


#include <pcl/filters/project_inliers.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkPlaneSource.h>
#include <vtkTexture.h>
#include "TriDT.h"



/*
 * filenameImage_OUT : image direct en pgm (%d.pgm inutile pour le moment)
 * filenameConfCloudASC_IN : coordonnees sphere unitaire de points en coord cartesiennes (fichier %d.asc)
 * filenameCartezCloudASC_IN : surface 3D de points (%d_noConf.asc)
 * filenameCurvature_IN : valeur de courbure (%d_curvature3D.txt) /!\ les valeurs sont ordonnées pour fitter avec les autres fichiers de surface 3D
 * filenameImagePano_OUT : panoramique avec la valeur de courbure de la surface 3D  (%s%d_%d_curveElev.asc)
 * filenameVTKSph_IN : le nom du fichier VTK de le sphere unitaire
 * idxPano : nombre de la panoramique traite 
 * idxView : nombre de la vue traite pour la pano "idxPano"
 * nbView : nombre de vue dans le modele
 *
 */

int ConformalSphere2ImageProjection_ElevationBatch(char *filenameImage_OUT, char *filenameConfCloudASC_IN, char *filenameCartezCloudASC_IN, char* filenameCurvature_IN, char *filenameImagePano_OUT, char *filenameVTKSph_IN, int idxPano, int idxView, int nbView)
{
  
  
  
  
  
  printf("D. Craciun 4 CAOR - Mines \n"); 

  // take points in vector   
  p3D stack3DMesh_XYZRGB = CD_readASC_filename(filenameCartezCloudASC_IN);

  //p3D stack3DMesh_XYZRGB = CD_readASC();
  ////////////
  printf("Loading 3D point clouds  file ... \n");
  
   
   

  char ch; // file_name[25];
  FILE *fp;
  int ii;
 
  char *file_name = filenameConfCloudASC_IN; 

   
   
   
  char *filenameCartez = filenameCartezCloudASC_IN; 
   
   
  fp = fopen(file_name,"r"); // read mode
 
  if( fp == NULL )
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }
  // give here the name file 
 
 
  printf("The contents of %s file are :\n", file_name);
  double x, y, z; 
  int space=0;
  int newline = 0;
  while( ( ch = fgetc(fp) ) != EOF )
    {
      if (ch == ' ') space++;
      if(ch == '\n') newline++;
        
    }


  typedef struct {
    float X;
    float Y;
    float Z;
    
    float R;
    float G;
    float B; 
  } pt3D;

  printf("spaces  %d newlines %d\n",  space, newline); 
   
  
  int ok_seek = fseek(fp, 0, SEEK_SET);
  double d;

   
  //length:: 3 (XyZ)* nbLignes+ 1
  int nbTotalNumber = newline * 3; // X,Y,Z,R,G,B
  printf("nbTotalNumber %d\n", nbTotalNumber);
  int nbPts3D = newline;

  pt3D *pointsXYZRGB; //stack here points
   
  float * pts3D;
  int length = 0;
  pts3D = (float *)malloc(nbTotalNumber*sizeof(float));
  length = 0; 
  pointsXYZRGB = (pt3D *)malloc(newline*sizeof(pt3D));
  int countNb3D=0;
  while( length<nbTotalNumber )
    {
        
      fscanf(fp, "%lf", &d);
        
      pts3D[length] = d;
      length++;
        
    }


  int countline=0;
  for(ii=0; ii<length; ii+=3)
    {

      pointsXYZRGB[countline].X = pts3D[ii];
      pointsXYZRGB[countline].Y = pts3D[ii+1];
      pointsXYZRGB[countline].Z = pts3D[ii+2];
 
      pointsXYZRGB[countline].R = 0;
      pointsXYZRGB[countline].G = 0;
      pointsXYZRGB[countline].B = 0; 

      countline++;
        
    
    }
  
 
  fclose(fp);
  pcl::PointCloud<pcl::PointXYZRGB> cloud_true;
  pcl::PointCloud<pcl::PointXYZRGB> cloud_inliers;
  pcl::PointCloud<pcl::PointXYZ> cloud;


  cloud_true.width    = newline;
  cloud_true.height   = 1;
  cloud_true.is_dense = false;
  cloud_true.points.resize (cloud_true.width * cloud_true.height);

  
  
  printf("size %d \n", cloud_true.points.size());

  cloud.width  = newline;
  cloud.height = 1;
  cloud.points.resize (cloud.width * cloud.height);



  countline =0;
  for (size_t i = 0; i < cloud_true.points.size(); ++i)
    {
      cloud_true.points[i].x = pointsXYZRGB[countline].X;
      cloud_true.points[i].y = pointsXYZRGB[countline].Y;
      cloud_true.points[i].z = pointsXYZRGB[countline].Z;

      cloud.points[i].x = pointsXYZRGB[countline].X;
      cloud.points[i].y = pointsXYZRGB[countline].Y;
      cloud.points[i].z = pointsXYZRGB[countline].Z;

 

      //cloud_opt.points[i].y = points_opt[i].y;
      //cloud_opt.points[i].z = points_opt[i].z;
      cloud_true.points[i].r = pointsXYZRGB[countline].R;
      cloud_true.points[i].g = pointsXYZRGB[countline].G;
      cloud_true.points[i].b = pointsXYZRGB[countline].B;
      countline++;
    }

  


  free(pointsXYZRGB);
  free(pts3D);
  printf("Finish loading file \n");
  
  // stack3DMesh_XYZRGB
  //////////////////////////////////
  
  
  
  /////////////////////////////////
  
  
  
  int flagPCL_Display = 0;
 
  // test display 28 Sept
  if(flagPCL_Display)
    {
      pcl::visualization::PCLVisualizer viewer("3D Viewer");
      viewer.setBackgroundColor(0,255,0);
      viewer.addCoordinateSystem (2.0); // scaled 
      viewer.initCameraParameters ();


      pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> green(cloud_true.makeShared());  

      viewer.addPointCloud<pcl::PointXYZRGB> (cloud_true.makeShared(), green, "true points");
      viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "true points");

      viewer.spin();
    }
  // test display 
  printf("finishing loading \n");
  ////////////////////////// finishing reading and loading the 3D point cloud

  //from planar segmentation


  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZ> seg;
  // Optional
  seg.setOptimizeCoefficients (true);

 
  // Mandatory
  seg.setModelType(pcl::SACMODEL_PLANE);
  seg.setMethodType(pcl::SAC_RANSAC);
  //seg.setMethodType(pcl::SAC_PROSAC); //174, 05
  //seg.setMethodType(pcl::SAC_LMEDS);
  seg.setDistanceThreshold (10000000);// 15 ver init from me


  printf("1\n");
  seg.setInputCloud(cloud.makeShared());
  printf("2\n");
  seg.segment (*inliers, *coefficients);
  printf("3\n");

  p3D stackP3DInliers;
  int flagRANSAC_OK = 0; 
  if (inliers->indices.size () == 0)
    {
      PCL_ERROR ("Could not estimate a planar model for the given dataset.");
      //p3D stackP3DInliers;
      stackP3DInliers.sizeStackPoints3D = cloud_true.points.size();
      //  stackP3DInliers.stackPoints3D = (point3D *)malloc(cloud_true.points.size());
  
      /*16 Oct 2015*/
      int idx_inliersIN =0;
      for (size_t i = 0; i < cloud_true.points.size(); ++i)
	{
	  stackP3DInliers.stackPoints3D[idx_inliersIN].x=cloud_true.points[i].x;
	  stackP3DInliers.stackPoints3D[idx_inliersIN].y=cloud_true.points[i].y;
	  stackP3DInliers.stackPoints3D[idx_inliersIN].z=cloud_true.points[i].z;

	  stackP3DInliers.stackPoints3D[idx_inliersIN].Red = cloud_true.points[i].r;
	  stackP3DInliers.stackPoints3D[idx_inliersIN].Green = cloud_true.points[i].g;
	  stackP3DInliers.stackPoints3D[idx_inliersIN].Blue = cloud_true.points[i].b;
	  stackP3DInliers.stackPoints3D[idx_inliersIN].index = i;
	  printf(" %f %f %f\n", stackP3DInliers.stackPoints3D[idx_inliersIN].x, stackP3DInliers.stackPoints3D[idx_inliersIN].y, 
		 stackP3DInliers.stackPoints3D[idx_inliersIN].z);
	  ++idx_inliersIN;
	}
      flagRANSAC_OK =0;
   

      //return (-1);
    } // end if not planar 
  else{  // planar

    flagRANSAC_OK = 1;
    printf("coeff plane %f %f %f %f \n", coefficients->values[0], coefficients->values[1], coefficients->values[2], coefficients->values[3]); 

    printf("Model inliers %d of %d \n", inliers->indices.size(), nbPts3D); 



    //inliers point cloud initialisation  
  
    cloud_inliers.width    = inliers->indices.size();
    cloud_inliers.height   = 1;
    cloud_inliers.is_dense = false;
    cloud_inliers.points.resize (cloud_inliers.width * cloud_inliers.height);
    //p3D stackP3DInliers;
    stackP3DInliers.sizeStackPoints3D = inliers->indices.size();
    stackP3DInliers.stackPoints3D = (point3D *)malloc(inliers->indices.size()*sizeof(point3D));
    ///////////// write ascii file with the inliers
    FILE *fileXYZRGBInliers;
    if( (fileXYZRGBInliers = fopen("XYZInliers.asc", "w") ) == NULL)
      {
	fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "XYZInliers.asc");
	exit(-1);
      }

  

    //write an ascii file with the inliers  
  

    size_t idx_inliers=0;
    //std::cerr << "Model inliers: " << inliers->indices.size () << std::endl;
  
    for (size_t i = 0; i < inliers->indices.size(); ++i)
      { //std::cerr << inliers->indices[i] << "    " << cloud.points[inliers->indices[i]].x << " "
	//                                       << cloud.points[inliers->indices[i]].y << " "
	//                                     << cloud.points[inliers->indices[i]].z << std::endl;

	int idxInliers = inliers->indices[i];
	//printf("idtrue %d idxcount %d\n", idxInliers, idx_inliers);
    
    
	cloud_inliers.points[idx_inliers].x = cloud_true.points[inliers->indices[i]].x; //cloud.true[inliers->indices[i]].x;
	cloud_inliers.points[idx_inliers].y = cloud_true.points[inliers->indices[i]].y;
	cloud_inliers.points[idx_inliers].z = cloud_true.points[inliers->indices[i]].z;
	cloud_inliers.points[idx_inliers].r = cloud_true.points[inliers->indices[i]].r;
	cloud_inliers.points[idx_inliers].g = cloud_true.points[inliers->indices[i]].g;
	cloud_inliers.points[idx_inliers].b = cloud_true.points[inliers->indices[i]].b;

	
	// write an ascii file with the inliers
	//fprintf(fileXYZRGBInliers,"%f %f %f %d %d %d\n", cloud_inliers.points[idx_inliers].x, cloud_inliers.points[idx_inliers].y, cloud_inliers.points[idx_inliers].z, cloud_inliers.points[idx_inliers].r, cloud_inliers.points[idx_inliers].g, cloud_inliers.points[idx_inliers].b); 
	fprintf(fileXYZRGBInliers,"%f %f %f %d %d %d\n", stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].x,stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].y, stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].z, cloud_inliers.points[idx_inliers].r, cloud_inliers.points[idx_inliers].g, cloud_inliers.points[idx_inliers].b); 
	//printf("%f %f %f\n", stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].x,stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].y, stack3DMesh_XYZRGB.stackPoints3D[idx_inliers].z );

 
	// set points for the spherical projection
	stackP3DInliers.stackPoints3D[idx_inliers].x=cloud_true.points[inliers->indices[i]].x;
	stackP3DInliers.stackPoints3D[idx_inliers].y=cloud_true.points[inliers->indices[i]].y;
	stackP3DInliers.stackPoints3D[idx_inliers].z=cloud_true.points[inliers->indices[i]].z;

	stackP3DInliers.stackPoints3D[idx_inliers].Red = cloud_true.points[inliers->indices[i]].r;
	stackP3DInliers.stackPoints3D[idx_inliers].Green = cloud_true.points[inliers->indices[i]].g;
	stackP3DInliers.stackPoints3D[idx_inliers].Blue = cloud_true.points[inliers->indices[i]].b;
	stackP3DInliers.stackPoints3D[idx_inliers].index = idx_inliers;
   

	++idx_inliers;
      }
    fclose(fileXYZRGBInliers);

  } 

  printf("flagRANSAC_ok : %d \n", flagRANSAC_OK);
  /*flagRANSAC_ok semble etre toujours 1*/
 

  // passage des inliers pour la triangulation spherique et projection image pour le remplissage des trous
  //////////////////////////////////////////////////// 
  p3D stackSphInliers; 
  int flagRGB = 1;
 
  // /!\ conversion des coordonées cartesiennes à sphériques du la sphère unité 
  if (flagRANSAC_OK) 
    {
      stackSphInliers= stackCartezian2Spheric_mview(stackP3DInliers, inliers->indices.size(), flagRGB, idxView, nbView);
    }
  else {
    stackSphInliers= stackCartezian2Spheric_mview(stackP3DInliers,cloud_true.points.size(), flagRGB, idxView, nbView);
  } 



  /* FILE *fileSphCoordSph;
    if( (fileSphCoordSph = fopen("SphCoordSph.asc", "w") ) == NULL)
      {
	fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "SphCoordSph.asc");
	exit(-1);
      }
  
    //write an ascii file with the inliers  

    for (size_t i = 0; i < stackSphInliers.sizeStackPoints3D; ++i)
      { 
	fprintf(fileSphCoordSph,"%f %f %f\n", stackSphInliers.stackPoints3D[i].x, stackSphInliers.stackPoints3D[i].y, stackSphInliers.stackPoints3D[i].z); 

      }
      fclose(fileSphCoordSph);*/

  


  
  
  printf("Spherical conversion done ...\n");  

  int stackNbSphInliers = stackSphInliers.sizeStackPoints3D;

  
  printf("main sph %d \n", stackNbSphInliers);

  // compute bounds 
  
  
   
  SphericalBounds mySphericBounds; 
  mySphericBounds = computeBoundSph(stackSphInliers, stackNbSphInliers);
  printf("Spherical bounds done ...\n");
  // we should recover the ro too 
  // multi-resolution and one resolution routine 
  int flagMulti_Resolution = 1;

  Image2Laser outImageLaser; 
  Image2Laser outImageLaser_L1;
  Image2Laser outImageLaser_L2;
  Image2Laser outImageLaser_L3;
  int stepCoeff = 1;
  
  if(flagMulti_Resolution==0){

    //   outImageLaser = vidock_triangulateStackSpheric2Image(stackSphInliers, mySphericBounds, stackNbSphInliers, stackP3DInliers);
    printf("Not used anymore \n");
  
  }
  else {
    printf("Curvature loading \n");
    /*Recupere les valeur de courbure*/
    ifstream curvatureFile;
    double tmpVal;
    int sizeCurvFile = 0;
  
    curvatureFile.open(filenameCurvature_IN);
  
    while(curvatureFile >> tmpVal)
      {
	sizeCurvFile ++;
      }

    float *arrCurv = (float*)malloc(sizeCurvFile * sizeof(float));;

    std::cout << filenameCurvature_IN << "\n";
    printf("size arrCurv : %d \n", sizeCurvFile);
    
    curvatureFile.clear();                 // clear fail and eof bits
    curvatureFile.seekg(0, std::ios::beg);

    ii =0;
    while(curvatureFile >> tmpVal)
      {

	arrCurv[ii] = tmpVal ;

	ii++;
      }

    /* /!\ /!\ /!\ Entree dans la fonction d'attribution de la valeur d'elevation. Fonction dans triIO.c */
    outImageLaser = vidock_triangulateStackSpheric2ImageElevation_Step(stackSphInliers, stack3DMesh_XYZRGB, mySphericBounds, stackNbSphInliers, stackP3DInliers, filenameVTKSph_IN, arrCurv, stepCoeff, filenameImage_OUT, filenameImagePano_OUT, idxPano);

    /* /!\ /!\ /!\ Entree dans la fonction d'attribution de la valeur rho. Fonction dans triIO.c */
    //outImageLaser = vidock_triangulateStackSpheric2Image_Step(stackSphInliers, mySphericBounds, stackNbSphInliers, stackP3DInliers, stepCoeff, filenameImage_OUT, idxPano);
   
   
    unsigned int _nbLignes = outImageLaser.nbRows; 
    unsigned int _nbCols = outImageLaser.nbCols; 

    //int okElevation = writeFloatImage(outImageLaser.dDepthImage, _nbLignes,_nbCols);
    free(arrCurv);

   
  }

  printf("Spherical DT triangulation done ...\n");



  
  free(stack3DMesh_XYZRGB.stackPoints3D);
  free( stackP3DInliers.stackPoints3D);
  
  
  
  
  
  return 1; 
}
/// end curvature








// recover the image and save it with itk 
int writeFloatImage(float *imageInput, int nbLignes, int nbCols){
   

  printf("Vidock: writing float image  %d %d \n", nbLignes, nbCols);


  std::string outputFilename;

  outputFilename = "Elevation_Image.tif";

  typedef itk::Image< float, 2>  ImageType;
 
  ImageType::RegionType region;
  ImageType::IndexType start;
  start[0] = 0; // x - col 
  start[1] = 0;  // y - row
 
  ImageType::SizeType size;
  size[0] = nbCols; // nbCols  
  size[1] = nbLignes; // nb Rows
 
  region.SetSize(size);
  region.SetIndex(start);
 
  ImageType::Pointer image = ImageType::New();
  image->SetRegions(region);
  image->Allocate();
 
  itk::ImageRegionIterator<ImageType> imageIterator(image,region);
  int countpix= 0;
  

  printf("k\n"); 
 
  while(!imageIterator.IsAtEnd())
    {

    countpix++; 
    ++imageIterator;
   }
 
  typedef  itk::ImageFileWriter< ImageType  > WriterType;
  typedef  itk::TIFFImageIO TIFFIOType;

  WriterType::Pointer writer = WriterType::New();
  TIFFIOType::Pointer tiffIO = TIFFIOType::New();
  tiffIO->SetPixelType(itk::ImageIOBase::RGBA);
  writer->SetFileName(outputFilename);
  writer->SetInput(image);
  writer->SetImageIO(tiffIO);
  writer->Update();
  // end writing image int depth image 
  
  
  return 1; 
}
