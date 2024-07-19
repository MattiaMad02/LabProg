cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./googletest-1.15.0)
set(gtest_SOURCE_DIR,./googletest-1.15.0/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES RunAllTest.cpp activityTest.cpp todolistTest.cpp)
add_executable(runLabProgrTests ${TEST_SOURCE_FILES})
target_link_libraries(runLabProgrTests gtest_main ${CMAKE_PROJECT_NAME}_)