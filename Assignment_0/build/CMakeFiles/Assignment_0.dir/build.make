# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_0.dir/flags.make

CMakeFiles/Assignment_0.dir/src/main.cpp.o: CMakeFiles/Assignment_0.dir/flags.make
CMakeFiles/Assignment_0.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_0.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment_0.dir/src/main.cpp.o -c /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/src/main.cpp

CMakeFiles/Assignment_0.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_0.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/src/main.cpp > CMakeFiles/Assignment_0.dir/src/main.cpp.i

CMakeFiles/Assignment_0.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_0.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/src/main.cpp -o CMakeFiles/Assignment_0.dir/src/main.cpp.s

# Object files for target Assignment_0
Assignment_0_OBJECTS = \
"CMakeFiles/Assignment_0.dir/src/main.cpp.o"

# External object files for target Assignment_0
Assignment_0_EXTERNAL_OBJECTS =

Assignment_0: CMakeFiles/Assignment_0.dir/src/main.cpp.o
Assignment_0: CMakeFiles/Assignment_0.dir/build.make
Assignment_0: /usr/lib/x86_64-linux-gnu/libGL.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libGLU.so
Assignment_0: external/glfw-3.1.2/src/libglfw3.a
Assignment_0: external/libGLEW_1130.a
Assignment_0: /usr/lib/x86_64-linux-gnu/librt.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libm.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libX11.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXrandr.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXinerama.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXi.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXcursor.so
Assignment_0: /usr/lib/x86_64-linux-gnu/librt.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libm.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libX11.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXrandr.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXinerama.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXi.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libXcursor.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libGL.so
Assignment_0: /usr/lib/x86_64-linux-gnu/libGLU.so
Assignment_0: CMakeFiles/Assignment_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assignment_0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_0.dir/build: Assignment_0

.PHONY : CMakeFiles/Assignment_0.dir/build

CMakeFiles/Assignment_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment_0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_0.dir/clean

CMakeFiles/Assignment_0.dir/depend:
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0 /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0 /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/CMakeFiles/Assignment_0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_0.dir/depend

