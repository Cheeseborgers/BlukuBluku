# bluku bluku Engine

add_subdirectory(engine)

add_subdirectory(include/argpass)

# Generic test that uses conan libs
add_executable(blukubluku main.cpp)

find_package(spdlog REQUIRED)

target_link_libraries(blukubluku PRIVATE project_options project_warnings argpass blukuengine PUBLIC spdlog::spdlog)
