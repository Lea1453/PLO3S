cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(EDTSurf)

find_package(PCL 1.7 REQUIRED)
find_package( OpenCV REQUIRED )
find_package(ITK REQUIRED)

include(${ITK_USE_FILE})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_compile_options(-Wall -Wextra)

add_executable (EDTSurf EDTSurf.cpp ParsePDB.cpp ProteinSurface.cpp vtkOFFReader.cpp itkConformal.cpp TriDT.cpp TriCall_CD.c TriIO.c triangle.c pnmio.c error.c)
target_link_libraries (EDTSurf ${PCL_LIBRARIES}  ${OpenCV_LIBS} ${ITK_LIBRARIES} )
