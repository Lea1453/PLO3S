#ifndef _VISUALIZEIMAGES_H_
#define _VISUALIZEIMAGES_H_


#include <vtkImageData.h>

void displayImagesPatches(float *I1, float *I2, int *posI1, int *posI2, int *revPosI2, int *coordMin_I1vsI2, int *sizeXY1, int *sizeXY2, int size_patch);
void CreateColorImage(vtkImageData* image, float *I1, int *posI1, int sizeX1, int sizeY1, int size_patch);
void changePositionPatch(vtkImageData* image, float *I1, int *posI1, int posPi, int posPj, int diffPosPi, int diffPosPj, int sizeX1, int sizeY1, int size_patch);

#endif
