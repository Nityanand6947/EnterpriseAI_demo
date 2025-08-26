cmake_minimum_required(VERSION 3.10)

project(EnterprisesAI)

# Specify the C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add your source files here, e.g., main.cpp
add_executable(EnterprisesAI AI_Demo.cpp)
