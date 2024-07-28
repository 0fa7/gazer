cmake_minimum_required(VERSION 3.20)

project(gazer)

option(GAZER_ENABLE_TESTING "GAZER_ENABLE_TESTING - Default OFF - Enables unit tests using googletest" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(GAZER_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(GAZER_LIB_SOURCES
    Vec3.cpp)

add_library(${CMAKE_PROJECT_NAME}
    ${GAZER_LIB_SOURCES})

set(GAZER_MAIN_SOURCES
    Gazer.cpp)

add_executable(${CMAKE_PROJECT_NAME}_main
    ${GAZER_MAIN_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_main
    ${CMAKE_PROJECT_NAME})

if(GAZER_ENABLE_TESTING)
    enable_testing()

    find_package(GTest 1.14.0 REQUIRED)
    
    add_subdirectory(tests)
endif()