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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/ubuntu/WebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/WebServer/cmake

# Include any dependencies generated for this target.
include CMakeFiles/sylar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sylar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sylar.dir/flags.make

CMakeFiles/sylar.dir/sylar/log.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/log.cpp.o: ../sylar/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sylar.dir/sylar/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/log.cpp.o -c /home/ubuntu/WebServer/sylar/log.cpp

CMakeFiles/sylar.dir/sylar/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/log.cpp > CMakeFiles/sylar.dir/sylar/log.cpp.i

CMakeFiles/sylar.dir/sylar/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/log.cpp -o CMakeFiles/sylar.dir/sylar/log.cpp.s

CMakeFiles/sylar.dir/sylar/util.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/util.cpp.o: ../sylar/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sylar.dir/sylar/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/util.cpp.o -c /home/ubuntu/WebServer/sylar/util.cpp

CMakeFiles/sylar.dir/sylar/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/util.cpp > CMakeFiles/sylar.dir/sylar/util.cpp.i

CMakeFiles/sylar.dir/sylar/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/util.cpp -o CMakeFiles/sylar.dir/sylar/util.cpp.s

CMakeFiles/sylar.dir/sylar/config.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/config.cpp.o: ../sylar/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sylar.dir/sylar/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/config.cpp.o -c /home/ubuntu/WebServer/sylar/config.cpp

CMakeFiles/sylar.dir/sylar/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/config.cpp > CMakeFiles/sylar.dir/sylar/config.cpp.i

CMakeFiles/sylar.dir/sylar/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/config.cpp -o CMakeFiles/sylar.dir/sylar/config.cpp.s

CMakeFiles/sylar.dir/sylar/thread.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/thread.cpp.o: ../sylar/thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sylar.dir/sylar/thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/thread.cpp.o -c /home/ubuntu/WebServer/sylar/thread.cpp

CMakeFiles/sylar.dir/sylar/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/thread.cpp > CMakeFiles/sylar.dir/sylar/thread.cpp.i

CMakeFiles/sylar.dir/sylar/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/thread.cpp -o CMakeFiles/sylar.dir/sylar/thread.cpp.s

CMakeFiles/sylar.dir/sylar/fiber.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/fiber.cpp.o: ../sylar/fiber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sylar.dir/sylar/fiber.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/fiber.cpp.o -c /home/ubuntu/WebServer/sylar/fiber.cpp

CMakeFiles/sylar.dir/sylar/fiber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/fiber.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/fiber.cpp > CMakeFiles/sylar.dir/sylar/fiber.cpp.i

CMakeFiles/sylar.dir/sylar/fiber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/fiber.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/fiber.cpp -o CMakeFiles/sylar.dir/sylar/fiber.cpp.s

CMakeFiles/sylar.dir/sylar/scheduler.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/scheduler.cpp.o: ../sylar/scheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sylar.dir/sylar/scheduler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/scheduler.cpp.o -c /home/ubuntu/WebServer/sylar/scheduler.cpp

CMakeFiles/sylar.dir/sylar/scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/scheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/scheduler.cpp > CMakeFiles/sylar.dir/sylar/scheduler.cpp.i

CMakeFiles/sylar.dir/sylar/scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/scheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/scheduler.cpp -o CMakeFiles/sylar.dir/sylar/scheduler.cpp.s

CMakeFiles/sylar.dir/sylar/iomanager.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/iomanager.cpp.o: ../sylar/iomanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sylar.dir/sylar/iomanager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/iomanager.cpp.o -c /home/ubuntu/WebServer/sylar/iomanager.cpp

CMakeFiles/sylar.dir/sylar/iomanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/iomanager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/iomanager.cpp > CMakeFiles/sylar.dir/sylar/iomanager.cpp.i

CMakeFiles/sylar.dir/sylar/iomanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/iomanager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/iomanager.cpp -o CMakeFiles/sylar.dir/sylar/iomanager.cpp.s

CMakeFiles/sylar.dir/sylar/timer.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/timer.cpp.o: ../sylar/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sylar.dir/sylar/timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/timer.cpp.o -c /home/ubuntu/WebServer/sylar/timer.cpp

CMakeFiles/sylar.dir/sylar/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/timer.cpp > CMakeFiles/sylar.dir/sylar/timer.cpp.i

CMakeFiles/sylar.dir/sylar/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/timer.cpp -o CMakeFiles/sylar.dir/sylar/timer.cpp.s

CMakeFiles/sylar.dir/sylar/hook.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/hook.cpp.o: ../sylar/hook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sylar.dir/sylar/hook.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/hook.cpp.o -c /home/ubuntu/WebServer/sylar/hook.cpp

CMakeFiles/sylar.dir/sylar/hook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/hook.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/hook.cpp > CMakeFiles/sylar.dir/sylar/hook.cpp.i

CMakeFiles/sylar.dir/sylar/hook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/hook.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/hook.cpp -o CMakeFiles/sylar.dir/sylar/hook.cpp.s

CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o: ../sylar/fd_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o -c /home/ubuntu/WebServer/sylar/fd_manager.cpp

CMakeFiles/sylar.dir/sylar/fd_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/fd_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/fd_manager.cpp > CMakeFiles/sylar.dir/sylar/fd_manager.cpp.i

CMakeFiles/sylar.dir/sylar/fd_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/fd_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/fd_manager.cpp -o CMakeFiles/sylar.dir/sylar/fd_manager.cpp.s

CMakeFiles/sylar.dir/sylar/address.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/address.cpp.o: ../sylar/address.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sylar.dir/sylar/address.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/address.cpp.o -c /home/ubuntu/WebServer/sylar/address.cpp

CMakeFiles/sylar.dir/sylar/address.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/address.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/address.cpp > CMakeFiles/sylar.dir/sylar/address.cpp.i

CMakeFiles/sylar.dir/sylar/address.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/address.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/address.cpp -o CMakeFiles/sylar.dir/sylar/address.cpp.s

CMakeFiles/sylar.dir/sylar/socket.cpp.o: CMakeFiles/sylar.dir/flags.make
CMakeFiles/sylar.dir/sylar/socket.cpp.o: ../sylar/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/sylar.dir/sylar/socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sylar.dir/sylar/socket.cpp.o -c /home/ubuntu/WebServer/sylar/socket.cpp

CMakeFiles/sylar.dir/sylar/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sylar.dir/sylar/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/WebServer/sylar/socket.cpp > CMakeFiles/sylar.dir/sylar/socket.cpp.i

CMakeFiles/sylar.dir/sylar/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sylar.dir/sylar/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/WebServer/sylar/socket.cpp -o CMakeFiles/sylar.dir/sylar/socket.cpp.s

# Object files for target sylar
sylar_OBJECTS = \
"CMakeFiles/sylar.dir/sylar/log.cpp.o" \
"CMakeFiles/sylar.dir/sylar/util.cpp.o" \
"CMakeFiles/sylar.dir/sylar/config.cpp.o" \
"CMakeFiles/sylar.dir/sylar/thread.cpp.o" \
"CMakeFiles/sylar.dir/sylar/fiber.cpp.o" \
"CMakeFiles/sylar.dir/sylar/scheduler.cpp.o" \
"CMakeFiles/sylar.dir/sylar/iomanager.cpp.o" \
"CMakeFiles/sylar.dir/sylar/timer.cpp.o" \
"CMakeFiles/sylar.dir/sylar/hook.cpp.o" \
"CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o" \
"CMakeFiles/sylar.dir/sylar/address.cpp.o" \
"CMakeFiles/sylar.dir/sylar/socket.cpp.o"

# External object files for target sylar
sylar_EXTERNAL_OBJECTS =

../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/log.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/util.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/config.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/thread.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/fiber.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/scheduler.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/iomanager.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/timer.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/hook.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/fd_manager.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/address.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/sylar/socket.cpp.o
../lib/libsylar.so: CMakeFiles/sylar.dir/build.make
../lib/libsylar.so: CMakeFiles/sylar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/WebServer/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX shared library ../lib/libsylar.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sylar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sylar.dir/build: ../lib/libsylar.so

.PHONY : CMakeFiles/sylar.dir/build

CMakeFiles/sylar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sylar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sylar.dir/clean

CMakeFiles/sylar.dir/depend:
	cd /home/ubuntu/WebServer/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/WebServer /home/ubuntu/WebServer /home/ubuntu/WebServer/cmake /home/ubuntu/WebServer/cmake /home/ubuntu/WebServer/cmake/CMakeFiles/sylar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sylar.dir/depend
