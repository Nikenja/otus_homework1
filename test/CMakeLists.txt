cmake_minimum_required(VERSION 3.2)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../lib ${CMAKE_CURRENT_SOURCE_DIR}/../lib/build)

add_executable(version_test version_test.cpp)

target_include_directories(version_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib ${CMAKE_CURRENT_SOURCE_DIR}/../include)

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

# add_test(version_test versin_test)
