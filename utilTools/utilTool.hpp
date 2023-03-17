#ifndef _UTILTOOL_H_
#define _UTILTOOL_H_

#include <string>

#include "gradient.hpp"
#include "arrDeriv.hpp"
#include "secondDeriv.hpp"

int countLinesFile(char *fname);
int countLinesFile(std::string fname);
int countCharsLine(std::string line);
int comp (const void * elem1, const void * elem2);
int maxInt(int *tmax, int size);
void maxPositionArray(int *pos, int *max, int size);
int minInt(int *tmin, int size);
int secondMaxInt(int *tmax, int size);
int countNbZeros(int *t, int size);
int countNbZeros(float *t, int size);
int countNbZeros_patch(int *t, int sizeX, int sizeY, int ideb, int jdeb, int sizep);
float maxFloat(float *tmax, int size);
float maxFloat2D(float **tmax, int sizei, int *sizej);
float secondMaxFloat(float *tmax, int size);
float minFloat(float *tmin, int size);
float minFloat2D(float **tmin, int sizei, int *sizej);
float distMAD(float x, float y);
float distScoring(float x, float y);
void normalizeFloatArr(float *arrF, int size);
float meanPatch(int *X, int sizeX, int sizeY, int ideb, int jdeb, int sizeP);
void readHeader_mapCvx(char **filenamesGrad, int **sizeXY, int *size_patch, int sizei);
void readHeader_mapCvx_mView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei);
void readHeader_mapCvx_mView_allView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei, int nbView);
void readBinaryHeader_mapCvx_mView_allView(char **filenamesGrad, int *size, int *size_patch, int **sizeAllXY, int sizei, int nbView);

void loadFile_mapCvx_mView_desc(char *filenamesGrad, float **ac, int *size);
void loadFile_mapCvx_mView(char *filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch);
void loadFiles_mapCvx_mView(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch, int sizei, int idxI, int idxJ);
void loadFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int *sizeXY, int *size_patch, int nbView);
void loadFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int *size, int *sizeXY, int *size_patch, int nbView);
void loadBinaryFile_mapCvx_mView_allView(char **filenamesGrad, float **ac, int *size, int *sizeXY, int size_patch, int nbView);
void loadFile_mapCvx_mView_allView_WKS(char **filenamesGrad, float **ac, int *size, int *sizeXY, int *size_patch, int nbView);
void loadBinaryFile_mapCvx_mView_allView_WKS(char **filenamesGrad, float **ac, int *size, int *sizeXY, int size_patch, int nbView);
void loadFiles_mapCvx(char **filenamesGrad, int **a, int *sizeX, int *sizeY, int sizei);
void loadFiles_mapCvx(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch, int sizei);
void loadFiles_mapCvx_patch(char **filenamesGrad, int **ac, int **pos, float **z, int *size, int *size_patch, int sizei);
void loadFiles_mapCvx_patch(char **filenamesGrad, float **ac, int **pos, int **revPos, int *size, int **sizeXY, int *size_patch, int sizei);
void loadFileWithTriangles(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles);
void loadFileWithTriangles_desc(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles, int sizeZ);
void loadFileBinaryWithTriangles(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles);
void loadFileBinaryWithTriangles_desc(char *filename, float **tabVal, int **revPosVal, int *sizeXY, int *sizeNbP, int **trianglesIndex, int *nbTriangles, int sizeZ);         
void computePatches_allFiles(float **c, float **cLoc, int **sizeXY, int size_patch, int sizeac);
void computePatches(float *c, float *cLoc, int sizeX, int sizeY, int size_patch);
void computePatches_withMalloc(float *c, float **cLoc, int sizeX, int sizeY, int size_patch);
void computePatches_withMalloc_allView(float *c, float **cLoc, int sizeAllView, int *sizeXY, int size_patch, int nbView);

void readASCIIFile(char *fname, float **I, int *sizeX,int *sizeY);
void readASCIIFile(char *fname, int **x, int **y, float **z, int *size);
void readMultiASCIIFile(char **filesNames, float **I, int *sizeX,int *sizeY, int sizei);
void readASCIIFile_courbElev(char *fname, float **courbElev, bool **maskCourbElev, int *sizeX,int *sizeY);
void loadFile_matrixScore(char *filenamesMatScore, float *matSc, int sizeX, int sizeY);

void saveGraphValuesXY_int_float(char *fnameout, int *x, float *y, int size);
void saveCoordPatch_desc(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int nbView, int idx1, int idx2);
void saveCoordPatch_desc_allView(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int nbView, int idx1, int idx2);
void saveCoordPatch_desc_vsPatch(char *fnameout, int *coordMin_I1vsI2, float *minMat_I1vsI2, int **sizeAllXY, int size, int sizeac, int nbView, int idx1,  int *coordAssociateImg);
void saveVectorFile_int(char *fnameout, int *tabVal , int size);
void readVectorFile_int(char *fname, int **tabVal, int *size);
void readDoubleVectorFile_int_float(char *fname, int **tabVal, float **tabVal2, int *size);

void saveImageAscii(float *I, char *fnameout, int sizeX, int sizeY);
void saveImageAscii(int *x, int *y, float *z, char *fnameout, int size);
void saveImageAscii_grad(char *fnameout_gx, char *fnameout_gy, char *fnameout_gxgy, Gradient *gradImg, int sizeX, int sizeY);
void saveImageAscii_deriv(char *fnameout_deriv, Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY);
void saveImageAscii_deriv_full(char *fnameout_deriv, float *courbElev,  Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY);

void loadFile_deriv(char *filenamesDeriv, ArrDeriv *ad);
void loadFiles_WKS(char **filenamesWKS, float **wks,  int *size, int *size_desc, int sizeac);
void loadFiles_deriv(char **filenamesDeriv, ArrDeriv *ad, int sizei);

void loadSaveFile_matrixScore();

void saveMatrixScore(char *fnameout, float *matDist, int sizeMat);
void saveMatrixScore_transpose(char *fnameout, float *matDist, int sizeX, int sizeY);
void saveMatrixScore(char *fnameout, float *matDist, int sizeX, int sizeY);
void saveMatrixScore_append(char *fnameout, float *matDist, int sizeQueries, int j);
void saveMatrixScore(char *fnameout_gx, char *fnameout_gy, char *fnameout_norm, char *fnameout_arctan, float *matDistX, float *matDistY, float *matDistNorm, float *matDistArctan, int sizeMat);


void crossProduct3f(float *x, float *y, float *z);
void dotProduct2i(int *x, int *y, int *z);
void computeBarycentricCoord2i(int* A, int* B, int* C, int* P, float* u, float* v, float* w);
bool isInTriangle(float u, float v, float w);

#endif
