cmake_minimum_required(VERSION 3.2)

add_subdirectory(lib)
add_subdirectory(test)

add_executable(otus_hw1 main.cpp lib/versioner.cpp)

set_target_properties(otus_hw1 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_include_directories(otus_hw1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# set_target_properties(test_version PROPERTIES
#     COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#     INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
# )

# target_link_libraries(otus_homework1
#     versioner
# )

# target_link_libraries(test_version
#     ${Boost_LIBRARIES}
#     versioner
# )

# install(TARGETS otus_homework1 RUNTIME DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_CONTACT Nikenja@yandex.com)

# include(CPack)

# enable_testing()

# add_test(test_version test_version)

