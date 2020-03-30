# bluku bluku Engine

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(engine)

add_subdirectory(include/argpass)

# Generic test that uses conan libs
add_executable(blukubluku main.cpp)

target_link_libraries(blukubluku PRIVATE project_options project_warnings argpass glad blukuengine)
