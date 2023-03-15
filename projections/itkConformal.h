int vidock_itkConformal(/*int argc*/char *vtkFilename , char *vtkFilenameSph);


// this function output the CloudSphericXYZRGB_max.asc
int convertFile_VTK2ASC(char *filenameVTKSphIn);

// D. Craciun 11 Decembre 2015
int convertFile_VTK2ASC_RGB(char *FilenameASC_Out, char *filenameVTKSphIn);
int convertFile_VTK2ASC_NoRGB(char *FilenameASC_Out, char *filenameVTKSphIN, char *filenameCurvature_IN);

int Sphere2ImageProjection();

// 1/02/2016 idxPano_level.pgm
int Sphere2ImageProjection_Batch(char *filenameImage_OUT, char *filenameCloudASC_IN, int idxPano, int idxView, int nbView);


// 14/03/2016 idxPano_level.pgm
int Sphere2ImageProjection_ElevationBatch(char *filenameImage_OUT, char *filenameConfCloudASC_IN,  char *filenameCartezCloudASC_IN, char *filenameCurvature_IN, char *filenameImagePano_OUT, char *filenameVTKSph_IN, int idxPano, int idxView, int nbView);
