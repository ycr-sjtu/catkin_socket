# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ycr/catkin_socket/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ycr/catkin_socket/build

# Include any dependencies generated for this target.
include socket/CMakeFiles/test1.dir/depend.make

# Include the progress variables for this target.
include socket/CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include socket/CMakeFiles/test1.dir/flags.make

socket/CMakeFiles/test1.dir/src/test1.cpp.o: socket/CMakeFiles/test1.dir/flags.make
socket/CMakeFiles/test1.dir/src/test1.cpp.o: /home/ycr/catkin_socket/src/socket/src/test1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ycr/catkin_socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object socket/CMakeFiles/test1.dir/src/test1.cpp.o"
	cd /home/ycr/catkin_socket/build/socket && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test1.dir/src/test1.cpp.o -c /home/ycr/catkin_socket/src/socket/src/test1.cpp

socket/CMakeFiles/test1.dir/src/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test1.dir/src/test1.cpp.i"
	cd /home/ycr/catkin_socket/build/socket && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ycr/catkin_socket/src/socket/src/test1.cpp > CMakeFiles/test1.dir/src/test1.cpp.i

socket/CMakeFiles/test1.dir/src/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test1.dir/src/test1.cpp.s"
	cd /home/ycr/catkin_socket/build/socket && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ycr/catkin_socket/src/socket/src/test1.cpp -o CMakeFiles/test1.dir/src/test1.cpp.s

socket/CMakeFiles/test1.dir/src/test1.cpp.o.requires:

.PHONY : socket/CMakeFiles/test1.dir/src/test1.cpp.o.requires

socket/CMakeFiles/test1.dir/src/test1.cpp.o.provides: socket/CMakeFiles/test1.dir/src/test1.cpp.o.requires
	$(MAKE) -f socket/CMakeFiles/test1.dir/build.make socket/CMakeFiles/test1.dir/src/test1.cpp.o.provides.build
.PHONY : socket/CMakeFiles/test1.dir/src/test1.cpp.o.provides

socket/CMakeFiles/test1.dir/src/test1.cpp.o.provides.build: socket/CMakeFiles/test1.dir/src/test1.cpp.o


# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/src/test1.cpp.o"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

/home/ycr/catkin_socket/devel/lib/socket/test1: socket/CMakeFiles/test1.dir/src/test1.cpp.o
/home/ycr/catkin_socket/devel/lib/socket/test1: socket/CMakeFiles/test1.dir/build.make
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/libroscpp.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/librosconsole.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/librostime.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /opt/ros/melodic/lib/libcpp_common.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/ycr/catkin_socket/devel/lib/socket/test1: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/ycr/catkin_socket/devel/lib/socket/test1: socket/CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ycr/catkin_socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/ycr/catkin_socket/devel/lib/socket/test1"
	cd /home/ycr/catkin_socket/build/socket && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
socket/CMakeFiles/test1.dir/build: /home/ycr/catkin_socket/devel/lib/socket/test1

.PHONY : socket/CMakeFiles/test1.dir/build

socket/CMakeFiles/test1.dir/requires: socket/CMakeFiles/test1.dir/src/test1.cpp.o.requires

.PHONY : socket/CMakeFiles/test1.dir/requires

socket/CMakeFiles/test1.dir/clean:
	cd /home/ycr/catkin_socket/build/socket && $(CMAKE_COMMAND) -P CMakeFiles/test1.dir/cmake_clean.cmake
.PHONY : socket/CMakeFiles/test1.dir/clean

socket/CMakeFiles/test1.dir/depend:
	cd /home/ycr/catkin_socket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ycr/catkin_socket/src /home/ycr/catkin_socket/src/socket /home/ycr/catkin_socket/build /home/ycr/catkin_socket/build/socket /home/ycr/catkin_socket/build/socket/CMakeFiles/test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : socket/CMakeFiles/test1.dir/depend

