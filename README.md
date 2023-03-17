# PLO3S

## Building the method

The 3 part of the method in folder "comparison", "projections" and "triangulation" can be build with the script "building.sh". WKS algorithm in the "WKS" folder use MATLAB.


## Executing

You need to launch the PLO3S.sh script which will compute the PWKSMs and compare them. The result matrix can be found in "comparison/out" folder.

You need to make a ".txt" file called "NAME_OBJECTS.txt" in the "comparison/build" folder for the name of the objects to be display on the image of the matrix created. If you don't need the visualisation of the matrix, you can delete the part after the line "MATRIX IMAGE-----------" in the file scorePWKSMMView.sh in the "comparison/build" folder

## Librairies & dependencies

The method a

InsightToolKit (ITK) version 4.8.1 (include in the github repository)
Point Cloud Librart (PCL) version 1.8
OpenCV version 2.4.9
OpenCL version 2.1
Visualisation ToolKit (VTK) version 5.8

