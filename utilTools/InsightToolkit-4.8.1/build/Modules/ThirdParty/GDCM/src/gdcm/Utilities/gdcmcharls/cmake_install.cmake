# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Libraries")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkgdcmcharls-4.8.so.1")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so.1")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "DebugDevel")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkgdcmcharls-4.8.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkgdcmcharls-4.8.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/gdcmcharls" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/lookuptable.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/encoderstrategy.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/colortransform.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/losslesstraits.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/streams.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/defaulttraits.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/scan.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/context.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/processline.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/publictypes.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/config.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/interface.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/decoderstrategy.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/header.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/contextrunmode.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmcharls/util.h"
    )
endif()

