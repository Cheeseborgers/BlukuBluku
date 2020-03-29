project(glad)

add_library(glad STATIC ${PROJECT_SOURCE_DIR}/src/glad.c ${PROJECT_SOURCE_DIR}/include/glad/glad.h)

target_include_directories(glad PUBLIC include)
