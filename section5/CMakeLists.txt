# test dbus
cmake_minimum_required(VERSION 3.10)
project(APP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET "APP")

include_directories(
    ${CMAKE_SOURCE_DIR}
)

add_executable(
    ${TARGET}

    main.cpp
)

target_link_libraries(
    ${TARGET}
    curl
    pthread
    cpr
)