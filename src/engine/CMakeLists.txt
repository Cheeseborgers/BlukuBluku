cmake_minimum_required(VERSION 3.5...3.16)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
project(Blukuengine VERSION 1.0 LANGUAGES CXX)

add_library(blukuengine STATIC
        engine.cpp
        client/client.cpp
        client/client.h
        client/window.cpp
        client/window.h
        server/server.cpp
        server/server.h)

add_subdirectory(include/glfw)
add_subdirectory(include/glad)

target_link_libraries(blukuengine glfw glad)

target_include_directories(blukuengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})