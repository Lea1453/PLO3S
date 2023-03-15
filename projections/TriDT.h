//TriDT.h


int ConformalSphere2ImageProjection_ElevationBatch(char *filenameImage_OUT, char *filenameConfCloudASC_IN, char *filenameCartezCloudASC_IN, char* filenameCurvature_IN,char *filenameImagePano_OUT, char *filenameVTKSph_IN, int idxPano, int idxView, int nbView); 

int writeFloatImage(float *imageInput, int nbLignes, int nbCols);
