cmake_minimum_required(VERSION 3.2)

set(CMAKE_MODULES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

include(${CMAKE_MODULES_PATH}/GetGitRevisionDescription.cmake)

git_describe(VERSION)
message("Version " ${VERSION})


# if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
#     project(otus_homework1 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
# else()
#     project(otus_homework1 VERSION 0.0.1)
# endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(otus_homework1 main.cpp)

add_library(otus_homework1_lib lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(otus_homework1 otus_homework1_lib test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(otus_homework1
    otus_homework1_lib
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    otus_homework1_lib
)

install(TARGETS otus_homework1 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Nikenja@yandex.com)

include(CPack)

enable_testing()

add_test(test_version test_version)

