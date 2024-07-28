cmake_minimum_required(VERSION 3.20)

set(VEC3_TEST_SOURCES
    Vec3Test.cpp)

add_executable(Vec3Test ${VEC3_TEST_SOURCES})

target_link_libraries(Vec3Test
    gazer
    gtest
    gtest_main)

target_include_directories(Vec3Test PRIVATE
    ${GAZER_ROOT_DIR})

add_test(NAME Vec3Test
    COMMAND Vec3Test)