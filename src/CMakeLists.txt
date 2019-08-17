cmake_minimum_required (VERSION 2.8)
project (Todo)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (Todo main.cpp)
target_link_libraries(Todo ${CURSES_LIBRARIES})


