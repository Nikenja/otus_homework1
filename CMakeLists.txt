cmake_minimum_required(VERSION 3.2)

project(otus_homework1)

find_package(Boost COMPONENTS program_options REQUIRED)

enable_testing()

add_subdirectory(lib/versioner)

add_executable(otus_hw1 main.cpp lib/versioner/versioner.cpp)

set_target_properties(otus_hw1 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(otus_hw1
    versioner
    ${Boost_LIBRARIES}
)

install(TARGETS otus_hw1 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Nikenja@yandex.com)

include(CPack)
