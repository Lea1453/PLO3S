cmake_minimum_required(VERSION 2.8)

PROJECT(scoreDistCvxLocal)

set (CMAKE_CXX_STANDARD 11)

find_package(VTK REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenCL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system iostreams filesystem)

include(${VTK_USE_FILE} ../utilTools/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../utilTools ${OpenCL_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

add_executable(scoreDistCvxLocal scoreDistCvxLocal.cpp visualizeImages.cpp ../utilTools/utilTool.cpp ../utilTools/gradient.cpp ../utilTools/arrDeriv.cpp ../utilTools/secondDeriv.cpp ../utilTools/stats.cpp findMinimum.cpp openCL_tools.cpp scoreDist.cpp)


target_link_libraries(scoreDistCvxLocal ${VTK_LIBRARIES}  ${OpenCV_LIBS} ${OpenCL_LIBRARY} ${Boost_LIBRARIES})

