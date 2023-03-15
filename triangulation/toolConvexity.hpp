#ifndef _TOOLCONVEXITY_H_
#define _TOOLCONVEXITY_H_

bool isConvex(int v1);
bool isCriticalPt(int v1, int v2);
bool isCriticalPt(float v1, float v2);
int* smootheringWithMeanPatches_convex(int *convex, int sizeX, int sizeY, int sizeP, float thresh);
void fillConvexity( int *convexX, int *convexY, int sizeX, int sizeY);
void fillConvexityX( int *convexX, int sizeX, int sizeY);
void fillConvexityY(int *convexY, int sizeX, int sizeY);

#endif
