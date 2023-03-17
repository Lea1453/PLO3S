# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/gdcmjpeg" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jpegint.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jconfig.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jinclude.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jpeglib.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jversion.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jerror.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jmemsys.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jdhuff.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jlossy.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jlossls.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jdct.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jmorecfg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jchuff.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/8/cmake_install.cmake")
  include("/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/12/cmake_install.cmake")
  include("/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/16/cmake_install.cmake")

endif()

