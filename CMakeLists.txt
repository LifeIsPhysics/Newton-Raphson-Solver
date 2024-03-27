cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)

project(
  NewtonRaphsonSolver
  VERSION 1.0
  DESCRIPTION
    "Algorithm to find the root of a function. The Newton Raphson algorithm."
  LANGUAGES CXX)

add_executable(NewtonRaphsonSolver src/main.cpp src/solver.cpp src/helper.cpp src/equations.cpp)
enable_testing()
add_test(NAME mytest COMMAND Test)
add_executable(Test src/test.cpp src/equations.cpp src/helper.cpp)
