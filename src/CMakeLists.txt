cmake_minimum_required (VERSION 2.8) project (todo)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories("../include")

file(GLOB todo_src 
    "*.cpp"
)

add_executable (todo ${todo_src})
target_link_libraries(todo ${CURSES_LIBRARIES})


