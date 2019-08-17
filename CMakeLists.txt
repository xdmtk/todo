cmake_minimum_required (VERSION 2.8)
project (todo)


set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost)
find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories("include")

file(GLOB todo_src 
    "src/*.cpp"
)

add_executable (todo ${todo_src})
target_link_libraries(todo ${CURSES_LIBRARIES})
target_link_libraries(todo ${Boost_LIBRARIES})


