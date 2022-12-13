cmake_minimum_required(VERSION 3.23)
project(EmployeeManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(EmployeeManagement main.cpp worker/workerManager.cpp worker/workerManager.h)
