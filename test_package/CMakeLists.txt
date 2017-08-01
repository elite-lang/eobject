project(LibTest)
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(libtest test.c)
target_link_libraries(libtest ${CONAN_LIBS})
