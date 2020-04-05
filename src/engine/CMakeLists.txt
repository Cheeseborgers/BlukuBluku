cmake_minimum_required(VERSION 3.5...3.16)

# This is your project statement. You should always list languages;
# Listing the version is nice here since it sets lots of useful variables
############ Project name and version
set(TEST_MAJOR_VERSION 1)
set(TEST_MINOR_VERSION 0)
set(TEST_PATCH_VERSION 0)
set(TEST_VERSION ${TEST_MAJOR_VERSION}.${TEST_MINOR_VERSION}.${TEST_PATCH_VERSION})
project(Blukuengine VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(libname "libconfig")

add_library(blukuengine STATIC
        engine.cpp
        logger/logger.cpp
        logger/logger.h
        client/client.cpp
        client/client.h
        client/window.cpp
        client/window.h
        client/states/state.cpp
        client/states/state.h
        client/player_config.cpp
        client/player_config.h
        server/server.cpp
        server/server.h
        )

add_subdirectory(include/glfw)
add_subdirectory(include/glad)
add_subdirectory(include/glm)
add_subdirectory(include/libconfig/lib)

target_link_libraries(blukuengine PRIVATE glfw glad config++)

target_include_directories(blukuengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}include/libconfig/lib)