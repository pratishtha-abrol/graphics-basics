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
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.o: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.o: ../external/glfw-3.1.2/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.o"
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o   -c /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/external/glfw-3.1.2/tests/windows.c

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/external/glfw-3.1.2/tests/windows.c > CMakeFiles/windows.dir/windows.c.i

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/external/glfw-3.1.2/tests/windows.c -o CMakeFiles/windows.dir/windows.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/windows: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.o
external/glfw-3.1.2/tests/windows: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build.make
external/glfw-3.1.2/tests/windows: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/librt.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libm.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libX11.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libXrandr.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libXinerama.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libXi.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libXcursor.so
external/glfw-3.1.2/tests/windows: /usr/lib/x86_64-linux-gnu/libGL.so
external/glfw-3.1.2/tests/windows: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable windows"
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build: external/glfw-3.1.2/tests/windows

.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/clean:
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend:
	cd /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0 /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/external/glfw-3.1.2/tests /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests /home/pratzz/Desktop/OpenSource/graphics-basics/Assignment_0/build/external/glfw-3.1.2/tests/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend

