#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#include <opencv2/highgui/highgui.hpp>

#include "convexity.hpp"
#include "gradient.hpp"
#include "utilTool.hpp"
#include "toolConvexity.hpp"

#define VALUE_CONVEX 1
#define VALUE_CONCAVE -1
#define INCREMENT_THRESH 0.2
#define FIRST_THRESH 1.1
#define RAD_TO_DEG (180.0/3.14)
#define SIZE_PATCH 15
#define SIZE_WKS 100

#define FILE_FORMAT ".asc"


int main(int argc, char** argv)
{
  
       
  curvatureWithTriangles(argv[1], argv[2]);
 
  
  return 0;
}

/*
 * saveMapConvexity : this function is for easily changing between asc and txt format
 */
void saveMapConvexity(int *convex, int sizeX, int sizeY, std::string fnameOutCvx)
{
  saveMapConvexity_asc(convex, sizeX, sizeY, fnameOutCvx);
}

/*
 * saveMapConvexity_txt : save a txt map of the convexity, -1 : concavity, 0 : not defined, 1 : convex
 */
void saveMapConvexity_txt(int *convex, int sizeX, int sizeY,  std::string fnameOutCvx)
{
  int i,j;
  std::ofstream fmapCvx (fnameOutCvx.c_str(), std::ios::out);

  
  if(fmapCvx.is_open() )
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      
	      fmapCvx << convex[j*sizeX + i] << " ";
	      //fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
	      fmapCvx << "\n";
		
	}
      fmapCvx.close();
 
    } 

  else
    {
      std::cout << "(saveMapConvexity_txt int) Unable to open file \n";
    }
}



/*
 * saveMapConvexity_asc : save a asc map of the convexity, -1 : concavity, 0 : not defined, 1 : convex
 */
void saveMapConvexity_asc(int *convex, int sizeX, int sizeY, std::string fnameOutCvx)
{
  int i,j;
  std::ofstream fmapCvx (fnameOutCvx.c_str(), std::ios::out);

  
  if(fmapCvx.is_open() )
    {
      
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapCvx << i << " "<< j << " " << convex[j*sizeX + i] << "\n";
	      //fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
		
	}
      fmapCvx.close();
 
    } 

  else
    {
      std::cout << "(saveMapConvexity_asc int) Unable to open file \n";
    }
}


void saveMapCurvature_asc(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCurv)
{
  int i,j;
  std::ofstream fmapCurv (fnameOutCurv.c_str(), std::ios::out);

  
  if(fmapCurv.is_open() )
    {

      fmapCurv << sizeX << " "<< sizeY << " " << size_patch << "\n";
      
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapCurv << i << " "<< j << " " << curvature[j*sizeX + i] << "\n";
	      //fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
		
	}
      fmapCurv.close();
 
    } 

  else
    {
      std::cout << "(saveMapCurvature_asc) Unable to open file \n";
    }
}


void saveMapCurvature_asc_desc(float *curvature, int sizeX, int sizeY, int size_patch, int size_desc, std::string fnameOutCurv)
{
  int i,j,k;
  std::ofstream fmapCurv (fnameOutCurv.c_str(), std::ios::out);

  
  if(fmapCurv.is_open() )
    {

      fmapCurv << sizeX << " "<< sizeY << " " << size_patch << "\n";
      
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapCurv << i << " "<< j;
	      for(k = 0; k < size_desc; k++)
		{
		  fmapCurv << " " << curvature[(j*sizeX + i)*size_desc + k];	  
		}
	      fmapCurv << "\n";
		//fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
		
	}
      fmapCurv.close();
 
    } 

  else
    {
      std::cout << "(saveMapCurvature_asc_desc) Unable to open file \n";
    }
}

 void saveBinaryMapCurvature_asc_desc(float *curvature, int sizeX, int sizeY, int size_patch, int size_desc, std::string fnameOutCurv)
{
  int i,j,k;
  std::ofstream fmapCurv (fnameOutCurv.c_str(), std::ios::out | std::ios::binary);


  printf("%d %d \n", sizeX, sizeY);
  if(fmapCurv.is_open() )
    {

      fmapCurv.write( (char*) (&sizeX), sizeof(int));
      fmapCurv.write( (char*) (&sizeY), sizeof(int));
      fmapCurv.write( (char*) (&size_patch), sizeof(int));  
      
      printf("%d %d \n", sizeX, sizeY);
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapCurv.write( (char*) (&i), sizeof(int));
	      fmapCurv.write( (char*) (&j), sizeof(int));  
	      for(k = 0; k < size_desc; k++)
		{
		  /*		    if(curvature[(j*sizeX+i)*size_desc+k] != curvature[(j*sizeX+i)*size_desc+k])
		    {
		      printf("%d %d %d et %f \n", i,j,k,curvature[(j*sizeX+i)*size_desc+k]);
		      }*/
		   printf("%d %d %d et %f \n", i,j,k,curvature[(j*sizeX+i)*size_desc+k]);
		  fmapCurv.write( (char*) (&curvature[(j*sizeX + i)*size_desc + k]), sizeof(float));	  
		  }
	    }
		
	}
      fmapCurv.close();
 
    } 

  else
    {
      std::cout << "(saveBinaryMapCurvature_asc_desc) Unable to open file \n";
    }
}



/*
 * saveMapCurvature_txt : save a txt map of the curvature
 */
void saveMapCurvature_txt(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCurve)
{
  int i,j;
  std::ofstream fmapCurve (fnameOutCurve.c_str(), std::ios::out);

  
  if(fmapCurve.is_open() )
    {
      fmapCurve << sizeX << " "<< sizeY << " " << size_patch << "\n";

      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapCurve << curvature[j*sizeX + i] << " ";
	      //fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
	      fmapCurve << "\n";
		
	}
      fmapCurve.close();
 
    } 

  else
    {
      std::cout << "(saveMapCurvature_txt float) Unable to open file  \n";
    }
}

/*
 * saveMapConvexity_txt : save a txt map of the convexity, -1 : concavity, 0 : not defined, 1 : convex
 */
void saveMapLaplacian_txt(float *laplacian, int sizeX, int sizeY, std::string fnameOutLpc)
{
  int i,j;
  std::ofstream fmapLpc (fnameOutLpc.c_str(), std::ios::out);

  
  if(fmapLpc.is_open() )
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {
	      fmapLpc << laplacian[j*sizeX + i] << " ";
	      //fmapCvx << "(" <<i<<","<<j<<") : " << convex[j*sizeX + i] << " ";
	    }
	      fmapLpc << "\n";
		
	}
      fmapLpc.close();
 
    } 

  else
    {
      std::cout << "(saveMaplaplacian) Unable to open file \n";
    }
}

/*
 * saveMapConvexity_asc : save a asc map of the convexity, -1 : concavity, 0 : not defined, 1 : convex
 */
void saveMapConvexityLocal(int *convex, float *z, float *ad, int sizeX, int sizeY, int size_patch, std::string fnameOutCvx)
{
  int i,j,k1,k2;
  bool onlyZeros;
  std::ofstream fmapCvx (fnameOutCvx.c_str(), std::ios::out);

  
  if(fmapCvx.is_open() )
    {
      fmapCvx << sizeX << " "<< sizeY << " " << size_patch << "\n";
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {

	      /*We are looking for patches with only zeroes (undefined) labels*/
	      onlyZeros = true;
	      k1=0;
	      while(k1 < size_patch && onlyZeros)
		{
		  k2=0;
		  while(k2 < size_patch && onlyZeros)
		    {

		      if( convex[(j*sizeX + i)*size_patch*size_patch + k1*size_patch + k2] != 0)
			onlyZeros = false;
		      k2++;
		    }
		  k1++;
		}

	      /*We dont save patch with only zeroes because the comparison is useless*/
	      if(!onlyZeros)
		{
		  fmapCvx << i << " " << j;
		  for(k1 = 0; k1 < size_patch; k1++)
		    {
		      for(k2 = 0; k2 < size_patch; k2++)
			{
	      
			  fmapCvx << " " << convex[(j*sizeX + i)*size_patch*size_patch + k1*size_patch + k2] ;

			}
		    }

		  fmapCvx  << " " << z[j*sizeX+i] << " " << ad[j*sizeX+i] << "\n";

		}
	    }	
	}
      fmapCvx.close();
    } 

  else
    {
      std::cout << "(saveMapConvexity_ascii) Unable to open file \n";
    }
}

/*
 *
 */
void saveMapCurvatureLocal(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCvx)
{
  int i,j,k1,k2;
  bool onlyZeros;
  std::ofstream fmapCvx (fnameOutCvx.c_str(), std::ios::out);

  
  if(fmapCvx.is_open() )
    {
      fmapCvx << sizeX << " "<< sizeY << " " << size_patch << "\n";
      for(j = 0; j < sizeY; j++)
	{
	  for(i = 0; i < sizeX; i++)
	    {

	      /*We are looking for patches with only zeroes (undefined) labels*/
	      onlyZeros = true;
	      k1=0;
	      while(k1 < size_patch && onlyZeros)
		{
		  k2=0;
		  while(k2 < size_patch && onlyZeros)
		    {
		      //printf("i, j : %d %d and k1, k2 : %d %d and sizeX, sizeY : %d %d CURVATURe : %f \n",i,j, k1,k2, sizeX, sizeY, curvature[(j*sizeX + i)*size_patch*size_patch + k1*size_patch + k2]);
		      if( curvature[(j*sizeX + i)*size_patch*size_patch + k1*size_patch + k2] != 0)
			onlyZeros = false;
		      k2++;
		    }
		  k1++;
		}

	      /*We dont save patch with only zeroes because the comparison is useless*/
	      if(!onlyZeros)
		{
		  fmapCvx << i << " " << j;
		  for(k1 = 0; k1 < size_patch; k1++)
		    {
		      for(k2 = 0; k2 < size_patch; k2++)
			{
	      
			  fmapCvx << " " << curvature[(j*sizeX + i)*size_patch*size_patch + k1*size_patch + k2] ;

			}
		    }

		  fmapCvx  << "\n";

		}
	    }	
	}
      fmapCvx.close();
    } 

  else
    {
      std::cout << "(saveMapConvexity_ascii) Unable to open file \n";
    }
}




/*
 * saveMapConvexity_tiff : save a tiff map of the convexity (negative value seems to not
 * be include, todo) 
 */
void saveMapConvexity_tiff(int *convex, int sizeX, int sizeY, std::string fnameOutCvx)
{

  std::ofstream fmapCvx (fnameOutCvx.c_str(), std::ios::out);

  cv::Mat matCvx(sizeY,sizeX,CV_32S,convex);
  
  if(fmapCvx.is_open() )
    {
      matCvx.convertTo(matCvx, CV_8U, 255.0);
      cv::imwrite(fnameOutCvx,matCvx);
      fmapCvx.close();
    }

  else
    {
      std::cout << "(saveMapConvexity) Unable to open file \n";
    }
}

/*
 * groupConvexity : start to define area of the convexity and concavity (not use, in project)
 */
/*void groupConvexityX(int *convexX, int *grpConvexX, int sizeX, int sizeY)
{
  int i,j;
  int vCvx = VALUE_CONVEX + 1, vCcv = VALUE_CONCAVE - 1;


  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  if(convexX[j*sizeX+i] == 0)
	    convexX[j*sizeX+i] = valueToZero(convexX,i,j, sizeX, sizeY);
	  
	  if(asNeighbours(convexX, i,j, sizeX, sizeY))
	    {
	      convexX[j*sizeX+i] = minNeighbour_line(convexX,i,j, sizeX, sizeY);
	    }
	  else
	    {
	      if(convexX[j*sizeX+i] == VALUE_CONVEX)
	      convexX[j*sizeX+i] = vCvx++;
	      else //la possibilite que ca soit un zero est regle avant
		convexX[j*sizeX+i] = vCcv++;					 
	    }
	}
    }

  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{	  
	  convexX[j*sizeX+i] = minNeighbour(convexX,i,j, sizeX, sizeY);
	}
    }
  
}*/

/*
 * findConvexityX : define convexity for the gradient X according to the arrGradient and maskCourbElev
 * with the value give in the define at the beginning 
 */

void findConvexityX(bool *maskCourbElev, ArrDeriv *ad, int *convexX, int sizeX, int sizeY)
{
  int i,j,k,l;
  int firstCritPt;
  /*les index a ajouter dans dans le tableau convex pour
    indiquer les differentes convexite/concavite*/
  int vCvx = VALUE_CONVEX;
  int vCcv = VALUE_CONCAVE;

  float gradPrec;
  int *indPtsMon;
  int sizePtsMon;
  bool cvx;
  
  /*alloc un peu grande, mais on ne peux pas prevoir le nombre de points qu'il y aura pour une monotonie*/
  indPtsMon = (int*)calloc((sizeX)*(sizeY), sizeof(int));

  
  for(j = 0; j < sizeY; j++)
    {
      k=0;
      /* on cherche le premier point de chaque ligne pour savoir si on demarrer avec
	 une convexity ou concavite*/
  
      while(k < sizeX && !maskCourbElev[j*sizeX+k]  )
	k++; 

      /*evite de traiter une ligne ou il n'y a aucun points*/
      if(k != sizeX)
	{
	  gradPrec = ad->getgx(k,j);
 
	  while(k < sizeX && (!maskCourbElev[j*sizeX+k] || !isCriticalPt(gradPrec,ad->getgx(k,j))))
	    {
	      /*ad->getgx(k,j) != 0.0 permet d'eviter de traiter les points qui on un gradient nul en x mais font partie du masque*/
	      if(maskCourbElev[j*sizeX+k] && ad->getgx(k,j) != 0.0)
		gradPrec = ad->getgx(k,j);
	      k++;
	    }

	  /*permet de stocker l'indice du premier point critique de la ligne*/
	  firstCritPt = k;
	  /* la monotonie n'est que sur un ligne, pas besoin du j*/
	  indPtsMon[0] = k;
	  sizePtsMon = 1;

	  /*evite de traiter une ligne ou il n'y a qu'une monotonie */
	  if(k != sizeX)
	    {
	      if(ad->getgx(k,j) < 0.0 )
		cvx = true;
	      else /* parce que ad->getgx(k,j) != 0.0 precedemment on est sur de pas avoir == 0*/
		cvx = false;

	      gradPrec = ad->getgx(k,j);
	      i = k+1;
  
	      /*on va revenir au début de la ligne car des poitns sont pas traite car on doit commencer par un point critique*/
	      do
		{
		  if(maskCourbElev[j*sizeX+i] && ad->getgx(i,j) != 0.0 )
		    {

		      /*si pas changement monotonie*/
		      if(isCriticalPt(gradPrec,ad->getgx(i,j)))
			{
			  /*on passe de concave a convex ou vice et versa*/
			  cvx = !cvx;
			  /* pour une monotonie, on separe en 2 celle ci, la premiere partie etant la convexite
			   * ou concavite d'avant et la deuxieme partie l'inverse*/
			  for(l =  (sizePtsMon+1)/2; l < sizePtsMon; l++)
			    {
		    
			      if(cvx)
				convexX[j*sizeX+indPtsMon[l]] = vCvx;
			      else
				convexX[j*sizeX+indPtsMon[l]] = vCcv;
			
			    }
		    
			  indPtsMon[0] = i;
			  sizePtsMon = 1;
			}
		      else
			{
			  indPtsMon[sizePtsMon] = i;
			  sizePtsMon++;
			}
	      
		      if(cvx)
			convexX[j*sizeX+i] = vCvx;
		      else
			convexX[j*sizeX+i] = vCcv;

		      gradPrec = ad->getgx(i,j);
		    }
		  i++;
		  i = i % sizeX;
		} while( i != firstCritPt);

	    }
	}
    }

  free(indPtsMon);
}

/*
 * findConvexityY : define convexity for the gradient Y according to the arrGradient and maskCourbElev
 * with the value give in the define at the beginning 
 */
void findConvexityY(bool *maskCourbElev, ArrDeriv *ad, int *convexY, int sizeX, int sizeY)
{
  int i,j,k,l;
  int firstCritPt;
  /*les index a ajouter dans dans le tableau convex pour
    indiquer les differentes convexite/concavite*/
  int vCvx = VALUE_CONVEX;
  int vCcv = VALUE_CONCAVE;

  float gradPrec;
  int *indPtsMon;
  int sizePtsMon;
  bool cvx;

  
  /*alloc un peu grande, mais on ne peux pas prevoir le nombre de points qu'il y aura pour une monotonie*/
  indPtsMon = (int*)calloc((sizeX)*(sizeY), sizeof(int));

  

  /*for convexY*/
  for(i = 0; i < sizeX; i++)
    {
      k=0;
   
      /* on cherche le premier point de chaque colonne pour savoir si on demarrer avec
	 une convexity ou concavite*/
      while(k < sizeY && !maskCourbElev[k*sizeX+i])
	{
	  k++;
	}
      
      /*evite de traiter une colonne ou il n'y a aucun points*/
      if(k != sizeY)
	{
	  gradPrec = ad->getgy(i,k);
  
	  while(k < sizeY && (!maskCourbElev[k*sizeX+i] || !isCriticalPt(gradPrec,ad->getgy(i,k))))
	    {
	      if(maskCourbElev[k*sizeX+i] && ad->getgy(i,k) != 0.0)
		gradPrec = ad->getgy(i,k);
	      k++;
	    }

	  firstCritPt = k;

	  /* la monotonie n'est que sur un colonne, pas besoin du j*/
	  indPtsMon[0] = k;
	  sizePtsMon = 1;
	  
	  /*evite de traiter une colonne ou il n'y a qu'une monotonie */
	  if(k != sizeY)
	    {
	      if(ad->getgy(i,k) < 0.0 )
		cvx = true;
	      else /* parce que ad->getgy(i,k) != 0.0 precedemment on est sur de pas avoir == 0*/
		cvx = false;
      
	      gradPrec = ad->getgy(i,k);
	      j = k+1;
	      do
		{
		  if(maskCourbElev[j*sizeX+i] && ad->getgy(i,j) != 0.0 )
		    {
		      /*si pas changement monotonie*/
		      if(isCriticalPt(gradPrec,ad->getgy(i,j)) )
			{

			  /*on passe de concave a convex ou vice et versa*/
			  cvx = !cvx;
			  /* pour une monotonie, on separe en 2 celle ci, la premiere partie etant la convexite
			   * ou concavite d'avant et la deuxieme partie l'inverse*/
			  for(l = (sizePtsMon+1)/2; l < sizePtsMon; l++)
			    {
			      if(cvx)
				convexY[indPtsMon[l]*sizeX+i] = vCvx;
			      else
				convexY[indPtsMon[l]*sizeX+i] = vCcv;
			
			    }
		  
			  indPtsMon[0] = j;
			  sizePtsMon = 1;
			}
		      else
			{
			  indPtsMon[sizePtsMon] = j;
			  sizePtsMon++;
			}
	      
		      if(cvx)
			convexY[j*sizeX+i] = vCvx;
		      else
			convexY[j*sizeX+i] = vCcv;

		      gradPrec = ad->getgy(i,j);
		    }
		  j++;
		  j = j % sizeY;
		} while( j != firstCritPt);
	    }
	}
    }

  free(indPtsMon);
}

/*
 * findConvexityXY : define convexity for the gradient in X and in Y according to the arrGradient and maskCourbElev
 * with the value give in the define at the beginning
 */
void findConvexityXY(bool *maskCourbElev, ArrDeriv *ad, int **convexX, int **convexY, int sizeX, int sizeY)
{
  *convexX = (int*)calloc((sizeX ) * (sizeY), sizeof(int));
  *convexY = (int*)calloc((sizeX ) * (sizeY), sizeof(int));
    
  /*for convexX*/
  findConvexityX(maskCourbElev, ad, *convexX, sizeX, sizeY);
  /*for convexY*/
  findConvexityY(maskCourbElev, ad, *convexY, sizeX, sizeY);
  // findConvexity_secondDeriv(maskCourbElev, ad, *convexX, *convexY, sizeX, sizeY);
  
  //fillConvexity(*convexX, *convexY, sizeX, sizeY);
}

/*
 * findConvexity : define convexity according to the arrGradient and maskCourbElev
 * with the value give in the define at the beginning
 */
void findConvexity(bool *maskCourbElev, ArrDeriv *ad, int **convex, int sizeX, int sizeY)
{
  int i;
  
  *convex = (int*)calloc((sizeX ) * (sizeY), sizeof(int));

  for(i = 0; i < sizeX*sizeY; i++)
    {
      if (ad->getarctan(i,0)  > 0)
	(*convex)[i] = VALUE_CONVEX;
      else if (ad->getarctan(i,0) < 0 )
	(*convex)[i] = VALUE_CONCAVE;
    }

}

void findConvexity_consensus(bool *maskCourbElev, ArrDeriv *ad, int **convex, int sizeX, int sizeY)
{
  int i;
  
  int *convexX, *convexY;
   
  *convex = (int*)calloc((sizeX ) * (sizeY), sizeof(int));

  convexX = (int*)calloc((sizeX ) * (sizeY), sizeof(int));
  convexY = (int*)calloc((sizeX ) * (sizeY), sizeof(int));
  
  /*for convexX*/

  findConvexityX(maskCourbElev, ad, convexX, sizeX, sizeY);
  /*for convexY*/
  findConvexityY(maskCourbElev, ad, convexY, sizeX, sizeY);
  // findConvexity_secondDeriv(maskCourbElev, ad, convexX, convexY, sizeX, sizeY);
  
  // fillConvexity(convexX, convexY, sizeX, sizeY);;
  for(i = 0; i < sizeX*sizeY; i++)
    {
      /*elimine un "point col" mais a terme trouver une solution */
      /*   if(convexX[i] == convexY[i])
	   (*convex)[i] = convexX[i];*/
      if ((RAD_TO_DEG*ad->getarctan(i,0)  >= 45  && RAD_TO_DEG*ad->getarctan(i,0) < 135 ) || (RAD_TO_DEG*ad->getarctan(i,0)  < -45  && RAD_TO_DEG*ad->getarctan(i,0) >= -135 ))
	(*convex)[i] = convexY[i];
      else if ( (RAD_TO_DEG*ad->getarctan(i,0)  < 45  && RAD_TO_DEG*ad->getarctan(i,0) >= -45 ) || (RAD_TO_DEG*ad->getarctan(i,0)  <= -135  || RAD_TO_DEG*ad->getarctan(i,0) > 135 ) )
	(*convex)[i] = convexX[i];
      
    }
     
  free(convexX);
  free(convexY);
}

void findConvexity_secondDeriv(bool *maskCourbElev, ArrDeriv *ad, int *convexX, int *convexY, int sizeX, int sizeY)
{
  int i,j;
  /*les index a ajouter dans dans le tableau convex pour
    indiquer les differentes convexite/concavite*/
  int vCvx = VALUE_CONVEX;
  int vCcv = VALUE_CONCAVE;

  
  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  if(ad->getdx(i,j) < 0)
	    convexX[j*sizeX+i] = vCvx;
	  else if(ad->getdx(i,j) > 0)
	    convexX[j*sizeX+i] = vCcv;


	  if(ad->getdy(i,j) < 0)
	    convexY[j*sizeX+i] = vCvx;
	  else if(ad->getdy(i,j) > 0)
	    convexY[j*sizeX+i] = vCcv;
	}
    }

}

void findConvexity_norm(bool *maskCourbElev, ArrDeriv *ad, int *convexX, int *convexY, int sizeX, int sizeY)
{
  int i,j;
  /*les index a ajouter dans dans le tableau convex pour
    indiquer les differentes convexite/concavite*/
  int vCvx = VALUE_CONVEX;
  int vCcv = VALUE_CONCAVE;

  
  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  if(ad->getdx(i,j) < 0)
	    convexX[j*sizeX+i] = vCvx;
	  else if(ad->getdx(i,j) > 0)
	    convexX[j*sizeX+i] = vCcv;


	  if(ad->getdy(i,j) < 0)
	    convexY[j*sizeX+i] = vCvx;
	  else if(ad->getdy(i,j) > 0)
	    convexY[j*sizeX+i] = vCcv;
	}
    }

}

void findCurvature(ArrDeriv *ad, float **curvature, int sizeX, int sizeY)
{
  int i,j;
  *curvature = (float*)calloc((sizeX ) * (sizeY), sizeof(float));

  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  
	  if(ad->getgx(i,j) == 0 || ad->getgy(i,j) == 0)
	    {
	      (*curvature)[j*sizeX+i] = 0.0;
	    }
	  else
	    {
	      (*curvature)[j*sizeX+i] =  abs(ad->getgx(i,j)*ad->getdy(i,j) - ad->getgy(i,j)*ad->getdx(i,j))/(pow(sqrt(ad->getgx(i,j)*ad->getgx(i,j)+ad->getgy(i,j)*ad->getgy(i,j)),3));
	      /*  if((*curvature)[j*sizeX+i] > 1.0)
		(*curvature)[j*sizeX+i] = 1.0;
	      */}
	 
	}
    }
  

}
 

/***********************
 *
 * findConvexity_Laplacian : calcul le laplacien selon les images du gradient (en x et y) 
 * 
 ********************************/

void findConvexity_Laplacian( ArrDeriv *ad, float **laplacian, bool *maskCourbElev, int sizeX, int sizeY)
{
  int i,j;
  
   
  *laplacian = (float*)calloc((sizeX ) * (sizeY), sizeof(float));


  

  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{

	  (*laplacian)[j*sizeX+i] = ad->getgx(i,j) + ad->getdy(i,j);
	}
    }
     

}

void averageValueOnSamePoint()
{


}



/*****************************
 *
 * interpolate the value of each pixel of the image
 *
 *****************************/
void interpolationPoints(float *valCurv, int *revPosCurv, int *sizeXY, int sizeNbP, int *trianglesIndex, int nbTriangles, int sizeWKS)
{
  int i, j, k, x, y;
  float u = 0, v = 0, w = 0;
  int iTri1, iTri2, iTri3;
  bool existingPointsTab[sizeXY[0]*sizeXY[1]] = {false};

  int A[2] = {0}, B[2] = {0}, C[2] = {0}, P[2] = {0};

  
  /* note et conserve les points inexistant (et donc a interpoler) */
  for(i = 0; i < sizeNbP; i++)
    {
      //printf("existing point : %d %d \n", revPosCurv[2*i+1], revPosCurv[2*i]);      
      existingPointsTab[revPosCurv[2*i+1]*sizeXY[0] + revPosCurv[2*i]] = true;
    }

  
  for(y = 0; y < sizeXY[1]; y++)
    {
      for(x = 0; x < sizeXY[0]; x++)
	{
	  j = 0;
	  u = -1.0;
	  v = -1.0;
	  w = -1.0;
	  
	
	  if(!existingPointsTab[y*sizeXY[0] + x])
	    {
	      while(!isInTriangle(u,v,w) && j < nbTriangles)
		{

		  iTri1 = trianglesIndex[3*j];
		  iTri2 = trianglesIndex[3*j+1];
		  iTri3 = trianglesIndex[3*j+2];

		  A[0] = revPosCurv[2*iTri1]; A[1] = revPosCurv[2*iTri1+1];
		  B[0] = revPosCurv[2*iTri2]; B[1] = revPosCurv[2*iTri2+1];
		  C[0] = revPosCurv[2*iTri3]; C[1] = revPosCurv[2*iTri3+1];
		  P[0] = x; P[1] = y;
		  /*
		   if(x == 219 && y == 0)
		    {*/
		  computeBarycentricCoord2i(A, B, C, P, &u, &v, &w);
		  /* }*/
		  j++;
		}
      
	      if(j < nbTriangles)
		{
		  for(k = 0; k < sizeWKS; k++)
		    {
		      /*  if(x == 219 && y == 0)
		    {
		      printf("val : %f %f %f et %f \n",  valCurv[(revPosCurv[2*iTri1+1]*sizeXY[0] + revPosCurv[2*iTri1])*sizeWKS + k],
	        valCurv[(revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCurv[2*iTri2])*sizeWKS + k]
			     , valCurv[(revPosCurv[2*iTri3+1]*sizeXY[0] + revPosCurv[2*iTri3])*sizeWKS + k], u*valCurv[(revPosCurv[2*iTri1+1]*sizeXY[0] + revPosCurv[2*iTri1])*sizeWKS + k]
			+ v*valCurv[(revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCurv[2*iTri2])*sizeWKS + k]
			+ w*valCurv[(revPosCurv[2*iTri3+1]*sizeXY[0] + revPosCurv[2*iTri3])*sizeWKS + k] );

		      printf("%d \n", (revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCurv[2*iTri2])*sizeWKS);
		      }*/
		      valCurv[(y*sizeXY[0]+x)*sizeWKS + k] = u*valCurv[(revPosCurv[2*iTri1+1]*sizeXY[0] + revPosCurv[2*iTri1])*sizeWKS + k]
			+ v*valCurv[(revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCurv[2*iTri2])*sizeWKS + k]
			+ w*valCurv[(revPosCurv[2*iTri3+1]*sizeXY[0] + revPosCurv[2*iTri3])*sizeWKS + k];

		      /*	      if(valCurv[(y*sizeXY[0]+x)*sizeWKS + k] != valCurv[(y*sizeXY[0]+x)*sizeWKS + k] )
			{
 printf("val : %f %f %f et %f \n",  valCurv[(revPosCurv[2*\
iTri1+1]*sizeXY[0] + revPosCurv[2*iTri1])*sizeWKS + k],                         
                valCurv[(revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCurv[2*iTri2])\
*sizeWKS + k]                                                                   
                             , valCurv[(revPosCurv[2*iTri3+1]*sizeXY[0] + revPo\
sCurv[2*iTri3])*sizeWKS + k], u*valCurv[(revPosCurv[2*iTri1+1]*sizeXY[0] + revP\
osCurv[2*iTri1])*sizeWKS + k]                                                   
                        + v*valCurv[(revPosCurv[2*iTri2+1]*sizeXY[0] + revPosCu\
rv[2*iTri2])*sizeWKS + k]                                                       
                        + w*valCurv[(revPosCurv[2*iTri3+1]*sizeXY[0] + revPosCu\
rv[2*iTri3])*sizeWKS + k] );
}*/
		    }

		  
		  /*if(x == 219 && y == 0)
		    {
		      printf("abc0 : %d %d %d abc1 %d %d %d u,v,w : %f %f %f \n", A[0], B[0], C[0], A[1], B[1], C[1], u, v, w);
		      }*/
		  
		}
	      else 
		{
		  //printf("abc0 : %d %d %d abc1 %d %d %d u,v,w : %f %f %f \n", A[0], B[0], C[0], A[1], B[1], C[1], u, v, w); 
		  std::cout << "interpolationPoints, a point cannot be interpolate " << j << " " << x << " " << y << " nb triangles : " << nbTriangles << "\n";
		}
	    }
	}
    }
  
}


/*****************
 *
 * Read a curvature map with triangles included and interpolate the missing pixels 
 * of the image of the map then save it in the same format
 *
 *****************/
void curvatureWithTriangles(char *fnameCurv, char *fnameOutCurv)
{
  int sizeXY[2], sizeNbP, nbTriangles;
  float *valCurv = NULL;
  int *revPosVal = NULL, *trianglesIndex = NULL;
  std::ostringstream strOutCurv_txt, strOutCurv_asc;
    struct timespec tBegin, tEnd;

  std::cout << "Loading file \n";
  //loadFileBinaryWithTriangles_desc(fnameCurv, &valCurv, &revPosVal, sizeXY, &sizeNbP, &trianglesIndex, &nbTriangles, SIZE_WKS);
  loadFileWithTriangles_desc(fnameCurv, &valCurv, &revPosVal, sizeXY, &sizeNbP, &trianglesIndex, &nbTriangles, SIZE_WKS);
  std::cout << sizeXY[0] << " " << sizeXY[1] << "\n";

  std::cout << "Average of same points on the map \n";
  
  
  std::cout << "Interpolating \n";

  clock_gettime(CLOCK_REALTIME, &tBegin);
  
  interpolationPoints(valCurv, revPosVal, sizeXY, sizeNbP, trianglesIndex, nbTriangles, SIZE_WKS);


  clock_gettime(CLOCK_REALTIME, &tEnd);

  printf("Time interpolating one maps (all view) (seconds) : (%ld - %ld)  %ld  \n",tEnd.tv_sec, tBegin.tv_sec, ((tEnd.tv_sec - tBegin.tv_sec) ));

  
  std::cout << "Saving file \n";
  // strOutCurv_txt.clear();
  //strOutCurv_txt.str("");
  //strOutCurv_txt << fnameOutCurv << "_NoSmoothering.txt";

  //  saveMapCurvature_txt(valCurv, sizeXY[0], sizeXY[1], SIZE_PATCH, strOutCurv_txt.str());


  
  strOutCurv_asc.clear();
  strOutCurv_asc.str("");
  strOutCurv_asc << fnameOutCurv << "_NoSmoothering" << FILE_FORMAT;

  //saveBinaryMapCurvature_asc_desc(valCurv, sizeXY[0], sizeXY[1], SIZE_PATCH, SIZE_WKS, strOutCurv_asc.str());
  saveMapCurvature_asc_desc(valCurv, sizeXY[0], sizeXY[1], SIZE_PATCH, SIZE_WKS, strOutCurv_asc.str());


}





/*
 * convexity : create a map of convexity of a 2D elevation map and gradient map
 * in : name of curve elev in, grad map in and name out convexity map
 */
void convexity(char *fnameCourbElev, char *fnameOutCvx)
{
  int sizeX,sizeY;
  int i, j, jEq;

  float *courbElev = NULL;
  bool *maskCourbElev = NULL;
  float *adLoc = NULL;
  ArrDeriv ad;

  std::ostringstream strOutCvx_tiff;
  std::ostringstream strOutCvx_txt;
  std::ostringstream strOutCvx_asc;
    
  std::ostringstream strOutCurve_txt;
  
  float *curvature, *curvatureLoc;
  float *curvatureEq;




  

  
  readASCIIFile(fnameCourbElev, &curvature, &sizeX, &sizeY );
 

  /*permet de diviser par 1/3 a chaque pole la carte*/
  curvatureEq = (float*)calloc((sizeX) * (sizeY/3) * SIZE_PATCH * SIZE_PATCH, sizeof(float));

  for(j = (sizeY/3); j < (sizeY/3)*2; j++)
    {
      jEq = j % (sizeY / 3);
      for(i = 0; i < sizeX; i++)
	{
	  curvatureEq[jEq*sizeX + i] = curvature[j*sizeX + i];
	}
    }
  

  strOutCvx_txt.clear();
  strOutCvx_txt.str("");
  strOutCvx_txt << fnameOutCvx << "_NoSmoothering.txt";
  
  // saveMapConvexity(convex, sizeX, sizeY, strOutCvx_txt.str());
  saveMapCurvature_txt(curvatureEq, sizeX, sizeY/3, SIZE_PATCH, strOutCvx_txt.str());

  
 

  //  convexLoc = (int*)malloc((sizeX) * (sizeY) * SIZE_PATCH * SIZE_PATCH *sizeof(int));
  curvatureLoc = (float*)calloc((sizeX) * (sizeY) * SIZE_PATCH * SIZE_PATCH, sizeof(float));
  /*  z = (float*)malloc((sizeX) * (sizeY) * sizeof(float));
      zLoc = (float*)malloc((sizeX) * (sizeY) * sizeof(float));*/
  adLoc = (float*)calloc((sizeX) * (sizeY), sizeof(float));
  

  // SecondDeriv::getArrayZ(ad.getDeriv(), z, sizeX*sizeY);


  std::clock_t begin_time = std::clock();
  
  //computePatches(convex, convexLoc, z, zLoc, &ad, adLoc, sizeX, sizeY, SIZE_PATCH);
  computePatches(curvature, curvatureLoc, sizeX, sizeY, SIZE_PATCH);

  std::cout << "time in sec for computing convexity (noSmoothering) : " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << "\n";

  
  std::cout << "End of computation patches \n";
  /*on sauvegarde sans le lissage */

  /* strOutCvx_tiff.clear();
     strOutCvx_tiff.str("");
     strOutCvx_tiff << fnameOutCvx <<  "_NoSmoothing" << ".tiff";
  */
  strOutCvx_asc.clear();
  strOutCvx_asc.str("");
  strOutCvx_asc << fnameOutCvx << "_NoSmoothering" << FILE_FORMAT;
      
  // saveMapConvexity_tiff(newConvex, sizeX, sizeY, strOutCvx_tiff.str());
  // saveMapConvexityLocal(convexLoc, zLoc, adLoc, sizeX, sizeY, SIZE_PATCH, strOutCvx_asc.str());
    
  saveMapCurvatureLocal(curvatureLoc,sizeX, sizeY, SIZE_PATCH, strOutCvx_asc.str());
  std::cout << "End of saving \n";
       
   
  /* free(convex);
     free(convexLoc);
     free(z);
     free(zLoc);*/
  free(curvature);
  free(curvatureLoc);


  free(courbElev);
  free(maskCourbElev);

  
}
