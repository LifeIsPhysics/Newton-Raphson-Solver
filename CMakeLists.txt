cmake_minimum_required(VERSION 3.16..3.24)
set(CMAKE_CXX_STANDARD 23)

project(NewtonRaphsonSolver
	VERSION 1.0
	DESCRIPTION "Algorithm to find the root of a function. The Newton Raphson algorithm."
	LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME mytest COMMAND Test)





