cmake_minimum_required(VERSION 3.6)
project(conjure_arcade_leds)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")


set(SOURCE_FILES main.cpp ws2812-rpi.cpp)
add_executable(conjure_arcade_leds ${SOURCE_FILES})

# ---
# Referenced code:
#   https://stackoverflow.com/questions/34014970/what-difference-lx11-option-vs-target-link-libraries-in-cmake
# ---

find_package(X11 REQUIRED)

message(STATUS "X11_FOUND = ${X11_FOUND}")
message(STATUS "X11_INCLUDE_DIR = ${X11_INCLUDE_DIR}")
message(STATUS "X11_LIBRARIES = ${X11_LIBRARIES}")

include_directories(${X11_INCLUDE_DIR})
link_directories(${X11_LIBRARIES})
target_link_libraries(conjure_arcade_leds ${X11_LIBRARIES})

#--- end of referenced code

