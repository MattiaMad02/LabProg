cmake_minimum_required(VERSION 3.26)
project(LabProgr)

set(CMAKE_CXX_STANDARD 11)

add_executable(LabProgr main.cpp
        Activity.h
        Date.h
        Time.h
        TodoList.cpp
        TodoList.h
        Activity.cpp
        Date.cpp
        Time.cpp
        LabTest/RunAllTest.cpp
        LabTest/activityTest.cpp
        LabTest/todolistTest.cpp
)
