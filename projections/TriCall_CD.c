

/*#include <stdio.h>

#include "triangle.h"

//#include "triangle_io.h"

//#include "laser.h"*/


// before ds tricall.c


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*#include "triangle.h"
#include "ply.h"*/
//#include "TriIO.h"
#include "TriCall_CD.h"




// define TRILIBRARY in .cpp where is the main

//TriCall();



int TriCall(p3D _stackProj3D) {
  // call a function in another file
  
  //read_test();

  printf("D. Craciun for CAOR-ENSMP: 5 July 2013\n");
  //printf("D. Craciun: read Ply File\n");
   
  //CD_examplePLYIO(); 
  //CD_examplePLY_Read(); // passe a ply file in argument
  //CD_examplePLY_Write();
  //char *CD_filename = "test";
  /*p3D *stackp3D; 
  stackp3D = */

  //p3D stackp3D;

  //stackp3D.sizeStackPoints3D = 36;
  //stackp3D.stackPoints3D = (point3D *)malloc(36*sizeof(point3D)); 
    
 
 //==================================
 
  
  //point3D * stackPoints; 

  
  /*p3D stackP3D;
  stackP3D = CD_readASC( );*/
  
/*p3D stackP3D;
  
  stackP3D = CD_readPLY( );*/
  
  


  /*int mainNbPts = stackP3D.sizeStackPoints3D;
  int flagRGB = 1; 
  printf("CAOR Nb pts %d \n", mainNbPts);*/
  // triangulate 
  
  
  
  
  
  /* this loop allows to set coordinates 

   int ii;
  for(ii=0; ii<mainNbPts; ii++)
   {
     //printf(" Cartezian %f %f %f ", stackP3D.stackPoints3D[ii].x,stackP3D.stackPoints3D[ii].y,stackP3D.stackPoints3D[ii].z);
     point3D cartezian;
     cartezian.x=stackP3D.stackPoints3D[ii].x; cartezian.y=stackP3D.stackPoints3D[ii].y; cartezian.z=stackP3D.stackPoints3D[ii].z;
     
    if(flagRGB)printf("RGB %d %d %d", stackP3D.stackPoints3D[ii].Red,stackP3D.stackPoints3D[ii].Green, stackP3D.stackPoints3D[ii].Blue);  
    //point3D spherical;
    //spherical = Cartezian2Spheric(stackP3D.stackPoints3D[ii]);

    

   }*/
  
  // conversion stack to spherical coord: test on RGB data 
  /*p3D stackSph; 
  stackSph= stackCartezian2Spheric(stackP3D, mainNbPts, flagRGB);

  int stackNbSph = stackSph.sizeStackPoints3D;
  printf("main sph %d \n", stackNbSph);*/


  /*for(ii=0; ii<stackNbSph; ii++)
  {
     printf(" spheric %f %f %f ",  stackSph.stackPoints3D[ii].x, stackSph.stackPoints3D[ii].y, stackSph.stackPoints3D[ii].z);
  }*/

  // compute bounds 
  
  
   
  /*SphericalBounds mySphericBounds; 
  mySphericBounds = computeBoundSph(stackSph, stackNbSph);*/

 /*image MyIntImage;
 MyIntImage=triangulateStackSpheric(stackSph, mySphericBounds, stackNbSph, stackP3D);*/

  //=======================================

  
 //Image2Laser outImageLaser = triangulateStackSpheric2Image(stackSph, mySphericBounds, stackNbSph, stackP3D);
 /*Image2Lase outImageLaser =*/ 

//triangulateStackSpheric2ImageLaplacianSmooth(stackSph, mySphericBounds, stackNbSph, stackP3D);
 
 
 /*char *imgIntfilename = "Scan2DepthImgMainCartez"; 

 pgmWriteFile(imgIntfilename,outImageLaser.intensity, outImageLaser.nbCols, outImageLaser.nbRows);*/
  
 
 
 //Photo2Ground(outImageLaser, mySphericBounds);

//CCtriangulateStackSphericCloudCompare(stackSph, mySphericBounds, stackNbSph, stackP3D);

 
 // for visualizing, no need to save into ASC file, anyway the output should be expoitable by 

  

 //////******----------*******/ 
 // backprojection in the 3D space 
 //input: image 
  
  
    

  //fill image 

  //FillHoles(MyIntImage); 

  //segment image

  // display image

  /*free(stackP3D.stackPoints3D);
  free(stackSph.stackPoints3D);*/
return 0;

}





