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
include CMakeFiles/philo_three.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_three.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_three.dir/flags.make

CMakeFiles/philo_three.dir/philo_three/philo_three.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/philo_three.c.o: ../philo_three/philo_three.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_three.dir/philo_three/philo_three.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/philo_three.c.o   -c /Users/triou/philosophers/philo_three/philo_three.c

CMakeFiles/philo_three.dir/philo_three/philo_three.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/philo_three.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/philo_three.c > CMakeFiles/philo_three.dir/philo_three/philo_three.c.i

CMakeFiles/philo_three.dir/philo_three/philo_three.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/philo_three.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/philo_three.c -o CMakeFiles/philo_three.dir/philo_three/philo_three.c.s

CMakeFiles/philo_three.dir/philo_three/utils1.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/utils1.c.o: ../philo_three/utils1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_three.dir/philo_three/utils1.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/utils1.c.o   -c /Users/triou/philosophers/philo_three/utils1.c

CMakeFiles/philo_three.dir/philo_three/utils1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/utils1.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/utils1.c > CMakeFiles/philo_three.dir/philo_three/utils1.c.i

CMakeFiles/philo_three.dir/philo_three/utils1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/utils1.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/utils1.c -o CMakeFiles/philo_three.dir/philo_three/utils1.c.s

CMakeFiles/philo_three.dir/philo_three/time.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/time.c.o: ../philo_three/time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_three.dir/philo_three/time.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/time.c.o   -c /Users/triou/philosophers/philo_three/time.c

CMakeFiles/philo_three.dir/philo_three/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/time.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/time.c > CMakeFiles/philo_three.dir/philo_three/time.c.i

CMakeFiles/philo_three.dir/philo_three/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/time.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/time.c -o CMakeFiles/philo_three.dir/philo_three/time.c.s

CMakeFiles/philo_three.dir/philo_three/print.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/print.c.o: ../philo_three/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_three.dir/philo_three/print.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/print.c.o   -c /Users/triou/philosophers/philo_three/print.c

CMakeFiles/philo_three.dir/philo_three/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/print.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/print.c > CMakeFiles/philo_three.dir/philo_three/print.c.i

CMakeFiles/philo_three.dir/philo_three/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/print.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/print.c -o CMakeFiles/philo_three.dir/philo_three/print.c.s

CMakeFiles/philo_three.dir/philo_three/philosopher.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/philosopher.c.o: ../philo_three/philosopher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_three.dir/philo_three/philosopher.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/philosopher.c.o   -c /Users/triou/philosophers/philo_three/philosopher.c

CMakeFiles/philo_three.dir/philo_three/philosopher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/philosopher.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/philosopher.c > CMakeFiles/philo_three.dir/philo_three/philosopher.c.i

CMakeFiles/philo_three.dir/philo_three/philosopher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/philosopher.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/philosopher.c -o CMakeFiles/philo_three.dir/philo_three/philosopher.c.s

CMakeFiles/philo_three.dir/philo_three/monitor.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/monitor.c.o: ../philo_three/monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philo_three.dir/philo_three/monitor.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/monitor.c.o   -c /Users/triou/philosophers/philo_three/monitor.c

CMakeFiles/philo_three.dir/philo_three/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/monitor.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/monitor.c > CMakeFiles/philo_three.dir/philo_three/monitor.c.i

CMakeFiles/philo_three.dir/philo_three/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/monitor.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/monitor.c -o CMakeFiles/philo_three.dir/philo_three/monitor.c.s

CMakeFiles/philo_three.dir/philo_three/config.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/config.c.o: ../philo_three/config.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/philo_three.dir/philo_three/config.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/config.c.o   -c /Users/triou/philosophers/philo_three/config.c

CMakeFiles/philo_three.dir/philo_three/config.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/config.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/config.c > CMakeFiles/philo_three.dir/philo_three/config.c.i

CMakeFiles/philo_three.dir/philo_three/config.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/config.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/config.c -o CMakeFiles/philo_three.dir/philo_three/config.c.s

CMakeFiles/philo_three.dir/philo_three/utils2.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/utils2.c.o: ../philo_three/utils2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/philo_three.dir/philo_three/utils2.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/utils2.c.o   -c /Users/triou/philosophers/philo_three/utils2.c

CMakeFiles/philo_three.dir/philo_three/utils2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/utils2.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/triou/philosophers/philo_three/utils2.c > CMakeFiles/philo_three.dir/philo_three/utils2.c.i

CMakeFiles/philo_three.dir/philo_three/utils2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/utils2.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/triou/philosophers/philo_three/utils2.c -o CMakeFiles/philo_three.dir/philo_three/utils2.c.s

# Object files for target philo_three
philo_three_OBJECTS = \
"CMakeFiles/philo_three.dir/philo_three/philo_three.c.o" \
"CMakeFiles/philo_three.dir/philo_three/utils1.c.o" \
"CMakeFiles/philo_three.dir/philo_three/time.c.o" \
"CMakeFiles/philo_three.dir/philo_three/print.c.o" \
"CMakeFiles/philo_three.dir/philo_three/philosopher.c.o" \
"CMakeFiles/philo_three.dir/philo_three/monitor.c.o" \
"CMakeFiles/philo_three.dir/philo_three/config.c.o" \
"CMakeFiles/philo_three.dir/philo_three/utils2.c.o"

# External object files for target philo_three
philo_three_EXTERNAL_OBJECTS =

philo_three: CMakeFiles/philo_three.dir/philo_three/philo_three.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/utils1.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/time.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/print.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/philosopher.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/monitor.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/config.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/utils2.c.o
philo_three: CMakeFiles/philo_three.dir/build.make
philo_three: CMakeFiles/philo_three.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/triou/philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable philo_three"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_three.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_three.dir/build: philo_three

.PHONY : CMakeFiles/philo_three.dir/build

CMakeFiles/philo_three.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_three.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_three.dir/clean

CMakeFiles/philo_three.dir/depend:
	cd /Users/triou/philosophers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/triou/philosophers /Users/triou/philosophers /Users/triou/philosophers/cmake-build-debug /Users/triou/philosophers/cmake-build-debug /Users/triou/philosophers/cmake-build-debug/CMakeFiles/philo_three.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_three.dir/depend

