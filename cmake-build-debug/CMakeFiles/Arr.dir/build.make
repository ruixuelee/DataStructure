# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\code\DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\code\DataStructure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Arr.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Arr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Arr.dir/flags.make

CMakeFiles/Arr.dir/Arr.cpp.obj: CMakeFiles/Arr.dir/flags.make
CMakeFiles/Arr.dir/Arr.cpp.obj: ../Arr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\code\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Arr.dir/Arr.cpp.obj"
	D:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Arr.dir\Arr.cpp.obj -c D:\code\DataStructure\Arr.cpp

CMakeFiles/Arr.dir/Arr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arr.dir/Arr.cpp.i"
	D:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\code\DataStructure\Arr.cpp > CMakeFiles\Arr.dir\Arr.cpp.i

CMakeFiles/Arr.dir/Arr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arr.dir/Arr.cpp.s"
	D:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\code\DataStructure\Arr.cpp -o CMakeFiles\Arr.dir\Arr.cpp.s

# Object files for target Arr
Arr_OBJECTS = \
"CMakeFiles/Arr.dir/Arr.cpp.obj"

# External object files for target Arr
Arr_EXTERNAL_OBJECTS =

Arr.exe: CMakeFiles/Arr.dir/Arr.cpp.obj
Arr.exe: CMakeFiles/Arr.dir/build.make
Arr.exe: CMakeFiles/Arr.dir/linklibs.rsp
Arr.exe: CMakeFiles/Arr.dir/objects1.rsp
Arr.exe: CMakeFiles/Arr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\code\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Arr.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Arr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Arr.dir/build: Arr.exe
.PHONY : CMakeFiles/Arr.dir/build

CMakeFiles/Arr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arr.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Arr.dir/clean

CMakeFiles/Arr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\code\DataStructure D:\code\DataStructure D:\code\DataStructure\cmake-build-debug D:\code\DataStructure\cmake-build-debug D:\code\DataStructure\cmake-build-debug\CMakeFiles\Arr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Arr.dir/depend

