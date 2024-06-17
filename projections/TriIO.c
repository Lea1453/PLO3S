//#pragma warning(disable:4786)


#include <stdlib.h>     /* malloc, qsort */
#include <stdio.h>
#include <math.h>
//#include <cstdlib> 
#include <time.h>

#include "triangle.h"
#include "pnmio.h"


#include "TriIO.h"
// 23 Sept fuse ITK use for handleing floating point images 

//#include "itkImage.h"
/*#include "itkImageFileWriter.h"
#include "itkImageRegionIterator.h"
#include "itkTIFFImageIO.h"
#include "itkRGBAPixel.h"*/


#define SIZE_DESC_WKS 100

#define SIZE_MIN_WKS 0
#define SIZE_MAX_WKS 100


#define NULL 0



#define MIN(a,b) (((a)<(b))?(a):(b))
/*#define MAX(a,b) (((a)>(b))?(a):(b))*/

void BoundingAngle()
{
  printf("Compute bounding angles \n");
  
  
}

point3D Cartezian2Spheric(point3D cartez)
{
 
 point3D spherical;

 spherical.z = sqrt( (cartez.x*cartez.x) + (cartez.y*cartez.y) + (cartez.z*cartez.z) );
 
 //printf("wtf depth %f \n", spherical.z); 
 //theta :: zenith
 spherical.y =acos(cartez.z / spherical.z);
 // phi :azimuth  
 spherical.x = -atan2(cartez.y,cartez.x);

 spherical.index = cartez.index;

 // printf("x : %f y : %f z : %f, depth z %f theta %f phi %f \n", spherical.z, spherical.y, spherical.x); 
 return spherical;
 
}


p3D stackCartezian2Spheric_mview(p3D stackP3DCartezIN, int nbPoints, int flagRGB, int idxView, int nbView)
{
  p3D stackP3DSphOUT;
  stackP3DSphOUT.sizeStackPoints3D= nbPoints;
  stackP3DSphOUT.stackPoints3D = (point3D *)malloc(nbPoints*sizeof(point3D)); 

 int ii;
 int k;
 float alph;

 point3D cartezian;

 /*
//PERMET DE VOIR LES ROTATION DE LA SPHERE NE FICHIER (CF PLUS LOIN ECRITURE)
 FILE *fileCartezianSphTrans;
 if( (fileCartezianSphTrans = fopen("cartezianSphTrans.asc", "w") ) == NULL)
   {
     fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "XYZInliers.asc");
     exit(-1);
     }*/

 
   for(ii=0; ii<nbPoints; ii++)
   {


     //changing the view by modifying the coordinates

     //PERMET DE VOIR LA SPHERE
     //  fprintf(fileCartezianSphTrans,"%f %f %f\n", stackP3DCartezIN.stackPoints3D[ii].x, stackP3DCartezIN.stackPoints3D[ii].y, stackP3DCartezIN.stackPoints3D[ii].z);

     //POUR AVOIR 7 VUE avec une rotation de 2PI/3
     //The first image is always the same
     if(idxView == 0)
       {
	 alph = 0;
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x;            			  
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].y * cos(alph) - stackP3DCartezIN.stackPoints3D[ii].z * sin(alph); 
	 cartezian.z = stackP3DCartezIN.stackPoints3D[ii].y * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].z * cos(alph);

       }
 //arround x axis
     else if(idxView < (nbView-1)/3)
       {

	
	 alph = (idxView  % ((nbView+2)/3))*(2.0/((nbView+2)/3)) ;
	 //	 printf("alpha1 : %f \n", alph);

	 alph *= M_PI;

	  
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x;            			  
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].y * cos(alph) - stackP3DCartezIN.stackPoints3D[ii].z * sin(alph); 
	 cartezian.z = stackP3DCartezIN.stackPoints3D[ii].y * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].z * cos(alph);
	    

       }
     //arround y axis
     else if(idxView < 2*(nbView-1) / 3)
       {
	 alph = (idxView  % ((nbView+2)/3))*(2.0/((nbView+2)/3));
	 //Preventing 0 degres to be computed

	 alph = alph*M_PI + (2.0*M_PI/((nbView+2)/3));

        
	
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x * cos(alph) + stackP3DCartezIN.stackPoints3D[ii].z * sin(alph);             
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].y; 
	 cartezian.z = -stackP3DCartezIN.stackPoints3D[ii].x * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].z * cos(alph);

	
       }
     //arround z axis
     else
       {
	 alph = (idxView  % ((nbView+2)/3))*(2.0/((nbView+2)/3));
	 
	 //Preventing 0 to be computed
	   alph = alph*M_PI + (2.0*M_PI/((nbView/3)+2));

	
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x * cos(alph) - stackP3DCartezIN.stackPoints3D[ii].y * sin(alph);             
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].x * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].y * cos(alph);
	 cartezian.z = stackP3DCartezIN.stackPoints3D[ii].z;
       }
     
     /* //CETTE PARTIE PERMET d'AVOIR 18 VUES AVEC UNE ROTATION DE PI/4

     //arround x axis
     if(idxView < nbView/3)
       {

	
	 alph = (idxView  % (nbView/3))*(2.0/((nbView/3)+2)) ;
	 //	 printf("alpha1 : %f \n", alph);
	 //Preventing 90 et 270 degres to be computed
	 if(alph < 1.0/2)
	   alph *= M_PI;
	 else if(alph >= 1.0/2 && alph + (2.0/((nbView/3)+2))  < 3.0/2)
	   alph = alph*M_PI + (2.0*M_PI/((nbView/3)+2));
	 else
	   alph = alph*M_PI + 2*(2.0*M_PI/((nbView/3)+2));


	  
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x;            			  
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].y * cos(alph) - stackP3DCartezIN.stackPoints3D[ii].z * sin(alph); 
	 cartezian.z = stackP3DCartezIN.stackPoints3D[ii].y * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].z * cos(alph);
	    

       }
     //arround y axis
     else if(idxView < 2*nbView / 3)
       {
	 alph = (idxView  % (nbView/3))*(2.0/((nbView/3)+2));
	 //Preventing 0 et 180 degres to be computed
	 if(alph < 1.0)
	   alph = alph*M_PI + (2.0*M_PI/((nbView/3)+2));
	 else 
	   alph = alph*M_PI + 2*(2.0*M_PI/((nbView/3)+2));
        
	
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x * cos(alph) + stackP3DCartezIN.stackPoints3D[ii].z * sin(alph);             
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].y; 
	 cartezian.z = -stackP3DCartezIN.stackPoints3D[ii].x * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].z * cos(alph);

	
       }
     //arround z axis
     else
       {
	 alph = (idxView  % (nbView/3))*(2.0/((nbView/3)+2));
	 
	 //Preventing 0 et 180 degres to be computed
	 if(alph < 1.0)
	   alph = alph*M_PI + (2.0*M_PI/((nbView/3)+2));
	 else 
	   alph = alph*M_PI + 2*(2.0*M_PI/((nbView/3)+2));
	
	 cartezian.x = stackP3DCartezIN.stackPoints3D[ii].x * cos(alph) - stackP3DCartezIN.stackPoints3D[ii].y * sin(alph);             
	 cartezian.y = stackP3DCartezIN.stackPoints3D[ii].x * sin(alph) + stackP3DCartezIN.stackPoints3D[ii].y * cos(alph);
	 cartezian.z = stackP3DCartezIN.stackPoints3D[ii].z;
       }*/

     //PERMET DE VOIR LES SPHERE EN ROTATION (par contre copier le fichier a la main poru eviter l ecrasement a chaque fois)
     //  fprintf(fileCartezianSphTrans,"%f %f %f\n", cartezian.x, cartezian.y, cartezian.z); 
     
     /*   cartezian.x=stackP3DCartezIN.stackPoints3D[ii].x;            			  
	  cartezian.y=stackP3DCartezIN.stackPoints3D[ii].y; 
	  cartezian.z=stackP3DCartezIN.stackPoints3D[ii].z;*/

     cartezian.index = stackP3DCartezIN.stackPoints3D[ii].index;  
     // add here intensity, RGB and other attributes  
   
   
       
     point3D spherical;
      spherical = Cartezian2Spheric(cartezian);
     // spherical = Cartezian2Spheric(stackP3DCartezIN.stackPoints3D[ii]);
     // note that the index is taken on the fly during conversion
     stackP3DSphOUT.stackPoints3D[ii] = spherical;
     if(flagRGB)
       { 
	 stackP3DSphOUT.stackPoints3D[ii].Red = stackP3DCartezIN.stackPoints3D[ii].Red;
	 stackP3DSphOUT.stackPoints3D[ii].Green = stackP3DCartezIN.stackPoints3D[ii].Green;
	 stackP3DSphOUT.stackPoints3D[ii].Blue = stackP3DCartezIN.stackPoints3D[ii].Blue;
   
       }
 
   }

   //FERMETURE POUR LES FICHIERS MOTNRANT LA ROTATION
   //fclose(fileCartezianSphTrans);

   return stackP3DSphOUT;
}



p3D stackCartezian2Spheric(p3D stackP3DCartezIN, int nbPoints, int flagRGB)
{
  p3D stackP3DSphOUT;
  stackP3DSphOUT.sizeStackPoints3D= nbPoints;
  stackP3DSphOUT.stackPoints3D = (point3D *)malloc(nbPoints*sizeof(point3D)); 

 int ii;
 int k;
 float alph;

 point3D cartezian;

 for(ii=0; ii<nbPoints; ii++)
   {


     //changing the view by modifying the coordinates

   
  
     cartezian.x=stackP3DCartezIN.stackPoints3D[ii].x;            			  
     cartezian.y=stackP3DCartezIN.stackPoints3D[ii].y; 
     cartezian.z=stackP3DCartezIN.stackPoints3D[ii].z;

     /*   cartezian.x=stackP3DCartezIN.stackPoints3D[ii].x;            			  
	  cartezian.y=stackP3DCartezIN.stackPoints3D[ii].y; 
	  cartezian.z=stackP3DCartezIN.stackPoints3D[ii].z;*/

     cartezian.index = stackP3DCartezIN.stackPoints3D[ii].index;  
     // add here intensity, RGB and other attributes  
   
   
       
     point3D spherical;
     spherical = Cartezian2Spheric(stackP3DCartezIN.stackPoints3D[ii]);
     // note that the index is taken on the fly during conversion
     stackP3DSphOUT.stackPoints3D[ii] = spherical;
     if(flagRGB)
       { 
	 stackP3DSphOUT.stackPoints3D[ii].Red = stackP3DCartezIN.stackPoints3D[ii].Red;
	 stackP3DSphOUT.stackPoints3D[ii].Green = stackP3DCartezIN.stackPoints3D[ii].Green;
	 stackP3DSphOUT.stackPoints3D[ii].Blue = stackP3DCartezIN.stackPoints3D[ii].Blue;
   
       }
 
   }

   return stackP3DSphOUT;
}


SphericalBounds computeBoundSph(p3D stackP3DSph, int nbPoints)
{
  SphericalBounds sphBounds; //= (double *)malloc(6*sizeof(double)); 

  printf("compute spheric bounds\n");

  // init min and max values
  //  x : phi, y : theta, z : depth, ro 
    sphBounds.phiMin = stackP3DSph.stackPoints3D[0].x;
  sphBounds.phiMax = stackP3DSph.stackPoints3D[0].x;
  sphBounds.thetaMin = stackP3DSph.stackPoints3D[0].y;
  sphBounds.thetaMax = stackP3DSph.stackPoints3D[0].y;
  sphBounds.depthMin = stackP3DSph.stackPoints3D[0].z;
  sphBounds.depthMax = stackP3DSph.stackPoints3D[0].z;

  sphBounds.phiMin = -M_PI;



   
  
  int ii; 
  for(ii = 1; ii< nbPoints; ii++)
    {
     
      if( stackP3DSph.stackPoints3D[ii].x < sphBounds.phiMin) sphBounds.phiMin = stackP3DSph.stackPoints3D[ii].x;

      if(stackP3DSph.stackPoints3D[ii].y <  sphBounds.thetaMin) sphBounds.thetaMin = stackP3DSph.stackPoints3D[ii].y;
   
      if( stackP3DSph.stackPoints3D[ii].z <  sphBounds.depthMin) sphBounds.depthMin = stackP3DSph.stackPoints3D[ii].z;

      if( stackP3DSph.stackPoints3D[ii].x > sphBounds.phiMax) sphBounds.phiMax = stackP3DSph.stackPoints3D[ii].x;
      if( stackP3DSph.stackPoints3D[ii].y > sphBounds.thetaMax) sphBounds.thetaMax = stackP3DSph.stackPoints3D[ii].y;
      if( stackP3DSph.stackPoints3D[ii].z > sphBounds.depthMax) sphBounds.depthMax = stackP3DSph.stackPoints3D[ii].z;
     
 
      }

  printf("sphBounds phi [%f, %f]\n", sphBounds.phiMin, sphBounds.phiMax);
  printf("sphBounds Theta [%f, %f]\n", sphBounds.thetaMin, sphBounds.thetaMax);
  printf("sphBounds depth [%f, %f]\n", sphBounds.depthMin, sphBounds.depthMax);
  return sphBounds;
}

int compare_doubles (const void *a, const void *b)
{
  const double *da = (const double *) a;
  const double *db = (const double *) b;
     
  return (*da > *db) - (*da < *db);
}


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}




////////////////////////////////////////////////////////////////
// 14 Mars Elevation 2016  Cd CNAM iMATH - GBA 
/*
 * stackP3DSph : coordonnees spheriques de la sphere unitaire (stackP3DCartezIN)
 * stackP3DMeshCartez : coordonnees des poitns 3D de la surface
 * _mySphericBounds : les limites (boundaries) de la sphere dans les coord spheriques
 * nbPoints : le nombre de points de la sphere unitaire (calcule sur la sphere avec les coord spherique)
 * stackP3DCartezIN : coordonnes cartesienne de la sphere unitaire
 *  filenameVTKSph_IN : le nom du fichier VTK de le sphere unitaire
 * arrCurv : tableau des valeurs de courbure
 * _stepCoeff : valeur de 1, semble inutile
 * nFilename : nom de l'image .pgm, inutilise maintenant
 * idxPano : nombre de la panoramique traite 
 *
 */

Image2Laser vidock_triangulateStackSpheric2ImageElevation_Step(p3D stackP3DSph,p3D stackP3DMeshCartez, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN, char *filenameVTKSph_IN, float *arrCurv, int _stepCoeff, char *nFilename, char *filenameImagePano, int idxPano)
{
  printf("VIDOCK : digital elevation image with curvature ... \n");  

  struct timeval tBegin, tEnd;


  struct triangulateio *sphTriIO;
  sphTriIO = (struct triangulateio *)malloc(sizeof(struct triangulateio));

  sphTriIO->pointlist=NULL;
  sphTriIO->pointattributelist=NULL;
  sphTriIO->pointmarkerlist=NULL;
  sphTriIO->numberofpoints=0;
  sphTriIO->numberofpointattributes=0;

  sphTriIO->trianglelist=NULL;
  sphTriIO->triangleattributelist=NULL;
  sphTriIO->trianglearealist=NULL;
  sphTriIO->neighborlist=NULL;
  sphTriIO->numberoftriangles=0;
  sphTriIO->numberofcorners=0;
  sphTriIO->numberoftriangleattributes=0;
  sphTriIO->segmentlist=NULL;
  sphTriIO->segmentmarkerlist=NULL;
  sphTriIO->numberofsegments=0;
  sphTriIO->holelist=NULL;
  sphTriIO->numberofholes=0;
  sphTriIO->regionlist=NULL;
  sphTriIO->numberofregions=0;
  sphTriIO->edgelist=NULL;
  sphTriIO->edgemarkerlist=NULL;
  sphTriIO->normlist=NULL;
  sphTriIO->numberofedges=0;
   
   
  printf("begin initialisation %d\n", nbPoints);

  /*===========================*/
  sphTriIO->numberofpoints=nbPoints;
  sphTriIO->numberofpointattributes = 1;

  /*===========================*/

  printf("nb of attributes %d\n ", sphTriIO->numberofpointattributes);


  sphTriIO->pointlist = (REAL*)malloc(sphTriIO->numberofpoints*2*sizeof(REAL));
  sphTriIO->pointattributelist = (REAL*)malloc(sphTriIO->numberofpoints*sphTriIO->numberofpointattributes*sizeof(REAL));


  int ii, jj; 
  for(ii = 0; ii< nbPoints; ii++)
    {

      sphTriIO->pointlist[2*ii] = stackP3DSph.stackPoints3D[ii].x; // phi
      sphTriIO->pointlist[2*ii+1] =  stackP3DSph.stackPoints3D[ii].y;  // theta
      sphTriIO->pointattributelist[ii]= ii; // keep the index for the moment
    }


  //poru les triangles directement du vtk sph
  /* int *trianglesList;
  int sizeTrianglesList;
  
   sizeTrianglesList = readVTK_trianglesList(filenameVTKSph_IN, &trianglesList);

  */
  
  int is_triangulated = 0;
  printf("Finish triDT initialisation \n");
   
   int convex = 1;
   if(convex)triangulate("cepnzs", sphTriIO,sphTriIO,NULL );
   else triangulate("epnzs", sphTriIO, sphTriIO, NULL);
  
   



   //pour les triangles du vtk sph 
   /*sphTriIO->trianglelist = trianglesList;

   printf("compute point2Triangle \n");
  
   printf("# of triangle %d\n", sphTriIO->numberoftriangles);


   sphTriIO->numberoftriangles = sizeTrianglesList;*/
 
   
   // compute point to triangle
   int done_point_2_triangle = 0;
   int *point_2_triangle;
   point_2_triangle = (int*)malloc(sphTriIO->numberofpoints*sizeof(int));

   int *indexpoint = sphTriIO->trianglelist;

   printf("compute point2Triangle \n");
  
   printf("# of triangle %d\n", sphTriIO->numberoftriangles);


 
   for(ii=0; ii<sphTriIO->numberoftriangles; ii++)
   {
      for(jj=0; jj<3; jj++)
      {
        point_2_triangle[*indexpoint] = ii;
        indexpoint++;
      }
   }



  done_point_2_triangle =1;
  /// finish point2triangle

  
  is_triangulated = 1;   


  // recover edgelist and compute statistics on Azimuth (phi) and Zenith (theta)
 
  int nbSteps =0; int sizeStackPhi =0; int sizeStackTheta =0;

  printf("numberofedges %d \n", sphTriIO->numberofedges);
  double *stackStepPhi = (double *)malloc(sphTriIO->numberofedges*sizeof(double));
  double *stackStepTheta = (double *)malloc(sphTriIO->numberofedges*sizeof(double));
  

  //Fait la difference entre les points selon les deux angles : theta et phi de deux points relie
  //Conserve le plus grand pas entre phi et theta pour chaque pair de point relie
  if(sphTriIO->numberofedges >0)
   {
      for(ii=0; ii<sphTriIO->numberofedges; ii++)
        {
           int idxV1 =  sphTriIO->edgelist[2*ii];
           int idxV2 =  sphTriIO->edgelist[2*ii+1];

           double stepPhi = fabs(sphTriIO->pointlist[2*idxV2] - sphTriIO->pointlist[2*idxV1]); 
           double stepTheta = fabs(sphTriIO->pointlist[2*idxV2+1] - sphTriIO->pointlist[2*idxV1+1]);


	   
          //take the max for the pixel size
          nbSteps++;
	  
          if(stepPhi > stepTheta) {stackStepPhi[sizeStackPhi] = stepPhi;
                                   sizeStackPhi++;
                                  }
          else  {stackStepTheta[sizeStackTheta]=stepTheta;
                 sizeStackTheta++;
                }
           
        }

   }

  ///////////////////////
  qsort (stackStepTheta, sizeStackTheta, sizeof(double), compare_doubles); 
  int n;
  
  qsort (stackStepPhi, sizeStackPhi, sizeof(double), compare_doubles); 
   
  printf("nbSteps %d Phi %d Theta %d \n", nbSteps, sizeStackPhi, sizeStackTheta);

  //compute median value 

  int indexMedianTheta = floor(sizeStackTheta/2);
  printf("Index Theta Median %d\n", indexMedianTheta);
  int indexMedianPhi = floor(sizeStackPhi/2);
  printf("Index Theta Phi %d\n", indexMedianPhi);
  double stepMedianTheta = stackStepTheta[indexMedianTheta]; 
  double stepMedianPhi = stackStepPhi[indexMedianPhi]; 
  printf("Median Theta %f MedianPhi %f\n", stepMedianTheta, stepMedianPhi);


  /*a partir d'ici on a : ajoute les coord de la sphere unitaire en coord spherique dans une struct (triangleio :sphTriIO) qui permet
   * d'avoir plein d'info (edge, point, triangle etc ...). Cette strut est ensuite envoye dans une fonction qui fait la triangulation
   * puis on utilise les edges des triangles pour faire la difference entre les angles phi1, phi2 et theta1, theta2 des deux points relie
   * Ensuite on prends la valeur mediane de phi et theta
   */
  

  

  //calcul des nombres des lignes et nombres des colonnes
  // phi :: azimuth (colonnes ), //theta :: zenith
  printf("Phi %f %f \n", _mySphericBounds.phiMin, _mySphericBounds.phiMax );
  printf("Theta min %f max %f \n", _mySphericBounds.thetaMin, _mySphericBounds.thetaMax );


  // /!\/!\/!\ ici on change la resolution : 0.02 -> 0.01 : quadruple (2*l x 2L) la resolution

  double stepAngleWanted = 0.02;
  double stepCoeffAdaptionPhi = 0.0, stepCoeffAdaptionTheta = 0.0; 
  
  if ((stepMedianTheta < stepAngleWanted) && (stepMedianPhi < stepAngleWanted) )
    {
      stepCoeffAdaptionPhi= stepMedianPhi/stepAngleWanted; 
      printf("adaptedStep %f \n", stepCoeffAdaptionPhi);
      stepCoeffAdaptionTheta= stepMedianTheta/stepAngleWanted; 
    }
  /* ca plante si on initialise pas CoeffAdapt*/
  /*Le if else permet d'avoir des carte desquilibré car on donne un pas different mais si on supprime l'un des deux tjrs desqui*/
  else
    {
      stepCoeffAdaptionPhi= _stepCoeff; 
      printf("adaptedStep %f \n", stepCoeffAdaptionPhi);
      stepCoeffAdaptionTheta= _stepCoeff; 

    }
                                                                                 
  
  //int nbColonnes = floor(0.5 + ((_mySphericBounds.phiMax-_mySphericBounds.phiMin)/(stepMedianPhi/_stepCoeff) )    );
  //int nbLignes =  floor(0.5 + ((_mySphericBounds.thetaMax-_mySphericBounds.thetaMin)/(stepMedianTheta/_stepCoeff) )    );

  //calcul la largeur et longueur de l'image
  int nbColonnes = floor(0.5 + ((_mySphericBounds.phiMax-_mySphericBounds.phiMin)/(stepMedianPhi/stepCoeffAdaptionPhi) )    );
  int nbLignes =  floor(0.5 + ((_mySphericBounds.thetaMax-_mySphericBounds.thetaMin)/(stepMedianTheta/stepCoeffAdaptionTheta) )    );
  
  
  
   
  printf("compute nbCols %f %d\n",(_mySphericBounds.phiMax-_mySphericBounds.phiMin)/stepMedianPhi, nbColonnes );
  printf("nbCol CNAM - GBA nbColonnes %d nbLignes %d\n", nbColonnes, nbLignes);
  

  
  free(stackStepTheta);  free(stackStepPhi);
  // free(sphTriIO); //dangereux car on l'utilise après !!!! 

  // this is the output
  Image2Laser myImage2Laser; 


  myImage2Laser.nbRows = nbLignes;
  myImage2Laser.nbCols = nbColonnes;
  myImage2Laser.intensity = (unsigned char *)malloc(nbLignes*nbColonnes*sizeof(unsigned char)); 
  int nbCol_Low_1 = nbColonnes/16;
  int nbRow_Low1 = nbLignes/16;
  
  unsigned char *imgLowRes1 = (unsigned char *)malloc(nbRow_Low1*nbCol_Low_1*sizeof(unsigned char));
  

  myImage2Laser.dDepthImage = (float *)malloc(nbLignes*nbColonnes*sizeof(float));  

  int idxCol, idxRow;
  // init images 
  for(idxCol = 0; idxCol<nbColonnes; idxCol++) 
    for(idxRow =0; idxRow<nbLignes; idxRow++)
      {
	//printf("%d %d %d %d  \n", idxCol, idxRow, nbColonnes, nbLignes);
	myImage2Laser.intensity[idxRow*nbColonnes+idxCol] = 0;
	myImage2Laser.dDepthImage[idxRow*nbColonnes+idxCol] = 0.0;
	//imgMaskOccurence[idxRow*nbColonnes + idxCol] =0;
	//myImage2Laser.dDepthImage[idxRow*nbColonnes+idxCol] = 0.0; 
       }

 

  
  double *depthTri = (double *)malloc(nbPoints*sizeof(double));
  double *depthTri_OffSet = (double *)malloc(nbPoints*sizeof(double));
  double *depthTri_OffSetFine = (double *)malloc(nbPoints*sizeof(double));
  double *newDepth = (double *)malloc(nbPoints*sizeof(double));
  double *normalized_depth = (double *)malloc(nbPoints*sizeof(double));  
  int *stackColonnes = (int *)malloc(nbPoints*sizeof(int)); 
  int *stackRows=(int *)malloc(nbPoints*sizeof(int)); 
  
  int *stackPoint3DSph_Inside = (int *)malloc(nbPoints*sizeof(int));
  int *stackCountSamePixInner=(int *)malloc(nbPoints*sizeof(int));
  int *stackIdxPointCoincident = (int *)malloc(nbPoints*sizeof(int));
  int *stackIdxPointOutside = (int *)malloc(nbPoints*sizeof(int)); 

  printf("NB PTS : %d \n", nbPoints);
  /* /!\ /!\ /!\ Attribution de la valeur d'elevation ? Non, voir plus loin ici ca sert a rien*/
  for(ii=0; ii<nbPoints; ii++)
  {
    depthTri[ii]=10;//arrCurv[ii];
  } 

  qsort (depthTri, nbPoints, sizeof(double), compare_doubles); 

  double maxDepth, minDepth; 
  minDepth = depthTri[0]; maxDepth=depthTri[nbPoints-1];


  printf("maxDepth %f, minDepth %f \n",maxDepth, minDepth);

  double offSet = 1000; 
  
  double depthOffSet;
  double depthOffSet2;
  for(ii=0; ii<nbPoints; ii++)
  {
     /* /!\ /!\ /!\ Attribution de la valeur d'elevation  | EN FAIT non ??? a (re)verifier*/
      depthOffSet=(arrCurv[ii]*offSet)-1000;
     
   
    depthOffSet2=depthOffSet*1000;
    //printf("%f\n", depthOffSet2);
    depthTri_OffSet[ii] = depthOffSet2;
  } 
  qsort (depthTri_OffSet, nbPoints, sizeof(double), compare_doubles); 
  
  double maxDepthOffSet, minDepthOffSet; 
  minDepthOffSet = depthTri_OffSet[0]; maxDepthOffSet=depthTri_OffSet[nbPoints-1];
  printf("maxDepthOffSet %f, minDepthOffSet %f \n",maxDepthOffSet, minDepthOffSet);

  
  double minBoundDepth = minDepthOffSet+(-minDepthOffSet);
  double maxBoundDepth = maxDepthOffSet+(-minDepthOffSet);


  printf(" newDepth Bound %f %f \n", minBoundDepth, maxBoundDepth);
  
  for(ii=0; ii<nbPoints; ii++)
  {
    
    depthTri_OffSetFine[ii] = depthTri_OffSet[ii]+(-minDepthOffSet);
  } 

  qsort (depthTri_OffSetFine, nbPoints, sizeof(double), compare_doubles);  

  double maxDepthOffSetFine, minDepthOffSetFine; 
  minDepthOffSetFine = depthTri_OffSetFine[0]; maxDepthOffSetFine=depthTri_OffSetFine[nbPoints-1];

  
  for(ii=0; ii<nbPoints; ii++)
  {

    //les deux lignes premieres servent a l'ecriture du pgm
    newDepth[ii]=( ( (/*stackP3DSph.stackPoints3D[ii].z*/arrCurv[ii]*offSet)-1000)*1000)-minDepthOffSet;
     normalized_depth[ii] = (newDepth[ii]*255.)/maxDepthOffSetFine;
     //printf("%f %f\n", newDepth[ii], normalized_depth[ii]);
     stackPoint3DSph_Inside[ii] = 0;
     stackColonnes[ii] = 0;
     stackRows[ii] =0; 
     stackCountSamePixInner[ii]=0;
     stackIdxPointCoincident[ii] = 0;
     stackIdxPointOutside[ii] = 0;
        
  } 
 
   

   FILE *fileImageVector;
 
 
   //NON BINAIRE : w BINAIRE wb
  if( (fileImageVector = fopen(filenameImagePano, "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", filenameImagePano);
      exit(-1);
      }

  printf("Printing image \n");
  // starting filling the image 
  //int idxcol =0, idxrow =0;
  int idxColPrec =0, idxRowPrec=0;
  int countSamePixel =0, countSameCol=0, countSameRow=0;
  
  //double offsetPhiMin =-_mySphericBounds.phiMin; 
  //double newPhiMin = _mySphericBounds.phiMin+ offsetPhiMin;
    
  int countPixOutside = 0;
  int countPixInside = 0;

  int idxcol;
  int idxrow;


  //NON BINARY :
   fprintf(fileImageVector, "POINTS %d SIZEXY %d %d float\n", nbPoints, nbColonnes, nbLignes); 
  //BINARY :
  //fwrite(&nbPoints, sizeof(int), 1, fileImageVector);
  //fwrite(&nbColonnes, sizeof(int), 1, fileImageVector);
  //fwrite(&nbLignes, sizeof(int), 1, fileImageVector);

  gettimeofday(&tBegin, NULL);
  for(ii = 0; ii<nbPoints; ii++)
  {
    
    //int idxcol =  MIN(nbColonnes-1, floor( (stackP3DSph.stackPoints3D[ii].x-_mySphericBounds.phiMin)/(stepMedianPhi/_stepCoeff)) );

    
    idxcol =  MIN(nbColonnes-1, floor( (stackP3DSph.stackPoints3D[ii].x-_mySphericBounds.phiMin)/(stepMedianPhi/stepCoeffAdaptionPhi)) );      

    //int idxrow = MIN(nbLignes-1,floor((stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/(stepMedianTheta/_stepCoeff)));
    
    idxrow = MIN(nbLignes-1,floor((stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/(stepMedianTheta/stepCoeffAdaptionTheta)));
    
    
    
    //int idxRowFloor = floor( ((stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/stepMedianTheta/_stepCoeff) );
     int idxRowFloor = floor( ((stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/stepMedianTheta/stepCoeffAdaptionPhi) );
    
    

   int positif_idxRowFloor;
   int flagMappedOnce = 0;
   int flagCorrected = 0; 
   if( (idxRowFloor<0) && (flagMappedOnce==0)  ) {
                
     positif_idxRowFloor = abs(idxRowFloor);
     //printf("pt %d %d %d\n", ii, positif_idxRowFloor, idxCol);
     //myImage2Laser.intensity[positif_idxRowFloor*nbColonnes + idxcol] = 255;                  
     //flagMappedOnce =1;
     flagCorrected=1;
   }

    // test if outside the image 

    if( (idxrow>=0) && (idxrow < nbLignes) && (idxcol >=0) && (idxcol< nbColonnes) )
      {
       //myImage2Laser.intensity[idxrow*nbColonnes + idxcol]=0; 
       
       myImage2Laser.intensity[idxrow*nbColonnes + idxcol] =floor(normalized_depth[ii]);
       
       //myImage2Laser.dDepthImage[idxrow*nbColonnes+idxcol] = (float)(stackP3DSph.stackPoints3D[ii].z);
       myImage2Laser.dDepthImage[idxrow*nbColonnes+idxcol]= (float)(stackP3DMeshCartez.stackPoints3D[ii].z);      
        

     ///!\/!\/!\ ICI AJOUT DANS LE FICHIER DES COORD DE WKS !!!
       //NON BINARY :
       fprintf(fileImageVector, "%d %d",idxcol, idxrow);
       //BINARY :
       //fwrite(&idxcol, sizeof(int), 1, fileImageVector);
       //fwrite(&idxrow, sizeof(int), 1, fileImageVector);

       //printf("ii : %d idxCol : %d idxRw : %d et nb : %d %d  \n", ii, idxcol, idxrow, nbColonnes, nbLignes);
       
	 //METTRE LA TAILLE DU VECTEUR WKS ICI, on ajoute le vecteur, si on souhaite que ce qui est entre 30 et 80 on doit lajotuer a la main 
	 for(int idxDesc = SIZE_MIN_WKS; idxDesc < SIZE_MAX_WKS; idxDesc++)
	   {
	     //NON BINARY :
	    fprintf(fileImageVector, " %f", arrCurv[ii*SIZE_DESC_WKS+idxDesc]);
	     //BINARY (ICI ON REPREND l'IDéE D'UNE ECRITURE NON BINAIRE, ON POURRAIS JSUTE FAIRE fwrite(arrCurv, sizeof(float), nbPoints, fileImageVector mais ça demande trop de modif pour le moment) :
	    // fwrite(&(arrCurv[ii*SIZE_DESC_WKS+idxDesc]), sizeof(float), 1, fileImageVector);
	      
	     if(arrCurv[ii*SIZE_DESC_WKS+idxDesc] != arrCurv[ii*SIZE_DESC_WKS+idxDesc])
	       printf("%f et %d \n",arrCurv[ii*SIZE_DESC_WKS+idxDesc], ii*SIZE_DESC_WKS+idxDesc);
	   }
	 //NON BINARY :
	  fprintf(fileImageVector, "\n");

     
   
     countPixInside++;

      // sur ce qui sont inside, s'il y a des doublons
      if(stackPoint3DSph_Inside[ii] == 0){
                                           stackPoint3DSph_Inside[ii]+=1;  // inside several times ??
                                           //stack the index of the pixel location
                                           stackRows[ii] = (idxrow*nbColonnes+idxcol);
                                           if(stackPoint3DSph_Inside[ii]==1)
                                            { // on map une seule fois 
                                             //myImage2Laser.intensity[idxrow*nbColonnes + idxcol] = floor(normalized_depth[ii]);

                                            }
                                           } 

                                           
                                         
                                    
      }
   else{
        countPixOutside++;
         stackIdxPointOutside[ii] = ii; 
        // take idxCoor3D take ii index 
         //fprintf(fileCartezOutside, "%f %f %f\n",stackP3DCartezIN.stackPoints3D[ii].x,
// stackP3DCartezIN.stackPoints3D[ii].y,stackP3DCartezIN.stackPoints3D[ii].z); 

       //  check here why idxrow is negative 
          double idxRowRecomputed = floor( ( (stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/stepMedianTheta ) ) ;
          

 //( (stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin)/stepMedianTheta) ) 
          double diff = stackP3DSph.stackPoints3D[ii].y-_mySphericBounds.thetaMin;
          double inv_diff = _mySphericBounds.thetaMin - stackP3DSph.stackPoints3D[ii].y;



       }


  }



  /*AJOUTE LES TRIANGLES au fichier*/
  printf("Ajout des triangles au fichier \n");
  
  //NON BINARY :
  fprintf(fileImageVector, "POLYGONS %d %d\n", sphTriIO->numberoftriangles, 4*sphTriIO->numberoftriangles);
  //BINARY :
  // fwrite(&(sphTriIO->numberoftriangles), sizeof(int), 1, fileImageVector);
  //int fourTimeNbTri = 4*sphTriIO->numberoftriangles;
  // fwrite(&fourTimeNbTri, sizeof(int), 1, fileImageVector);
  
  jj=0;
  char isInBound = 1;
  for(ii=0; ii<sphTriIO->numberoftriangles; ii++)
    {
      isInBound = 1;
      for(jj = 0; jj < 3; jj++)
	{
	  idxcol =  MIN(nbColonnes-1, floor( (stackP3DSph.stackPoints3D[sphTriIO->trianglelist[3*ii+jj]].x-_mySphericBounds.phiMin)/(stepMedianPhi/stepCoeffAdaptionPhi)) );      


	  idxrow = MIN(nbLignes-1,floor((stackP3DSph.stackPoints3D[sphTriIO->trianglelist[3*ii+jj]].y-_mySphericBounds.thetaMin)/(stepMedianTheta/stepCoeffAdaptionTheta)));

	    if( (idxrow<0) || (idxrow >= nbLignes) || (idxcol < 0) || (idxcol >= nbColonnes) )
	      {
		isInBound = 0;
	      }


	}

      if( isInBound == 1 )
	{


	  int trois = 3;

	  //NON BINARY :
	   fprintf(fileImageVector, "3 %d %d %d\n",sphTriIO->trianglelist[3*ii+0] , sphTriIO->trianglelist[3*ii+1],sphTriIO->trianglelist[3*ii+2] );
	  //BINARY :
	  // fwrite(&trois, sizeof(int), 1, fileImageVector);
	  // fwrite(&(sphTriIO->trianglelist[3*ii+0]), sizeof(int), 1, fileImageVector);
	  //fwrite(&(sphTriIO->trianglelist[3*ii+1]), sizeof(int), 1, fileImageVector);
	  //fwrite(&(sphTriIO->trianglelist[3*ii+2]), sizeof(int), 1, fileImageVector);
	  

	}
    }

  gettimeofday(&tEnd, NULL);

  printf("Time saving file (milliseconds) : (%ld - %ld)  %ld  \n",tEnd.tv_usec, tBegin.tv_usec, ((tEnd.tv_usec - tBegin.tv_usec) / 1000));

  fclose(fileImageVector);
  
  //pour les triangles directement du vtk sph
  /*
    jj=0;
  char isInBound = 1;
  for(ii=0; ii<sizeTrianglesList; ii++)
    {
      // printf("%d %d %d \n", 3*ii, trianglesList[3*ii], nbPoints, sizeTrianglesList);
      isInBound = 1;
      for(jj = 0; jj < 3; jj++)
	{
	  if(trianglesList[3*ii+jj] < nbPoints)
	    {
	  idxcol =  MIN(nbColonnes-1, floor( (stackP3DSph.stackPoints3D[trianglesList[3*ii+jj]].x-_mySphericBounds.phiMin)/(stepMedianPhi/stepCoeffAdaptionPhi)) );      


	  idxrow = MIN(nbLignes-1,floor((stackP3DSph.stackPoints3D[trianglesList[3*ii+jj]].y-_mySphericBounds.thetaMin)/(stepMedianTheta/stepCoeffAdaptionTheta)));

	  if( (idxrow<0) || (idxrow >= nbLignes) || (idxcol < 0) || (idxcol >= nbColonnes) )
	      {
		isInBound = 0;
	      }
	    }
	  else
	    {
	      isInBound = 0;
	    }

	}

      if( isInBound == 1 )
	{


	  fprintf(fileImageVector, "3 %d %d %d\n", trianglesList[3*ii+0] , trianglesList[3*ii+1], trianglesList[3*ii+2] ); 


	}
	}*/


    
  


  free(depthTri); free(depthTri_OffSet); free(depthTri_OffSetFine);
  free(newDepth); free(normalized_depth);
  free(stackColonnes); free(stackRows);

  free(myImage2Laser.intensity);
  free(myImage2Laser.dDepthImage);

  
  free(sphTriIO->pointlist);
  free(sphTriIO->pointattributelist);
  free(sphTriIO);
  
  free(stackPoint3DSph_Inside);
  free(stackCountSamePixInner);
  free(stackIdxPointCoincident);
  free(stackIdxPointOutside); 

  
   free(imgLowRes1);
  //free(PixOccurenceSameRow);
  //free(PixOccurenceSameCol);

  return myImage2Laser;
  
}
////////////////////// 14 Mars 2016 Elevation 



/////////////////////// 27 Oct
double Diff_Images(unsigned char *imageModel, unsigned char *imageTarget, int nbCol, int nbRows)
{
  
  double score=0.0;
  int index_image;
  // use a mask here
  
  for(index_image=0; index_image<nbCol*nbRows; index_image++)
  {
   score+= abs(imageModel[index_image] - imageTarget[index_image]); 
  }
  score /=(nbCol*nbRows);
  printf("similarity score %f\n", score);
  
  return score;
}



/// 1 Oct 2015 CNAM


void initQUnit(qunit *qu)
{qu->q[0]=0.0;
 qu->q[1]=0.0;
 qu->q[2]=0.0;
 qu->q[3]=0.0;
}

void displayQUnit(qunit qu)
{printf("qunit\n %f %f %f %f \n", qu.q[0],qu.q[1],qu.q[2],qu.q[3]);

}




void initRotation(Rotation *R)
{
 R->mat[0]=1.0;
 R->mat[1]=0.0;
 R->mat[2]=0.0;
 R->mat[3]=0.0;
 R->mat[4]=1.0;
 R->mat[5]=0.0;
 R->mat[6]=0.0;
 R->mat[7]=0.0;
 R->mat[8]=1.0;
 
}


void initAxis(axis *N)
{ // X 001 en col 
  N->n[0]=0;
  N->n[1]=0;
  N->n[2]=1;
}


// 5 Oct 2015
void initAxisFromUserValues(axis *N, float Nx, float Ny, float Nz )
{ 
  N->n[0]=Nx;
  N->n[1]=Ny;
  N->n[2]=Nz;
}



// this is for tacking arbitrary axes for the rotation 
void initAxisVect(axis *N/*,TPoint3D <double> VectRot*/)
{ /*Z_axis n=(0,0,1)*/
  /*N->n[0]=VectRot.x;
  N->n[1]=VectRot.y;
  N->n[2]=VectRot.z;*/
  
}


void displayRotation( Rotation R)
 {
  printf("Matrix:\n %f %f %f \n %f %f %f \n %f %f %f \n", R.mat[0], R.mat[1], R.mat[2],R.mat[3],R.mat[4], R.mat[5],R.mat[6],R.mat[7],R.mat[8]);
 }


void Quaternion2R(qunit q,Rotation *R)
{
 //printf (" Quaternion2R: %f %f %f %f \n",q.q[0],q.q[1],q.q[2],q.q[3],q.q[4]);
 R->mat[0]=(q.q[0]*q.q[0])+(q.q[1]*q.q[1])-(q.q[2]*q.q[2])-(q.q[3]*q.q[3]);
 R->mat[1]=2*((q.q[1]*q.q[2])-(q.q[0]*q.q[3]));
 R->mat[2]=2*((q.q[1]*q.q[3])+(q.q[0]*q.q[2]));
 R->mat[3]=2*((q.q[1]*q.q[2])+(q.q[0]*q.q[3]));
 R->mat[4]=(q.q[0]*q.q[0])-(q.q[1]*q.q[1])+(q.q[2]*q.q[2])-(q.q[3]*q.q[3]);
 R->mat[5]=2*((q.q[2]*q.q[3])-(q.q[0]*q.q[1]));
 R->mat[6]=2*((q.q[1]*q.q[3])-(q.q[0]*q.q[2]));
 R->mat[7]=2*((q.q[2]*q.q[3])+(q.q[0]*q.q[1]));
 R->mat[8]=(q.q[0]*q.q[0])-(q.q[1]*q.q[1])-(q.q[2]*q.q[2])+(q.q[3]*q.q[3]);
 //displayRotation(R);
}

////////////////////////////////////////////////////////////////////////////////
// 1 Oct 2015
////////////////////////////////////////////////////////////////////////////////
void RotateCloud_SG_CC(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser)
{

 printf("CNAM 1Oct 15: RotateCloud procedure begin \n"); 


  /*initialisation stuff*/
  Rotation* Rot=(Rotation *)malloc(9*sizeof(float));
  initRotation(Rot); // this puts all to the [I] 3 x 3 matrix 
  displayRotation(Rot[0]); 
  qunit* qUnit=(qunit*)malloc(4*sizeof(double));
  initQUnit(qUnit);
  displayQUnit(qUnit[0]);
  axis* NRot=(axis*)malloc(3*sizeof(double));
  initAxis(NRot);
  // initAxisVect(NRox, VectRot); // when (row, col) => vect de rotation affected to the axis 
  
  double AngleDegrees = 90; double AngleRadians = (M_PI*AngleDegrees)/180; 
   

   qUnit->q[0]=cos((AngleRadians/2));
   qUnit->q[1]=sin((AngleRadians/2))*NRot->n[0];
   qUnit->q[2]=sin((AngleRadians/2))*NRot->n[1];
   qUnit->q[3]=sin((AngleRadians/2))*NRot->n[2];
   
   displayQUnit(qUnit[0]);

   double normeQuaternion =sqrt( (qUnit->q[0]*qUnit->q[0]) + (qUnit->q[1]*qUnit->q[1]) + (qUnit->q[2]*qUnit->q[2]) +(qUnit->q[3]*qUnit->q[3]) );  
   printf("norm quaternion %f \n", normeQuaternion);

    
   // when the axis is not unitary, normalize the quaternion to 1 
   // compute the rotation matrix 
  
   Quaternion2R(qUnit[0], Rot);
   displayRotation(Rot[0]);


   /*appliquer la rotation aux coord en cartez*/

   p3D stackP3DRotated;
   stackP3DRotated.sizeStackPoints3D = _nbPointsCartez; 
   stackP3DRotated.stackPoints3D = (point3D *)malloc(_nbPointsCartez*sizeof(point3D)); 

   
  FILE *fileCartezRotatedCloud; 
  FILE *fileSphRotatedCloud;


  if( (fileCartezRotatedCloud = fopen("1brsA_CartezRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_CartezRotatedCloud.asc");
      exit(-1);
    }
  
 if( (fileSphRotatedCloud = fopen("1brsA_SphRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_SphRotatedCloud.asc");
      exit(-1);
    }

    
   unsigned int p; 
   for (p=0;p<_nbPointsCartez;p++)
      { 
        
        
        stackP3DRotated.stackPoints3D[p].x=Rot->mat[0]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[1]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[2]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].y=Rot->mat[3]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[4]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[5]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].z=Rot->mat[6]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[7]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[8]*_stackP3DCartezIN.stackPoints3D[p].z;
        // recover the color 
        
        stackP3DRotated.stackPoints3D[p].Red =_stackP3DCartezIN.stackPoints3D[p].Red;
        stackP3DRotated.stackPoints3D[p].Green = _stackP3DCartezIN.stackPoints3D[p].Green; 
        stackP3DRotated.stackPoints3D[p].Blue= _stackP3DCartezIN.stackPoints3D[p].Blue;
        
        fprintf(fileCartezRotatedCloud,"%f %f %f %d %d %d\n",stackP3DRotated.stackPoints3D[p].x, stackP3DRotated.stackPoints3D[p].y, stackP3DRotated.stackPoints3D[p].z, stackP3DRotated.stackPoints3D[p].Red, stackP3DRotated.stackPoints3D[p].Green, stackP3DRotated.stackPoints3D[p].Blue);   
        
        //printf("point %d transforme de %f\n",p,AngleDegrees);
       }
 
  
  int flagRGB=1; 
  p3D stackP3DSphRotated = stackCartezian2Spheric(stackP3DRotated, _nbPointsCartez, flagRGB);
  printf("Rotate CG_CC: Spherical conversion done ...\n");  
  
  //double xCol_Estimated = 0.0, yRow_Estimated = 0.0; 

  // the size of the old image
  // the angular step, MinMax Resolution


  /*typedef struct{
               unsigned char *intensity;
               double *dDepthImage;
               //added 25 Sept 2015
               float *fDepthImageTrueRo; 
               //float *dDepthImage;
               double *sphAzimuthX; //Phi, col
               double *sphZenithY;  //zenith, row
               int nbRows;
               int nbCols;
               float *cartezX;
               float *cartezY;
               float *cartezZ;
               double azimuthStep; // here median value is taken
               double zenithStep;  // median value is taken
               // on a pas RGB, il faut rajouter */


  int nbColonnes = _myImage2Laser.nbCols;
  int nbLignes= _myImage2Laser.nbRows;


  unsigned char *imgDepthIntEstimate =(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char));
  

 for(p=0; p<nbColonnes*nbLignes; p++)
   {
     imgDepthIntEstimate[p] = 0;
   }

  
   int countPixOK = 0;
  for(p=0; p<_nbPointsCartez; p++)
   {
     fprintf(fileSphRotatedCloud,"%f %f %f %d %d %d\n",stackP3DSphRotated.stackPoints3D[p].x, stackP3DSphRotated.stackPoints3D[p].y, stackP3DSphRotated.stackPoints3D[p].z, stackP3DSphRotated.stackPoints3D[p].Red, stackP3DSphRotated.stackPoints3D[p].Green, stackP3DSphRotated.stackPoints3D[p].Blue);  

    // within the same loop, take the angular step and compute the corresponding image coordinates

      //int xColEstimate =  MIN(nbColonnes-1, floor( (stackP3DSphRotated.stackPoints3D[p].x-_mySphericBounds.phiMin)/_myImage2Laser.azimuthStep) );
      //int yRowEstimate = MIN(nbLignes-1,floor(abs(stackP3DSphRotated.stackPoints3D[p].y-_mySphericBounds.thetaMin)/_myImage2Laser.zenithStep));
      float xColEstimate =  (stackP3DSphRotated.stackPoints3D[p].x-_mySphericBounds.phiMin)/_myImage2Laser.azimuthStep;
      float yRowEstimate = (stackP3DSphRotated.stackPoints3D[p].y-_mySphericBounds.thetaMin)/_myImage2Laser.zenithStep;
      // printf("step %f %f col %d %d \n", _myImage2Laser.azimuthStep,_myImage2Laser.zenithStep, xColEstimate,yRowEstimate);
     
      // test to see if outside of the image  
      if ((xColEstimate >= 0 ) && ( xColEstimate <= nbColonnes) && (yRowEstimate >=0) && (yRowEstimate <= nbLignes) )
       {
         
          int idxColEstimate = (int) (xColEstimate);  int idxRowEstimate = (int) yRowEstimate; 
          printf("p %d %f %d %f %d\n", p, xColEstimate, idxColEstimate, yRowEstimate, idxRowEstimate);

          // intensity must be the depth image in int 
          imgDepthIntEstimate[idxRowEstimate*nbColonnes + idxColEstimate] = _myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];

          // 255; //_myImage2Laser.intensity[xColEstimate*nbColonnes+yRowEstimate];
          countPixOK++; 
       }
    
      
   }
   char *fileNameEstimateImage = "1brsA_EstimateImage.pgm";
   
   pgmWriteFile(fileNameEstimateImage,imgDepthIntEstimate, nbColonnes, nbLignes);
   printf("pixel ok %d \n", countPixOK); 

   // compute image coordinates of the transformed points 
   // take the corresponding pixel from the reference image, tacking the same bounds 

   // write red channal with reference image, green channel with the transformed image 
    


   /////////////////////
   /// save the cloud in ascii format 
   ////////////////////////

   fclose(fileCartezRotatedCloud); fclose(fileSphRotatedCloud);
   
   free(Rot); free(qUnit); free (NRot);
   // we have to recover this 
   free(stackP3DRotated.stackPoints3D);
   free(stackP3DSphRotated.stackPoints3D);

   free(imgDepthIntEstimate); 
  
}


/**************************************/
///////////////////////////////////////////////////

////////////// 2 Oct 2015

//// void RotateCloud_SG_CC(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser)
void RotateCloud_SG_CC_2_SphericImage(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser, char *nameImageFileEstimated)
{



  printf("Rotate Cloud 2 SphericImage ..\n"); 
  
  axis* NRot=(axis*)malloc(3*sizeof(double));
  float axisX =0., axisY=1., axisZ=0.;
  initAxisFromUserValues(NRot, axisX, axisY, axisZ);
  printf("axis %f %f %f\n", NRot->n[0], NRot->n[1], NRot->n[2]);
  int ii; 
  int nbColonnes = _myImage2Laser.nbCols;
  int nbLignes= _myImage2Laser.nbRows;
  unsigned char *imgInt=(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char));
 unsigned char *imgBlue=(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char));
  
  for(ii=0; ii<(nbColonnes*nbLignes); ii++)
   {
     
     imgInt[ii]=0; // this is where we put the estimated image , depth coord in int values for the moment, this is the green channel
     imgBlue[ii] =0;
   }



   // not now pgmWriteFile(nameImageFileEstimated, imgInt, nbColonnes, nbLignes);
   // write two channel with ImgInt - green, ImgIntRef - red channel 


 ///////////////////////////////////////////////////////

  

  /*initialisation stuff*/
  Rotation* Rot=(Rotation *)malloc(9*sizeof(float));
  initRotation(Rot); // this puts all to the [I] 3 x 3 matrix 
  displayRotation(Rot[0]); 
  qunit* qUnit=(qunit*)malloc(4*sizeof(double));
  initQUnit(qUnit);
  displayQUnit(qUnit[0]);
  //axis* NRot=(axis*)malloc(3*sizeof(double));
  //initAxis(NRot);
  // initAxisVect(NRox, VectRot); // when (row, col) => vect de rotation affected to the axis 
  
  double AngleDegrees = 90; double AngleRadians = (M_PI*AngleDegrees)/180; 
   

   qUnit->q[0]=cos((AngleRadians/2));
   qUnit->q[1]=sin((AngleRadians/2))*NRot->n[0];
   qUnit->q[2]=sin((AngleRadians/2))*NRot->n[1];
   qUnit->q[3]=sin((AngleRadians/2))*NRot->n[2];
   
   displayQUnit(qUnit[0]);

   double normeQuaternion =sqrt( (qUnit->q[0]*qUnit->q[0]) + (qUnit->q[1]*qUnit->q[1]) + (qUnit->q[2]*qUnit->q[2]) +(qUnit->q[3]*qUnit->q[3]) );  
   printf("norm quaternion %f \n", normeQuaternion);

    
   // when the axis is not unitary, normalize the quaternion to 1 
   // compute the rotation matrix 
  
   Quaternion2R(qUnit[0], Rot);
   displayRotation(Rot[0]);


   //appliquer la rotation aux coord en cartez

   p3D stackP3DRotated;
   stackP3DRotated.sizeStackPoints3D = _nbPointsCartez; 
   stackP3DRotated.stackPoints3D = (point3D *)malloc(_nbPointsCartez*sizeof(point3D)); 

   
  /*FILE *fileCartezRotatedCloud; 
  FILE *fileSphRotatedCloud;


  if( (fileCartezRotatedCloud = fopen("1brsA_CartezRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_CartezRotatedCloud.asc");
      exit(-1);
    }
  
 if( (fileSphRotatedCloud = fopen("1brsA_SphRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_SphRotatedCloud.asc");
      exit(-1);
    } out for the moment */ 

    
   unsigned int p; 
   for (p=0;p<_nbPointsCartez;p++)
      { 
        
        
        stackP3DRotated.stackPoints3D[p].x=Rot->mat[0]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[1]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[2]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].y=Rot->mat[3]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[4]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[5]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].z=Rot->mat[6]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[7]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[8]*_stackP3DCartezIN.stackPoints3D[p].z;
        // recover the color 
        
        stackP3DRotated.stackPoints3D[p].Red =_stackP3DCartezIN.stackPoints3D[p].Red;
        stackP3DRotated.stackPoints3D[p].Green = _stackP3DCartezIN.stackPoints3D[p].Green; 
        stackP3DRotated.stackPoints3D[p].Blue= _stackP3DCartezIN.stackPoints3D[p].Blue;
        
       // fprintf(fileCartezRotatedCloud,"%f %f %f %d %d %d\n",stackP3DRotated.stackPoints3D[p].x, stackP3DRotated.stackPoints3D[p].y, stackP3DRotated.stackPoints3D[p].z, stackP3DRotated.stackPoints3D[p].Red, stackP3DRotated.stackPoints3D[p].Green, stackP3DRotated.stackPoints3D[p].Blue);   
        
        //printf("point %d transforme de %f\n",p,AngleDegrees);
       }

  
  int flagRGB=1; 
  p3D stackP3DSphRotated = stackCartezian2Spheric(stackP3DRotated, _nbPointsCartez, flagRGB);
  printf("Rotate CG_CC: Spherical conversion done ...\n");  
  
  
  /*unsigned char *imgDepthIntEstimate =(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char)); 
  

 for(p=0; p<nbColonnes*nbLignes; p++)
   {
     imgDepthIntEstimate[p] = 0;
   }*/

  
   int countPixOK = 0;
  for(p=0; p<_nbPointsCartez; p++)
   {
     //fprintf(fileSphRotatedCloud,"%f %f %f %d %d %d\n",stackP3DSphRotated.stackPoints3D[p].x, stackP3DSphRotated.stackPoints3D[p].y, stackP3DSphRotated.stackPoints3D[p].z, stackP3DSphRotated.stackPoints3D[p].Red, stackP3DSphRotated.stackPoints3D[p].Green, stackP3DSphRotated.stackPoints3D[p].Blue);  

    // within the same loop, take the angular step and compute the corresponding image coordinates

      float xColEstimate =  (stackP3DSphRotated.stackPoints3D[p].x-_mySphericBounds.phiMin)/_myImage2Laser.azimuthStep;
      float yRowEstimate = (stackP3DSphRotated.stackPoints3D[p].y-_mySphericBounds.thetaMin)/_myImage2Laser.zenithStep;
      // printf("step %f %f col %d %d \n", _myImage2Laser.azimuthStep,_myImage2Laser.zenithStep, xColEstimate,yRowEstimate);
     
      // test to see if outside of the image  
      if ((xColEstimate >= 0 ) && ( xColEstimate <= nbColonnes) && (yRowEstimate >=0) && (yRowEstimate <= nbLignes) )
       {
         
          int idxColEstimate = (int) (xColEstimate);  int idxRowEstimate = (int) yRowEstimate; 
          printf("p %d %f %d %f %d\n", p, xColEstimate, idxColEstimate, yRowEstimate, idxRowEstimate);

          // intensity must be the depth image in int 
          //imgDepthIntEstimate[idxRowEstimate*nbColonnes + idxColEstimate] = _myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];
          imgInt[idxRowEstimate*nbColonnes + idxColEstimate] = _myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];
          // 255; //_myImage2Laser.intensity[xColEstimate*nbColonnes+yRowEstimate];
          countPixOK++; 
       }
    
      
   }
   char *fileNameEstimateImage = "1brsA_EstimateSuperposed.pgm";
   
   //pgmWriteFile(fileNameEstimateImage,imgDepthIntEstimate, nbColonnes, nbLignes);
  //pgmWriteFile(nameImageFileEstimated, /*imgInt*/_myImage2Laser.intensity, imgInt, nbColonnes, nbLignes);
  
  ppmWriteFileRGB(fileNameEstimateImage,_myImage2Laser.intensity, imgInt, imgBlue, nbColonnes,nbLignes);
  
   printf("pixel ok %d \n", countPixOK); 

   // compute image coordinates of the transformed points 
   // take the corresponding pixel from the reference image, tacking the same bounds 

   // write red channal with reference image, green channel with the transformed image 
    


   /////////////////////
   /// save the cloud in ascii format 
   ////////////////////////

   //fclose(fileCartezRotatedCloud); fclose(fileSphRotatedCloud);
   
   //free(Rot); free(qUnit); free (NRot);
   // we have to recover this 
   //free(stackP3DRotated.stackPoints3D);
   //free(stackP3DSphRotated.stackPoints3D);

   //free(imgDepthIntEstimate); 
   

 ////////////////////////////////////////////////////////
  

  
 
  




  
   
   // we have to recover this 
   free(stackP3DRotated.stackPoints3D);
   free(stackP3DSphRotated.stackPoints3D);

  free(NRot); free(Rot); free(qUnit); 
  free(imgInt); free(imgBlue);
  

}

///////////////////////////////////////////////////////////////////////////////////
void CD_ppmWriteFileRGB( char *fname, 
  unsigned char *redimg,
  unsigned char *greenimg,
  unsigned char *blueimg,
  int ncols, 
  int nrows)
{
 ppmWriteFileRGB(fname,redimg, greenimg, blueimg, ncols,nrows);

}
///////////////////////////////////////////////////////////////////////////////////

////////////////////5 Octobre 2015 ////Begin/////////////
void RotateCloud_SG_CC_2_SphericImage_AngleLooping(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser, char *nameImageFileEstimated, double angleDegrees)
{



  printf("Rotate Cloud 2 SphericImage ..\n"); 
  
  axis* NRot=(axis*)malloc(3*sizeof(double));

  // replace this with hard values   

  //float axisX =0, axisY=0, axisZ=1;
  //float axisX =0, axisY=1, axisZ=0;
  //float axisX =1, axisY=0, axisZ=0;
  float axisX =0, axisY=1, axisZ=0; 
  initAxisFromUserValues(NRot, axisX, axisY, axisZ);
  

  printf("axis %f %f %f\n", NRot->n[0], NRot->n[1], NRot->n[2]);
  int ii; 
  int nbColonnes = _myImage2Laser.nbCols;
  int nbLignes= _myImage2Laser.nbRows;
  unsigned char *imgInt=(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char));
  unsigned char *imgBlue=(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char));
  _myImage2Laser.intensityEstimate = (unsigned char *)malloc(nbLignes*nbColonnes*sizeof(unsigned char)); 

  for(ii=0; ii<(nbColonnes*nbLignes); ii++)
   {
     
     imgInt[ii]=0; // this is where we put the estimated image , depth coord in int values for the moment, this is the green channel
     imgBlue[ii] =0;
     _myImage2Laser.intensityEstimate[ii] = 0;
   }



   // not now pgmWriteFile(nameImageFileEstimated, imgInt, nbColonnes, nbLignes);
   // write two channel with ImgInt - green, ImgIntRef - red channel 


 ///////////////////////////////////////////////////////

  

  /*initialisation stuff*/
  Rotation* Rot=(Rotation *)malloc(9*sizeof(float));
  initRotation(Rot); // this puts all to the [I] 3 x 3 matrix 
  displayRotation(Rot[0]); 
  qunit* qUnit=(qunit*)malloc(4*sizeof(double));
  initQUnit(qUnit);
  displayQUnit(qUnit[0]);
  //axis* NRot=(axis*)malloc(3*sizeof(double));
  //initAxis(NRot);
  // initAxisVect(NRox, VectRot); // when (row, col) => vect de rotation affected to the axis 
  
  double AngleDegrees = angleDegrees; 
  double AngleRadians = (M_PI*AngleDegrees)/180; 
   

   qUnit->q[0]=cos((AngleRadians/2));
   qUnit->q[1]=sin((AngleRadians/2))*NRot->n[0];
   qUnit->q[2]=sin((AngleRadians/2))*NRot->n[1];
   qUnit->q[3]=sin((AngleRadians/2))*NRot->n[2];
   
   displayQUnit(qUnit[0]);

   double normeQuaternion =sqrt( (qUnit->q[0]*qUnit->q[0]) + (qUnit->q[1]*qUnit->q[1]) + (qUnit->q[2]*qUnit->q[2]) +(qUnit->q[3]*qUnit->q[3]) );  
   printf("norm quaternion %f \n", normeQuaternion);

    
   // when the axis is not unitary, normalize the quaternion to 1 
   // compute the rotation matrix 
  
   Quaternion2R(qUnit[0], Rot);
   displayRotation(Rot[0]);


   //appliquer la rotation aux coord en cartez

   p3D stackP3DRotated;
   stackP3DRotated.sizeStackPoints3D = _nbPointsCartez; 
   stackP3DRotated.stackPoints3D = (point3D *)malloc(_nbPointsCartez*sizeof(point3D)); 

   
  /*FILE *fileCartezRotatedCloud; 
  FILE *fileSphRotatedCloud;


  if( (fileCartezRotatedCloud = fopen("1brsA_CartezRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_CartezRotatedCloud.asc");
      exit(-1);
    }
  
 if( (fileSphRotatedCloud = fopen("1brsA_SphRotatedCloud.asc", "w") ) == NULL)
    {
      fprintf(stderr, "\n erreur: ouverture de fichier %s sauvegarde impossible\n", "1brsA_SphRotatedCloud.asc");
      exit(-1);
    } out for the moment */ 

    
   unsigned int p; 
   for (p=0;p<_nbPointsCartez;p++)
      { 
        
        
        stackP3DRotated.stackPoints3D[p].x=Rot->mat[0]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[1]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[2]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].y=Rot->mat[3]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[4]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[5]*_stackP3DCartezIN.stackPoints3D[p].z;
        stackP3DRotated.stackPoints3D[p].z=Rot->mat[6]*_stackP3DCartezIN.stackPoints3D[p].x+Rot->mat[7]*_stackP3DCartezIN.stackPoints3D[p].y+Rot->mat[8]*_stackP3DCartezIN.stackPoints3D[p].z;
        // recover the color 
        
        stackP3DRotated.stackPoints3D[p].Red =_stackP3DCartezIN.stackPoints3D[p].Red;
        stackP3DRotated.stackPoints3D[p].Green = _stackP3DCartezIN.stackPoints3D[p].Green; 
        stackP3DRotated.stackPoints3D[p].Blue= _stackP3DCartezIN.stackPoints3D[p].Blue;
        
       // fprintf(fileCartezRotatedCloud,"%f %f %f %d %d %d\n",stackP3DRotated.stackPoints3D[p].x, stackP3DRotated.stackPoints3D[p].y, stackP3DRotated.stackPoints3D[p].z, stackP3DRotated.stackPoints3D[p].Red, stackP3DRotated.stackPoints3D[p].Green, stackP3DRotated.stackPoints3D[p].Blue);   
        
        //printf("point %d transforme de %f\n",p,AngleDegrees);
       }

  
  int flagRGB=1; 
  p3D stackP3DSphRotated = stackCartezian2Spheric(stackP3DRotated, _nbPointsCartez, flagRGB);
  printf("Rotate CG_CC: Spherical conversion done ...\n");  
  
  
  /*unsigned char *imgDepthIntEstimate =(unsigned char *)malloc(nbColonnes*nbLignes*sizeof(unsigned char)); 
  

 for(p=0; p<nbColonnes*nbLignes; p++)
   {
     imgDepthIntEstimate[p] = 0;
   }*/

  
   int countPixOK = 0;
  for(p=0; p<_nbPointsCartez; p++)
   {
     
      float xColEstimate =  (stackP3DSphRotated.stackPoints3D[p].x-_mySphericBounds.phiMin)/_myImage2Laser.azimuthStep;
      float yRowEstimate = (stackP3DSphRotated.stackPoints3D[p].y-_mySphericBounds.thetaMin)/_myImage2Laser.zenithStep;
      // printf("step %f %f col %d %d \n", _myImage2Laser.azimuthStep,_myImage2Laser.zenithStep, xColEstimate,yRowEstimate);
     
      // test to see if outside of the image  
      if ((xColEstimate >= 0 ) && ( xColEstimate <= nbColonnes) && (yRowEstimate >=0) && (yRowEstimate <= nbLignes) )
       {
         
          int idxColEstimate = (int) (xColEstimate);  int idxRowEstimate = (int) yRowEstimate; 
          //printf("p %d %f %d %f %d\n", p, xColEstimate, idxColEstimate, yRowEstimate, idxRowEstimate);

          // intensity must be the depth image in int 
          //imgDepthIntEstimate[idxRowEstimate*nbColonnes + idxColEstimate] = _myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];
          imgInt[idxRowEstimate*nbColonnes + idxColEstimate] = _myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];
          _myImage2Laser.intensityEstimate[idxRowEstimate*nbColonnes + idxColEstimate]=_myImage2Laser.intensity[idxRowEstimate*nbColonnes + idxColEstimate];
          
          countPixOK++; 
       }
    
      
   }
   //char *fileNameEstimateImage = "1brsA_EstimateSuperposed.pgm";
   
pgmWriteFile(nameImageFileEstimated,_myImage2Laser.intensityEstimate, nbColonnes, nbLignes);


   //pgmWriteFile(cstr,/*fileNameEstimateImage*/imgInt/*imgDepthIntEstimate*/, nbColonnes, nbLignes);
  //pgmWriteFile(nameImageFileEstimated, /*imgInt*/_myImage2Laser.intensity, imgInt, nbColonnes, nbLignes);
  
  //ppmWriteFileRGB(fileNameEstimateImage,_myImage2Laser.intensity, imgInt, imgBlue, nbColonnes,nbLignes);
  
   printf("pixel ok %d \n", countPixOK); 

   // compute image coordinates of the transformed points 
   // take the corresponding pixel from the reference image, tacking the same bounds 

   // write red channal with reference image, green channel with the transformed image 
    


   /////////////////////
   /// save the cloud in ascii format 
   ////////////////////////

   //fclose(fileCartezRotatedCloud); fclose(fileSphRotatedCloud);
   
   //free(Rot); free(qUnit); free (NRot);
   // we have to recover this 
   //free(stackP3DRotated.stackPoints3D);
   //free(stackP3DSphRotated.stackPoints3D);

   //free(imgDepthIntEstimate); 
   

 ////////////////////////////////////////////////////////
  
 
  
   
   // we have to recover this after 
   free(stackP3DRotated.stackPoints3D);
   free(stackP3DSphRotated.stackPoints3D);

  free(NRot); free(Rot); free(qUnit); 
  free(imgInt); free(imgBlue);
  //free(_myImage2Laser.intensityEstimate);
  

}






/**********************************************/
/* CD-Mines CAOR: July 2013: read an ASCII file from key*************/
/*and output an  outputs a stack p3D of points*/
/**********************************************/

p3D CD_readASC( )
{
   p3D pt3DXYZRGB;
   printf("read ASC file ... \n");


   char ch, file_name[25];
   FILE *fp;
 
   printf("Enter the name of file you wish to see\n");
   gets(file_name);
 
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
   printf("The contents of %s file are :\n", file_name);
   double x, y, z; 
   int length=0;
   //int count 3D; 
   int space=0;
   int newline = 0;
   while( ( ch = fgetc(fp) ) != EOF )
      {
        //printf(" length %d %c\n",length, ch);
        if (ch == ' ') space++;
        if(ch == '\n') newline++;
        //length++;
        
      }

   
  printf("spaces  %d newlines %d\n",  space, newline); 
   
  double d;
  int ok_seek = fseek(fp, 0, SEEK_SET);


  int nbTotalNumber = newline * 6; // X,Y,Z,R,G,B
   printf("nbTotalNumber %d\n", nbTotalNumber);
   int nbPts3D = newline;

   //pt3D *pointsXYZRGB; //stack here points
   
   float * pts3D;
   pts3D = (float *)malloc(nbTotalNumber*sizeof(float));
   length = 0; 
   //p3D pt3DXYZRGB;
   pt3DXYZRGB.stackPoints3D = (point3D *)malloc(newline*sizeof(point3D));
   
   //pointsXYZRGB = (pt3D *)malloc(newline*sizeof(pt3D));
   int countNb3D=0;
   while( length<nbTotalNumber )
      {
        //printf(" length %d %c\n",length, ch);
        // if (ch == ' ') n++;
        // if(ch == '\n') newline++;
        //if(ch!)count 3D++;
        //x = ch; 
        //x= (double)ch;
        //printf("double %f", x);
        // fscanf (pFile, "%f", &f);
        //if()countNb3D ==)
        fscanf(fp, "%lf", &d);
        //printf("wtf %f\n", d);
        
        pts3D[length] = d;
        length++;
        
       }

  
  printf("length %d \n", length); 
  int ii = 0;
  /*for(ii=0; ii<nbTotalNumber; ii++)
  {
    //printf("points %f %f %f %f %f %f \n", pts3D[newline], pts3D[newline+1], pts3D[newline+2], pts3D[newline+3], pts3D[newline+4], pts3D[newline+5]);
    //printf("ii %d points %f \n", ii, pts3D[ii]);
  } */
   
  int countline=0;
  for(ii=0; ii<length; ii+=6)
  {
    //printf("newline %d ii %d \n", newline, ii);
    // printf("countline %d points %d %f %d %f %d %f %d %f %d %f %d %f \n",countline, ii, pts3D[ii], ii+1, pts3D[ii+1], ii+2, pts3D[ii+2], ii+3,pts3D[ii+3], ii+4, pts3D[ii+4], ii+5, pts3D[ii+5]);
  

  pt3DXYZRGB.stackPoints3D[countline].x = pts3D[ii];
  pt3DXYZRGB.stackPoints3D[countline].y = pts3D[ii+1];
  pt3DXYZRGB.stackPoints3D[countline].z = pts3D[ii+2];
  pt3DXYZRGB.stackPoints3D[countline].Red = pts3D[ii+3];
  pt3DXYZRGB.stackPoints3D[countline].Green = pts3D[ii+4];
  pt3DXYZRGB.stackPoints3D[countline].Blue = pts3D[ii+5];
  pt3DXYZRGB.stackPoints3D[countline].index = countline;  
  

  /* pointsXYZRGB[countline].X = pts3D[ii];
  pointsXYZRGB[countline].Y = pts3D[ii+1];
  pointsXYZRGB[countline].Z = pts3D[ii+2];
  pointsXYZRGB[countline].R = pts3D[ii+3];
  pointsXYZRGB[countline].G = pts3D[ii+4];
  pointsXYZRGB[countline].B = pts3D[ii+5]; */
  //printf("countline %d \n", countline);
  countline++;
  
  
    
  }
  
  pt3DXYZRGB.sizeStackPoints3D = newline;
  fclose(fp);
  free(pts3D);

  ///////////copy this in our structure if not already done

   return pt3DXYZRGB;
}



 /*char *file_name = filenameConfCloudASC_IN;
   
   
   
   char *filenameCartez = filenameCartezCloudASC_IN; 
   
   
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   // give here the name file 
 
 
   printf("The contents of %s file are :\n", file_name);
   */



int readVTK_trianglesList(char *filename_IN, int **trianglesList )
{

   printf("read VTK file's edges \n");
   
   char *file_name = filename_IN; 

   char ch3 = 0;
   int ch, chprec = (int)' ', chprecprec = (int)' '; // file_name[25];
   long int fileSeek = 0;
   FILE *fp;
 
   //printf("Enter the name of file you wish to see\n");
   //gets(file_name);
 
   ////////////////////////////////////////////
   
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
   double x, y, z; 
   int length=0;
   //int count 3D; 
   int currentLine = 0;
   int newline = 0;
   char isLookingFirstLineTri = 1;
   while( ( ch = fgetc(fp) ) != EOF )
      {

	if(ch == (int)'\n')
	  {
	    currentLine++;
	  }
        if(ch3 == 1 && ch == (int)'\n')
	  {
	    ch3 = 0;
	    newline++;
	  }

	if(chprecprec == (int)'\n' && chprec == (int)'3' && ch == (int)' ')
	  {
	    isLookingFirstLineTri = 0;
	    ch3 = 1;
	  }
	//permet d'avoir le positionnement au debut de la ligne ou commence les triangles
	if(isLookingFirstLineTri == 1)
	  {
	    fileSeek = (ftell(fp)-1);
	  }
	
	chprecprec = chprec;
        chprec = ch;
	
      }

  
   printf("newlines %d, fileSeek : %d\n", newline, fileSeek); 
   
  int d;
  int ok_seek = fseek(fp, fileSeek, SEEK_SET);


  int nbTotalNbPtsTriangles = 3*newline; // pt1, pt2, pt3
   printf("nbTotalNumber %d\n", nbTotalNbPtsTriangles);

   *trianglesList = (int*)malloc(nbTotalNbPtsTriangles*sizeof(int));
   
  
   int countNb3D=0;
   int mod4Loop = 0;
   while( length< nbTotalNbPtsTriangles)
      {
        //printf(" length %d %c\n",length, ch);
        // if (ch == ' ') n++;
        // if(ch == '\n') newline++;
        //if(ch!)count 3D++;
        //x = ch; 
        //x= (double)ch;
        //printf("double %f", x);
        // fscanf (pFile, "%f", &f);
        //if()countNb3D ==)
        fscanf(fp, "%d", &d);
        //printf("wtf %f\n", d);

	if(mod4Loop != 0 )
	  {
	    (*trianglesList)[length] = d;
	    // printf("%d, %d \n", d, length);
	    length++;
	  }
	mod4Loop++;
	mod4Loop = mod4Loop % 4;
       }


  printf("length %d \n", length); 
  
  fclose(fp);

  //retourne le nombre de triangles
  return newline;
  
}






////14 Mars 2016 
p3D CD_readASC_filename(char *filenameCloudASC_IN )
{
   p3D pt3DXYZRGB;
   printf("read ASC file ... \n");
   
   char *file_name = filenameCloudASC_IN; 

   int ch; // file_name[25];
   FILE *fp;
 
   //printf("Enter the name of file you wish to see\n");
   //gets(file_name);
 
   ////////////////////////////////////////////
   
   fp = fopen(file_name,"r"); // read mode
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
   printf("The contents of %s file are :\n", file_name);
   double x, y, z; 
   int length=0;
   //int count 3D; 
   int space=0;
   int newline = 0;
   while( ( ch = fgetc(fp) ) != EOF )
      {
        //printf(" length %d %c\n",length, ch);
        if (ch == (int)' ') space++;
        if(ch == (int)'\n') newline++;

        
      }

  
  printf("spaces  %d newlines %d\n",  space, newline); 
   
  double d;
  int ok_seek = fseek(fp, 0, SEEK_SET);


  int nbTotalNumber = newline * 6; // X,Y,Z,R,G,B
   printf("nbTotalNumber %d\n", nbTotalNumber);
   int nbPts3D = newline;

   //pt3D *pointsXYZRGB; //stack here points
   
   float * pts3D;
   pts3D = (float *)malloc(nbTotalNumber*sizeof(float));
   length = 0; 
   //p3D pt3DXYZRGB;
   pt3DXYZRGB.stackPoints3D = (point3D *)malloc(newline*sizeof(point3D));
   
   //pointsXYZRGB = (pt3D *)malloc(newline*sizeof(pt3D));
   int countNb3D=0;
   while( length<nbTotalNumber )
      {
        //printf(" length %d %c\n",length, ch);
        // if (ch == ' ') n++;
        // if(ch == '\n') newline++;
        //if(ch!)count 3D++;
        //x = ch; 
        //x= (double)ch;
        //printf("double %f", x);
        // fscanf (pFile, "%f", &f);
        //if()countNb3D ==)
        fscanf(fp, "%lf", &d);
        //printf("wtf %f\n", d);
  
        pts3D[length] = d;
        length++;
        
       }

  
  printf("length %d \n", length); 
  int ii = 0;
  /*for(ii=0; ii<nbTotalNumber; ii++)
  {
    //printf("points %f %f %f %f %f %f \n", pts3D[newline], pts3D[newline+1], pts3D[newline+2], pts3D[newline+3], pts3D[newline+4], pts3D[newline+5]);
    //printf("ii %d points %f \n", ii, pts3D[ii]);
  } */
   
  int countline=0;
  for(ii=0; ii<length; ii+=6)
  {
    //printf("newline %d ii %d \n", newline, ii);
    // printf("points %d %f %d %f %d %f %d %f %d %f %d %f \n", ii, pts3D[ii], ii+1, pts3D[ii+1], ii+2, pts3D[ii+2], ii+3,pts3D[ii+3], ii+4, pts3D[ii+4], ii+5, pts3D[ii+5]);
  

  pt3DXYZRGB.stackPoints3D[countline].x = pts3D[ii];
  pt3DXYZRGB.stackPoints3D[countline].y = pts3D[ii+1];
  pt3DXYZRGB.stackPoints3D[countline].z = pts3D[ii+2];
  pt3DXYZRGB.stackPoints3D[countline].Red = pts3D[ii+3];
  pt3DXYZRGB.stackPoints3D[countline].Green = pts3D[ii+4];
  pt3DXYZRGB.stackPoints3D[countline].Blue = pts3D[ii+5];
  pt3DXYZRGB.stackPoints3D[countline].index = countline;  
  

  /* pointsXYZRGB[countline].X = pts3D[ii];
  pointsXYZRGB[countline].Y = pts3D[ii+1];
  pointsXYZRGB[countline].Z = pts3D[ii+2];
  pointsXYZRGB[countline].R = pts3D[ii+3];
  pointsXYZRGB[countline].G = pts3D[ii+4];
  pointsXYZRGB[countline].B = pts3D[ii+5]; */
  //printf("countline %d \n", countline);
  countline++;
  
  
    
  }
  
  pt3DXYZRGB.sizeStackPoints3D = newline;
  fclose(fp);
  free(pts3D);

  ///////////copy this in our structure if not already done

   return pt3DXYZRGB;
}




/******************************************************/
/*Routine qui genere une pyramide d'images d'Intensite*/
/******************************************************/


/*void Image2Laser*/ void triangulateStackSphericCloudCompare(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN)
{
  
   
   struct triangulateio *sphTriIO;
   sphTriIO = (struct triangulateio *)malloc(sizeof(struct triangulateio));

   sphTriIO->pointlist=NULL;
   sphTriIO->pointattributelist=NULL;
   sphTriIO->pointmarkerlist=NULL;
	sphTriIO->numberofpoints=0;
	sphTriIO->numberofpointattributes=0;

	sphTriIO->trianglelist=NULL;
	sphTriIO->triangleattributelist=NULL;
	sphTriIO->trianglearealist=NULL;
	sphTriIO->neighborlist=NULL;
	sphTriIO->numberoftriangles=0;
	sphTriIO->numberofcorners=0;
	sphTriIO->numberoftriangleattributes=0;
	sphTriIO->segmentlist=NULL;
	sphTriIO->segmentmarkerlist=NULL;
	sphTriIO->numberofsegments=0;
	sphTriIO->holelist=NULL;
	sphTriIO->numberofholes=0;
	sphTriIO->regionlist=NULL;
	sphTriIO->numberofregions=0;
	sphTriIO->edgelist=NULL;
	sphTriIO->edgemarkerlist=NULL;
	sphTriIO->normlist=NULL;
	sphTriIO->numberofedges=0;
   
   
   printf("begin initialisation %d\n", nbPoints);

   /*===========================*/
    sphTriIO->numberofpoints=nbPoints;
    sphTriIO->numberofpointattributes = 1;

   /*===========================*/

printf("nb of attributes %d\n ", sphTriIO->numberofpointattributes);


sphTriIO->pointlist = (REAL*)malloc(sphTriIO->numberofpoints*2*sizeof(REAL));
sphTriIO->pointattributelist = (REAL*)malloc(sphTriIO->numberofpoints*sphTriIO->numberofpointattributes*sizeof(REAL));


   int ii; 
   for(ii = 0; ii< nbPoints; ii++)
   {

      sphTriIO->pointlist[2*ii] = stackP3DSph.stackPoints3D[ii].x; // phi
      sphTriIO->pointlist[2*ii+1] =  stackP3DSph.stackPoints3D[ii].y; 
      sphTriIO->pointattributelist[ii]= ii; // keep the index for the moment
   }
   int is_triangulated = 0;
   printf("Finish triDT initialisation \n");
   

   /*int convex = 1;
   if(convex)*/triangulate("zN", sphTriIO,sphTriIO,NULL );
   //else triangulate("epnzs", sphTriIO, sphTriIO, NULL);
   /*int convex = 1;
   if(convex)triangulate("cepnzs", sphTriIO,sphTriIO,NULL );
   else triangulate("epnzs", sphTriIO, sphTriIO, NULL);*/
   
}


// passage aussi en xyz et trouver le smooth 



/*TriangulatePoint()
{
   
}*/

/*triangulate()
{
   
}*/

/*TriangulationInit()
{
  pointlist = NULL;
  
}*/



//#include "triangle_io.h"

//#include "laser.h"

//#pragma warning(disable:4786)


// triangulation




//Create image








