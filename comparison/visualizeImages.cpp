#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderer.h>
#include <vtkImageMapper.h>
#include <vtkActor2D.h>
#include <vtkImageSlice.h>


#include <vtkRendererCollection.h>
#include <vtkWorldPointPicker.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>


#include <limits> 

#include "utilTool.hpp"
#include "visualizeImages.hpp"

#define IS_INTERACTING true


class MouseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
  float *I1, *I2;
  int *posI1, *posI2, *revPosI2;
  int *coordMin_I1vsI2;
  int *sizeXY1, *sizeXY2;
  int size_patch;
  int previ, previ2, prevj, prevj2;
  vtkSmartPointer<vtkImageData> colorImage1;
  vtkSmartPointer<vtkImageData> colorImage2;
  vtkSmartPointer<vtkRenderer> renderer1;
  vtkSmartPointer<vtkRenderer> renderer2;
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;

  static MouseInteractorStyle* New();
    vtkTypeMacro(MouseInteractorStyle, vtkInteractorStyleTrackballCamera);

  void initialize(float *I1, float *I2,  int *posI1, int *posI2, int *revPosI2,  int *coordMin_I1vsI2,  int *sizeXY1, int *sizeXY2,  int size_patch,  vtkSmartPointer<vtkImageData> colorImage1,  vtkSmartPointer<vtkImageData> colorImage2,  vtkSmartPointer<vtkRenderer> renderer1, vtkSmartPointer<vtkRenderer> renderer2, vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor)
  {
    this->I1 = I1;
    this->I2 = I2;
    this->posI1 = posI1;
    this->posI2 = posI2;
    this->revPosI2 = revPosI2;
    this->coordMin_I1vsI2 = coordMin_I1vsI2;
    this->sizeXY1 = sizeXY1;
    this->sizeXY2 = sizeXY2;
    this->size_patch = size_patch;
    this->prevj = 0;
    this->prevj2 = 0;
    this->previ = 0;
    this->previ2 = 0;
    this->colorImage1 = colorImage1;
    this->colorImage2 = colorImage2;
    this->renderer1 = renderer1;
    this->renderer2 = renderer2;
    this->renderWindowInteractor = renderWindowInteractor;

  }
  
  virtual void OnLeftButtonDown() 
  {
    int i,j,i2,j2;

    int sizeX1, sizeY1;
    int sizeX2, sizeY2;
  
    sizeX1 = this->sizeXY1[0];
    sizeY1 = this->sizeXY1[1];
    sizeX2 = this->sizeXY2[0];
    sizeY2 = this->sizeXY2[1];

    i = this->Interactor->GetEventPosition()[0];
    j = this->Interactor->GetEventPosition()[1];

    printf("ij : %d %d \n", posI1[j*sizeXY1[0]+i], coordMin_I1vsI2[posI1[j*sizeX1+i]]);
    
    if( (posI1[j*sizeXY1[0]+i] != -1 && coordMin_I1vsI2[posI1[j*sizeX1+i]] != -2) )
      {

	i2 = revPosI2[coordMin_I1vsI2[posI1[j*sizeXY1[0]+i]]*2+0];
	//car l'axe est inverse sur la fenetre (cf  changePositionPatch IS_INTERACTING*/
	j2 = sizeY2 - revPosI2[coordMin_I1vsI2[posI1[j*sizeXY1[0]+i]]*2+1];
	printf("i2j2 : %d %d \n", i2,j2);
	// printf("coordMLinbIvsJ : %d, ij (posI1) : %d %d (%d) i2j2 : %d %d. Size1 : %d %d size2 : %d %d  \n", coordMin_I1vsI2[posI1[j*sizeX1+i]],i,j,posI1[j*sizeX1+i],i2,j2, sizeX1, sizeY1, sizeX2, sizeY2);
	changePositionPatch(colorImage1, I1, posI1, i, j, previ, prevj, sizeX1, sizeY1, size_patch);
	changePositionPatch(colorImage2, I2, posI2, i2, j2, previ2, prevj2, sizeX2, sizeY2, size_patch);
	this->prevj = j;
	this->prevj2 = j2;
	this->previ = i;
	this->previ2 = i2;

	renderer1->Render();
	renderer2->Render();
	renderWindowInteractor->Render();
      }

      
    std::cout << "Picking pixel: " << this->Interactor->GetEventPosition()[0] << " " << this->Interactor->GetEventPosition()[1] << std::endl;
    /*   this->Interactor->GetPicker()->Pick(this->Interactor->GetEventPosition()[0], 
	 this->Interactor->GetEventPosition()[1], 
	 0,  // always zero.
	 this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());*/
    /* double picked[3];
       this->Interactor->GetPicker()->GetPickPosition(picked);
       std::cout << "Picked value: " << picked[0] << " " << picked[1] << " " << picked[2] << std::endl;*/
    // Forward events
    vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
  }
};
vtkStandardNewMacro(MouseInteractorStyle);

bool IsClickingLeft( vtkObject* vtkNotUsed(caller), long unsigned int vtkNotUsed(eventId), void* vtkNotUsed(clientData), void* vtkNotUsed(callData) )
{
  return true;
}


void displayImagesPatches(float *I1, float *I2, int *posI1, int *posI2, int *revPosI2, int *coordMin_I1vsI2, int *sizeXY1, int *sizeXY2, int size_patch)
{

  // std::string c = "1";
  int c = 1;
  int i,j,i2,j2;
  int previ, previ2, prevj, prevj2;
  int sizeX1, sizeY1;
  int sizeX2, sizeY2;
  double xmins[2] = {0,0.5};
  double xmaxs[2] = {0.5,1};
  double ymins[2] = {0,0};
  double ymaxs[2] = {1,1};

  sizeX1 = sizeXY1[0];
  sizeY1 = sizeXY1[1];
  sizeX2 = sizeXY2[0];
  sizeY2 = sizeXY2[1];


  
  vtkSmartPointer<vtkRenderer> renderer1 = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderer> renderer2 = vtkSmartPointer<vtkRenderer>::New();
  
  // Setup render window
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
  
  // Render and start interaction
  renderWindowInteractor->SetRenderWindow(renderWindow);

  vtkSmartPointer<vtkImageMapper> imageMapper1 = vtkSmartPointer<vtkImageMapper>::New();
  vtkSmartPointer<vtkActor2D> imageActor1 = vtkSmartPointer<vtkActor2D>::New();

  vtkSmartPointer<vtkImageMapper> imageMapper2 = vtkSmartPointer<vtkImageMapper>::New();
  vtkSmartPointer<vtkActor2D> imageActor2 = vtkSmartPointer<vtkActor2D>::New();
  
  vtkSmartPointer<vtkImageData> colorImage1 = vtkSmartPointer<vtkImageData>::New();
  CreateColorImage(colorImage1, I1, posI1, sizeX1, sizeY1, size_patch);
  vtkSmartPointer<vtkImageData> colorImage2 = vtkSmartPointer<vtkImageData>::New();
  CreateColorImage(colorImage2, I2, posI2, sizeX2, sizeY2, size_patch);



    
  // Setup renderers
  
  renderWindow->SetSize(sizeX1+sizeX2+100,sizeY1+100); 

  /*1st image*/
  renderWindow->AddRenderer(renderer1);
  
  renderer1->SetViewport(xmins[0],ymins[0],xmaxs[0],ymaxs[0]);

#if VTK_MAJOR_VERSION <= 5
  imageMapper1->SetInputConnection(colorImage1->GetProducerPort());
#else
  imageMapper1->SetInputData(colorImage1);
#endif
  imageMapper1->SetColorWindow(255);
  imageMapper1->SetColorLevel(127.5);

  imageActor1->SetMapper(imageMapper1);
  imageActor1->SetPosition(0,0);
  

  renderer1->AddViewProp(imageActor1);
  renderer1->AddActor2D(imageActor1);

  renderWindow->Render();

  /*2nd image*/
  
  renderWindow->AddRenderer(renderer2);

	 
  renderer2->SetViewport(xmins[1],ymins[1],xmaxs[1],ymaxs[1]);

#if VTK_MAJOR_VERSION <= 5
  imageMapper2->SetInputConnection(colorImage2->GetProducerPort());
#else
  imageMapper2->SetInputData(colorImage2);
#endif
  imageMapper2->SetColorWindow(255);
  imageMapper2->SetColorLevel(127.5);


  imageActor2->SetMapper(imageMapper2);
  imageActor2->SetPosition(0, 0);

  renderer2->AddViewProp(imageActor2);
  renderer2->AddActor2D(imageActor2);

  renderWindow->Render();


  renderer1->Render();
  renderer2->Render();
  renderWindowInteractor->Render();
  
  prevj = 0;
  prevj2 = 0;
  previ = 0;
  previ2 = 0;
  printf("%d %d %d \n", sizeX1, sizeY1, sizeX1*sizeY1);
  if(IS_INTERACTING)
    {
      /*  vtkWorldPointPicker* picker = vtkWorldPointPicker::New();
      double pickCoords[3];
      bool cont = true;

      
      picker->Pick(mouseX, mouseY, 0.0, myRenderer);
      picker->GetPickPosition(pickCoords);*/

      
      vtkSmartPointer<MouseInteractorStyle> style = 
	vtkSmartPointer<MouseInteractorStyle>::New();
      /*style.I1 = I1;
      style.I2 = I2;
      style.posI1 = posI1;
      style.posI2 = posI2;
      style.coordMin_I1vsI2 = coordMin_I1vsI2;
      style.sizeXY1 = sizeXY1;
      style.sizeXY2 = sizeXY2;
      style.size_patch = size_patch;
      style.prevj = 0;
      style.prevj2 = 0;
      style.previ = 0;
      style.previ2 = 0;
      style.renderer1 = renderer1;
      style.renderer2 = renderer2;*/

      style->initialize(I1, I2, posI1, posI2, revPosI2, coordMin_I1vsI2, sizeXY1, sizeXY2, size_patch, colorImage1, colorImage2, renderer1, renderer2, renderWindowInteractor);
      renderWindowInteractor->SetInteractorStyle( style );

      renderWindowInteractor->Start();


	  

      
    }

  else
    {
      for(j = (size_patch/2)+1 ; j < (sizeY1-((size_patch/2)+1)); j++)
	{

       
	  for(i = 0; i < sizeX1; i++) 
	    {

	  
	      //  printf("ij : %d %d et %d \n",i,j, posI1[j*sizeXY1[0]+i]);

	      // printf("coordMLinbIvsJ : %d, i2j2 : %d %d  \n", coordMin_I1vsI2[posI1[j*sizeXY1[0]+i]],i2,j2);
	      if( (posI1[j*sizeXY1[0]+i] != -1 && coordMin_I1vsI2[posI1[j*sizeX1+i]] != -2) )
		{

		  i2 = revPosI2[coordMin_I1vsI2[posI1[j*sizeXY1[0]+i]]*2+0];
		  j2 = revPosI2[coordMin_I1vsI2[posI1[j*sizeXY1[0]+i]]*2+1];
		  // printf("coordMLinbIvsJ : %d, ij (posI1) : %d %d (%d) i2j2 : %d %d. Size1 : %d %d size2 : %d %d  \n", coordMin_I1vsI2[posI1[j*sizeX1+i]],i,j,posI1[j*sizeX1+i],i2,j2, sizeX1, sizeY1, sizeX2, sizeY2);
		  changePositionPatch(colorImage1, I1, posI1, i, j, previ, prevj, sizeX1, sizeY1, size_patch);
		  changePositionPatch(colorImage2, I2, posI2, i2, j2, previ2, prevj2, sizeX2, sizeY2, size_patch);
		  prevj = j;
		  prevj2 = j2;
		  previ = i;
		  previ2 = i2;

		  renderer1->Render();
		  renderer2->Render();
		  renderWindowInteractor->Render();
		}
	    }

	}
    }
  /* do 
     {
 
     } while (cin.get() != '\n');*/


 

}

 
void CreateColorImage(vtkImageData* image, float *I, int *posI, int sizeX, int sizeY, int size_patch)
{
  int k = 0;
  int size_patch_sq = size_patch * size_patch;
  int size_patch_div2_sq = size_patch_sq/2;

  image->SetDimensions(sizeX, sizeY, 1);
  //std::cout << "Init images " << sizeX << " " << sizeY << "\n";
#if VTK_MAJOR_VERSION <= 5
  image->SetNumberOfScalarComponents(3);
  image->SetScalarTypeToUnsignedChar();
  image->AllocateScalars();
#else
  image->AllocateScalars(VTK_UNSIGNED_CHAR,3);
#endif
  // std::cout << "End init images \n";

  
  for(int j = 0; j < sizeY; j++)
    {
      for(int i = 0; i < sizeX; i++)
	{
		  
	  unsigned char* pixel = static_cast<unsigned char*>(image->GetScalarPointer(i,(sizeY-1)-j,0));
	  
	  k = posI[j*sizeX+i];
	  
	  if(k != -1)
	    {	 

	      if(I[k*size_patch_sq+size_patch_div2_sq] < 0.0 )
		{
		  pixel[0] = 255;
		  pixel[1] = 0;
		  pixel[2] = 0;
		}
	      else if(I[k*size_patch_sq+size_patch_div2_sq] > 0.0)
		{
		  pixel[0] = 0;
		  pixel[1] = 255;
		  pixel[2] = 0;
		}
		  
	      else if(I[k*size_patch_sq+size_patch_div2_sq] == 0.0)
		{
		  pixel[0] = 0;
		  pixel[1] = 0;
		  pixel[2] = 255;
		}
	    }
	  else
	    {
	      pixel[0] = 0;
	      pixel[1] = 0;
	      pixel[2] = 0;
	    }
	  
	}
    }

  image->Modified();
}


void changePositionPatch(vtkImageData* image, float *I, int *posI, int posPi, int posPj, int prevPosPi, int prevPosPj, int sizeX, int sizeY, int size_patch)
{

  int k=0;
  int i1m;
  int size_patch_sq = size_patch*size_patch;
  int size_patch_div2_sq = size_patch_sq/2;
  int size_patch_div2 = size_patch/2;
  int posPi_min, posPi_max, posPj_min, posPj_max;
  unsigned char* pixel;



  posPi_min = (prevPosPi+sizeX - size_patch_div2);
  posPi_max = (prevPosPi+sizeX + size_patch_div2);
  posPj_min = std::max(0,prevPosPj - size_patch_div2);
  posPj_max = std::min(sizeY-1,prevPosPj + size_patch_div2);


    printf("Rendering patch center in : %d %d \n", posPi,posPj);
  //printf("pos %d %d diff : %d %d min : %d %d max : %d %d \n", posPi, posPj, diffPosPi, diffPosPj, posPi_min, posPj_min, posPi_max, posPj_max);

  for(unsigned int j = posPj_min; j < posPj_max + 1; j++)
    {
      for(unsigned int i =  posPi_min; i < posPi_max + 1; i++)
	{
	  i1m = i % sizeX;


	  /*car pick un pixel n'inverse pas l'axe des y*/
	  if(IS_INTERACTING)
	    {
	      pixel = static_cast<unsigned char*>(image->GetScalarPointer(i1m,j,0));
	    }
	  else
	    {
	      pixel = static_cast<unsigned char*>(image->GetScalarPointer(i1m,(sizeY-1)-j,0));
	    }
	  /*  printf("ij %d %d im %d \n",i,j,i1m);
	  printf("posI : %d \n", posI[j*sizeX+i1m]);
	  printf("pixel : %d %d %d \n", pixel[0], pixel[1], pixel[2] );*/
	  k = posI[j*sizeX+i1m];

	  //  printf("ij %d %d\n",i,j);

	  if( ( (j == posPj_min || j == posPj_max) ||
		(i == posPi_min || i == posPi_max )  ) &&
	      posI[j*sizeX+i1m] != -1)
	    {
	      //  printf("sq %d \n",k*size_patch_sq+size_patch_div2_sq);
	      //if a point existing in the 3D shape do :
	      
	      if(I[k*size_patch_sq+size_patch_div2_sq] < 0.0 )
		{
		  pixel[0] = 255;
		  pixel[1] = 0;
		  pixel[2] = 0;
		}
	      else if(I[k*size_patch_sq+size_patch_div2_sq] > 0.0)
		{
		  pixel[0] = 0;
		  pixel[1] = 255;
		  pixel[2] = 0;
		}
	      else if(I[k*size_patch_sq+size_patch_div2_sq] == 0.0)
		{
		  pixel[0] = 0;
		  pixel[1] = 0;
		  pixel[2] = 255;
		}
	    }
	  else if(posI[j*sizeX+i1m] == -1)
	    {
	      pixel[0] = 0;
	      pixel[1] = 0;
	      pixel[2] = 0;
	    }


	}	   	  
    }

  posPi_min = (posPi+sizeX - size_patch_div2);
  posPi_max = (posPi+sizeX + size_patch_div2);
  posPj_min = std::max(0,posPj - size_patch_div2);
  posPj_max = std::min(sizeY-1,posPj + size_patch_div2);

  //std::cout << "pi :" << posPi << " pj : " << posPj << " diffi : " << prevPosPi << " diffj : " << prevPosPj << " size patch : " << size_patch << "\n";
  // std::cout <<  "minI: " << posPi_min << " maxI: " << posPi_max << " minJ: " << posPj_min << " maxJ: " << posPj_max <<"\n";
    
  //printf("pos %d %d diff : %d %d min : %d %d max : %d %d \n", posPi, posPj, diffPosPi, diffPosPj, posPi_min, posPj_min, posPi_max, posPj_max);
  
  for(unsigned int j = posPj_min; j < posPj_max + 1; j++)
    {
      for(unsigned int i =  posPi_min; i < posPi_max + 1; i++)
	{
	  i1m = i % sizeX;

	  if(IS_INTERACTING)
	    {
	      pixel = static_cast<unsigned char*>(image->GetScalarPointer(i1m,j,0));
	    }
	  else
	    {
	      pixel = static_cast<unsigned char*>(image->GetScalarPointer(i1m,(sizeY-1)-j,0));
	    }
        
	  if( (((j == posPj_min && posPj_min > 0) || (j == posPj_max && posPj_max < sizeY)) && i <= posPi_max && i >= posPi_min) ||
	      ((i == posPi_min || i == posPi_max) && j <= posPj_max && j >= posPj_min) )
	    {
	      pixel[0] = 255;
	      pixel[1] = 255;
	      pixel[2] = 255;

	    }
	}	   	  
    }

  image->Modified();
}
