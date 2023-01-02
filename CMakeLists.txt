cmake_minimum_required(VERSION 3.16.0)

project(SDL2_ProjectTemplate)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

set(SDL2_DIR ${PROJECT_SOURCE_DIR}/3rdparty/SDL2/cmake)
set(SDL2_IMAGE_LIBRARY SDL2_image)
set(SDL2_SHARED_LIBRARIES_DIR ${PROJECT_SOURCE_DIR}/3rdparty/SDL2/x86_64-w64-mingw32/bin)

find_package(SDL2 REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/src
)

add_executable(
    SDL2_ProjectTemplate
    ${PROJECT_SOURCE_DIR}/src/Main.cpp
)

target_link_libraries(
    SDL2_ProjectTemplate
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARY}
)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SDL2_SHARED_LIBRARIES_DIR}"
        "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>"    
)
