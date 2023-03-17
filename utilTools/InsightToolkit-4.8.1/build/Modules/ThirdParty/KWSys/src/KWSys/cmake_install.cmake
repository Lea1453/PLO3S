# Install script for directory: /home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/KWSys/src/KWSys

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/Modules/ThirdParty/KWSys/src/KWSys/Copyright.txt")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/algorithm")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/deque")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/exception")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/functional")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/iterator")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/list")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/map")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/memory")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/new")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/numeric")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/queue")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/set")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/stack")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/stdexcept")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/string.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/string")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/utility")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/stl" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/stl/vector")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/cstddef")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/ios" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/ios/iostream")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/ios" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/ios/fstream")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/ios" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/ios/sstream")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys/ios" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/ios/iosfwd")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Directory.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/DynamicLoader.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Encoding.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Glob.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/RegularExpression.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/SystemTools.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/CommandLineArguments.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/FStream.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/SystemInformation.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Configure.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/SharedForward.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Process.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Base64.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Encoding.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/FundamentalType.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/MD5.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/System.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/Configure.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/String.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/hashtable.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/hash_fun.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/hash_map.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/hash_set.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Development")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.8/itksys" TYPE FILE FILES "/home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/ThirdParty/KWSys/src/itksys/auto_ptr.hxx")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "RuntimeLibraries")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitksys-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitksys-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitksys-4.8.so.1"
    "/home/jeremy/kit/InsightToolkit-4.8.1/build/lib/libitksys-4.8.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitksys-4.8.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libitksys-4.8.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

