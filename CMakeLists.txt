cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME PXVM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(${PROJECT_NAME})

include_directories(${CMAKE_SOURCE_DIR}/core/header)

file(GLOB_RECURSE SOURCE_DIR ${CMAKE_SOURCE_DIR}/core/source/*.cpp)
file(GLOB_RECURSE HEADER_DIR ${CMAKE_SOURCE_DIR}/core/header/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_DIR} ${HEADER_DIR})

target_link_libraries(${PROJECT_NAME} ${Boost_PROGRAM_OPTIONS_LIBRARY})