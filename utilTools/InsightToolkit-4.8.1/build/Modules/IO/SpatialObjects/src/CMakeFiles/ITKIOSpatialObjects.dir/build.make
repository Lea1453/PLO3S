# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeremy/kit/InsightToolkit-4.8.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremy/kit/InsightToolkit-4.8.1/build

# Include any dependencies generated for this target.
include Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/depend.make

# Include the progress variables for this target.
include Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/progress.make

# Include the compile flags for this target's objects.
include Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/flags.make

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/flags.make
Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o: ../Modules/IO/SpatialObjects/src/itkPolygonGroupSpatialObjectXMLFile.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremy/kit/InsightToolkit-4.8.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o -c /home/jeremy/kit/InsightToolkit-4.8.1/Modules/IO/SpatialObjects/src/itkPolygonGroupSpatialObjectXMLFile.cxx

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.i"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremy/kit/InsightToolkit-4.8.1/Modules/IO/SpatialObjects/src/itkPolygonGroupSpatialObjectXMLFile.cxx > CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.i

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.s"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremy/kit/InsightToolkit-4.8.1/Modules/IO/SpatialObjects/src/itkPolygonGroupSpatialObjectXMLFile.cxx -o CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.s

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.requires:

.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.requires

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.provides: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.requires
	$(MAKE) -f Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/build.make Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.provides.build
.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.provides

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.provides.build: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o


# Object files for target ITKIOSpatialObjects
ITKIOSpatialObjects_OBJECTS = \
"CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o"

# External object files for target ITKIOSpatialObjects
ITKIOSpatialObjects_EXTERNAL_OBJECTS =

lib/libITKIOSpatialObjects-4.8.so.1: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o
lib/libITKIOSpatialObjects-4.8.so.1: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/build.make
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKSpatialObjects-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKIOXML-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKIOImageBase-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKMesh-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKStatistics-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkNetlibSlatec-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKCommon-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitksys-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKVNLInstantiation-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkvnl_algo-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkv3p_lsqr-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkvnl-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkvcl-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkv3p_netlib-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libitkdouble-conversion-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: lib/libITKEXPAT-4.8.so.1
lib/libITKIOSpatialObjects-4.8.so.1: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremy/kit/InsightToolkit-4.8.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../lib/libITKIOSpatialObjects-4.8.so"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ITKIOSpatialObjects.dir/link.txt --verbose=$(VERBOSE)
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../lib/libITKIOSpatialObjects-4.8.so.1 ../../../../lib/libITKIOSpatialObjects-4.8.so.1 ../../../../lib/libITKIOSpatialObjects-4.8.so

lib/libITKIOSpatialObjects-4.8.so: lib/libITKIOSpatialObjects-4.8.so.1
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libITKIOSpatialObjects-4.8.so

# Rule to build all files generated by this target.
Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/build: lib/libITKIOSpatialObjects-4.8.so

.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/build

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/requires: Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/itkPolygonGroupSpatialObjectXMLFile.cxx.o.requires

.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/requires

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/clean:
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src && $(CMAKE_COMMAND) -P CMakeFiles/ITKIOSpatialObjects.dir/cmake_clean.cmake
.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/clean

Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/depend:
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremy/kit/InsightToolkit-4.8.1 /home/jeremy/kit/InsightToolkit-4.8.1/Modules/IO/SpatialObjects/src /home/jeremy/kit/InsightToolkit-4.8.1/build /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Modules/IO/SpatialObjects/src/CMakeFiles/ITKIOSpatialObjects.dir/depend

