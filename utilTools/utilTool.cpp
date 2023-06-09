#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>


#include "utilTool.hpp"

#define EPSILON 0.000001


/**********************************
 *
 * countLinesFiles count the number of lines of a file
 * 
********************************/
int countLinesFile(char *fname)
{

  int ch;
  int lines = 0;
  FILE *f;

  if ( (f = fopen(fname, "r")) == NULL)
    printf("(readASCIIFile) Can't open file named '%s' for reading\n", fname);

  while (EOF != (ch=fgetc(f)))
    if (ch=='\n')
      ++lines;

  fclose(f);

  return lines;

}

/**********************************
 *
 * countLinesFiles count the number of lines of a file
 * 
********************************/
int countLinesFile(std::string fname)
{

  int lines = 0;
  std::string l;
  std::ifstream f;

  f.open(fname.c_str(),std::ios::in);

  if(f.is_open())
    {
      while (std::getline(f,l))
	  ++lines;

      f.close();
    }
  else
    std::cout << "unable open file (countLinesFiles) " << fname << "\n";

  return lines;

}

/**********************************
 *
 * countCharsLine count the number of space so the number of word can be counted
 * 
********************************/
int countCharsLine(char *fname)
{

  int ch;
  int size = 0;
  FILE *f;

  if ( (f = fopen(fname, "r")) == NULL)
    printf("(countCharsLine) Can't open file named '%s' for reading\n", fname);

  /*first line si an header so we ignore it*/
  while ('\n' != (ch=fgetc(f)));
  
  while ('\n' != (ch=fgetc(f)))
    {
      if (ch==' ')
	size++;
    }
  fclose(f);

  return size;

}



/**********************************
 *
 * countCharsLine count the number of character of a line given as argument
 * 
********************************/
int countCharsLine(std::string line)
{
  unsigned int i;
  int size = 0;


  for(i = 0; i < line.size(); i++)
    {
      if(line[i] == ' ')
	size++;
    }
 
    

  return size;

}


/**********************************
 *
 * countNbZeros count how many zeros there is in the array t
 * 
********************************/

int countNbZeros(int *t, int size)
{
  int i;
  int nbZeros = 0;
  
  for(i = 0; i < size; i++)
    {
      if(t[i] == 0)
	nbZeros ++;
    }
  return nbZeros;
}

/**********************************
 *
 * countNbZeros count how many zeros there is in the array t
 * 
********************************/

int countNbZeros(float *t, int size)
{
  int i;
  int nbZeros = 0;
  
  for(i = 0; i < size; i++)
    {
      if(t[i] == 0.0)
	nbZeros ++;
    }
  return nbZeros;
}


/**********************************
 *
 * countNbZeros_patch count how many zeros there is in the patch
 * 
********************************/

int countNbZeros_patch(int *t, int sizeX, int sizeY, int ideb, int jdeb, int sizep)
{
  int i,j;
  int nbZeros = 0;

  for(j = jdeb; j < sizep+jdeb; j++)
    {
      for(i = ideb; i < sizep+ideb; i++)
	{
	  if(t[j*sizeX + i] == 0)
	    nbZeros ++;
	}
    }
  return nbZeros;
}


/**********************************
 *
 * comp compare two elements
 * 
********************************/

int comp (const void * elem1, const void * elem2) 
{
    float f = *((float*)elem1);
    float s = *((float*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

/**********************************
 *
 * maxInt find the maximun of a array of int
 * 
********************************/

int maxInt(int *tmax, int size)
{
  int i;
  int max =  tmax[0];

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	max = tmax[i];
    }
  return max;
}

void maxPositionArray(int *pos, int *max, int size)
{
  int i;
  max[0] = pos[0];
  max[1] = pos[1];

  for (i =1; i < size; i++)
    {
      if ( max[0] < pos[2*i+0])
	max[0] = pos[2*i+0];
      if ( max[1] < pos[2*i+1])
	max[1] = pos[2*i+1];
    }
}

/**********************************
 *
 * minInt find the maximun of a array of int
 * 
********************************/

int minInt(int *tmin, int size)
{
  int i;
  int min =  tmin[0];

  for (i =1; i < size; i++)
    {
      if ( min > tmin[i])
	min = tmin[i];
    }
  return min;
}

/**********************************
 *
 * secMaxInt find the maximun of a array of int
 * 
********************************/

int secondMaxInt(int *tmax, int size)
{
  int i;
  int max =  tmax[0];
  int secMax;

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	{
	  secMax = max;
	  max = tmax[i];
	}
    }
  return secMax;
}

/**********************************
 *
 * maxFloat find the maximun of a array of float
 * 
********************************/
float maxFloat(float *tmax, int size)
{
  int i;
  float max =  tmax[0];

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	max = tmax[i];
    }
  return max;
}

/**********************************
 *
 * maxFloatArr find the maximun of a 2D array of float
 * 
********************************/
float maxFloat2D(float **tmax, int sizei, int *sizej)
{
  int i,j;
  float max =  tmax[0][0];

  for (i =0; i < sizei; i++)
    {
      for (j = 0; j < sizej[i]; j++)
	{
	  //  printf("ij : %d tax : %f \n", i,j, tmax[i][j]);
	  if ( max < tmax[i][j])
	    max = tmax[i][j];
	}
    }
  return max;
}

/**********************************
 *
 * secondMaxFloat find the maximun of a array of float
 * 
********************************/
float secondMaxFloat(float *tmax, int size)
{
  int i;
  float max =  tmax[0];
  float secMax;
  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	{
	  secMax = max;
	  max = tmax[i];
	}
    }
  return secMax;
}

/**********************************
 *
 * minFloat find the minimum of a array of float
 * 
********************************/
float minFloat(float *tmin, int size)
{
  int i;
  float min =  tmin[0];

  for (i =1; i < size; i++)
    {
      if ( min > tmin[i])
	min = tmin[i];
    }
  return min;
}

/**********************************
 *
 * minFloat find the minimum of a 2D array of float
 * 
********************************/
float minFloat2D(float **tmin, int sizei, int *sizej)
{
  int i,j;
  float min =  tmin[0][0];

  for (i =0; i < sizei; i++)
    {
      for (j =0; j < sizej[i]; j++)
	{
	  //  printf("ij : %d %d size : %d %d  value : %f %f \n", i,j,sizei, sizej[i], min, tmin[i][j]);
	  if ( min > tmin[i][j])
	    min = tmin[i][j];
	}
    }
  return min;
}


float distMAD(float x, float y)
{
    return fabs(x - y);
}

float distScoring(float x, float y)
{
  if(x == y)
    return 0;
  if(x == 0.0 || y == 0.0)
    return 1;
  return 1;
}


/**********************************
 *
 * normalizeFloatArr normalize sur 256 un tableau de float
 * 
********************************/
void normalizeFloatArr(float *arrF, int size)
{
  int i;
  float aMax = maxFloat(arrF,size);
  float aMin = minFloat(arrF,size);

  if(aMax != aMin)
    {
      for(i = 0; i < size; i++)
	{
	  arrF[i] = (arrF[i]-aMin)*(255/(aMax-aMin));
	}
    }
}

/**********************************
 *
 * meanPatch calculate the mean of a patch of size sizeP 
 * in X of size sizeX*sizeY
 * the index of the upper left corner of the patch is ideb, jdeb
 * 
********************************/
float meanPatch(int *X, int sizeX, int sizeY, int ideb, int jdeb, int sizeP)
{
  int i,j;
  float mean = 0.0;
  
  j = jdeb;
  while(j < jdeb+sizeP)
    {
      i = ideb;
      while(i < ideb+sizeP)
	{
	  mean += X[j*sizeX+i];
	  i++;
	  i = i % sizeX;
	}
      j++;
      j = j % sizeY;
    }

  return mean/(sizeP*sizeP);
}



/**********************************
 *
 * readHeader_mapCvx lecture des header d'un fichier de map de convexity/courbure
 * 
********************************/

void readHeader_mapCvx(char **filenamesGrad, int **sizeXY, int *size_patch, int sizei)
{
  int i,j;
  unsigned int k;
  int nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{


	  sizeXY[i] = new int[2];
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[i][j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }
	  
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
}

/**********************************
 *
 * readHeader_mapCvx lecture des header d'un fichier de map de convexity/courbure
 * 
********************************/

void readHeader_mapCvx_mView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei)
{
  int i,j;
  unsigned int k;
  int sizeX, sizeY;
  int nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{

	  sizeAllXY[i] = new int[2];


	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol == 0)
		    sizeX = std::stoi(line.substr(ideb));
		  if(nCol == 1)
		    sizeY = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }

	  sizeAllXY[i][0] = sizeX;
	  sizeAllXY[i][1] = sizeY;
	  size[i] = sizeX*sizeY;
	  
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
}


/**********************************
 *
 * readHeader_mapCvx_mview_allView lecture des header d'un fichier de map de convexity/courbure
 * 
********************************/

void readHeader_mapCvx_mView_allView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei, int nbView)
{
  int i,j;
  unsigned int k;
  int sizeX, sizeY;
  int nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
      
      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{

	  sizeAllXY[i] = new int[2];


	  /***********MODIF SHREC20 ************/
	  /*	  //extrait le mot "POINTS"                                    
          std::getline(fileGrad,line, ' ');                            
	  //std::cout << "td " << line << "\n";                                                           
          //extrait le nombre de point total                          
          std::getline(fileGrad, line, ' ');                           
	  // *sizeNbP = std::stoi(line);                               
                                                                       
          //extrait le mot "SIZEXY"                                    
          std::getline(fileGrad,line, ' ');                            
	  //std::cout << "test " << i <<"\n";
	  
          //extrait la taille, largeur (sizeX)                         
          std::getline(fileGrad, line, ' ');                           
	  //std::cout << "hello " << line << "\n";
	  sizeX = std::stoi(line);                        
	  
          //extrait la taille, longueur (sizeY)                        
          std::getline(fileGrad, line);
	  //std::cout << "hello2 " << line << "\n";
	  sizeY = std::stoi(line);

	  *size_patch = 50;
	  */
	  /*********END MODIF SHREC20 DECOMMENTER EN DESSOUS*************/
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol == 0)
		    sizeX = std::stoi(line.substr(ideb));
		  if(nCol == 1)
		    sizeY = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }
	  
	  sizeAllXY[i][0] = sizeX;
	  sizeAllXY[i][1] = sizeY;
	  
	  if(i % nbView == 0)
	    size[i/nbView] = 0;
	  
	  size[i/nbView] += sizeX*sizeY;
	  
	  
	  fileGrad.close();
	  

	}
	
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
}



/**********************************
 *
 * readHeader_mapCvx_mview_allView lecture des header d'un fichier de map de convexity/courbure
 * 
********************************/

void readBinaryHeader_mapCvx_mView_allView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei, int nbView)
{
  int i,j;
  unsigned int k;
  int sizeX, sizeY, sizeNbP, sizeTmpPatch;
  int nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
      
      fileGrad.open(filenamesGrad[i],std::ios::in | std::ios::binary);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{

	  sizeAllXY[i] = new int[2];


	  /***********MODIF SHREC20 ************/
    
          //extrait le nombre de point total                          
	  //  fileGrad.read( (char*) &sizeNbP, sizeof(int));                      
     
	  
          //extrait la taille, largeur (sizeX)                         
          fileGrad.read( (char*) &sizeX, sizeof(int));                        
	  
          //extrait la taille, longueur (sizeY)                        
          fileGrad.read( (char*) &sizeY, sizeof(int));

	  //extrait la taille du patch, desuet
	  fileGrad.read( (char*) &sizeTmpPatch, sizeof(int));  

	  *size_patch = 50;
	  /*********END MODIF SHREC20 *************/
	  
	  
	  sizeAllXY[i][0] = sizeX;
	  sizeAllXY[i][1] = sizeY;


	   printf("%d %d \n", sizeAllXY[i][0], sizeAllXY[i][1]);
	  
	  if(i % nbView == 0)
	    size[i/nbView] = 0;
	  
	  size[i/nbView] += sizeX*sizeY;
	  
	  
	  fileGrad.close();
	  

	}
	
      else
	{
	  std::cout << "(loadBinaryFiles_header_allView) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
}



/**********************************
 *
 * loadFile_mapCvx_mView_desc prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image 
 * 
 ********************************/

void loadFile_mapCvx_mView_desc(char *filenamesGrad, float **ac, int *size)
{
  int j,l;
  unsigned int k;
  int nCol;
  int sizeXY[2];
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
 

  fileGrad.open(filenamesGrad,std::ios::in);
  // printf("opening file %s \n", filenamesGrad);

  if(fileGrad.is_open())
    {

	  
      /*get the size in the header == first line*/
      std::getline(fileGrad,line);
      j=0;
      ideb=0;
      nCol = 0;
      for(k = 0; k < line.size(); k++)
	{
	  if(line[k] == ' ' || k == line.size()-1 )
	    {
	      //The way of extracting the column value is not clean, TODO :find a way of making it more clean
	      if(nCol < 2)
		sizeXY[j] = std::stoi(line.substr(ideb));
	      ideb = k+1;
	      j++;
	      nCol++;
	    }
	}

      *ac = new float[sizeXY[0]*sizeXY[1]];
      *size = sizeXY[0]*sizeXY[1];
      
      j = 0;
      while (std::getline(fileGrad,line))
	{
	  // printf("%s \n", line.c_str());
	  ideb=0;
	  l = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ')
		{
		  (*ac)[j*sizeXY[0]+l] = std::stof(line.substr(ideb));
		  ideb = k+1;
		  l++;
		}
	    }
	      
	  j++;
	}
      fileGrad.close();
    }
  else
    {
      std::cout << "(loadFile_mapCvx_mView_desc) doesn't open files " <<  filenamesGrad << " \n";
    }
    
}



/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image 
 * 
 ********************************/

void loadFile_mapCvx_mView(char *filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch)
{
  int i,j,l;
  unsigned int k;
  int x,y;
  int nbLine, nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
 

  fileGrad.open(filenamesGrad,std::ios::in);
  //printf("opening file %s \n", filenamesGrad);

  if(fileGrad.is_open())
    {

      /*-1 is for removing the first line with size */
      nbLine = countLinesFile(filenamesGrad)-1;

      //printf("%d \n", nbLine);

      *sizeXY = new int[2];
	  
      /*get the size in the header == first line*/
      std::getline(fileGrad,line);
      j=0;
      ideb=0;
      nCol = 0;
      for(k = 0; k < line.size(); k++)
	{
	  if(line[k] == ' ' || k == line.size()-1 )
	    {
	      //The way of extracting the column value is not clean, TODO :find a way of making it more clean
	      if(nCol < 2)
		(*sizeXY)[j] = std::stoi(line.substr(ideb));
	      if(nCol == 2)
		*size_patch = std::stoi(line.substr(ideb));
	      ideb = k+1;
	      j++;
	      nCol++;
	    }

	}

      //  printf("%d \n", nbChar);
      *ac = new float[(*sizeXY)[0]*(*sizeXY)[1]];
      *pos = new int[(*sizeXY)[0]*(*sizeXY)[1]];
      *revPos = new int[nbLine*2];
      *size = (*sizeXY)[0]*(*sizeXY)[1];

      /*initialize pos to -1*/
      for(i = 0; i <  (*sizeXY)[0]*(*sizeXY)[1]; i++)
	{
	  (*pos)[i] = -1;
	}
	  
      j = 0;
      while (std::getline(fileGrad,line))
	{
	  // printf("%s \n", line.c_str());
	  ideb=0;
	  l = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      // printf("%d %d \n", i, line.size());
	      if(line[k] == ' ')
		{
		  (*ac)[j*(*sizeXY)[0]+l] = std::stof(line.substr(ideb));
		  ideb = k+1;
		  // printf("sqdkjl : %f \n", ac[i][j*sizeXY[i][0]+l] );
		  l++;
		}
	    }

	  x = j %  (*sizeXY)[0];
	  y = j - (j / (*sizeXY)[0]);
	      
	  (*pos)[y* (*sizeXY)[0]+x] = j;
	  (*revPos)[j*2+0] = x;
	  (*revPos)[j*2+1] = y;

	  j++;
	}
      fileGrad.close();
	  

    }
  else
    {
      std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
    }
    
}



/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image 
 * 
********************************/

void loadFiles_mapCvx_mView(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch, int sizei, int idxI, int idxJ)
{
  int i,j,l;
  unsigned int k;
  int idxFile;
  int x,y;
  int nbLine, nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
 
      for(i = 0; i < sizei; i++)
	{
	  if(i == 0)
	    idxFile = idxI;
	  else
	    idxFile = idxJ;
	  
	  fileGrad.open(filenamesGrad[idxFile],std::ios::in);
	  printf("opening file %s \n", filenamesGrad[idxFile]);

	  if(fileGrad.is_open())
	    {

	  /*-1 is for removing the first line with size */
	  nbLine = countLinesFile(filenamesGrad[idxFile])-1;

	  //printf("%d \n", nbLine);

	  sizeXY[i] = new int[2];
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[i][j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }

	  //  printf("%d \n", nbChar);
	  ac[i] = new float[sizeXY[i][0]*sizeXY[i][1]];
	  pos[i] = new int[sizeXY[i][0]*sizeXY[i][1]];
	  revPos[i] = new int[nbLine*2];
	  size[i] = sizeXY[i][0]*sizeXY[i][1];

	  /*initialize pos to -1*/
	  for(i = 0; i <  sizeXY[i][0]* sizeXY[i][1]; i++)
	    {
	      pos[i][i] = -1;
	    }
	  
	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      ac[i][j*sizeXY[i][0]+l] = std::stof(line.substr(ideb));
		      ideb = k+1;
		      // printf("sqdkjl : %f \n", ac[i][j*sizeXY[i][0]+l] );
		      l++;
		    }
		}

	      x = j %  sizeXY[i][0];
	      y = j - (j /  sizeXY[i][0]);
	      
	      pos[i][y* sizeXY[i][0]+x] = j;
	      revPos[i][j*2+0] = x;
	      revPos[i][j*2+1] = y;

	      j++;
	    }
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_mapCvx_mView) doesn't open files " <<  filenamesGrad[idxFile] << " \n";
	}
    }
}


/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image 
 * 
 ********************************/

void loadFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int *sizeXY, int *size_patch, int nbView)
{
  int i,j,l, idxF;
  unsigned int k;
  int x,y;
  int nCol;
  int sizeXYCum;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;


  *size = 0;

  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s, nbView : %d %d \n", filenamesGrad[idxF], nbView, idxF);

      if(fileGrad.is_open())
	{

	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  
	  /*We need to initialize only one time, so idxF == 0*/

	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1)
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[idxF*2 + j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }

	  *size += sizeXY[idxF*2 + 0]*sizeXY[idxF*2 + 1];

	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }

  //initialize the data
  *ac = new float[*size];
  *pos = new int[*size];
  *revPos = new int[2*(*size)];
	     
	    

  /*initialize pos to -1*/
  for(i = 0; i < (*size); i++)
    {
      (*pos)[i] = -1;
    }

  //Cette variable s'incremente avec la boucle "idxF" et permet de sauter toutes les images déjà enregistré
  sizeXYCum = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s \n", filenamesGrad[idxF]);

      if(fileGrad.is_open())
	{
	  
	  /*get the size in the header == first line, we need nothing from it because before*/
	  std::getline(fileGrad,line);
        

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  if(line[k] == ' ')
		    {
		      (*ac)[j*sizeXY[idxF*2 + 0]+l + sizeXYCum] = std::stof(line.substr(ideb));
		      
		      ideb = k+1;
		      l++;
		    }
		}

	      
	      x = j % ( sizeXY[idxF*2 + 0]);
	      y = j - (j / ( sizeXY[idxF*2 + 0]) );
	      (*pos)[y* sizeXY[idxF*2 + 0]+x + sizeXYCum] = j;
	      (*revPos)[j*2+0 + sizeXYCum] = x;
	      (*revPos)[j*2+1 + sizeXYCum] = y;

	      j++;
	    }
	  sizeXYCum += sizeXY[idxF*2 + 0] * sizeXY[idxF*2 + 1];
	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
}


/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image
 * cette version est sans pos et revPos !!!! 
 * 
 ********************************/

void loadFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int *size, int *sizeXY, int *size_patch, int nbView)
{
  int i,j,l, idxF;
  unsigned int k;
  int x,y;
  int nCol;
  int sizeXYCum;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;


  *size = 0;

  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s, nbView : %d %d \n", filenamesGrad[idxF], nbView, idxF);

      if(fileGrad.is_open())
	{

	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  
	  /*We need to initialize only one time, so idxF == 0*/

	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1)
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[idxF*2 + j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }

	  *size += sizeXY[idxF*2 + 0]*sizeXY[idxF*2 + 1];

	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }

  //initialize the data
  *ac = new float[*size];
	     
  //std::cout << *size << "\n";   



  //Cette variable s'incremente avec la boucle "idxF" et permet de sauter toutes les images déjà enregistré
  sizeXYCum = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s \n", filenamesGrad[idxF]);

      if(fileGrad.is_open())
	{
	  
	  /*get the size in the header == first line, we need nothing from it because before*/
	  std::getline(fileGrad,line);
        

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  if(line[k] == ' ')
		    {
		      (*ac)[j*sizeXY[idxF*2 + 0]+l + sizeXYCum] = std::stof(line.substr(ideb));
		      
		      ideb = k+1;
		      l++;
		    }
		}

	      
	      x = j % ( sizeXY[idxF*2 + 0]);
	      y = j - (j / ( sizeXY[idxF*2 + 0]) );


	      j++;
	    }
	  sizeXYCum += sizeXY[idxF*2 + 0] * sizeXY[idxF*2 + 1];
	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
}



/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image
 * cette version est sans pos et revPos !!!! 
 * 
 ********************************/

void loadBinaryFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int *size, int *sizeXY, int size_patch, int nbView)
{
  int i,j, idxF;
  int sizeNbP, sizeXTmp, sizeYTmp, sizeTmpPatch;
  unsigned int k;
  int x,y;
  int k1,k2, k2p;
  int nCol;
  int sizeXYCum;
  float vTmp;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  *size = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in | std::ios::binary);
      //printf("opening file %s, nbView : %d %d \n", filenamesGrad[idxF], nbView, idxF);

      if(fileGrad.is_open())
	{


	  /************** DEBUT  MODIF SHREC 20 - A SUPPRIEMR APRES ********/
	 
	  //extrait le nombre de point total
	  //  fileGrad.read( (char*) &sizeNbP, sizeof(int));

	    
	  //extrait la taille, largeur (sizeX)
	  fileGrad.read( (char*)  &(sizeXY[idxF*2 + 0]), sizeof(int));

	  //extrait la taille, longueur (sizeY)
	  fileGrad.read( (char*) &(sizeXY[idxF*2 + 1]), sizeof(int));

	  //extrait la taille du patch, desuet
	  fileGrad.read( (char*) &sizeTmpPatch, sizeof(int));

	  
	  /************** END MODIF SHREC 20***************/
	  
	  /*get the size in the header == first line*/
	  //std::getline(fileGrad,line);

	  sizeXY[idxF*2 + 0] = sizeXY[idxF*2 + 0];
	  sizeXY[idxF*2 + 1] = sizeXY[idxF*2 + 1];
	  
	  *size += sizeXY[idxF*2 + 0]*sizeXY[idxF*2 + 1];

	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadBinaryFile_mapCvx_mView_allView (1)) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
  //initialize the data /!\ le 50 est la taille du descripteur
  *ac = new float[*size]();
  //std::cout << *size << "\n";   

  nCol = 0;

  //Cette variable s'incremente avec la boucle "idxF" et permet de sauter toutes les images déjà enregistré
  sizeXYCum = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in | std::ios::binary);
      //printf("opening file %s \n", filenamesGrad[idxF]);

      if(fileGrad.is_open())
	{
	  
	  /*get the size in the header == first line, we need nothing from it because before*/
	  //extrait le nombre de point total                        
          //fileGrad.read( (char*) &sizeNbP, sizeof(int));                        
                                                                             
          //extrait la taille, largeur (sizeX)                                 
          fileGrad.read( (char*)  &(sizeXTmp), sizeof(int));          
                                                                               
          //extrait la taille, longueur (sizeY)                                
          fileGrad.read( (char*) &(sizeYTmp), sizeof(int));

	  //extrait la taille du patch, desuet
	  fileGrad.read( (char*) &sizeTmpPatch, sizeof(int));
        

	  sizeNbP = sizeXTmp*sizeYTmp;
	  
	  for(j = 0; j < sizeNbP; j++)
	    {

	      fileGrad.read( (char*) &x, sizeof(int));
	      fileGrad.read( (char*) &y, sizeof(int));
	      
	      fileGrad.read( (char*) &vTmp, sizeof(float));
        
	      (*ac)[y*sizeXY[idxF*2 + 0]+x + sizeXYCum] = vTmp;


	    }


	  sizeXYCum +=  sizeXY[idxF*2 + 0] * sizeXY[idxF*2 + 1];
	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadBinaryFile_mapCvx_mView_allView (2)) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
}




/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image
 * cette version est sans pos et revPos !!!! 
 * 
 ********************************/

void loadFile_mapCvx_mView_allView_WKS(char **filenamesGrad, float **ac, int *size, int *sizeXY, int *size_patch, int nbView)
{
  int i,j,l, idxF;
  unsigned int k;
  int x,y;
  int nCol;
  int sizeXYCum;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  int sizeDesc = 100;

  *size = 0;

  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s, nbView : %d %d \n", filenamesGrad[idxF], nbView, idxF);

      if(fileGrad.is_open())
	{


	  /************** DEBUT  MODIF SHREC 20 - A SUPPRIEMR APRES ********/
	  /*	  //extrait le mot "POINTS"                                    
	  std::getline(fileGrad,line, ' ');
	  
	  //extrait le nombre de point total                           
	  std::getline(fileGrad, line, ' ');                           
	  //	  *sizeNbP = std::stoi(line);

	  //extrait le mot "SIZEXY"                                    
	  std::getline(fileGrad, line, ' ');
	  
	  //extrait la taille, largeur (sizeX)
	  std::getline(fileGrad, line, ' ');
	  sizeXY[idxF*2 + 0] = std::stoi(line);

	  //extrait la taille, longueur (sizeY)
	  std::getline(fileGrad, line);
	  sizeXY[idxF*2 + 1] = std::stoi(line);

	  *size_patch = 50;
	  */
	  /************** END MODIF SHREC 20***************/
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  
	  /*We need to initialize only one time, so idxF == 0*/

	   j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1)
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[idxF*2 + j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }
	  
	  *size += sizeXY[idxF*2 + 0]*sizeXY[idxF*2 + 1];

	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
  //initialize the data
  *ac = new float[*size*sizeDesc]();
	     
  //std::cout << *size << "\n";   

  nCol = 0;

  //Cette variable s'incremente avec la boucle "idxF" et permet de sauter toutes les images déjà enregistré
  sizeXYCum = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in);
      //printf("opening file %s \n", filenamesGrad[idxF]);

      if(fileGrad.is_open())
	{
	  
	  /*get the size in the header == first line, we need nothing from it because before*/
	  std::getline(fileGrad,line);
        
	  /*******notTriangle ajout de SHREC20 a supprimer apres avec e if qui check POLYGONS****/
	  // bool notTriangle = true;
	  
	  j = 0;
	  while (std::getline(fileGrad,line)/* && notTriangle*/)
	    {
	      ideb=0;
	      l = 0;
	      nCol = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  if(line[k] == ' '/* && notTriangle*/)
		    {
		      
		      /* // ajout de SHREC20
			if(nCol == 0 && line.substr(ideb, line.find(' ')) == "POLYGONS" )
			{
			  notTriangle = false;
			}
		      else
		      {*/
     
		      if(nCol == 0)
			x = std::stoi(line.substr(ideb));
		      else if (nCol == 1)
			y = std::stof(line.substr(ideb));
		      else
			(*ac)[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] = std::stof(line.substr(ideb));

		      nCol++;
		      ideb = k+1;
		      l++;
		    }
		  
		}

	      j++;
	    }
	  sizeXYCum += sizeDesc * sizeXY[idxF*2 + 0] * sizeXY[idxF*2 + 1];
	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
}

/**********************************
 *
 * loadFile_mapCvx prends un fichier sous le format : "x11 x12 ... x1n \n"
 * et créer un tableau de de map de courbure/convexity correspondent chaque image
 * cette version est sans pos et revPos !!!! 
 * 
 ********************************/

void loadBinaryFile_mapCvx_mView_allView_WKS(char **filenamesGrad, float **ac, int *size, int *sizeXY, int size_patch, int nbView)
{
  int i,j,l, idxF;
  int sizeNbP, sizeXTmp, sizeYTmp, sizeTmpPatch;
  unsigned int k;
  int x,y;
  int k1,k2, k2p;
  int nCol;
  int sizeXYCum;
  float *acTmp, vTmp;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  int sizeDesc = 10; //Rendre ca plus propre en l'envoyant en argument /!\ /!\ changer la valeur en fonction de la taille du descripteur
  
  *size = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in | std::ios::binary);
      //printf("opening file %s, nbView : %d %d \n", filenamesGrad[idxF], nbView, idxF);

      if(fileGrad.is_open())
	{


	  /************** DEBUT  MODIF SHREC 20 - A SUPPRIEMR APRES ********/
	 
	  //extrait le nombre de point total
	  //  fileGrad.read( (char*) &sizeNbP, sizeof(int));

	    
	  //extrait la taille, largeur (sizeX)
	  fileGrad.read( (char*)  &(sizeXY[idxF*2 + 0]), sizeof(int));

	  //extrait la taille, longueur (sizeY)
	  fileGrad.read( (char*) &(sizeXY[idxF*2 + 1]), sizeof(int));

	  //extrait la taille du patch, desuet
	  fileGrad.read( (char*) &sizeTmpPatch, sizeof(int));

	  
	  /************** END MODIF SHREC 20***************/
	  
	  /*get the size in the header == first line*/
	  //std::getline(fileGrad,line);

	  sizeXY[idxF*2 + 0] = sizeXY[idxF*2 + 0];
	  sizeXY[idxF*2 + 1] = sizeXY[idxF*2 + 1];
	  
	  *size += sizeXY[idxF*2 + 0]*sizeXY[idxF*2 + 1];

	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadFile_mapCvx_mView) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
  //initialize the data /!\ le 50 est la taille du descripteur
  *ac = new float[*size*sizeDesc]();
  acTmp = new float[*size*sizeDesc]();
  //std::cout << *size << "\n";   

  nCol = 0;

  //Cette variable s'incremente avec la boucle "idxF" et permet de sauter toutes les images déjà enregistré
  sizeXYCum = 0;
  for(idxF = 0; idxF < nbView; idxF++)
    {

      fileGrad.open(filenamesGrad[idxF], std::ios::in | std::ios::binary);
      //printf("opening file %s \n", filenamesGrad[idxF]);

      if(fileGrad.is_open())
	{
	  
	  /*get the size in the header == first line, we need nothing from it because before*/
	  //extrait le nombre de point total                        
          //fileGrad.read( (char*) &sizeNbP, sizeof(int));                        
                                                                             
          //extrait la taille, largeur (sizeX)                                 
          fileGrad.read( (char*)  &(sizeXTmp), sizeof(int));          
                                                                               
          //extrait la taille, longueur (sizeY)                                
          fileGrad.read( (char*) &(sizeYTmp), sizeof(int));

	  //extrait la taille du patch, desuet
	  fileGrad.read( (char*) &sizeTmpPatch, sizeof(int));
        

	  sizeNbP = sizeXTmp*sizeYTmp;
	  
	  for(j = 0; j < sizeNbP; j++)
	    {

	      fileGrad.read( (char*) &x, sizeof(int));
	      fileGrad.read( (char*) &y, sizeof(int));
	      

	      for(l = 0; l < sizeDesc; l++)
		{
		  fileGrad.read( (char*) &vTmp, sizeof(float));
		  //  printf("%d et sizeNbP : %d \n", j, sizeNbP);

		  //SI PATCH DECOMMENTER ICI
		    acTmp[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] = vTmp;
		  
		  //SI PAS PATCH DECOMENTER ICI
		  // (*ac)[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] = vTmp;
		  
		  /* if((*ac)[(y*sizeXY[idxF*2 + 0]+x)*10 + l + sizeXYCum] != (*ac)[(y*sizeXY[idxF*2 + 0]+x)*10 + l + sizeXYCum])
		     {
		     std::cout << "x et y : " << x << " " << y << " j et size " << j << " " << sizeNbP << " " << (*ac)[(y*sizeXY[idxF*2 + 0]+x)*10 + l + sizeXYCum] << "\n";
		     std::cout << (y*sizeXY[idxF*2 + 0]+x)*10 + l + sizeXYCum << " " << 10*(*size) << "\n";
		     }*/
		}


	    }

	  /***** PART APPLYING PATCH *****/
	   for(j = 0; j < sizeNbP; j++)
	    {
	      x = j % sizeXY[idxF*2 + 0];
	      y = j / sizeXY[idxF*2 + 0];
	      
	      for(l = 0; l < sizeDesc; l++)
		{
		  (*ac)[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] = 0.0;
		}
	      
	      if(y >= size_patch/2 && y < (sizeXY[idxF*2 + 1] - size_patch/2))
		{
		  for(k1 = -size_patch/2; k1 <= size_patch/2; k1++)
		    {
		      for(k2p = -size_patch/2; k2p <= size_patch/2; k2p++)
			{
			  k2 = k2p;
			  //  printf("%d %d %d %d et %d %d %d  \n", x, y, k1, k2p, sizeXY[idxF*2 + 0], sizeXY[idxF*2 + 1]);
			  if((x+k2p) < 0)
			    k2 = sizeXY[idxF*2 + 0] + k2p;
			  if((x+k2p) >= sizeXY[idxF*2 + 0])
			    k2 = k2p - (sizeXY[idxF*2 + 0]);

			  for(l = 0; l < sizeDesc; l++)
			    {
			      (*ac)[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] += acTmp[((y+k1)*sizeXY[idxF*2 + 0]+(x+k2))*sizeDesc + l + sizeXYCum];
			    }
			  
			}
		    }
		  for(l = 0; l < sizeDesc; l++)
		    {
		      (*ac)[(y*sizeXY[idxF*2 + 0]+x)*sizeDesc + l + sizeXYCum] / (size_patch*size_patch) ;
		    }
		}

	    }
	  /***************************/
	  
	  sizeXYCum += sizeDesc * sizeXY[idxF*2 + 0] * sizeXY[idxF*2 + 1];
	  fileGrad.close();

	}
      else
	{
	  std::cout << "(loadBinaryFile_mapCvx_mView_allView_WKS) doesn't open files " <<  filenamesGrad << " \n";
	}
    }
  delete[] acTmp;
}



/**********************************
 *
 * loadFiles_mapCvx prends une liste de fichier sous le format : "x y gx gy norm arctan \n"
 * et créer une liste de tableau de gradien correspondent a une liste de chaque image des gradients
 * 
 ********************************/

void loadFiles_mapCvx(char **filenamesGrad, int **ac, int *sizeX, int *sizeY, int sizei)
{
  int i,j,l;
  unsigned int k;
  int nbLine, nbChar;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);

      if(fileGrad.is_open())
	{
	  nbLine = countLinesFile(filenamesGrad[i]);
	  nbChar = countCharsLine(filenamesGrad[i]);
	  //  printf("%d \n", nbChar);
	  ac[i] = new int[nbLine*nbChar];
	  sizeX[i] = nbChar;
	  sizeY[i] = nbLine;

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      ac[i][j*sizeX[i]+l] = std::stoi(line.substr(ideb));

		      ideb = k+1;
		     
		      l++;
		    }
		}
	      j++;
	    }
	  
	  fileGrad.close();
	  
	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    } 
}  

/**********************************
 *
 * loadFiles_mapCvx prends une liste de fichier sous le format : "x11 x12 ... x1n \n"
 * et créer une liste de tableau de de map de courbure/convexity correspondent a une liste de chaque image 
 * 
 ********************************/

void loadFiles_mapCvx(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch, int sizei)
{
  int i,j,l;
  unsigned int k;
  int x,y;
  int nbLine, nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{

	  /*-1 is for removing the first line with size */
	  nbLine = countLinesFile(filenamesGrad[i])-1;

	  //printf("%d \n", nbLine);

	  sizeXY[i] = new int[2];
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[i][j] = std::stoi(line.substr(ideb));
		  if(nCol == 2)
		    *size_patch = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }
	  

	  //  printf("%d \n", nbChar);
	  ac[i] = new float[sizeXY[i][0]*sizeXY[i][1]];
	  pos[i] = new int[sizeXY[i][0]*sizeXY[i][1]];
	  revPos[i] = new int[nbLine*2];
	  size[i] = sizeXY[i][0]*sizeXY[i][1];

	  /*initialize pos to -1*/
	  for(j = 0; j < sizeXY[i][0]*sizeXY[i][1]; j++)
	    {
	      pos[i][j] = -1;
	    }
	  
	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      ac[i][j*sizeXY[i][0]+l] = std::stof(line.substr(ideb));
		      ideb = k+1;
		     
		      l++;
		    }
		}

	      x = i % sizeXY[i][0];
	      y = i - (i / sizeXY[i][0]);
	      
	      pos[i][y*sizeXY[i][0]+x] = j;
	      revPos[i][j*2+0] = x;
	      revPos[i][j*2+1] = y;
	      
	      j++;
	    }
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
}


void loadFiles_mapCvx_patch(char **filenamesGrad, int **ac, int **pos, float **z, int *size, int *size_patch, int sizei)
{
  int i,j;
  unsigned int k;
  int nbLine, nbChar, nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;


  nbChar = countCharsLine(filenamesGrad[0]);
  *size_patch = nbChar-2;
  // printf("%d \n", *size_patch);
  
  for (i = 0; i < sizei; i++)
    {
     
      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);

      if(fileGrad.is_open())
	{
	  /*-1 is for removing the first line with size */
	  nbLine = countLinesFile(filenamesGrad[i])-1;

	  //printf("%d \n", nbLine);
	  ac[i] = new int[nbLine*(*size_patch)];
	  pos[i] = new int[nbLine*2];
	  z[i] = new float[nbLine];
	  size[i] = nbLine;

	  
	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      nCol = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		      if(nCol < 2)
			pos[i][j*2+nCol] = std::stoi(line.substr(ideb));
		      else if(nCol < (2+(*size_patch)) )	
			ac[i][j*(*size_patch)+(nCol-2)] = std::stoi(line.substr(ideb));
		      else
			z[i][j] = std::stof(line.substr(ideb));
		      
		      ideb = k+1;
		      nCol++;


		    }
		}

	      j++;
	    }
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx_patch) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    } 
}

void loadFiles_mapCvx_patch(char **filenamesGrad, float **ac, int **pos, int **revPos, float **z, int *size, int **sizeXY, int *size_patch, int sizei)
{
  int i,j;
  unsigned int k;
  int x,y;
  int nbLine, nbChar, nCol;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  nbChar = countCharsLine(filenamesGrad[0]);
  *size_patch = nbChar-2;
  // printf("%d \n", *size_patch);
  
   for (i = 0; i < sizei; i++)
    {

      fileGrad.open(filenamesGrad[i],std::ios::in);
      // printf("opening file %s \n", filenamesGrad[i]);
      
      if(fileGrad.is_open())
	{
	  /*-1 is for removing the first line with size */
	  nbLine = countLinesFile(filenamesGrad[i])-1;

	  //printf("%d \n", nbLine);

	  sizeXY[i] = new int[2];
	  
	  /*get the size in the header == first line*/
	  std::getline(fileGrad,line);
	  j=0;
	  ideb=0;
	  nCol = 0;
	  for(k = 0; k < line.size(); k++)
	    {
	      if(line[k] == ' ' || k == line.size()-1 )
		{
		  //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		  if(nCol < 2)
		    sizeXY[i][j] = std::stoi(line.substr(ideb));
		  ideb = k+1;
		  j++;
		  nCol++;
		}

	    }
	  ac[i] = new float[nbLine*(*size_patch)];
	  pos[i] = new int[sizeXY[i][0]*sizeXY[i][1]];
	  revPos[i] = new int[nbLine*2];
	  z[i] = new float[nbLine];
	  size[i] = nbLine;

	  /*initialize pos to -1*/
	  for(j = 0; j < sizeXY[i][0]*sizeXY[i][1]; j++)
	    {
	      pos[i][j] = -1;
	    }
	  
	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      //  printf("%s \n", line.c_str());
	      ideb=0;
	      nCol = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ' || k == line.size()-1)
		    {
		      //The way of extracting the column value is not clean, TODO :find a way of making it more clean
		      if(nCol == 0)
		        x = std::stoi(line.substr(ideb));
		      else if(nCol == 1)
			y = std::stoi(line.substr(ideb));
		      else if(nCol < (2+(*size_patch)) )	
			ac[i][j*(*size_patch)+(nCol-2)] = std::stof(line.substr(ideb));
		      else
			z[i][j] = std::stof(line.substr(ideb));

		      
		      ideb = k+1;
		      nCol++;
		    }

		}
	      //   printf("%d %d %d \n", x,y ,sizeXY[i][0]);
	      pos[i][y*sizeXY[i][0]+x] = j;
	      revPos[i][j*2+0] = x;
	      revPos[i][j*2+1] = y;
	      // printf("%d %d %d pos : %d\n", x,y ,sizeXY[i][0],j);

	      j++;
	    }
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx_patch) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    }
   printf("Exit loadFiles_matrix_Cvx_patch \n");

} 

/**********************
 *
 * Load files in the format :
 * X Y Z
 * ...
 * POLYGONS nbTriangle NbPoint*4 (trois pts par triangle + le 3)
 * 3 pt1 pt2 pt3 \n
 * ...
 *
 ***********************/


void loadFileWithTriangles(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles)
{

  int i;
  int x,y;
  std::string::size_type ideb;
  
  std::string line;
  std::ifstream fileTri;
  
  fileTri.open(filename, std::ios::in);
  printf("opening file %s \n", filename);
      
  if(fileTri.is_open())
    {
      //extrait le mot "POINTS"
      std::getline(fileTri,line, ' ');
      
     //extrait le nombre de point total
      std::getline(fileTri, line, ' ');
      *sizeNbP = std::stoi(line);

      //extrait le mot "SIZEXY"
      std::getline(fileTri,line, ' ');
      
      //extrait la taille, largeur (sizeX)
      std::getline(fileTri, line, ' ');
      sizeXY[0] = std::stoi(line);

      //extrait la taille, longueur (sizeY)
      std::getline(fileTri, line);
      sizeXY[1] = std::stoi(line);

      
      (*tabVal) = new float[sizeXY[0]*sizeXY[1]];
      (*revPosVal) = new int[2*(*sizeNbP)];
      
      for(i = 0; i < *sizeNbP; i++)
	{
	  //extrait la coord x
	  std::getline(fileTri,line, ' ');
	  x = std::stoi(line);

	  //extrait la coord y
	  std::getline(fileTri, line, ' ');
	  y = std::stoi(line);

	  (*revPosVal)[2*i+0] = x;
	  (*revPosVal)[2*i+1] = y;
	  
	  //extrait la valeur de la carte
	  std::getline(fileTri, line);
	  (*tabVal)[y*sizeXY[0] + x] =  std::stof(line);
	  
	}
      
      //extrait le mot "POLYGONS"
      std::getline(fileTri,line, ' ');

      //extrait le nombre de triangles
      std::getline(fileTri, line, ' ');
      *nbTriangles = std::stoi(line);

      //extrait le nombre de point valeur numerique (3+1)*nbtriangles
      std::getline(fileTri, line);

      (*trianglesIndex) = new int[3*(*nbTriangles)];
      
      for(i = 0; i < *nbTriangles; i++)
	{
	  printf("%d %d \n", i, *nbTriangles);
	  //extrait le 3 indiquant que c'est un triangle
	  std::getline(fileTri,line, ' ');
		  
	  //extrait le 1er index du coin du triangle
	  std::getline(fileTri,line, ' ');
	  (*trianglesIndex)[3*i] = std::stoi(line);

	  //extrait le 2eme index du coin du triangle
	  std::getline(fileTri, line, ' ');
	  (*trianglesIndex)[3*i+1] = std::stoi(line);

	  //extrait le 3eme index du coin du triangle
	  std::getline(fileTri, line);
	  (*trianglesIndex)[3*i+2] = std::stoi(line);
	  
	}

      fileTri.close();

    }
  else
    {
      std::cout << "(loadFileWithTriangles) doesn't open files " <<  filename << " \n";
    }
}

/*************************
 *
 * Load files in the format :
 * X Y Z1 Z2 Z3... Zn
 * ...
 * POLYGONS nbTriangle NbPoint*4 (trois pts par triangle + le 3)
 * 3 pt1 pt2 pt3 \n
 * ...
 *
 ***********************/


void loadFileWithTriangles_desc(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles, int sizeZ)
{

  int i, idxZ;
  int x,y;
  std::string::size_type ideb;
  
  std::string line;
  std::ifstream fileTri;
  
  fileTri.open(filename, std::ios::in);
  printf("opening file %s \n", filename);
      
  if(fileTri.is_open())
    {
      //extrait le mot "POINTS"
      std::getline(fileTri,line, ' ');
      
     //extrait le nombre de point total
      std::getline(fileTri, line, ' ');
      *sizeNbP = std::stoi(line);

      //extrait le mot "SIZEXY"
      std::getline(fileTri,line, ' ');
      
      //extrait la taille, largeur (sizeX)
      std::getline(fileTri, line, ' ');
      sizeXY[0] = std::stoi(line);

      //extrait la taille, longueur (sizeY)
      std::getline(fileTri, line);
      sizeXY[1] = std::stoi(line);

      
      (*tabVal) = new float[sizeZ*sizeXY[0]*sizeXY[1]];
      (*revPosVal) = new int[2*(*sizeNbP)];

      for(i = 0; i < *sizeNbP; i++)
	{
	  //extrait la coord x
	  std::getline(fileTri,line, ' ');
	  x = std::stoi(line);

	  //extrait la coord y
	  std::getline(fileTri, line, ' ');
	  y = std::stoi(line);

	  (*revPosVal)[2*i+0] = x;
	  (*revPosVal)[2*i+1] = y;


	  //extrait les valeurs de la carte (de taille sizeZ)
	  for(idxZ = 0; idxZ < sizeZ - 1; idxZ++)
	    {
	      std::getline(fileTri, line, ' ');
	      (*tabVal)[(y*sizeXY[0] + x)*sizeZ + idxZ] =  std::stof(line);
	    }
	  //on doit faire ca car le ' ' de getline ne prends pas le \n
	  std::getline(fileTri, line);
	  (*tabVal)[(y*sizeXY[0] + x)*sizeZ + (sizeZ - 1)] =  std::stof(line);	  
	}
      
      //extrait le mot "POLYGONS"
      std::getline(fileTri,line, ' ');

      //extrait le nombre de triangles
      std::getline(fileTri, line, ' ');
      *nbTriangles = std::stoi(line);

      //extrait le nombre de point valeur numerique (3+1)*nbtriangles
      std::getline(fileTri, line);

      (*trianglesIndex) = new int[3*(*nbTriangles)];
      
      for(i = 0; i < *nbTriangles; i++)
	{
	  //extrait le 3 indiquant que c'est un triangle
	  std::getline(fileTri,line, ' ');
		  
	  //extrait le 1er index du coin du triangle
	  std::getline(fileTri,line, ' ');
	  (*trianglesIndex)[3*i] = std::stoi(line);

	  //extrait le 2eme index du coin du triangle
	  std::getline(fileTri, line, ' ');
	  (*trianglesIndex)[3*i+1] = std::stoi(line);

	  //extrait le 3eme index du coin du triangle
	  std::getline(fileTri, line);
	  (*trianglesIndex)[3*i+2] = std::stoi(line);
	  
	}

      fileTri.close();

    }
  else
    {
      std::cout << "(loadFileWithTriangles) doesn't open files " <<  filename << " \n";
    }
}



/*************************
 *
 * Load BINARY files in the format :
 * X Y Z1 Z2 Z3... Zn
 * ...
 * 3 pt1 pt2 pt3 \n
 * ...
 *
 ***********************/


void loadFileBinaryWithTriangles(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles)
{

  int i;
  int x,y;
  int tmpTrois, tmpValue3Tri;
  std::string::size_type ideb;

  float tabValTmp;
  int *tabValCard;
  
  std::string line;
  std::ifstream fileTri;
  
  fileTri.open(filename, std::ios::in | std::ios::binary);
  printf("opening file %s \n", filename);
      
  if(fileTri.is_open())
    {
     //extrait le nombre de point total
      fileTri.read(reinterpret_cast<char*> (sizeNbP), sizeof(int));

      //      printf("ok %d \n", *sizeNbP);
      //extrait la taille, largeur (sizeX)
      fileTri.read(reinterpret_cast<char*> (&(sizeXY[0])), sizeof(int));
      // printf("okX %d \n", sizeXY[0]);
      //extrait la taille, longueur (sizeY)
      fileTri.read(reinterpret_cast<char*> (&(sizeXY[1])), sizeof(int));
      //printf("okY %d \n", sizeXY[1]);
      
      (*tabVal) = new float[sizeXY[0]*sizeXY[1]]();
      tabValCard = new int[sizeXY[0]*sizeXY[1]]();
      
      (*revPosVal) = new int[2*(*sizeNbP)];

      
      for(i = 0; i < *sizeNbP; i++)
	{
	  //extrait la coord x
	  fileTri.read(reinterpret_cast<char*> (&(x)), sizeof(int));

	  //extrait la coord y
	  fileTri.read(reinterpret_cast<char*> (&(y)), sizeof(int));

	  (*revPosVal)[2*i+0] = x;
	  (*revPosVal)[2*i+1] = y;

	  tabValCard[y*sizeXY[0] + x]++;
	  //printf("%d %d et x : %d y : %d idx :%d taille : %d %d %d  %d\n",i, *sizeNbP, x, y, (y*sizeXY[0] + x)*sizeZ + idxZ, sizeZ, sizeXY[0], sizeXY[1], sizeZ*sizeXY[0]*sizeXY[1]);
	 

	  fileTri.read(reinterpret_cast<char*> (&tabValTmp), sizeof(float));

	  (*tabVal)[y*sizeXY[0] + x] += tabValTmp;
	      
	  /*  if( (*tabVal)[y*sizeXY[0] + x] != (*tabVal)[y*sizeXY[0] + x])
		  printf("%d %d %d %f // ", x, y, i, (*tabVal)[y*sizeXY[0] + x]);  */                                                                      
	    
	  //printf("\n");

	}

      //permet de moyenner les valeurs qui se cumule en un seul point
      for(i = 0; i < sizeXY[0]*sizeXY[1]; i++)
	{
	  if(tabValCard[i] > 0)
	    {

	      (*tabVal)[i] /= tabValCard[i];

	    }
	}

      // printf("FIN LECTURE POINTS \n");
      //extrait le nombre de triangles
      fileTri.read(reinterpret_cast<char*> (nbTriangles), sizeof(int));

      //extrait le nombre de point valeur numerique (3+1)*nbtriangles
      fileTri.read(reinterpret_cast<char*> (&tmpValue3Tri), sizeof(int));

      (*trianglesIndex) = new int[3*(*nbTriangles)];                            
      
      for(i = 0; i < *nbTriangles; i++)
	{
	 
	  //extrait le 3 indiquant que c'est un triangle
	  fileTri.read(reinterpret_cast<char*> (&tmpTrois), sizeof(int));
		 
	  //extrait le 1er index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i])), sizeof(int));

	  //extrait le 2eme index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i+1])), sizeof(int));

	  //extrait le 3eme index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i+2])), sizeof(int));
	 
	}
      //printf("FIN LECTURE TRIANGLES \n");
      fileTri.close();
      delete[] tabValCard;

    }
  else
    {
      std::cout << "(loadFileWithTriangles) doesn't open files " <<  filename << " \n";
    }
}




/*************************
 *
 * Load BINARY files in the format :
 * X Y Z1 Z2 Z3... Zn
 * ...
 * 3 pt1 pt2 pt3 \n
 * ...
 *
 ***********************/


void loadFileBinaryWithTriangles_desc(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles, int sizeZ)
{

  int i, idxZ;
  int x,y;
  int tmpTrois, tmpValue3Tri;
  std::string::size_type ideb;

  float tabValTmp;
  int *tabValCard;
  
  std::string line;
  std::ifstream fileTri;
  
  fileTri.open(filename, std::ios::in | std::ios::binary);
  printf("opening file %s \n", filename);
      
  if(fileTri.is_open())
    {
     //extrait le nombre de point total
      fileTri.read(reinterpret_cast<char*> (sizeNbP), sizeof(int));

      //      printf("ok %d \n", *sizeNbP);
      //extrait la taille, largeur (sizeX)
      fileTri.read(reinterpret_cast<char*> (&(sizeXY[0])), sizeof(int));
      // printf("okX %d \n", sizeXY[0]);
      //extrait la taille, longueur (sizeY)
      fileTri.read(reinterpret_cast<char*> (&(sizeXY[1])), sizeof(int));
      //printf("okY %d \n", sizeXY[1]);
      
      (*tabVal) = new float[sizeZ*sizeXY[0]*sizeXY[1]]();
      tabValCard = new int[sizeXY[0]*sizeXY[1]]();
      
      (*revPosVal) = new int[2*(*sizeNbP)];

      for(i = 0; i < *sizeNbP; i++)
	{
	  //extrait la coord x
	  fileTri.read(reinterpret_cast<char*> (&(x)), sizeof(int));

	  //extrait la coord y
	  fileTri.read(reinterpret_cast<char*> (&(y)), sizeof(int));

	  (*revPosVal)[2*i+0] = x;
	  (*revPosVal)[2*i+1] = y;

	  tabValCard[y*sizeXY[0] + x]++;
	  //printf("%d %d et x : %d y : %d idx :%d taille : %d %d %d  %d\n",i, *sizeNbP, x, y, (y*sizeXY[0] + x)*sizeZ + idxZ, sizeZ, sizeXY[0], sizeXY[1], sizeZ*sizeXY[0]*sizeXY[1]);
	 
	  //extrait les valeurs de la carte (de taille sizeZ)
	  for(idxZ = 0; idxZ < sizeZ; idxZ++)
	    {
	      fileTri.read(reinterpret_cast<char*> (&tabValTmp), sizeof(float));

	      (*tabVal)[(y*sizeXY[0] + x)*sizeZ + idxZ] += tabValTmp;
	  
	      
	      if( (*tabVal)[(y*sizeXY[0] + x)*sizeZ + idxZ] != (*tabVal)[(y*sizeXY[0] + x)*sizeZ + idxZ])
		printf("%f ", (*tabVal)[(y*sizeXY[0] + x)*sizeZ + idxZ]);                                                                        
	    }
	  //printf("\n");

	}

      //permet de moyenner les valeurs qui se cumule en un seul point
      for(i = 0; i < sizeXY[0]*sizeXY[1]; i++)
	{
	  if(tabValCard[i] > 0)
	    {
	      for(idxZ = 0; idxZ < sizeZ; idxZ++)
		{
		  (*tabVal)[i*sizeZ + idxZ] /= tabValCard[i];
		}
	    }
	}

      // printf("FIN LECTURE POINTS \n");
      //extrait le nombre de triangles
      fileTri.read(reinterpret_cast<char*> (nbTriangles), sizeof(int));

      //extrait le nombre de point valeur numerique (3+1)*nbtriangles
      fileTri.read(reinterpret_cast<char*> (&tmpValue3Tri), sizeof(int));

      (*trianglesIndex) = new int[3*(*nbTriangles)];                            
      
      for(i = 0; i < *nbTriangles; i++)
	{
	 
	  //extrait le 3 indiquant que c'est un triangle
	  fileTri.read(reinterpret_cast<char*> (&tmpTrois), sizeof(int));
		 
	  //extrait le 1er index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i])), sizeof(int));

	  //extrait le 2eme index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i+1])), sizeof(int));

	  //extrait le 3eme index du coin du triangle
	  fileTri.read(reinterpret_cast<char*> (&((*trianglesIndex)[3*i+2])), sizeof(int));
	 
	}
      //printf("FIN LECTURE TRIANGLES \n");
      fileTri.close();
      delete[] tabValCard;

    }
  else
    {
      std::cout << "(loadFileWithTriangles) doesn't open files " <<  filename << " \n";
    }
}


/***********************
 *
 * compute patches of the Curvatures Maps "c", of size "sizeX*sizeY" 
 * with patch of "size_patch*size_patch" size
 * 
********************************/
void computePatches_allFiles(float **c, float **cLoc, int **sizeXY, int size_patch, int sizeac)
{

  int i;

  for(i = 0; i < sizeac; i++)
  {
    cLoc[i] = new float[sizeXY[i][0]*sizeXY[i][1]*size_patch*size_patch];
    computePatches(c[i], cLoc[i], sizeXY[i][0],  sizeXY[i][1], size_patch);

    /*printf("entering cLoc \n");
    for(int tt = 0; tt < sizeXY[i][0]*sizeXY[i][1]*size_patch*size_patch; tt++)
      {
	if(cLoc[i][tt] != 0.0)
	  {
	    printf("cLoc : %f \n", cLoc[i][tt]);
	  }
	  }*/
    
    delete[] c[i]; 
  }

 

}




/***********************
 *
 * compute patches of the Curvature Map "c", of size "sizeX*sizeY" 
 * with patch of "size_patch*size_patch" size
 * 
********************************/
void computePatches(float *c, float *cLoc, int sizeX, int sizeY, int size_patch)
{
  int i,j,k1,k2,l1,l2,n,m;

  for(j = (size_patch/2); j < (sizeY-(size_patch/2)); j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	 
	  
	  for(k1 = -(size_patch/2); k1 < (size_patch/2); k1++)
	    {
	      n = k1 + j;
	      l1 = k1 + (size_patch/2);
	      for(k2 = -(size_patch/2); k2 < (size_patch/2); k2++)
		{
		  m = (k2+sizeX+i) % sizeX;
		  l2 = k2 + (size_patch/2);
		  
		  cLoc[ (j*sizeX + i)*size_patch*size_patch + l1*size_patch + l2] = c[n*sizeX + m];

		}
	    }
	  
	}
    }

}

/***********************
 *
 * compute patches of the Curvature Map "c", of size "sizeX*sizeY" 
 * with patch of "size_patch*size_patch" size
 * 
********************************/
void computePatches_withMalloc(float *c, float **cLoc, int sizeX, int sizeY, int size_patch)
{
  int i,j,k1,k2,l1,l2,n,m;

 
  *cLoc = new float[sizeX*sizeY*size_patch*size_patch]();

  
  
  for(j = (size_patch/2); j < (sizeY-(size_patch/2)); j++)
    {
      for(i = 0; i < sizeX; i++)
	{
	 
	  
	  for(k1 = -(size_patch/2); k1 < (size_patch/2); k1++)
	    {
	      n = k1 + j;
	      l1 = k1 + (size_patch/2);
	      for(k2 = -(size_patch/2); k2 < (size_patch/2); k2++)
		{
		  m = (k2+sizeX+i) % sizeX;
		  l2 = k2 + (size_patch/2);
		  
		  (*cLoc)[(j*sizeX + i)*size_patch*size_patch + l1*size_patch + l2] = c[n*sizeX + m];
		}
	    }
	  
	}
    }

}


/***********************
 *
 * compute patches of the Curvature Map "c", of size "sizeX*sizeY*NB_MVIEW" 
 * with patch of "size_patch*size_patch" size
 * 
********************************/
void computePatches_withMalloc_allView(float *c, float **cLoc, int sizeAllView, int *sizeXY, int size_patch, int nbView)
{
  int i,j,k1,k2,l1,l2,n,m, nV;
  int sizeXYCum = 0;
 
  *cLoc = new float[sizeAllView*size_patch*size_patch]();

  for(nV = 0; nV < nbView; nV++)
    {
      
      for(j = 0; j < (size_patch/2); j++)
	{
	  for(i = 0; i < sizeXY[nV*2+0]; i++)
	    {
	      for(k1 = -(size_patch/2); k1 < (size_patch/2); k1++)
		{
		  l1 = k1 + (size_patch/2);
		  for(k2 = -(size_patch/2); k2 < (size_patch/2); k2++)
		    {
		      l2 = k2 + (size_patch/2);
		  
		      (*cLoc)[sizeXYCum*size_patch*size_patch + (j*sizeXY[nV*2+0] + i)*size_patch*size_patch + l1*size_patch + l2] = c[sizeXYCum + j*sizeXY[nV*2+0] + i];
			
		    }
		}
	    }
	}

      
      for(j = (size_patch/2); j < (sizeXY[nV*2+1]-(size_patch/2)); j++)
	{
	  for(i = 0; i < sizeXY[nV*2+0]; i++)
	    {

	      for(k1 = -(size_patch/2); k1 < (size_patch/2); k1++)
		{
		  n = k1 + j;
		  l1 = k1 + (size_patch/2);
		  for(k2 = -(size_patch/2); k2 < (size_patch/2); k2++)
		    {
		      m = (k2+sizeXY[nV*2+0]+i) % sizeXY[nV*2+0];
		      l2 = k2 + (size_patch/2);
		  
		      (*cLoc)[sizeXYCum*size_patch*size_patch + (j*sizeXY[nV*2+0] + i)*size_patch*size_patch + l1*size_patch + l2] = c[sizeXYCum + n*sizeXY[nV*2+0] + m];
			
		    }
		}
	  
	    }
	}


      for(j = (sizeXY[nV*2+1]-(size_patch/2)); j < sizeXY[nV*2+1]; j++)
	{
	  for(i = 0; i < sizeXY[nV*2+0]; i++)
	    {
	      for(k1 = -(size_patch/2); k1 < (size_patch/2); k1++)
		{
		  l1 = k1 + (size_patch/2);
		  for(k2 = -(size_patch/2); k2 < (size_patch/2); k2++)
		    {
		      l2 = k2 + (size_patch/2);
		  
		      (*cLoc)[sizeXYCum*size_patch*size_patch + (j*sizeXY[nV*2+0] + i)*size_patch*size_patch + l1*size_patch + l2] = c[sizeXYCum + j*sizeXY[nV*2+0] + i];
			
		    }
		}
	    }
	}
      
      sizeXYCum += sizeXY[nV*2+0]*sizeXY[nV*2+1];
    }
}





/**********************************
 *
 * readASCIIFile open an ASCII file with the coord (x,y) and value I[x,y] 
 * and initialize the image I
 * 
********************************/


void readASCIIFile(char *fname, float **I, int *sizeX,int *sizeY)
{
  FILE *fAsc; 
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int *x,*y;
  float *z;
  int i = 0;

  nbLine = countLinesFile(fname);
  x = (int*)malloc(nbLine*sizeof(int));
  y = (int*)malloc(nbLine*sizeof(int));
  z = (float*)malloc(nbLine*sizeof(float));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readASCIIFile) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {


	tok = strtok(line, " ");
	x[i] = atoi(tok);
 
	tok = strtok(NULL, " ");
	y[i] = atoi(tok);

	tok = strtok(NULL, " ");
	z[i] = atof(tok);

	i++;

      }

      *sizeX = maxInt(x, nbLine)+1;
      *sizeY = maxInt(y,nbLine)+1;

      *I= (float*)calloc((*sizeX ) * (*sizeY), sizeof(float));

  
      for (i = 0; i < nbLine; i++)
	{
	  (*I)[y[i]* (*sizeX) + x[i]] = z[i];
	}

      fclose(fAsc);

      free(line);
      free(x);
      free(y);
      free(z);
    }
}

/**********************************
 *
 * readASCIIFile open an ASCII file with the coord (x,y) and value I[x,y] 
 * and initialize the image I
 * 
********************************/

void readASCIIFile(char *fname, int **x, int **y, float **z, int *size)
{
  FILE *fAsc; 
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int i = 0;

  nbLine = countLinesFile(fname);
  *x = (int*)calloc(nbLine,sizeof(int));
  *y = (int*)calloc(nbLine,sizeof(int));
  *z = (float*)calloc(nbLine,sizeof(float));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readASCIIFile) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {


	tok = strtok(line, " ");
	(*x)[i] = atoi(tok);
 
	tok = strtok(NULL, " ");
	(*y)[i] = atoi(tok);

	tok = strtok(NULL, " ");
	(*z)[i] = atof(tok);

	i++;

      }

      //nbline+1?
      *size = nbLine;
  

      fclose(fAsc);

      free(line);

    }
}


/**********************************
 *
 * readMultiASCIIFile open multiple ASCII files with the coord (x,y) and value I[x,y] 
 * and initialize the image I.  sizei = number of ASCII files
 * 
********************************/

void readMultiASCIIFile(char **filesNames, float **I, int *sizeX,int *sizeY, int sizei)
{
  FILE *fAsc; 
  char * line = NULL;
  char *fname;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int *x,*y;
  float *z;
  int i ;
  int k;


  
  for(k = 0; k < sizei; k++)
    {
      fname=filesNames[k];
 
      nbLine = countLinesFile(fname);
      x = (int*)malloc(nbLine*sizeof(int));
      y = (int*)malloc(nbLine*sizeof(int));
      z = (float*)malloc(nbLine*sizeof(float));

      if ( (fAsc = fopen(fname, "r")) == NULL )
	printf("(readMultiASCIIFile) Can't open file named '%s' for reading\n", fname);
      else
	{

	  i = 0;
	  while ((read = getline(&line, &len, fAsc)) != -1) {


	    tok = strtok(line, " ");
	    x[i] = atoi(tok);
 
	    tok = strtok(NULL, " ");
	    y[i] = atoi(tok);

	    tok = strtok(NULL, " ");
	    z[i] = atof(tok);

	    i++;

	  }

	  sizeX[k] = maxInt(x, nbLine)+1;
	  sizeY[k] = maxInt(y,nbLine)+1;

	  I[k]= (float*)calloc((sizeX[k] ) * (sizeY[k]), sizeof(float));


	  for (i = 0; i < nbLine; i++)
	    {
	      (I[k])[y[i]* (sizeX[k]) + x[i]] = z[i];
	    }

	  fclose(fAsc);
	}


  
      free(x);
      free(y);
      free(z);
    }
  free(line);

}

/**********************************
 *
 * readASCIIFile open an ASCII file with the coord (x,y) of the panorama 
 * and the elevation of the 3D object z
 * and initialize the array courbElev who represent the panorama in an array
 * 
********************************/

void readASCIIFile_courbElev(char *fname, float **courbElev, bool **maskCourbElev, int *sizeX,int *sizeY)
{
  FILE *fAsc; 
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int *x,*y;
  float *z;
  int *nbPtsSamePos;
  int i = 0;

  nbLine = countLinesFile(fname);
  x = (int*)malloc(nbLine*sizeof(int));
  y = (int*)malloc(nbLine*sizeof(int));
  z = (float*)malloc(nbLine*sizeof(float));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readASCIIFile_courbElev) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {


	tok = strtok(line, " ");
	x[i] = atoi(tok);
 
	tok = strtok(NULL, " ");
	y[i] = atoi(tok);

	tok = strtok(NULL, " ");
	z[i] = atof(tok);

	i++;

      }

      *sizeX = maxInt(x, nbLine)+1;
      *sizeY = maxInt(y, nbLine)+1;

      *courbElev = (float*)calloc((*sizeX ) * (*sizeY), sizeof(float));
      *maskCourbElev = (bool*)calloc((*sizeX ) * (*sizeY), sizeof(bool));
      nbPtsSamePos = (int*)calloc((*sizeX ) * (*sizeY), sizeof(int));
  
      for (i = 0; i < nbLine; i++)
	{
	  (*courbElev)[y[i]* (*sizeX) + x[i]] += z[i];
	  (*maskCourbElev)[y[i]* (*sizeX) + x[i]] = true;
	  nbPtsSamePos[y[i]* (*sizeX) + x[i]]++;
	  
	}
      for (i = 0; i < (*sizeX)*(*sizeY); i++)
	{
	  if( nbPtsSamePos[i] != 0)
	    {
	      (*courbElev)[i] /= nbPtsSamePos[i];
	    }
	}

      fclose(fAsc);
    }
 
  free(nbPtsSamePos);
  free(line);
  free(x);
  free(y);
  free(z);
}

void saveGraphValuesXY_int_float(char *fnameout, int *x, float *y, int size)
{
  int i;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  
  if(fileASC.is_open())
    {
	  for(i =0; i < size; i++)
	    {
	      fileASC << x[i] << " " << y[i] << "\n";
	     
	    }
	
      fileASC.close();

    }
  else
    {
      std::cout << "(saveGraphValues_int_float) Unable to open file";
    }
}

/* save with a format : 
*** nView1 idx1_i idx1_j nView2 idx2_i idx2_j valMinMat
*/
void saveCoordPatch_desc(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int nbView, int idx1, int idx2)
{
  int i, j;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  std::cout << "maximum size of image : " << size << "\n";
  if(fileASC.is_open())
    {

      for(i = 0; i < size; i++)
	{
	  j = i / nbView;
	      
	  if(coordMin_I1vsI2[i] != -2)
	    {
	      
	      fileASC << j << " " << (i / nbView) % sizeAllXY[idx1 + j][0]  << " " <<  (i / nbView) / sizeAllXY[idx1 + j][0] << " " << coordMin_I1vsI2[i] / size << " " << (coordMin_I1vsI2[i] % size) % sizeAllXY[idx2 + j][0] << " " << (coordMin_I1vsI2[i] % size) / sizeAllXY[idx2 + j][0] << " " << minMat_I1vsI2[i] << "\n";
	    }
	      
	  // std::cout << sizeAllXY[idx1 + j][0]  << " "  <<  sizeAllXY[idx2 + j][0] << " " <<  coordMin_I1vsI2[j*size + i] << "\n";


	}

      std::cout << "End saveCoord \n";
      fileASC.close();

    }
  else
    {
      std::cout << "(saveCoordPatch_desc) Unable to open file";
    }
}



/* save with a format : 
*** nView1 idx1_i idx1_j nView2 idx2_i idx2_j valMinMat
*/
void saveCoordPatch_desc_allView(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int nbView, int idx1, int idx2)
{
  int i;
  int nView1, nView2;
  int sizeXYCum1, sizeXYCum2;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  std::cout << "maximum size of image : " << size << "\n";
  if(fileASC.is_open())
    {
      nView1 = 0;
      sizeXYCum1 = 0;//sizeAllXY[idx1 + 0][0]*sizeAllXY[idx1 + 0][1];
      for(i = 0; i < size; i++)
	{
	  if(i >= sizeXYCum1 + sizeAllXY[idx1 + nView1][0]*sizeAllXY[idx1 + nView1][1] && nView1 < nbView - 1)
	    {
	      sizeXYCum1 += sizeAllXY[idx1 + nView1][0]*sizeAllXY[idx1 + nView1][1];
	      nView1++;
	    }

	  if(coordMin_I1vsI2[i] != -2)
	    {
	      
	      nView2 = 0;
	      sizeXYCum2 = 0;//sizeAllXY[idx2 + 0][0]*sizeAllXY[idx2 + 0][1]; 
	      while(coordMin_I1vsI2[i] >= sizeXYCum2 + sizeAllXY[idx2 + nView2][0]*sizeAllXY[idx2 + nView2][1] && nView2 < nbView - 1)
		{
		  sizeXYCum2 += sizeAllXY[idx2 + nView2][0]*sizeAllXY[idx2 + nView2][1]; 
		  nView2++;
		}

	      fileASC << nView1 << " " << (i - sizeXYCum1) % sizeAllXY[idx1 + nView1][0]  << " " <<  (i - sizeXYCum1) / sizeAllXY[idx1 + nView1][0] << " " << nView2 << " " << (coordMin_I1vsI2[i] - sizeXYCum2) % sizeAllXY[idx2 + nView2][0] << " " << (coordMin_I1vsI2[i] - sizeXYCum2) / sizeAllXY[idx2 + nView2][0] << " " << minMat_I1vsI2[i] << "\n";
	    }
	      
	  //std::cout << i << " "  << idx1 << " " << idx2 << " " << nView1 << " " << nView2 << "\n";


	}

      std::cout << "End saveCoord \n";
      fileASC.close();

    }
  else
    {
      std::cout << "(saveCoordPatch_desc) Unable to open file";
    }
}


/* save with a format : 
*** nView1 idx1_i idx1_j imgageNumber nView2 idx2_i idx2_j valMinMat
*/
void saveCoordPatch_desc_vsPatch(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int sizeac, int nbView, int idx1, int *coordAssociateImg)
{
  int i, j, idx2;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  std::cout << "size : " << size << "\n";
  if(fileASC.is_open())
    {
      for(j = 0; j < nbView; j++)
	{
	  for(i = 0; i < size; i++)
	    {

	      idx2 = coordAssociateImg[j*size + i];
	      if(coordMin_I1vsI2[j*size + i] != -2)
		{

		  fileASC << j << " " << i % sizeAllXY[idx1 + j][0]  << " " <<  i / sizeAllXY[idx1 + j][0] << " " << idx2 / nbView <<" " << coordMin_I1vsI2[j*size + i] / size << " "  << (coordMin_I1vsI2[j*size + i] % size) % sizeAllXY[idx2 + j][0] << " " << (coordMin_I1vsI2[j*size + i] % size) / sizeAllXY[idx2 + j][0] << " "  <<  " " << minMat_I1vsI2[j*size + i] << "\n";

		}

	    }
	}
      std::cout << "End saveCoord \n";
      fileASC.close();

    }
  else
    {
      std::cout << "(saveCoordPatch_desc_vsPatch) Unable to open file";
    }
}



void saveVectorFile_int(char *fnameout, int *tabVal , int size)
{

 int i;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  
  if(fileASC.is_open())
    {
	  for(i =0; i < size; i++)
	    {
	      fileASC << i << "\n";
	     
	    }
	
      fileASC.close();

    }
  else
    {
      std::cout << "(saveVectoreFile_int) Unable to open file";
    }
  
}




void readVectorFile_int(char *fname, int **tabVal, int *size)
{
  FILE *fAsc; 
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int i = 0;

  nbLine = countLinesFile(fname);
  *size = nbLine;
  *tabVal = (int*)malloc(nbLine*sizeof(int));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readVectorFile) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {
	

	tok = strtok(line, " ");
	(*tabVal)[i] = atoi(tok);
	i++;
      }

      fclose(fAsc);
    }
 

  free(line);


}

void readDoubleVectorFile_int_float(char *fname, int **tabVal, float **tabVal2, int *size)
{
  FILE *fAsc; 
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int i = 0;

  nbLine = countLinesFile(fname);
  *size = nbLine;
  *tabVal = (int*)malloc(nbLine*sizeof(int));
  *tabVal2 = (float*)malloc(nbLine*sizeof(float));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readDoubleVectorFile) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {
	

	tok = strtok(line, " ");
	(*tabVal)[i] = atoi(tok);

	tok = strtok(NULL, " ");
	(*tabVal2)[i] = atof(tok);
	
	i++;
      }

      fclose(fAsc);
    }
 

  free(line);


}


/**********************************
 *
 * loadSaveFiles_matrixScore
 * 
********************************/

void loadSaveFile_matrixScore()
{
  int j,l;
  unsigned int k;
  int sizeX, sizeY;
  std::string line;  
  std::string::size_type ideb;

  float *matSc;
      
  std::ifstream file;
  std::ofstream fileOut;

  sizeX = 588;
  sizeY = 588;
  matSc = (float*)malloc(sizeX*sizeY*sizeof(float));
  
  file.open("scoreBackUp.txt",std::ios::in);

  if(file.is_open())
    {

      j = 0;
      while (std::getline(file,line))
	{
	  
	  ideb=0;
	  l = 0;


	  for(k = 0; k < line.size(); k++)
	    {
	      // printf("%d %d \n", i, line.size());
	      if(line[k] == ' ')
		{
		  if(l > j)
		    {
		      j++;
		      l = 0;
		    }
		  if(j == 365 || j == 510)
		    {
		      for(l = 0; l < j; l++)
			{
			  matSc[j*sizeX+l] = 10000.0;
			  matSc[l*sizeX+j] = matSc[j*sizeX+l];
			}
		      j++;
		      l = 0;
		    }
		  if(l == 365 || l == 510)
		    {
		      matSc[j*sizeX+l] = 10000.0;
		      matSc[l*sizeX+j] = matSc[j*sizeX+l];
		      l++;
		    }

		  matSc[j*sizeX+l] = std::stof(line.substr(ideb));
		  matSc[l*sizeX+j] = matSc[j*sizeX+l];
		  ideb = k+1;
		  l++;

		  //printf("%f \n",  matSc[j*sizeX+l]);
		}
	    }
	    
	}
	  
      file.close();
	  

    }
  else
    {
      std::cout << "(loadFiles_matrixScore) doesn't open files scoreBackUp.txt \n";
    }


    
  fileOut.open("scoreBackUp_redifined.txt",std::ios::out);

  if(fileOut.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(l = 0; l < sizeX; l++)
	    {
	      fileOut << matSc[j*sizeX + l] << " ";
	
	    }
	  fileOut << "\n";
	}
      fileOut.close();
    }
   else
    {
      std::cout << "(loadFiles_matrixScore) doesn't open files scoreBackUp_redifined.txt \n";
    }

    
}  


/**********************************
 *
 * loadFiles_matrixScore
 * Fonction temporaire poru traiter SHREC 20 
 * 
********************************/

void loadFile_matrixScore(char *filenamesMatScore, float *matSc, int sizeX, int sizeY)
{
  int j,l;
  unsigned int k;
  int nbLine, nbChar;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream file;

  

  file.open(filenamesMatScore,std::ios::in);

  if(file.is_open())
    {
      nbLine = countLinesFile(filenamesMatScore);
      nbChar = countCharsLine(filenamesMatScore);
      //  printf("%d \n", nbChar);
      sizeX = nbChar-1;
      sizeY = nbLine;

      j = 0;
      while (std::getline(file,line))
	{
	  ideb=0;
	  l = 0;

	  for(k = 0; k < line.size(); k++)
	    {
	      // printf("%d %d \n", i, line.size());
	      if(line[k] == ' ')
		{ 
		  matSc[j*sizeX+l] = std::stof(line.substr(ideb));
		  ideb = k+1;
		  l++;
		}
	    }

	  j++;
	}
	  
      file.close();
	  

    }
  else
    {
      std::cout << "(loadFiles_matrixScore) doesn't open files " <<  filenamesMatScore << " \n";
    }
    
}  


/**********************************
 *
 * saveImageAscii save 1 image in ascii format.
 * The ASCII style file is : x y I[x,y]
 *
********************************/

void saveImageAscii(float *I, char *fnameout, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  
  if(fileASC.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {
	      if(I[j*sizeX + i] != 0.0)
		fileASC << i << " " << j << " " << I[j*sizeX + i] << "\n";
	    }
	}
      fileASC.close();

    }
  else
    {
      std::cout << "(saveImageAscii_courbElev) Unable to open file";
    }
}

/**********************************
 *
 * saveImageAscii save 1 image in ascii format.
 * The ASCII style file is : x y I[x,y]
 *
********************************/

void saveImageAscii(int *x, int *y, float *z, char *fnameout, int size)
{
  int i;
  std::ofstream fileASC (fnameout, std::ios::out);
 
  
  if(fileASC.is_open())
    {
      for(i = 0; i < size; i++)
	{

	  if(z[i] != 0.0)
	    fileASC << x[i] << " " << y[i] << " " << z[i] << "\n";

	}
      fileASC.close();

    }
  else
    {
      std::cout << "(saveImageAscii_courbElev) Unable to open file";
    }
}



/**********************************
 *
 * saveImageAscii_grad save 3 image, one for gx and one for gy
 * with the value gx(gy) for the coord (x,y)
 * The last one is ASCII style file with gx gy <gx,gy> (euclidian norm) and arctan.
 *
********************************/

void saveImageAscii_grad(char *fnameout_gx, char *fnameout_gy, char *fnameout_gxgy, Gradient *gradImg, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC_gx (fnameout_gx, std::ios::out);
  std::ofstream fileASC_gy (fnameout_gy, std::ios::out);
  std::ofstream fileASC_gxgy (fnameout_gxgy, std::ios::out);
  
  if(fileASC_gx.is_open() && fileASC_gy.is_open() && fileASC_gxgy.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {
	      fileASC_gx << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << "\n";
	      fileASC_gy << i << " " << j << " " << gradImg[j*sizeX+i].getgy() << "\n";
	      fileASC_gxgy << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << " " << gradImg[j*sizeX+i].getgy() << " " << gradImg[j*sizeX+i].getnorm() << " " << gradImg[j*sizeX+i].getarctangx() << " " << gradImg[j*sizeX+i].getarctangx() << "\n";
	    }
	}
      fileASC_gx.close();
      fileASC_gy.close();
      fileASC_gxgy.close();
    }
  else
    {
      std::cout << "(saveImageAscii_courbElev) Unable to open file";
    }
}

/**********************************
 *
 * saveImageAscii_deriv save 1 image in
 * ASCII style file with gx gy dx dy <gx,gy> (euclidian norm) and arctan.
 *
********************************/

void saveImageAscii_deriv(char *fnameout_deriv, Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC_deriv (fnameout_deriv, std::ios::out);
  
  if(fileASC_deriv.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {

	      fileASC_deriv << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << " " << gradImg[j*sizeX+i].getgy() << " " << sDeriv[j*sizeX+i].getdx() << " " << sDeriv[j*sizeX+i].getdy() << " " << gradImg[j*sizeX+i].getnorm() << " " << gradImg[j*sizeX+i].getarctangx() << " " << gradImg[j*sizeX+i].getarctangx() << "\n";
	    }
	}
      fileASC_deriv.close();
    }
  else
    {
      std::cout << "(saveImageAscii_deriv) Unable to open file";
    }
}

/**********************************
 *
 * saveImageAscii_deriv_full save 1 image in
 * ASCII style file with i j z gx gy dx dy <gx,gy> (euclidian norm) and arctan.
 * i,j are image coordonate, x y z are euclidian 3D coordinate
 *
********************************/

void saveImageAscii_deriv_full(char *fnameout_deriv, float *courbElev,  Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC_deriv (fnameout_deriv, std::ios::out);
  
  if(fileASC_deriv.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {

	      fileASC_deriv << i << " " << j << " " << courbElev[j*sizeX+i] << " " << gradImg[j*sizeX+i].getgx() << " " << gradImg[j*sizeX+i].getgy() << " " << sDeriv[j*sizeX+i].getdx() << " " << sDeriv[j*sizeX+i].getdy() << " " << gradImg[j*sizeX+i].getnorm() << " " << gradImg[j*sizeX+i].getarctangx() << " " << gradImg[j*sizeX+i].getarctangx() << "\n";
	    }
	}
      fileASC_deriv.close();
    }
  else
    {
      std::cout << "(saveImageAscii_deriv) Unable to open file";
    }
}




 
/**********************************
 *
 * loadFile_WKS
 * 
********************************/

void loadFiles_WKS(char **filenamesWKS, float **wks, int *size, int *size_desc, int sizeac)
{
  int  i,j,k;

  std::string line;  
  std::stringstream ss;

  std::ifstream fileWKS;

     for (k = 0; k < sizeac; k++)
    {
     
  
      fileWKS.open(filenamesWKS[k],std::ios::in);

      if(fileWKS.is_open())
	{
	  size_desc[k] = countCharsLine(filenamesWKS[k]) + 1;
	  size[k] = countLinesFile(filenamesWKS[k]) + 1;

	  wks[k] = (float*) malloc((size_desc[k])*(size[k])*sizeof(float));
	  j = 0;
	  while (std::getline(fileWKS,line))
	    {

	      ss.str( line + "\n");

	      for(i = 0; i < (size_desc[k]); i++)
		{
		  ss >> wks[k][j*(size_desc[k])+i];
		}
	  
	      j++;
	    }
   
	  fileWKS.close();
	  
	}
      else
	{
	  std::cout << "(loadFile_WKS) doesn't open files " <<  filenamesWKS[k] << " \n";
	}
    }
}  



/**********************************
 *
 * loadFile_deriv prends un fichier sous le format : "x y gx gy dx dy norm arctan \n"
 * et créer un tableau de deriv correspondent aux derivee premiere et seconde d'une image
 * 
********************************/

void loadFile_deriv(char *filenamesDeriv, ArrDeriv *ad)
{
  int  j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::stringstream ss;
  int *x, *y, *z;
  float *gx, *gy;
  float *dx, *dy;

  std::ifstream fileDeriv;


    
  fileDeriv.open(filenamesDeriv,std::ios::in);

  if(fileDeriv.is_open())
    {
      nbLine = countLinesFile(filenamesDeriv);
      x = (int*)malloc(nbLine*sizeof(int));
      y = (int*)malloc(nbLine*sizeof(int));
      z = (int*)malloc(nbLine*sizeof(int));      
      gx = (float*)malloc(nbLine*sizeof(float));
      gy = (float*)malloc(nbLine*sizeof(float));
      dx = (float*)malloc(nbLine*sizeof(float));
      dy = (float*)malloc(nbLine*sizeof(float));

      j = 0;
      while (std::getline(fileDeriv,line))
	{

	  ss.str( line + "\n");
	      
	  ss >> x[j];
	  ss >> y[j];
	  ss >> z[j];
	  ss >> gx[j];
	  ss >> gy[j];
	  ss >> dx[j];
	  ss >> dy[j];
	  
	  j++;
	}

      sizeX = maxInt(x, nbLine)+1;
      sizeY = maxInt(y, nbLine)+1;

      ad->initDerivArr(sizeX,sizeY);
	  
  
      for (j = 0; j < nbLine; j++)
	{
	  ad->setDeriv(gx[j], gy[j], dx[j], dy[j], z[j], x[j], y[j]);
	}
	  
      fileDeriv.close();
	  
      free(x);
      free(y);
      free(z);
      free(gx);	  
      free(gy);
      free(dx);	  
      free(dy);
    }
  else
    {
      std::cout << "(loadFile_deriv) doesn't open files " <<  filenamesDeriv << " \n";
    }
  
}  


/**********************************
 *
 * loadFiles_deriv prends une liste de fichier sous le format : "x y gx gy dx dy norm arctan \n"
 * et créer une liste de tableau de derive correspondent a une liste de chaque image des derivees premiere et seconde
 * 
********************************/

void loadFiles_deriv(char **filenamesDeriv, ArrDeriv *ad, int sizei)
{
  int i, j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::stringstream ss;
  int *x, *y;
  float *gx, *gy;
  float *dx, *dy;

  std::ifstream fileDeriv;


  
  for (i = 0; i < sizei; i++)
    {
    
      fileDeriv.open(filenamesDeriv[i],std::ios::in);

      if(fileDeriv.is_open())
	{
	  nbLine = countLinesFile(filenamesDeriv[i]);
	  x = (int*)malloc(nbLine*sizeof(int));
	  y = (int*)malloc(nbLine*sizeof(int));
	  gx = (float*)malloc(nbLine*sizeof(float));
	  gy = (float*)malloc(nbLine*sizeof(float));
	  dx = (float*)malloc(nbLine*sizeof(float));
	  dy = (float*)malloc(nbLine*sizeof(float));
	  
	  j = 0;
	  while (std::getline(fileDeriv,line))
	    {

	      ss.str( line + "\n");
	      
	      ss >> x[j];
	      ss >> y[j];
	      ss >> gx[j];
	      ss >> gy[j];
	      ss >> dx[j];
	      ss >> dy[j];
	      
	      j++;
	    }

	  sizeX = maxInt(x, nbLine)+1;
	  sizeY = maxInt(y, nbLine)+1;

	  (ad[i]).initDerivArr(sizeX,sizeY);
	  

	  for (j = 0; j < nbLine; j++)
	    {
	      (ad[i]).setDeriv(gx[j], gy[j], dx[j], dy[j], x[j], y[j]);
	    }
	  
	  fileDeriv.close();
	  
	  free(x);
	  free(y);
	  free(gx);	  
	  free(gy);
	  free(dx);	  
	  free(dy);
	}
      else
	{
	  std::cout << "(loadFilesDeriv) doesn't open files " <<  filenamesDeriv[i] << " \n";
	}
    } 
}  

/**********************************
 *
 * saveMatrixScore save 1 image, matrix of the score
 * of float array
 * 
********************************/

void saveMatrixScore(char *fnameout, float *matDist, int sizeMat)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {
      for(j = 0; j < sizeMat; j++)
	{
	  for(i = 0; i < sizeMat; i++)
	    {
	      fileMat << matDist[j*sizeMat + i] << " ";
	    }
	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* flaot* int) Unable to open file";
    } 
}


/**********************************
 *
 * saveMatrixScore_transpose save 1 image, matrix transposition of the score
 * of float array
 * 
********************************/

void saveMatrixScore_transpose(char *fnameout, float *matDist, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {
      for(i =0; i < sizeX; i++)
	{
	  for(j = 0; j < sizeY; j++)
	    {
	      fileMat << matDist[j*sizeX + i] << " ";
	    }

	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* float* int int ) Unable to open file";
    }
}

/**********************************
 *
 * saveMatrixScore save 1 image, matrix of the score
 * of float array
 * 
********************************/

void saveMatrixScore(char *fnameout, float *matDist, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {

      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {
	      fileMat << matDist[j*sizeX + i] << " ";
	    }
	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* float* int int ) Unable to open file";
    }
}


/**********************************
 *
 * saveMatrixScore save 1 image, 1 column of a matrix
 * of float 
 * 
********************************/

void saveMatrixScore_append(char *fnameout, float *matDist, int sizeQueries, int j)
{
  int i;
  std::ofstream fileMat (fnameout, std::ios::out | std::ofstream::app);

  
  if(fileMat.is_open()  )
    {
   
      for(i = 0; i < sizeQueries; i++)
	{
	  fileMat << matDist[j*sizeQueries + i] << " ";
	}
      fileMat << "\n";
	
      fileMat.close();
    }
  else
    {
      std::cout << "saveMatrixScore_append(char, float, int, int), with file : " << fnameout << ", unable to open file";
    }
}


/**********************************
 *
 * saveMatrixScore save 4 image, matrix of the score
 * of gx, gy, norm, arctan
 * 
********************************/

void saveMatrixScore(char *fnameout_gx, char *fnameout_gy, char *fnameout_norm, char *fnameout_arctan, float *matDistX, float *matDistY, float *matDistNorm, float *matDistArctan, int sizeMat)
{
  int i,j;
  std::ofstream fileMat_gx (fnameout_gx, std::ios::out);
  std::ofstream fileMat_gy (fnameout_gy, std::ios::out);
  std::ofstream fileMat_norm (fnameout_norm, std::ios::out);
  std::ofstream fileMat_arctan (fnameout_arctan, std::ios::out);
  
  if(fileMat_gx.is_open() && fileMat_gy.is_open() && fileMat_norm.is_open() && fileMat_arctan.is_open() )
    {
      for(j = 0; j < sizeMat; j++)
	{
	  for(i =0; i < sizeMat; i++)
	    {
	      fileMat_gx << matDistX[j*sizeMat + i] << " ";
	      fileMat_gy << matDistY[j*sizeMat + i] << " ";
	      fileMat_norm << matDistNorm[j*sizeMat + i] << " ";
	      fileMat_arctan << matDistArctan[j*sizeMat + i] << " ";
	    }
	  fileMat_gx << "\n";
	  fileMat_gy << "\n";
	  fileMat_norm << "\n";
	  fileMat_arctan << "\n";
	}
      fileMat_gx.close();
      fileMat_gy.close();
      fileMat_norm.close();
      fileMat_arctan.close();
    }
  else
    {
      std::cout << "(saveImageAsciiScore) Unable to open file";
    }
}



/******************************************
 *
 * Compute the cross product z between x and y 
 *
 ******************************************/

void crossProduct3f(float *x, float *y, float *z)
{

  z[0] = x[1]*y[2] - x[2]*y[1];
  z[1] = x[0]*y[2] - x[2]*y[0];
  z[2] = x[0]*y[1] - x[1]*y[0];

}

/******************************************
 *
 * Compute the dot product z between x and y 
 *
 ******************************************/

void dotProduct2i(int *x, int *y, int *z)
{
  *z = x[0]*y[0] + x[1]*y[1];
}



/******************************************
 *
 * Compute the barycentric coordinates (u,v,w) insade triangle ABC of the P point
 * ABC are float array of 2 coordinates (the triangle coordinates)
 *
 ******************************************/

void computeBarycentricCoord2i(int* A, int* B, int* C, int* P, float* u, float* v, float* w)
{
  

  int cc, bc, pc, bb, pb;
  int denom;

  int c[2] = {C[0] - A[0], C[1] - A[1]}; 
  int b[2] = {B[0] - A[0], B[1] - A[1]}; 
  int p[2] = {P[0] - A[0], P[1] - A[1]};

  dotProduct2i(c, c, &cc);
  dotProduct2i(b, c, &bc);
  dotProduct2i(c, p, &pc);
  dotProduct2i(b, b, &bb);
  dotProduct2i(b, p, &pb);

  denom = cc*bb - bc*bc;
  // std::cout << " A : " << A[0] << " " << A[1] << " B : " << B[0] << " " << B[1] << " C : " << C[0] << " " << C[1] << "\n";
   // std::cout << " P : " << P[0] << " " << P[1] << "\n";
   // std::cout << "denom : " << denom << " " << (bb*pc - bc*pb) << " " << (cc*pb - bc*pc) << " " << (1.0*(bb*pc - bc*pb)) / denom  << "\n";
  if(denom != 0)
    {
      *u = (1.0*(bb*pc - bc*pb)) / denom;
      *v = (1.0*(cc*pb - bc*pc)) / denom;
      *w = 1.0 - (*u) - (*v);

      /*Otherwise there is an issue for rounded value and a point cannot be interpolate*/
      if(fabs(*u) < EPSILON)
	*u = 0;
      
      if(fabs(*v) < EPSILON)
	*v = 0;
      
      if(fabs(*w) < EPSILON)
	*w = 0;
      
    }
  //It seems to be non triangle (like A = B, or A = B = C). This is possible because we are going from a 3D to 2D
  else
    {
      *u = -1.0;
      *v = -1.0;
      *w = -1.0;
    }
  
}


/******************************************
 *
 * Check if a point is in a triangle with its barycentric coordinate (u,v,w)
 *
 ******************************************/

bool isInTriangle(float u, float v, float w)
{
  return (u >= 0) && (v >= 0) && (w >= 0);
}




/******************************************
 *
 * Check if a point is inside the triangle
 *
 ******************************************/
/*
bool rayTriangleIntersect( 
    float* orig, float* dir, 
    float* v0, float* v1, float* v2, 
    float* t, float* u, float* v) 
{ 
  // compute plane's normal
  float v0v1[3] = {v1[0] - v0[0], v1[1] - v0[1], v1[2] - v0[2]}; 
  float v0v2[3] = {v2[0] - v0[0], v2[1] - v0[1], v2[2] - v0[2]}; 
  // no need to normalize
  float N[3];
  crossProduct(v0v1, v0v2, N); // N 
  float area = sqrt(N[0]*N[0] + N[1]*N[1] + N[2]*N[2])/2; // area of the triangle 
 
  
  // Step 2: inside-outside test
  float C[3]; // vector perpendicular to triangle's plane 
 
  // edge 0
 
  // edge 1
  float edge1[3] = {v2[0] - v1[0], v2[1] - v1[1], v2[2] - v1[2]}; 
  Vec3f vp1 = P - v1; 
  C = edge1.crossProduct(vp1); 
  u = (C.length() / 2) / area; 
  if (N.dotProduct(C) < 0)  return false; // P is on the right side 
 
  // edge 2
  Vec3f edge2 = v0 - v2; 
  Vec3f vp2 = P - v2; 
  C = edge2.crossProduct(vp2); 
  v = (C.length() / 2) / area; 
  if (N.dotProduct(C) < 0) return false; // P is on the right side; 
 
  return true; // this ray hits the triangle 
} 
*/
