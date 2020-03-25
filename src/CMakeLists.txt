# Generic test that uses conan libs
add_executable(blukubluku main.cpp)
target_link_libraries(
  blukubluku PRIVATE project_options project_warnings)
