/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/



#include "itkMeshFileReader.h"
#include "itkMeshFileWriter.h"

#include "../utilTools/InsightToolkit-4.8.1/Modules/Nonunit/Review/include/itkConformalFlatteningMeshFilter.h"

#include "TriDT.h"


#include <pcl/io/io.h>
#include <pcl/io/ply_io.h>

#include <vtkPoints.h>
#include <vtkUnsignedCharArray.h>
#include <vtkVertexGlyphFilter.h>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include<vtkPolyDataReader.h>


#include "itkConformal.h"

/*vidock_itkConformal :
  Permet la projection conforme sur la sphère
  Arg :
  vtkFilename : fichier en entree vtk, surface 3D
  vtkFilenameSph : fichier sortie, sphere unitaire
*/
int vidock_itkConformal(/*int argc*/char *vtkFilename, char *vtkFilenameSph)
{
  
  printf("vidock_itkConformal \n");

  typedef itk::Mesh< double, 3 > MeshType;

  typedef itk::ConformalFlatteningMeshFilter<MeshType, MeshType>  FilterType;

  typedef itk::MeshFileReader<MeshType>  ReaderType;
  typedef itk::MeshFileWriter<MeshType>  WriterType;

  typedef MeshType::CellIdentifier  CellIdentifier;


  std::string _file_name= vtkFilename;
  std::cout << "Read " << _file_name << std::endl;
  
  
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( _file_name );

  try
    {
      reader->Update();
    }
  catch( itk::ExceptionObject & excp )
    {
      std::cerr << excp << std::endl;
      return EXIT_FAILURE;
    }

  MeshType::Pointer mesh = reader->GetOutput();

 
  
  FilterType::Pointer filter = FilterType::New();

  filter->SetInput( mesh );

  CellIdentifier  polarCellId = 0; // default set to the first cell


  filter->SetPolarCellIdentifier( polarCellId );
  // set to 1 by default for spherical projection
  int mapToSphere=1;
  
  if( mapToSphere == 1 )
    {
      filter->MapToSphere();
    }
  else
    {
      filter->MapToPlane();
    }



  std::cout << "Execute the filter" << std::endl;

  try
    {
      filter->Update();
    }
  catch( itk::ExceptionObject & excp )
    {
      std::cout << "error \n";
      std::cerr << excp << std::endl;
      return EXIT_FAILURE;
    }

  // Get the Smart Pointer to the Filter Output
  MeshType::Pointer newMesh = filter->GetOutput();

  //
  // Write to file
  //

  

  std::string _file_nameSph= vtkFilenameSph; 
  
  
  std::cout << "Write " << _file_nameSph << std::endl;
  WriterType::Pointer writer = WriterType::New();
  writer->SetInput( newMesh );
  writer->SetFileName(  _file_nameSph );

  try
    {
      writer->Update();
    }
  catch( itk::ExceptionObject & excp )
    {
      std::cerr << excp << std::endl;
      return EXIT_FAILURE;
    }


  return 1;
}


int convertFile_VTK2ASC(char *filenameVTKSphIN)
{
 
  
  vtkSmartPointer<vtkPolyData> polydataConformal_SphVTK;
  vtkSmartPointer<vtkPolyDataReader> readerVTKSph = vtkSmartPointer<vtkPolyDataReader>::New();



  readerVTKSph->SetFileName ( filenameVTKSphIN);
  readerVTKSph->Update();
  polydataConformal_SphVTK = readerVTKSph->GetOutput();
  printf("Loaded spherical conformal mapping  with %lu points/vertices.\n", polydataConformal_SphVTK->GetNumberOfPoints());



  pcl::PointCloud<pcl::PointXYZRGB> cloudSpherical;
  cloudSpherical.width    = polydataConformal_SphVTK->GetNumberOfPoints();
  cloudSpherical.height   = 1;
  cloudSpherical.is_dense = false; // w/ Nans
  cloudSpherical.points.resize (polydataConformal_SphVTK->GetNumberOfPoints() * cloudSpherical.height);
  
  FILE *fileXYZRGB;
  if( (fileXYZRGB = fopen("CloudSphericXYZRGB_max.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "CloudSphericXYZRGB_max.asc");
      exit(-1);
    }

  

 vtkIdType ii = 0;
 int idx = 0;
for(ii = 0; ii<polydataConformal_SphVTK->GetNumberOfPoints(); ii++)
 {
   
  
  printf("recover color points Color %lu \n", ii); 
  double point3D[3];
  polydataConformal_SphVTK->GetPoints()->GetPoint(ii, point3D);   
  
  

  printf("recover color points Color %lu %f %f %f \n", ii, point3D[0], point3D[1], point3D[2]); 
 
  
  cloudSpherical.points[idx].x = point3D[0];
  cloudSpherical.points[idx].y = point3D[1];  
  cloudSpherical.points[idx].z = point3D[2];


  fprintf(fileXYZRGB,"%f %f %f %d %d %d\n", cloudSpherical.points[idx].x, cloudSpherical.points[idx].y, cloudSpherical.points[idx].z, cloudSpherical.points[idx].r, cloudSpherical.points[idx].g, cloudSpherical.points[idx].b); 
 
 
  idx++;
    
 }  

fclose(fileXYZRGB);
  
  return 1;
}




int convertFile_VTK2ASC_RGB(char *FilenameASC_Out, char *filenameVTKSphIN)
{
  
  
vtkSmartPointer<vtkPolyData> polydataConformal_SphVTK;
vtkSmartPointer<vtkPolyDataReader> readerVTKSph = vtkSmartPointer<vtkPolyDataReader>::New();


// 
readerVTKSph->SetFileName (/*"1brsoutVTKSph.vtk"*/ filenameVTKSphIN);
readerVTKSph->Update();
polydataConformal_SphVTK = readerVTKSph->GetOutput();
printf("Loaded spherical conformal mapping  with %lu points/vertices.\n", polydataConformal_SphVTK->GetNumberOfPoints());

// looping on points 

  /*vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
  colors->SetNumberOfComponents(3);
  colors->SetName ("Colors");*/

  pcl::PointCloud<pcl::PointXYZRGB> cloudSpherical;
  cloudSpherical.width    = polydataConformal_SphVTK->GetNumberOfPoints();
  cloudSpherical.height   = 1;
  cloudSpherical.is_dense = false; // w/ Nans
  cloudSpherical.points.resize (polydataConformal_SphVTK->GetNumberOfPoints() * cloudSpherical.height);
  
  
  FILE *fileXYZRGB;
  
  if( (fileXYZRGB = fopen(/*"CloudSphericXYZRGB_max.asc"*/FilenameASC_Out, "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", /*"CloudSphericXYZRGB_max.asc"*/FilenameASC_Out);
      exit(-1);
    }

    
  vtkIdType ii = 0;
 int idx = 0;
for(ii = 0; ii<polydataConformal_SphVTK->GetNumberOfPoints(); ii++)
 {
   
   //polydata4ColoredPoints->GetPointData()
  
   //  printf("recover color points Color %lu \n", ii); 
  double point3D[3];
  polydataConformal_SphVTK->GetPoints()->GetPoint(ii, point3D);   
  
  

  //unsigned char colorR = polydata4ColoredPoints->GetPointData()->GetScalars(0, 0);
  

  // printf("recover color points Color %lu %f %f %f \n", ii, point3D[0], point3D[1], point3D[2]); 
  //unsigned char kk = polydata->GetPointData()->GetScalars(0,0); //id, component
  // idPoint, colorComponent
  /*unsigned char colorRed = polydataConformal_SphVTK->GetPointData()->GetScalars()->GetComponent(ii,0);
  unsigned char colorG = polydataConformal_SphVTK->GetPointData()->GetScalars()->GetComponent(ii,1);
  unsigned char colorB = polydataConformal_SphVTK->GetPointData()->GetScalars()->GetComponent(ii,2);*/

  //printf("wtf %d %d %d \n", colorRed, colorG, colorB);
  
  cloudSpherical.points[idx].x = point3D[0];
  cloudSpherical.points[idx].y = point3D[1];  
  cloudSpherical.points[idx].z = point3D[2];
  //cloudSpherical.points[idx].r = colorRed;
  //cloudSpherical.points[idx].g = colorG;
  //cloudSpherical.points[idx].b = colorB;

  //color adjustement for visu
  /*if( (colorRed!=0) && (colorG == 0) && (colorB == 0) ) // 1 0 0
   { //cloudSpherical.points[idx].r = 255;
     colorRed = 255; 
     //colorG = colorB=0;
   }
 if( (colorG !=0)&& (colorRed==0) &&(colorB==0)  ) // 0 1 0
   {
     colorG = 255;
     //colorRed = colorB = 0;
   } 

  if( (colorB !=0)&& (colorRed==0) &&(colorG==0)  ) // 0 0 1
   {
     colorB = 255;
     //colorRed = colorG = 0;
   } 
  // 110
   if( (colorG !=0)&& (colorRed!=0) &&(colorB==0)  ) // 1 1 0
   {
     colorRed = 255;
     colorG = 255;
   } 

   //011
    if( (colorRed ==0)&& (colorG!=0) &&(colorB!=0)  ) // 0 1 1 
   {
     colorG=255;
     colorB=255;
   } 
  
    if( (colorB !=0)&& (colorRed!=0) &&(colorG==0)  ) // 101
   {
     colorRed = 255;
     colorB = 255;
   } 

   if( (colorG !=0)&& (colorRed!=0) &&(colorB!=0)  ) // 1 1 1
   {
     colorRed= 255; //50
     colorG= 255; //125
     colorB=255; //255
   } */
  
  cloudSpherical.points[idx].r = 255; //colorRed;
  cloudSpherical.points[idx].g = 255; //colorG;
  cloudSpherical.points[idx].b = 255; //colorB;
  

  fprintf(fileXYZRGB,"%f %f %f %d %d %d\n", cloudSpherical.points[idx].x, cloudSpherical.points[idx].y, cloudSpherical.points[idx].z, cloudSpherical.points[idx].r, cloudSpherical.points[idx].g, cloudSpherical.points[idx].b); 
 
 
  idx++;
    
 }  

fclose(fileXYZRGB);






  
  
  
  return 1; 
}


//////////////////////////////////////////////////////////////2/02/2016
// handle no color in the input mesh 

///////////////////////////////////////////load vtk spheric mesh begin
// Load the input vtk mesh file


// Load the input vtk mesh file
// this is the macromolecular mesh 

int convertFile_VTK2ASC_NoRGB(char *FilenameASC_Out, char *filenameVTKSphIN, char *filenameCurvature_IN)
{
  
  
vtkSmartPointer<vtkPolyData> polydataConformal_SphVTK;

vtkSmartPointer<vtkPolyData> polydataConformal_SphASC;

vtkSmartPointer<vtkPolyDataReader> readerVTKSph = vtkSmartPointer<vtkPolyDataReader>::New();



readerVTKSph->SetFileName (/*"1brsoutVTKSph.vtk"*/ filenameVTKSphIN);
readerVTKSph->Update();

polydataConformal_SphVTK = readerVTKSph->GetOutput();
printf("Loaded spherical conformal mapping  with %lu points/vertices.\n", polydataConformal_SphVTK->GetNumberOfPoints());
 
pcl::PointCloud<pcl::PointXYZRGB> cloudSpherical;
  cloudSpherical.width    = polydataConformal_SphVTK->GetNumberOfPoints();
  cloudSpherical.height   = 1;
  cloudSpherical.is_dense = false; // w/ Nans
  cloudSpherical.points.resize (polydataConformal_SphVTK->GetNumberOfPoints() * cloudSpherical.height);
  
  
  FILE *fileXYZRGB;
  
  if( (fileXYZRGB = fopen(/*"CloudSphericXYZRGB_max.asc"*/FilenameASC_Out, "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", /*"CloudSphericXYZRGB_max.asc"*/FilenameASC_Out);
      exit(-1);
    }

  
  int ii;
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
  

//if(flagColoredNone)
//{ 
int idx=0;

for(ii = 0; ii<polydataConformal_SphVTK->GetNumberOfPoints(); ii++)
 {
   
  
   //printf("recover color points Color %lu \n", ii); 
  double point3D[3];
  // this is the input mesh triangular mesh 
  //polydataMesh->GetPoints()->GetPoint(ii, point3D);   
  polydataConformal_SphVTK->GetPoints()->GetPoint(ii, point3D);   
  
  // spheric points
  //double point3DSph[3];
  //polydataMeshSpheric->GetPoints()->GetPoint(ii,point3DSph);
  //polydataMeshSpheric
  //  printf("recover color points Color %lu %f %f %f \n", ii, point3D[0], point3D[1], point3D[2]); 
  
  unsigned char colorRed = 0;//polydataMesh->GetPointData()->GetScalars()->GetComponent(ii,0);
  unsigned char colorG = 0; //polydataMesh->GetPointData()->GetScalars()->GetComponent(ii,1);
  unsigned char colorB = 0; //polydataMesh->GetPointData()->GetScalars()->GetComponent(ii,2);
  
  cloudSpherical.points[idx].x = point3D[0];
  cloudSpherical.points[idx].y = point3D[1];  
  cloudSpherical.points[idx].z = point3D[2];
  
  cloudSpherical.points[idx].r = colorRed;
  cloudSpherical.points[idx].g = colorG;
  cloudSpherical.points[idx].b = colorB; 

  /*modif for curvElev*/
  /*rajouter un %f et , arrCurv[ii*100] (100 est la taille du descripteur) pour avoir la couleur sur cloud compare*/
   fprintf(fileXYZRGB,"%f %f %f \n", cloudSpherical.points[idx].x, cloudSpherical.points[idx].y, cloudSpherical.points[idx].z);
  /* fprintf(fileXYZRGB,"%f %f %f", cloudSpherical.points[idx].x, cloudSpherical.points[idx].y, cloudSpherical.points[idx].z);
  for(int tt=0; tt < 100; tt++)
    fprintf(fileXYZRGB," %f",  arrCurv[ii*100+tt]);
    fprintf(fileXYZRGB, "\n");*/

 
  
  idx++;
 }
 
 fclose(fileXYZRGB);
 
}





int Sphere2ImageProjection_ElevationBatch(char *filenameImage_OUT, char *filenameConfCloudASC_IN,  char *filenameCartezCloudASC_IN, char *filenameCurvature_IN, char  *filenameImagePano_OUT,  char *filenameVTKSph_IN, int idxPano, int idxView, int nbView)
{
  
  
   // passage pour l'elevation. Fonction dans TriDT.cpp 
 
  int ok = ConformalSphere2ImageProjection_ElevationBatch(filenameImage_OUT, filenameConfCloudASC_IN, filenameCartezCloudASC_IN, filenameCurvature_IN, filenameImagePano_OUT, filenameVTKSph_IN, idxPano, idxView, nbView);
    
    //(char *filenameImage_OUT, char *filenameConfCloudASC_IN, char *filenameCartezCloudASC_IN, int idxPano)
    
  
  return 1; 
}


/*void Display(vtkPolyData* polyData)
{
  




  vtkPolyDataMapper* mapper = vtkPolyDataMapper::New();
  mapper->SetScalarRange( -0.01, 0.01 );
   mapper->SetInputData( polyData);
  
  vtkActor* actor = vtkActor::New();
  actor->SetMapper(mapper);

 
  vtkRenderer* ren = vtkRenderer::New();
  ren->AddActor( actor );
 
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->AddRenderer( ren );
  renWin->SetSize( 300,300 );

  vtkRenderWindowInteractor* inter = vtkRenderWindowInteractor::New();
  inter->SetRenderWindow( renWin );

  renWin->Render();
  inter->Start();
}*/
