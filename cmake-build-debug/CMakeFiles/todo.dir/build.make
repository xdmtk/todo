# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/nick/JetBrains/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nick/JetBrains/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/prog/todo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/prog/todo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/todo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/todo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo.dir/flags.make

CMakeFiles/todo.dir/src/config.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/config.cpp.o: ../src/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/prog/todo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo.dir/src/config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/config.cpp.o -c /home/nick/prog/todo/src/config.cpp

CMakeFiles/todo.dir/src/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/prog/todo/src/config.cpp > CMakeFiles/todo.dir/src/config.cpp.i

CMakeFiles/todo.dir/src/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/prog/todo/src/config.cpp -o CMakeFiles/todo.dir/src/config.cpp.s

CMakeFiles/todo.dir/src/main.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/prog/todo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/todo.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/main.cpp.o -c /home/nick/prog/todo/src/main.cpp

CMakeFiles/todo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/prog/todo/src/main.cpp > CMakeFiles/todo.dir/src/main.cpp.i

CMakeFiles/todo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/prog/todo/src/main.cpp -o CMakeFiles/todo.dir/src/main.cpp.s

CMakeFiles/todo.dir/src/priority.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/priority.cpp.o: ../src/priority.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/prog/todo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/todo.dir/src/priority.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/priority.cpp.o -c /home/nick/prog/todo/src/priority.cpp

CMakeFiles/todo.dir/src/priority.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/priority.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/prog/todo/src/priority.cpp > CMakeFiles/todo.dir/src/priority.cpp.i

CMakeFiles/todo.dir/src/priority.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/priority.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/prog/todo/src/priority.cpp -o CMakeFiles/todo.dir/src/priority.cpp.s

CMakeFiles/todo.dir/src/todolist.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/src/todolist.cpp.o: ../src/todolist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/prog/todo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/todo.dir/src/todolist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/todo.dir/src/todolist.cpp.o -c /home/nick/prog/todo/src/todolist.cpp

CMakeFiles/todo.dir/src/todolist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/todo.dir/src/todolist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/prog/todo/src/todolist.cpp > CMakeFiles/todo.dir/src/todolist.cpp.i

CMakeFiles/todo.dir/src/todolist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/todo.dir/src/todolist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/prog/todo/src/todolist.cpp -o CMakeFiles/todo.dir/src/todolist.cpp.s

# Object files for target todo
todo_OBJECTS = \
"CMakeFiles/todo.dir/src/config.cpp.o" \
"CMakeFiles/todo.dir/src/main.cpp.o" \
"CMakeFiles/todo.dir/src/priority.cpp.o" \
"CMakeFiles/todo.dir/src/todolist.cpp.o"

# External object files for target todo
todo_EXTERNAL_OBJECTS =

todo: CMakeFiles/todo.dir/src/config.cpp.o
todo: CMakeFiles/todo.dir/src/main.cpp.o
todo: CMakeFiles/todo.dir/src/priority.cpp.o
todo: CMakeFiles/todo.dir/src/todolist.cpp.o
todo: CMakeFiles/todo.dir/build.make
todo: /usr/lib/x86_64-linux-gnu/libcurses.so
todo: /usr/lib/x86_64-linux-gnu/libform.so
todo: CMakeFiles/todo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/prog/todo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable todo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/todo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo.dir/build: todo

.PHONY : CMakeFiles/todo.dir/build

CMakeFiles/todo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/todo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/todo.dir/clean

CMakeFiles/todo.dir/depend:
	cd /home/nick/prog/todo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/prog/todo /home/nick/prog/todo /home/nick/prog/todo/cmake-build-debug /home/nick/prog/todo/cmake-build-debug /home/nick/prog/todo/cmake-build-debug/CMakeFiles/todo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/todo.dir/depend

