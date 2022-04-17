cmake_minimum_required(VERSION 3.4...3.18)
project(sample_package)

add_subdirectory(pybind11)
pybind11_add_module(sample_package src/main.cpp src/ops.h)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(sample_package
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
