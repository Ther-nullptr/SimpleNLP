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
CMAKE_SOURCE_DIR = /home/nullptr/open-source/simple-nlp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nullptr/open-source/simple-nlp

# Include any dependencies generated for this target.
include CMakeFiles/nlp_tool.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nlp_tool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nlp_tool.dir/flags.make

CMakeFiles/nlp_tool.dir/src/main.cpp.o: CMakeFiles/nlp_tool.dir/flags.make
CMakeFiles/nlp_tool.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nullptr/open-source/simple-nlp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nlp_tool.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nlp_tool.dir/src/main.cpp.o -c /home/nullptr/open-source/simple-nlp/src/main.cpp

CMakeFiles/nlp_tool.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nlp_tool.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nullptr/open-source/simple-nlp/src/main.cpp > CMakeFiles/nlp_tool.dir/src/main.cpp.i

CMakeFiles/nlp_tool.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nlp_tool.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nullptr/open-source/simple-nlp/src/main.cpp -o CMakeFiles/nlp_tool.dir/src/main.cpp.s

# Object files for target nlp_tool
nlp_tool_OBJECTS = \
"CMakeFiles/nlp_tool.dir/src/main.cpp.o"

# External object files for target nlp_tool
nlp_tool_EXTERNAL_OBJECTS =

nlp_tool: CMakeFiles/nlp_tool.dir/src/main.cpp.o
nlp_tool: CMakeFiles/nlp_tool.dir/build.make
nlp_tool: libsimple_nlp.a
nlp_tool: CMakeFiles/nlp_tool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nullptr/open-source/simple-nlp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nlp_tool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nlp_tool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nlp_tool.dir/build: nlp_tool

.PHONY : CMakeFiles/nlp_tool.dir/build

CMakeFiles/nlp_tool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nlp_tool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nlp_tool.dir/clean

CMakeFiles/nlp_tool.dir/depend:
	cd /home/nullptr/open-source/simple-nlp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nullptr/open-source/simple-nlp /home/nullptr/open-source/simple-nlp /home/nullptr/open-source/simple-nlp /home/nullptr/open-source/simple-nlp /home/nullptr/open-source/simple-nlp/CMakeFiles/nlp_tool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nlp_tool.dir/depend

