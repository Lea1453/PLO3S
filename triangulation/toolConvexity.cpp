#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "toolConvexity.hpp"
#include "utilTool.hpp"

bool isConvex(int v)
{
  return v > 0;
}

bool isCriticalPt(int v1, int v2)
{
  return v1*v2 < 0;
}
bool isCriticalPt(float v1, float v2)
{
  return v1*v2 < 0.0;
}

int* smootheringWithMeanPatches_convex(int *convex, int sizeX, int sizeY, int sizeP, float thresh)
{
  int i,j;
  int *newConvex;
  float mean;


  newConvex = (int*) malloc(sizeX*sizeY*sizeof(int));
  
  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  mean = meanPatch(convex, sizeX, sizeY, abs((i-sizeP))%sizeX, abs((j-sizeP))%sizeY, sizeP);
	 if(mean > thresh) 
	   newConvex[j*sizeX+i] = 1;
	 else if(mean < -thresh)
	   newConvex[j*sizeX+i] = -1;
	 else
	   newConvex[j*sizeX+i] = 0;
	}
    }
  
  return newConvex;
}

void fillConvexity( int *convexX, int *convexY, int sizeX, int sizeY)
{

  fillConvexityX(convexX, sizeX, sizeY);
  fillConvexityY(convexY, sizeX, sizeY);

}

void fillConvexityX( int *convexX, int sizeX, int sizeY)
{
  int i,j,k,l;

  /*l'index de la premiere valeur non nulle de la ligne*/
  int iFirstCvx;
  int iPrecCvx;
  int nbZeros;
  
  for(j = 0; j < sizeY; j++)
    {
      k = 0;
      while(k < sizeX && convexX[j*sizeX + k] == 0)
	k++;

      /*si on a que des 0 sur la ligne*/
      k = k % sizeX;
      
      iFirstCvx = k;
      iPrecCvx = k;
      i = k+1;
      nbZeros = 0;
      
      while(i != iFirstCvx)
	{

	  if(convexX[j*sizeX + i] == 0)
	    {
	      convexX[j*sizeX + i] = convexX[j*sizeX + iPrecCvx];
	      nbZeros++;
	    }
	  else
	    {
	      if(convexX[j*sizeX + i] != convexX[j*sizeX + iPrecCvx])
		{
		  l = (iPrecCvx+(nbZeros/2)+1);
		  while(l < i)
		    {
		      convexX[j*sizeX + l] = convexX[j*sizeX + i];
		      l++;
		      l = l % sizeX;
		    }
		}
	      iPrecCvx = i;
	      nbZeros = 0;
	    }
        
	  i++;
	  i = i % sizeX;
	}
    }
}


void fillConvexityY(int *convexY, int sizeX, int sizeY)
{
  int i,j,k,l;

  /*l'index de la premiere valeur non nulle de la ligne*/
  int jFirstCvx;
  int jPrecCvx;
  int nbZeros;
  
  for(i = 0; i < sizeX; i++)
    {
      k = 0;
      while(k < sizeY && convexY[k*sizeX + i] == 0)
	k++;

      /*si on a que des 0 sur la colonne*/
      k = k % sizeY;
      
      jFirstCvx = k;
      jPrecCvx = k;
      j = k+1;
      nbZeros = 0;
      
      while(j != jFirstCvx)
	{

	  if(convexY[j*sizeX + i] == 0)
	    {
	      convexY[j*sizeX + i] = convexY[jPrecCvx*sizeX + i];
	      nbZeros++;
	    }
	  else
	    {
	      if(convexY[j*sizeX + i] != convexY[jPrecCvx*sizeX + i])
		{
		  l = (jPrecCvx+(nbZeros/2)+1);
		  while(l < j)
		    {
		      convexY[l*sizeX + i] = convexY[j*sizeX + i];
		      l++;
		      l = l % sizeY;
		    }
		}
	      jPrecCvx = j;
	      nbZeros = 0;
	    }
        
	  j++;
	  j = j % sizeY;
	}
    }
}

int* fillConvexityExtend(int *convexX, int *convexY, int sizeX, int sizeY)
{
  int i,j,k,l;
  int valX, valY;
  int *newConvex;
  int vCvxty[3] = {0,1,2};

  newConvex = (int*) malloc(sizeX*sizeY*sizeof(int));
  memcpy(newConvex, convexX, sizeX*sizeY*sizeof(int));
  
  for(j = 0; j < sizeY; j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	  if(convexX[j*sizeX + i] == 1)
	    valX = 1;
	  else if (convexX[j*sizeX + i] == -1)
	    valX = -1;
	  else
	    valX = 0;
	  
	  for(l = - 1; l <= 1; l++)
	    {
	      for(k = - 1; k <= 1; k++)
		{
		  if(convexX[(j+l)*sizeX + (i+k)] == valX || convexX[(j+l)*sizeX + (i+k)] == 0)
		    newConvex[(j+l)*sizeX + (i+k)] = valX;
		}
	    }
	  

	}
    }
}
