# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "cppheaders")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itkhdf5/cpp" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5AbstractDs.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Alltypes.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5ArrayType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5AtomType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Attribute.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Classes.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CommonFG.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CompType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Cpp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CppDoc.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataSet.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataSpace.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DcreatProp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DxferProp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5EnumType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Exception.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FaccProp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FcreatProp.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5File.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FloatType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Group.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5IdComponent.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Include.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5IntType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Library.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Object.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5PredType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5PropList.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5StrType.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5VarLenType.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5_cpp-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5_cpp-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkhdf5_cpp-4.8.so.1"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkhdf5_cpp-4.8.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5_cpp-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5_cpp-4.8.so"
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

