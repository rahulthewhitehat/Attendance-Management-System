cmake_minimum_required(VERSION 3.25)
project(RP_Attendance_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RP_Attendance_Management_System
        admin.cpp
        student.cpp
        teacher.cpp
        user.h)
