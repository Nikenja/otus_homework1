cmake_minimum_required(VERSION 3.2)

set(Boost_USE_STATIC_LIBS   OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(version_test version_test.cpp)

set_target_properties(version_test PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

target_link_libraries(version_test
    ${Boost_LIBRARIES}
    versioner
)

target_include_directories(version_test PRIVATE ${Boost_INCLUDE_DIR})

add_test(version_test version_test)
