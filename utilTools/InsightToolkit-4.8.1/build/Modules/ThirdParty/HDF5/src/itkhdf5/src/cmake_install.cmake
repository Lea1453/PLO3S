# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itkhdf5" TYPE FILE FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/hdf5.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5api_adpt.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5public.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5version.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5overflow.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Apkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Apublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2pkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2public.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Edefin.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Einit.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epubgen.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Eterm.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDcore.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDdirect.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDfamily.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDlog.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmpi.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmpio.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmpiposix.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmulti.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDsec2.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDstdio.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MPpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Opkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Opublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Oshared.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ppkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ppublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Spkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Spublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SMpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ipkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ipublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MMpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpkg.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpublic.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5private.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Aprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2private.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5CSprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Eprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FLprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FOprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MFprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MMprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HPprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Iprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MPprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Oprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Pprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5RCprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5RSprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SLprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SMprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Sprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5STprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5TSprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Vprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5WBprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zprivate.h"
    "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5win32defs.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libraries")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkhdf5-4.8.so.1"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitkhdf5-4.8.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitkhdf5-4.8.so"
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

