add_library(blukuengine STATIC
        engine.cpp
        client/client.cpp
        client/client.h
        client/window.cpp
        client/window.h
        server/server.cpp
        server/server.h)


target_include_directories(blukuengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})