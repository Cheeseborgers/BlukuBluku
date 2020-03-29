# bluku bluku Engine
add_subdirectory(engine)
add_subdirectory(include/argpass)
add_subdirectory(include/glad)

# Generic test that uses conan libs
add_executable(blukubluku main.cpp)

target_link_libraries(blukubluku PRIVATE project_options project_warnings argpass glad blukuengine)
