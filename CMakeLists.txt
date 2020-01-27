cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME PXVM)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

project(${PROJECT_NAME})

include_directories(${CMAKE_CURRENT_LIST_DIR}/core/header)

file(GLOB_RECURSE SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/core/source/*.cpp)
file(GLOB_RECURSE HEADER_DIR ${CMAKE_CURRENT_LIST_DIR}/core/header/*.hpp)

if (NOT UNIX)
    find_package(Boost REQUIRED)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

add_executable(${PROJECT_NAME} ${SOURCE_DIR} ${HEADER_DIR})

target_link_libraries(${PROJECT_NAME})