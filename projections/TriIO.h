// TriIO.h

#ifdef __cplusplus
extern "C" {
#endif
//int c_func( void );



//#include "triangle.h"

/*typedef struct {double phiMin; 
                double phiMax; 
                double thetaMin;
                double theraMax;
               } SphericBounds;*/


typedef struct {
                 double  *Points3D;
                 //BoundingAngles();
                } ScanLaser;

typedef struct {
                 double x;
                 double y;
                 double z;
                 int index;
                 //stack attributes 
                 unsigned char ReflectanceLaser;
                 unsigned char Red;
                 unsigned char Green;
                 unsigned char Blue;
                 double normalNx;
                 double normalNy;
                 double normalNz;
               } point3D;

typedef struct { point3D *stackPoints3D;
                 int sizeStackPoints3D;
               } p3D;


//Spherical Bounds
typedef struct {
                 
                double phiMin; //azimuth
                double phiMax;
                double thetaMin; //zenith
                double thetaMax;
                double depthMin;
                double depthMax;
                 
               }SphericalBounds;


typedef struct {
  struct triangulateio *sphTriIO;
  
  
} triIO;


typedef struct{
               int idxV1;
               int idxV2;
               int idxV3; 
              }stackTriangle;

typedef struct{
                 stackTriangle * VerticesTriangles;
                 int numberTriangles; 
              } listeTriangles;


//struct for retaining points and index of triangle 

typedef struct{
                double x;
                double y;
                double z;
                int indexTriangle;
                
              }pointTriangle;

typedef struct {
                 double x; 
                 double y;
                 double z;
               }point3dSimple;


typedef struct{
                point3dSimple pt3D;
                int indexVertex;
                point3dSimple deplacement;
              }deplacVertex;

typedef struct{
                pointTriangle idx1;
                pointTriangle idx2;
                pointTriangle idx3;
                
              }FaceTri;

typedef struct{
               unsigned char *intensity;
               int nbRows;
               int nbCols;
              } image;


typedef struct{
               unsigned char *intensity;
               // added 5 Octobre 2015 
               unsigned char *intensityEstimate;
                   
               //double *dDepthImage;
               float *dDepthImage;
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
               // on a pas RGB, il faut rajouter 
    
     
              }Image2Laser;


/// 1 Oct  15

typedef struct 
        {
         double q[4];
        }qunit;
typedef struct 
        {
         float n[3];
        }axis;

typedef struct 
        {
         float mat[9];
        }Rotation;


/**********************************
***********************************/

// declarations des routines
  point3D Cartezian2Spheric(point3D cartez);
  p3D stackCartezian2Spheric_mview(p3D stackP3DCartezIN, int nbPoints, int flagRGB, int idxView, int nbView);
  p3D stackCartezian2Spheric(p3D stackP3DCartezIN, int nbPoints, int flagRGB);
  
  SphericalBounds computeBoundSph(p3D stackP3DSph, int nbPoints);

  int compare (const void * a, const void * b);
  int compare_doubles (const void *a, const void *b);

  image triangulateStackSpheric(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN);

  Image2Laser triangulateStackSpheric2Image(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN);


  Image2Laser vidock_triangulateStackSpheric2Image(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN);
  // 21 Oct 15 : automatic step param
  //27 oct add filename saving for multi resolution
  Image2Laser vidock_triangulateStackSpheric2Image_Step(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN, int _StepCoeff, char *nFilename, int idxPano);


  // 14 Mars 2016 
  Image2Laser vidock_triangulateStackSpheric2ImageElevation_Step(p3D stackP3DSph,p3D stackP3DMeshCartez, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN, char *filenameVTKSph_IN, float *arrCurv, int _StepCoeff, char *nFilename, char *filenameImagePano,  int idxPano);





  double Diff_Images(unsigned char *imageModel, unsigned char *imageTarget,  int nbCol, int nbRows);
  // added 1 OCt 2015

  // rotate cloud in cartesien coordinates, spherical geometry

  // init quaternion routines 
  void initQUnit(qunit *qu);
  void displayQUnit(qunit qu);

 
  void initRotation(Rotation *R);

  void initAxis(axis *N);

  void initAxisFromUserValues(axis *N, float Nx, float Ny, float Nz );


  void initAxisVect(axis *N /*,TPoint3D <doubl VectRot*/);


  void Quaternion2R(qunit q,Rotation *R); 

  void displayRotation( Rotation R);


  void RotateCloud_SG_CC(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser);

  void RotateCloud_SG_CC_2_SphericImage(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser, char *nameImageFileEstimated);

  void CD_ppmWriteFileRGB( char *fname, 
			   unsigned char *redimg,
			   unsigned char *greenimg,
			   unsigned char *blueimg,
			   int ncols, 
			   int nrows);



  void RotateCloud_SG_CC_2_SphericImage_AngleLooping(int _nbPointsCartez, p3D _stackP3DCartezIN, SphericalBounds _mySphericBounds, Image2Laser _myImage2Laser, char *nameImageFileEstimated, double angleDegrees);

  /*Image2Laser*/ void triangulateStackSpheric2ImageLaplacianSmooth(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN);

  /*void Image2Laser*/ void triangulateStackSphericCloudCompare(p3D stackP3DSph, SphericalBounds _mySphericBounds, int nbPoints, p3D stackP3DCartezIN);



  listeTriangles triangulateStackPlaneProjected( p3D stackP3DCartezIN, int _nbPoints3D,p3D stackP3DCartezINTrue);

void Photo2Ground(Image2Laser _image2Laser, SphericalBounds _mySphericBounds);

void WritePLYMeshFile();



//filling holes

//segmentation


//pyramidal


//fill image using vehicle approach 


  int readVTK_trianglesList(char *filename_IN, int **trianglesList );


p3D  CD_readPLY( );
//CD-CAOR: 18/07/2013 
p3D CD_readASC( );
// CD -GBA: 14 Mars 2016 
p3D CD_readASC_filename(char *filenameConfCloudASC_IN ); 


/*typedef struct {
                 pointlist = NULL;
                  
               } triangulatekk;*/

#ifdef __cplusplus
}
#endif

