# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "M:\Jet Brain CLion\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "M:\Jet Brain CLion\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = M:\CExpansion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = M:\CExpansion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CExpansion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CExpansion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CExpansion.dir/flags.make

CMakeFiles/CExpansion.dir/main.c.obj: CMakeFiles/CExpansion.dir/flags.make
CMakeFiles/CExpansion.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=M:\CExpansion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CExpansion.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CExpansion.dir\main.c.obj   -c M:\CExpansion\main.c

CMakeFiles/CExpansion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CExpansion.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E M:\CExpansion\main.c > CMakeFiles\CExpansion.dir\main.c.i

CMakeFiles/CExpansion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CExpansion.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S M:\CExpansion\main.c -o CMakeFiles\CExpansion.dir\main.c.s

CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.obj: CMakeFiles/CExpansion.dir/flags.make
CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.obj: ../LinearList/SequenceList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=M:\CExpansion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CExpansion.dir\LinearList\SequenceList.c.obj   -c M:\CExpansion\LinearList\SequenceList.c

CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E M:\CExpansion\LinearList\SequenceList.c > CMakeFiles\CExpansion.dir\LinearList\SequenceList.c.i

CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S M:\CExpansion\LinearList\SequenceList.c -o CMakeFiles\CExpansion.dir\LinearList\SequenceList.c.s

CMakeFiles/CExpansion.dir/Utls/MathHelper.c.obj: CMakeFiles/CExpansion.dir/flags.make
CMakeFiles/CExpansion.dir/Utls/MathHelper.c.obj: ../Utls/MathHelper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=M:\CExpansion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CExpansion.dir/Utls/MathHelper.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\CExpansion.dir\Utls\MathHelper.c.obj   -c M:\CExpansion\Utls\MathHelper.c

CMakeFiles/CExpansion.dir/Utls/MathHelper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CExpansion.dir/Utls/MathHelper.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E M:\CExpansion\Utls\MathHelper.c > CMakeFiles\CExpansion.dir\Utls\MathHelper.c.i

CMakeFiles/CExpansion.dir/Utls/MathHelper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CExpansion.dir/Utls/MathHelper.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S M:\CExpansion\Utls\MathHelper.c -o CMakeFiles\CExpansion.dir\Utls\MathHelper.c.s

# Object files for target CExpansion
CExpansion_OBJECTS = \
"CMakeFiles/CExpansion.dir/main.c.obj" \
"CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.obj" \
"CMakeFiles/CExpansion.dir/Utls/MathHelper.c.obj"

# External object files for target CExpansion
CExpansion_EXTERNAL_OBJECTS =

CExpansion.exe: CMakeFiles/CExpansion.dir/main.c.obj
CExpansion.exe: CMakeFiles/CExpansion.dir/LinearList/SequenceList.c.obj
CExpansion.exe: CMakeFiles/CExpansion.dir/Utls/MathHelper.c.obj
CExpansion.exe: CMakeFiles/CExpansion.dir/build.make
CExpansion.exe: CMakeFiles/CExpansion.dir/linklibs.rsp
CExpansion.exe: CMakeFiles/CExpansion.dir/objects1.rsp
CExpansion.exe: CMakeFiles/CExpansion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=M:\CExpansion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable CExpansion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CExpansion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CExpansion.dir/build: CExpansion.exe

.PHONY : CMakeFiles/CExpansion.dir/build

CMakeFiles/CExpansion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CExpansion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CExpansion.dir/clean

CMakeFiles/CExpansion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" M:\CExpansion M:\CExpansion M:\CExpansion\cmake-build-debug M:\CExpansion\cmake-build-debug M:\CExpansion\cmake-build-debug\CMakeFiles\CExpansion.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CExpansion.dir/depend
