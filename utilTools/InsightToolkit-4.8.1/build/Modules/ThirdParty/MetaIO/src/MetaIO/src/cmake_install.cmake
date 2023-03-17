# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "RuntimeLibraries")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libITKMetaIO-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libITKMetaIO-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libITKMetaIO-4.8.so.1"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libITKMetaIO-4.8.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libITKMetaIO-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libITKMetaIO-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaOutput.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImageUtils.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTube.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaEvent.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaVesselTube.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaITKUtils.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaContour.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaForm.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaFEMObject.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTypes.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaMesh.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTubeGraph.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaArray.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaGaussian.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImage.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaSurface.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaCommand.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaBlob.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/localMetaConfiguration.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaUtils.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaGroup.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaObject.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaEllipse.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTransform.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImageTypes.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaDTITube.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaLine.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaScene.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaLandmark.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaArrow.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaIOConfig.h"
    )
endif()

