cmake_minimum_required(VERSION 3.5)


project(LabProgr)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)



set(SOURCE_FILES
        Activity.cpp
        Activity.h
        Date.cpp
        Date.h
        Time.cpp
        Time.h
        TodoList.cpp
        TodoList.h
)


add_executable(${CMAKE_PROJECT_NAME} main.cpp)




add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)




