# test dbus
cmake_minimum_required(VERSION 3.10)
project(APP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

#-----------------------------------------------
# build sdbus server
#-----------------------------------------------
add_executable(
    sdbus-server

    sdbus-server.cpp
)

target_link_libraries(
    sdbus-server

    sdbus-c++
)

#-----------------------------------------------
# build sdbus client
#-----------------------------------------------
add_executable(
    sdbus-client

    sdbus-client.cpp
)

target_link_libraries(
    sdbus-client

    sdbus-c++
)