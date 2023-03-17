# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion

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
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkdouble-conversion-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkdouble-conversion-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkdouble-conversion-4.8.so.1"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkdouble-conversion-4.8.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkdouble-conversion-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkdouble-conversion-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/bignum.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/cached-powers.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/diy-fp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/double-conversion.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/fast-dtoa.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/fixed-dtoa.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/ieee.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/strtod.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/DoubleConversion/src/double-conversion/utils.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/DoubleConversion/src/double-conversion/double-conversion-configure.h"
    )
endif()

