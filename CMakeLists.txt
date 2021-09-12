cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(maze)
find_package(Curses REQUIRED)
include_directories(include)
include_directories(${CURSES_INCLUDE_DIRS})
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp"
                  "${PROJECT_SOURCE_DIR}/include/*.hpp")
add_executable(maze ${SOURCES})
target_link_libraries(maze ${CURSES_LIBRARIES})
