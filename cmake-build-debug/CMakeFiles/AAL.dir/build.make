# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/Wasiollo/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/Wasiollo/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Wasiollo/CLionProjects/AAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Wasiollo/CLionProjects/AAL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AAL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AAL.dir/flags.make

CMakeFiles/AAL.dir/main.cpp.o: CMakeFiles/AAL.dir/flags.make
CMakeFiles/AAL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AAL.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAL.dir/main.cpp.o -c /home/Wasiollo/CLionProjects/AAL/main.cpp

CMakeFiles/AAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAL.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Wasiollo/CLionProjects/AAL/main.cpp > CMakeFiles/AAL.dir/main.cpp.i

CMakeFiles/AAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAL.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Wasiollo/CLionProjects/AAL/main.cpp -o CMakeFiles/AAL.dir/main.cpp.s

CMakeFiles/AAL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/AAL.dir/main.cpp.o.requires

CMakeFiles/AAL.dir/main.cpp.o.provides: CMakeFiles/AAL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/AAL.dir/build.make CMakeFiles/AAL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/AAL.dir/main.cpp.o.provides

CMakeFiles/AAL.dir/main.cpp.o.provides.build: CMakeFiles/AAL.dir/main.cpp.o


CMakeFiles/AAL.dir/InputOutput.cpp.o: CMakeFiles/AAL.dir/flags.make
CMakeFiles/AAL.dir/InputOutput.cpp.o: ../InputOutput.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AAL.dir/InputOutput.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAL.dir/InputOutput.cpp.o -c /home/Wasiollo/CLionProjects/AAL/InputOutput.cpp

CMakeFiles/AAL.dir/InputOutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAL.dir/InputOutput.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Wasiollo/CLionProjects/AAL/InputOutput.cpp > CMakeFiles/AAL.dir/InputOutput.cpp.i

CMakeFiles/AAL.dir/InputOutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAL.dir/InputOutput.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Wasiollo/CLionProjects/AAL/InputOutput.cpp -o CMakeFiles/AAL.dir/InputOutput.cpp.s

CMakeFiles/AAL.dir/InputOutput.cpp.o.requires:

.PHONY : CMakeFiles/AAL.dir/InputOutput.cpp.o.requires

CMakeFiles/AAL.dir/InputOutput.cpp.o.provides: CMakeFiles/AAL.dir/InputOutput.cpp.o.requires
	$(MAKE) -f CMakeFiles/AAL.dir/build.make CMakeFiles/AAL.dir/InputOutput.cpp.o.provides.build
.PHONY : CMakeFiles/AAL.dir/InputOutput.cpp.o.provides

CMakeFiles/AAL.dir/InputOutput.cpp.o.provides.build: CMakeFiles/AAL.dir/InputOutput.cpp.o


CMakeFiles/AAL.dir/Generator.cpp.o: CMakeFiles/AAL.dir/flags.make
CMakeFiles/AAL.dir/Generator.cpp.o: ../Generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AAL.dir/Generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAL.dir/Generator.cpp.o -c /home/Wasiollo/CLionProjects/AAL/Generator.cpp

CMakeFiles/AAL.dir/Generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAL.dir/Generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Wasiollo/CLionProjects/AAL/Generator.cpp > CMakeFiles/AAL.dir/Generator.cpp.i

CMakeFiles/AAL.dir/Generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAL.dir/Generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Wasiollo/CLionProjects/AAL/Generator.cpp -o CMakeFiles/AAL.dir/Generator.cpp.s

CMakeFiles/AAL.dir/Generator.cpp.o.requires:

.PHONY : CMakeFiles/AAL.dir/Generator.cpp.o.requires

CMakeFiles/AAL.dir/Generator.cpp.o.provides: CMakeFiles/AAL.dir/Generator.cpp.o.requires
	$(MAKE) -f CMakeFiles/AAL.dir/build.make CMakeFiles/AAL.dir/Generator.cpp.o.provides.build
.PHONY : CMakeFiles/AAL.dir/Generator.cpp.o.provides

CMakeFiles/AAL.dir/Generator.cpp.o.provides.build: CMakeFiles/AAL.dir/Generator.cpp.o


CMakeFiles/AAL.dir/Algorithms.cpp.o: CMakeFiles/AAL.dir/flags.make
CMakeFiles/AAL.dir/Algorithms.cpp.o: ../Algorithms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AAL.dir/Algorithms.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAL.dir/Algorithms.cpp.o -c /home/Wasiollo/CLionProjects/AAL/Algorithms.cpp

CMakeFiles/AAL.dir/Algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAL.dir/Algorithms.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Wasiollo/CLionProjects/AAL/Algorithms.cpp > CMakeFiles/AAL.dir/Algorithms.cpp.i

CMakeFiles/AAL.dir/Algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAL.dir/Algorithms.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Wasiollo/CLionProjects/AAL/Algorithms.cpp -o CMakeFiles/AAL.dir/Algorithms.cpp.s

CMakeFiles/AAL.dir/Algorithms.cpp.o.requires:

.PHONY : CMakeFiles/AAL.dir/Algorithms.cpp.o.requires

CMakeFiles/AAL.dir/Algorithms.cpp.o.provides: CMakeFiles/AAL.dir/Algorithms.cpp.o.requires
	$(MAKE) -f CMakeFiles/AAL.dir/build.make CMakeFiles/AAL.dir/Algorithms.cpp.o.provides.build
.PHONY : CMakeFiles/AAL.dir/Algorithms.cpp.o.provides

CMakeFiles/AAL.dir/Algorithms.cpp.o.provides.build: CMakeFiles/AAL.dir/Algorithms.cpp.o


CMakeFiles/AAL.dir/Worker.cpp.o: CMakeFiles/AAL.dir/flags.make
CMakeFiles/AAL.dir/Worker.cpp.o: ../Worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AAL.dir/Worker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AAL.dir/Worker.cpp.o -c /home/Wasiollo/CLionProjects/AAL/Worker.cpp

CMakeFiles/AAL.dir/Worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AAL.dir/Worker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Wasiollo/CLionProjects/AAL/Worker.cpp > CMakeFiles/AAL.dir/Worker.cpp.i

CMakeFiles/AAL.dir/Worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AAL.dir/Worker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Wasiollo/CLionProjects/AAL/Worker.cpp -o CMakeFiles/AAL.dir/Worker.cpp.s

CMakeFiles/AAL.dir/Worker.cpp.o.requires:

.PHONY : CMakeFiles/AAL.dir/Worker.cpp.o.requires

CMakeFiles/AAL.dir/Worker.cpp.o.provides: CMakeFiles/AAL.dir/Worker.cpp.o.requires
	$(MAKE) -f CMakeFiles/AAL.dir/build.make CMakeFiles/AAL.dir/Worker.cpp.o.provides.build
.PHONY : CMakeFiles/AAL.dir/Worker.cpp.o.provides

CMakeFiles/AAL.dir/Worker.cpp.o.provides.build: CMakeFiles/AAL.dir/Worker.cpp.o


# Object files for target AAL
AAL_OBJECTS = \
"CMakeFiles/AAL.dir/main.cpp.o" \
"CMakeFiles/AAL.dir/InputOutput.cpp.o" \
"CMakeFiles/AAL.dir/Generator.cpp.o" \
"CMakeFiles/AAL.dir/Algorithms.cpp.o" \
"CMakeFiles/AAL.dir/Worker.cpp.o"

# External object files for target AAL
AAL_EXTERNAL_OBJECTS =

AAL: CMakeFiles/AAL.dir/main.cpp.o
AAL: CMakeFiles/AAL.dir/InputOutput.cpp.o
AAL: CMakeFiles/AAL.dir/Generator.cpp.o
AAL: CMakeFiles/AAL.dir/Algorithms.cpp.o
AAL: CMakeFiles/AAL.dir/Worker.cpp.o
AAL: CMakeFiles/AAL.dir/build.make
AAL: CMakeFiles/AAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable AAL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AAL.dir/build: AAL

.PHONY : CMakeFiles/AAL.dir/build

CMakeFiles/AAL.dir/requires: CMakeFiles/AAL.dir/main.cpp.o.requires
CMakeFiles/AAL.dir/requires: CMakeFiles/AAL.dir/InputOutput.cpp.o.requires
CMakeFiles/AAL.dir/requires: CMakeFiles/AAL.dir/Generator.cpp.o.requires
CMakeFiles/AAL.dir/requires: CMakeFiles/AAL.dir/Algorithms.cpp.o.requires
CMakeFiles/AAL.dir/requires: CMakeFiles/AAL.dir/Worker.cpp.o.requires

.PHONY : CMakeFiles/AAL.dir/requires

CMakeFiles/AAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AAL.dir/clean

CMakeFiles/AAL.dir/depend:
	cd /home/Wasiollo/CLionProjects/AAL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Wasiollo/CLionProjects/AAL /home/Wasiollo/CLionProjects/AAL /home/Wasiollo/CLionProjects/AAL/cmake-build-debug /home/Wasiollo/CLionProjects/AAL/cmake-build-debug /home/Wasiollo/CLionProjects/AAL/cmake-build-debug/CMakeFiles/AAL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AAL.dir/depend

