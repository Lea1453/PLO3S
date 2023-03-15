#ifndef _CONVEXITY_H_
#define _CONVEXITY_H_

#include "arrDeriv.hpp"

void saveMapConvexity(int *convex, int sizeX, int sizeY, std::string fnameOutCvx);
void saveMapConvexity_txt(int *convex, int sizeX, int sizeY, std::string fnameOutCvx);
void saveMapConvexity_asc(int *convex, int sizeX, int sizeY, std::string fnameOutCvx);
void saveMapCurvature_asc(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCvx);
void saveMapCurvature_asc_desc(float *curvature, int sizeX, int sizeY,int size_patch, int size_desc, std::string fnameOutCurv);
void saveBinaryMapCurvature_asc_desc(float *curvature, int sizeX, int sizeY, int size_patch, int size_desc, std::string fnameOutCurv);
void saveMapCurvature_txt(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCurve);
void saveMapLaplacian_txt(float *laplacian, int sizeX, int sizeY, std::string fnameOutLpc);
void saveMapConvexityLocal(int *convex, float *z, float *ad, int sizeX, int sizeY, int size_patch, std::string fnameOutCvx);
void saveMapCurvatureLocal(float *curvature, int sizeX, int sizeY, int size_patch, std::string fnameOutCvx);
void saveMapConvexity_tiff(int *convex, int sizeX, int sizeY, std::string fnameOutCvx);

void findConvexityX(bool *maskCourbElev, ArrDeriv *ad, int *convexX, int sizeX, int sizeY);
void findConvexityY(bool *maskCourbElev, ArrDeriv *ad, int *convexY, int sizeX, int sizeY);
void findConvexityXY(bool *maskCourbElev, ArrDeriv *ad, int **convexX, int **convexY, int sizeX, int sizeY);
void findConvexity(bool *maskCourbElev, ArrDeriv *ad, int **convex, int sizeX, int sizeY);
void findConvexity_consensus(bool *maskCourbElev, ArrDeriv *ad, int **convex, int sizeX, int sizeY);
void findConvexity_secondDeriv(bool *maskCourbElev, ArrDeriv *ad, int *convexX, int *convexY, int sizeX, int sizeY);
void findCurvature(ArrDeriv *ad, float *curvature, int sizeX, int sizeY);
void findConvexity_Laplacian( ArrDeriv *ad, float **laplacian, bool *maskCourbElev, int sizeX, int sizeY);

void interpolationPoints(float *valCurv, int *revPosCurv, int *sizeXY, int sizeNbP, int *trianglesIndex, int nbTriangles, int sizeWKS);

void curvatureWithTriangles(char *fnameCurv, char *fnameOutCurv);
void convexity(char *fnameCourbElev,  char *fnameOutCvx);


#endif
 
