cmake_minimum_required(VERSION 3.26)
project(LabProgr)

set(CMAKE_CXX_STANDARD 11)


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


add_executable(${CMAKE_PROJECT_NAME} main.cpp

)




