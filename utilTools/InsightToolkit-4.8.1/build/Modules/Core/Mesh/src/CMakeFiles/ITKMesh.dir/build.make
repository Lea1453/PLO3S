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
include Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/depend.make

# Include the progress variables for this target.
include Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/progress.make

# Include the compile flags for this target's objects.
include Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/flags.make

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/flags.make
Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o: ../Modules/Core/Mesh/src/itkMeshRegion.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremy/kit/InsightToolkit-4.8.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o -c /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkMeshRegion.cxx

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.i"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkMeshRegion.cxx > CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.i

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.s"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkMeshRegion.cxx -o CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.s

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.requires:

.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.requires

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.provides: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.requires
	$(MAKE) -f Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/build.make Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.provides.build
.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.provides

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.provides.build: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o


Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/flags.make
Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o: ../Modules/Core/Mesh/src/itkSimplexMeshGeometry.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremy/kit/InsightToolkit-4.8.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o -c /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkSimplexMeshGeometry.cxx

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.i"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkSimplexMeshGeometry.cxx > CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.i

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.s"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src/itkSimplexMeshGeometry.cxx -o CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.s

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.requires:

.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.requires

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.provides: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.requires
	$(MAKE) -f Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/build.make Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.provides.build
.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.provides

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.provides.build: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o


# Object files for target ITKMesh
ITKMesh_OBJECTS = \
"CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o" \
"CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o"

# External object files for target ITKMesh
ITKMesh_EXTERNAL_OBJECTS =

lib/libITKMesh-4.8.so.1: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o
lib/libITKMesh-4.8.so.1: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o
lib/libITKMesh-4.8.so.1: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/build.make
lib/libITKMesh-4.8.so.1: lib/libITKStatistics-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libITKCommon-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitksys-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libITKVNLInstantiation-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkvnl_algo-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkv3p_lsqr-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkvnl-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkvcl-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkdouble-conversion-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkNetlibSlatec-4.8.so.1
lib/libITKMesh-4.8.so.1: lib/libitkv3p_netlib-4.8.so.1
lib/libITKMesh-4.8.so.1: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremy/kit/InsightToolkit-4.8.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../../lib/libITKMesh-4.8.so"
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ITKMesh.dir/link.txt --verbose=$(VERBOSE)
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../lib/libITKMesh-4.8.so.1 ../../../../lib/libITKMesh-4.8.so.1 ../../../../lib/libITKMesh-4.8.so

lib/libITKMesh-4.8.so: lib/libITKMesh-4.8.so.1
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libITKMesh-4.8.so

# Rule to build all files generated by this target.
Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/build: lib/libITKMesh-4.8.so

.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/build

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/requires: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkMeshRegion.cxx.o.requires
Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/requires: Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/itkSimplexMeshGeometry.cxx.o.requires

.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/requires

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/clean:
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src && $(CMAKE_COMMAND) -P CMakeFiles/ITKMesh.dir/cmake_clean.cmake
.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/clean

Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/depend:
	cd /home/jeremy/kit/InsightToolkit-4.8.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremy/kit/InsightToolkit-4.8.1 /home/jeremy/kit/InsightToolkit-4.8.1/Modules/Core/Mesh/src /home/jeremy/kit/InsightToolkit-4.8.1/build /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src /home/jeremy/kit/InsightToolkit-4.8.1/build/Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Modules/Core/Mesh/src/CMakeFiles/ITKMesh.dir/depend

