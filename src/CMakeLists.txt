set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB mcwilliams_SOURCES *.cpp)
add_definitions(-std=c++11)

add_executable(../mcwilliams ${mcwilliams_SOURCES})
