project(mcwilliams)
cmake_minimum_required(VERSION 2.6)
add_definitions(-std=c++11)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory(src)

add_executable(mcwilliams rpg.cpp)
target_link_libraries(mcwilliams mcwilliams_lib)

add_subdirectory(test)

add_executable(runTests ${test_SOURCES})
target_link_libraries(runTests gtest
    gtest_main pthread mcwilliams_lib)
add_test(RunUnitTests runTests)
