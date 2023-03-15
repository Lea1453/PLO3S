#ifndef _SCOREDISTCVX_H_
#define _SCOREDISTCVX_H_

int scoreDistLocalArea(int *c1, int *c2, int sizeX1, int sizeY1, int sizeX2, int sizeY2,  float *dist, int size_patch,int size_area);
int computeHist(float *cPatch, float *cHist, int size, int size_patch);
int computeHist_float(float *cPatch, float *cHist, float *binVal, int size, int size_patch);
void computeCoefs(float *z, float *coefs, float maxZ, float minZ, int size);
void addCoefToDesc(float *desc, float *coefs, int size, int sizeDesc);

void createDescriptors(float **ac, float **acHist, int sizeac, int *size, int size_patch);
void createDescriptors(float *ac, float **acHist, float *binVal,  int size, int size_patch);
void creatingScaleDescriptors(char **filenamesIn, float *binVal, int sizeac, int size_patch);

void scoreDistCvx(char **filenamesCvxIn, char **filenamesWKS, char *filenameCvxOut, int sizeac);

#endif
