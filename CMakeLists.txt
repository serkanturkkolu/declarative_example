cmake_minimum_required(VERSION 3.5)
project(declarative)
set (CMAKE_CXX_STANDARD 17)
file (GLOB SOURCES "*.cc")
add_executable(${PROJECT_NAME} ${SOURCES})