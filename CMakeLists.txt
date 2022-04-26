cmake_minimum_required(VERSION 3.22)
project(Project)

find_package(pybind11 REQUIRED)

pybind11_add_module(example 
	pybind.cpp)

target_link_libraries(example 
	PRIVATE pybind11::module )
	