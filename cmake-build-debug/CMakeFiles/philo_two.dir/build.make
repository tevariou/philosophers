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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/triou/philosophers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/triou/philosophers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_two.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_two.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_two.dir/flags.make

CMakeFiles/philo_two.dir/philo_two/philo_two.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/philo_two/philo_two.c.o: ../philo_two/philo_two.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_two.dir/philo_two/philo_two.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/philo_two/philo_two.c.o   -c /Users/triou/philosophers/philo_two/philo_two.c

CMakeFiles/philo_two.dir/philo_two/philo_two.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/philo_two/philo_two.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_two/philo_two.c > CMakeFiles/philo_two.dir/philo_two/philo_two.c.i

CMakeFiles/philo_two.dir/philo_two/philo_two.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/philo_two/philo_two.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_two/philo_two.c -o CMakeFiles/philo_two.dir/philo_two/philo_two.c.s

# Object files for target philo_two
philo_two_OBJECTS = \
"CMakeFiles/philo_two.dir/philo_two/philo_two.c.o"

# External object files for target philo_two
philo_two_EXTERNAL_OBJECTS =

philo_two: CMakeFiles/philo_two.dir/philo_two/philo_two.c.o
philo_two: CMakeFiles/philo_two.dir/build.make
philo_two: CMakeFiles/philo_two.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable philo_two"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_two.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_two.dir/build: philo_two

.PHONY : CMakeFiles/philo_two.dir/build

CMakeFiles/philo_two.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_two.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_two.dir/clean

CMakeFiles/philo_two.dir/depend:
	cd /Users/triou/philosophers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/triou/philosophers /Users/triou/philosophers /Users/triou/philosophers/cmake-build-debug /Users/triou/philosophers/cmake-build-debug /Users/triou/philosophers/cmake-build-debug/CMakeFiles/philo_two.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_two.dir/depend

