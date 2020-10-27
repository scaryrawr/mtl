cmake_minimum_required(VERSION 3.11)
project("mtl"
        VERSION 0.1
        DESCRIPTION "Mike's template library"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(mtl INTERFACE)

target_include_directories(mtl INTERFACE include/)

add_subdirectory(examples)

install(TARGETS mtl)

set(BUILD_EXAMPLES ON)