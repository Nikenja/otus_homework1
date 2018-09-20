cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/modules)

include(${CMAKE_MODULES_PATH}/GetGitRevisionDescription.cmake)

git_describe(VERSION_FROM_GIT)

string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION_FROM_GIT}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION_FROM_GIT}")

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(otus_homework1 VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(otus_homework1 VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.0)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../include/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/../include/version.h)

add_library(versioner versioner.cpp)

target_include_directories(versioner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/)

set_target_properties(versioner PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

