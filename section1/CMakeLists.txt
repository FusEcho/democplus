cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET "RtspClient")

include_directories(
    ${CMAKE_SOURCE_DIR}
)

add_executable(
    ${TARGET}

    main.cpp
    RtspSource.cpp
)

target_link_libraries(
    ${TARGET}

    pthread
    liveMedia
    BasicUsageEnvironment
    groupsock
    UsageEnvironment
)