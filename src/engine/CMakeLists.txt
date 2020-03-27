add_library(blukuengine STATIC
        Engine.cpp
        client/Client.cpp
        client/Client.h
        server/Server.cpp
        server/Server.h
        )

target_include_directories(blukuengine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})