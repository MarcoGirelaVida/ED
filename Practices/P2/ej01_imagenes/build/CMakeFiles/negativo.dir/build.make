# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build

# Include any dependencies generated for this target.
include CMakeFiles/negativo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/negativo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/negativo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/negativo.dir/flags.make

CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o: CMakeFiles/negativo.dir/flags.make
CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o: /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/estudiante/src/negativo.cpp
CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o: CMakeFiles/negativo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o -MF CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o.d -o CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o -c /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/estudiante/src/negativo.cpp

CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/estudiante/src/negativo.cpp > CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.i

CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/estudiante/src/negativo.cpp -o CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.s

# Object files for target negativo
negativo_OBJECTS = \
"CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o"

# External object files for target negativo
negativo_EXTERNAL_OBJECTS =

negativo: CMakeFiles/negativo.dir/estudiante/src/negativo.cpp.o
negativo: CMakeFiles/negativo.dir/build.make
negativo: libimage.a
negativo: CMakeFiles/negativo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable negativo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/negativo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/negativo.dir/build: negativo
.PHONY : CMakeFiles/negativo.dir/build

CMakeFiles/negativo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/negativo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/negativo.dir/clean

CMakeFiles/negativo.dir/depend:
	cd /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build /home/marco/Drive/Proyectos/ED/Practices/P2/ej01_imagenes/build/CMakeFiles/negativo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/negativo.dir/depend

