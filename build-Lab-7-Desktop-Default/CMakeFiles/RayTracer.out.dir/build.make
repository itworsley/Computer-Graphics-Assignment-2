# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/home/itworsley/Desktop/COSC363/Lab 7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/RayTracer.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RayTracer.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RayTracer.out.dir/flags.make

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/RayTracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/RayTracer.cpp"

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/RayTracer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/RayTracer.cpp" > CMakeFiles/RayTracer.out.dir/RayTracer.cpp.i

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/RayTracer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/RayTracer.cpp" -o CMakeFiles/RayTracer.out.dir/RayTracer.cpp.s

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.requires

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.provides: CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.provides

CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o


CMakeFiles/RayTracer.out.dir/Ray.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/Ray.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/Ray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RayTracer.out.dir/Ray.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/Ray.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/Ray.cpp"

CMakeFiles/RayTracer.out.dir/Ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/Ray.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/Ray.cpp" > CMakeFiles/RayTracer.out.dir/Ray.cpp.i

CMakeFiles/RayTracer.out.dir/Ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/Ray.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/Ray.cpp" -o CMakeFiles/RayTracer.out.dir/Ray.cpp.s

CMakeFiles/RayTracer.out.dir/Ray.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/Ray.cpp.o.requires

CMakeFiles/RayTracer.out.dir/Ray.cpp.o.provides: CMakeFiles/RayTracer.out.dir/Ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/Ray.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/Ray.cpp.o.provides

CMakeFiles/RayTracer.out.dir/Ray.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/Ray.cpp.o


CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/SceneObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/SceneObject.cpp"

CMakeFiles/RayTracer.out.dir/SceneObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/SceneObject.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/SceneObject.cpp" > CMakeFiles/RayTracer.out.dir/SceneObject.cpp.i

CMakeFiles/RayTracer.out.dir/SceneObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/SceneObject.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/SceneObject.cpp" -o CMakeFiles/RayTracer.out.dir/SceneObject.cpp.s

CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.requires

CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.provides: CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.provides

CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o


CMakeFiles/RayTracer.out.dir/Sphere.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/Sphere.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RayTracer.out.dir/Sphere.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/Sphere.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/Sphere.cpp"

CMakeFiles/RayTracer.out.dir/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/Sphere.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/Sphere.cpp" > CMakeFiles/RayTracer.out.dir/Sphere.cpp.i

CMakeFiles/RayTracer.out.dir/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/Sphere.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/Sphere.cpp" -o CMakeFiles/RayTracer.out.dir/Sphere.cpp.s

CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.requires

CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.provides: CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.provides

CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/Sphere.cpp.o


CMakeFiles/RayTracer.out.dir/Plane.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/Plane.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RayTracer.out.dir/Plane.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/Plane.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/Plane.cpp"

CMakeFiles/RayTracer.out.dir/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/Plane.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/Plane.cpp" > CMakeFiles/RayTracer.out.dir/Plane.cpp.i

CMakeFiles/RayTracer.out.dir/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/Plane.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/Plane.cpp" -o CMakeFiles/RayTracer.out.dir/Plane.cpp.s

CMakeFiles/RayTracer.out.dir/Plane.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/Plane.cpp.o.requires

CMakeFiles/RayTracer.out.dir/Plane.cpp.o.provides: CMakeFiles/RayTracer.out.dir/Plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/Plane.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/Plane.cpp.o.provides

CMakeFiles/RayTracer.out.dir/Plane.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/Plane.cpp.o


CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o: CMakeFiles/RayTracer.out.dir/flags.make
CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o: /home/itworsley/Desktop/COSC363/Lab\ 7/Cylinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o -c "/home/itworsley/Desktop/COSC363/Lab 7/Cylinder.cpp"

CMakeFiles/RayTracer.out.dir/Cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.out.dir/Cylinder.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/itworsley/Desktop/COSC363/Lab 7/Cylinder.cpp" > CMakeFiles/RayTracer.out.dir/Cylinder.cpp.i

CMakeFiles/RayTracer.out.dir/Cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.out.dir/Cylinder.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/itworsley/Desktop/COSC363/Lab 7/Cylinder.cpp" -o CMakeFiles/RayTracer.out.dir/Cylinder.cpp.s

CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.requires:

.PHONY : CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.requires

CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.provides: CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/RayTracer.out.dir/build.make CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.provides.build
.PHONY : CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.provides

CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.provides.build: CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o


# Object files for target RayTracer.out
RayTracer_out_OBJECTS = \
"CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o" \
"CMakeFiles/RayTracer.out.dir/Ray.cpp.o" \
"CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o" \
"CMakeFiles/RayTracer.out.dir/Sphere.cpp.o" \
"CMakeFiles/RayTracer.out.dir/Plane.cpp.o" \
"CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o"

# External object files for target RayTracer.out
RayTracer_out_EXTERNAL_OBJECTS =

RayTracer.out: CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/Ray.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/Sphere.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/Plane.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o
RayTracer.out: CMakeFiles/RayTracer.out.dir/build.make
RayTracer.out: /usr/lib/x86_64-linux-gnu/libGL.so
RayTracer.out: /usr/lib/x86_64-linux-gnu/libGLU.so
RayTracer.out: /usr/lib/x86_64-linux-gnu/libglut.so
RayTracer.out: CMakeFiles/RayTracer.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RayTracer.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracer.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RayTracer.out.dir/build: RayTracer.out

.PHONY : CMakeFiles/RayTracer.out.dir/build

CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/RayTracer.cpp.o.requires
CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/Ray.cpp.o.requires
CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/SceneObject.cpp.o.requires
CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/Sphere.cpp.o.requires
CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/Plane.cpp.o.requires
CMakeFiles/RayTracer.out.dir/requires: CMakeFiles/RayTracer.out.dir/Cylinder.cpp.o.requires

.PHONY : CMakeFiles/RayTracer.out.dir/requires

CMakeFiles/RayTracer.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RayTracer.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RayTracer.out.dir/clean

CMakeFiles/RayTracer.out.dir/depend:
	cd /home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/itworsley/Desktop/COSC363/Lab 7" "/home/itworsley/Desktop/COSC363/Lab 7" /home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default /home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default /home/itworsley/Desktop/COSC363/build-Lab-7-Desktop-Default/CMakeFiles/RayTracer.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RayTracer.out.dir/depend

