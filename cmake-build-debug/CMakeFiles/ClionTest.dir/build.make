# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /opt/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/racso/Odessey/RAID5/ClionTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/racso/Odessey/RAID5/ClionTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClionTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClionTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClionTest.dir/flags.make

CMakeFiles/ClionTest.dir/main.cpp.o: CMakeFiles/ClionTest.dir/flags.make
CMakeFiles/ClionTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/racso/Odessey/RAID5/ClionTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClionTest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClionTest.dir/main.cpp.o -c /home/racso/Odessey/RAID5/ClionTest/main.cpp

CMakeFiles/ClionTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClionTest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/racso/Odessey/RAID5/ClionTest/main.cpp > CMakeFiles/ClionTest.dir/main.cpp.i

CMakeFiles/ClionTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClionTest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/racso/Odessey/RAID5/ClionTest/main.cpp -o CMakeFiles/ClionTest.dir/main.cpp.s

CMakeFiles/ClionTest.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ClionTest.dir/main.cpp.o.requires

CMakeFiles/ClionTest.dir/main.cpp.o.provides: CMakeFiles/ClionTest.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ClionTest.dir/build.make CMakeFiles/ClionTest.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ClionTest.dir/main.cpp.o.provides

CMakeFiles/ClionTest.dir/main.cpp.o.provides.build: CMakeFiles/ClionTest.dir/main.cpp.o


# Object files for target ClionTest
ClionTest_OBJECTS = \
"CMakeFiles/ClionTest.dir/main.cpp.o"

# External object files for target ClionTest
ClionTest_EXTERNAL_OBJECTS =

ClionTest: CMakeFiles/ClionTest.dir/main.cpp.o
ClionTest: CMakeFiles/ClionTest.dir/build.make
ClionTest: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.6.1
ClionTest: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.6.1
ClionTest: /usr/lib/x86_64-linux-gnu/libQt5Sql.so.5.6.1
ClionTest: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.6.1
ClionTest: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.6.1
ClionTest: CMakeFiles/ClionTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/racso/Odessey/RAID5/ClionTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ClionTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClionTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClionTest.dir/build: ClionTest

.PHONY : CMakeFiles/ClionTest.dir/build

CMakeFiles/ClionTest.dir/requires: CMakeFiles/ClionTest.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ClionTest.dir/requires

CMakeFiles/ClionTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClionTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClionTest.dir/clean

CMakeFiles/ClionTest.dir/depend:
	cd /home/racso/Odessey/RAID5/ClionTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/racso/Odessey/RAID5/ClionTest /home/racso/Odessey/RAID5/ClionTest /home/racso/Odessey/RAID5/ClionTest/cmake-build-debug /home/racso/Odessey/RAID5/ClionTest/cmake-build-debug /home/racso/Odessey/RAID5/ClionTest/cmake-build-debug/CMakeFiles/ClionTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClionTest.dir/depend

