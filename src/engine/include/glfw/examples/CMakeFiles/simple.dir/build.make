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
CMAKE_SOURCE_DIR = /home/fason/Downloads/glfw-3.3.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fason/Downloads/glfw-3.3.2

# Include any dependencies generated for this target.
include examples/CMakeFiles/simple.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/simple.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/simple.dir/flags.make

examples/CMakeFiles/simple.dir/simple.c.o: examples/CMakeFiles/simple.dir/flags.make
examples/CMakeFiles/simple.dir/simple.c.o: examples/simple.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fason/Downloads/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/simple.dir/simple.c.o"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple.dir/simple.c.o   -c /home/fason/Downloads/glfw-3.3.2/examples/simple.c

examples/CMakeFiles/simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/simple.c.i"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fason/Downloads/glfw-3.3.2/examples/simple.c > CMakeFiles/simple.dir/simple.c.i

examples/CMakeFiles/simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/simple.c.s"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fason/Downloads/glfw-3.3.2/examples/simple.c -o CMakeFiles/simple.dir/simple.c.s

examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/simple.dir/flags.make
examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fason/Downloads/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.o"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple.dir/__/deps/glad_gl.c.o   -c /home/fason/Downloads/glfw-3.3.2/deps/glad_gl.c

examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple.dir/__/deps/glad_gl.c.i"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fason/Downloads/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/simple.dir/__/deps/glad_gl.c.i

examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple.dir/__/deps/glad_gl.c.s"
	cd /home/fason/Downloads/glfw-3.3.2/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fason/Downloads/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/simple.dir/__/deps/glad_gl.c.s

# Object files for target simple
simple_OBJECTS = \
"CMakeFiles/simple.dir/simple.c.o" \
"CMakeFiles/simple.dir/__/deps/glad_gl.c.o"

# External object files for target simple
simple_EXTERNAL_OBJECTS =

examples/simple: examples/CMakeFiles/simple.dir/simple.c.o
examples/simple: examples/CMakeFiles/simple.dir/__/deps/glad_gl.c.o
examples/simple: examples/CMakeFiles/simple.dir/build.make
examples/simple: src/libglfw3.a
examples/simple: /usr/lib/x86_64-linux-gnu/libm.so
examples/simple: /usr/lib/x86_64-linux-gnu/librt.so
examples/simple: /usr/lib/x86_64-linux-gnu/libm.so
examples/simple: /usr/lib/x86_64-linux-gnu/libX11.so
examples/simple: examples/CMakeFiles/simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fason/Downloads/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable simple"
	cd /home/fason/Downloads/glfw-3.3.2/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/simple.dir/build: examples/simple

.PHONY : examples/CMakeFiles/simple.dir/build

examples/CMakeFiles/simple.dir/clean:
	cd /home/fason/Downloads/glfw-3.3.2/examples && $(CMAKE_COMMAND) -P CMakeFiles/simple.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/simple.dir/clean

examples/CMakeFiles/simple.dir/depend:
	cd /home/fason/Downloads/glfw-3.3.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fason/Downloads/glfw-3.3.2 /home/fason/Downloads/glfw-3.3.2/examples /home/fason/Downloads/glfw-3.3.2 /home/fason/Downloads/glfw-3.3.2/examples /home/fason/Downloads/glfw-3.3.2/examples/CMakeFiles/simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/simple.dir/depend

