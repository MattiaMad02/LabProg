cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-1.14.0)

set(gtest_SOURCE_DIR, ./lib/googletest-1.14.0)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST-SOURCE_FILES
        runAllTests.cpp
        activityTest.cpp
        todolistTest.cpp
        dateTest.cpp)
add_executable(runLabProgrTests ${TEST-SOURCE_FILES})
target_link_libraries(runLabProgrTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)