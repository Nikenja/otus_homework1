cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/modules)

include(${CMAKE_MODULES_PATH}/GetGitRevisionDescription.cmake)

git_describe(VERSION_FROM_GIT --long)

string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" PROJECT_VERSION_MAJOR "${VERSION_FROM_GIT}" PARENT_SCOPE)
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" PROJECT_VERSION_MINOR "${VERSION_FROM_GIT}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\-[0-9]+\\-g(.*)" "\\1" PROJECT_REVISION "${VERSION_FROM_GIT}")

set(PROJECT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR} PARENT_SCOPE)
set(PROJECT_VERSION_MINOR ${PROJECT_VERSION_MINOR} PARENT_SCOPE)
set(PROJECT_REVISION ${PROJECT_REVISION} PARENT_SCOPE)

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(PROJECT_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(PROJECT_VERSION_PATCH "0")
endif()

set(PROJECT_VERSION_PATCH ${PROJECT_VERSION_PATCH} PARENT_SCOPE)

file(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/version.h)
configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

add_library(versioner versioner.cpp)

target_include_directories(versioner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(versioner PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

add_subdirectory(test)
