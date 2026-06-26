cmake_minimum_required(VERSION 3.10)
project(OptimizedKNNSearch VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/DatasetLoader.cpp
    src/NaiveKNN.cpp
    src/KDTree.cpp
    src/RPTree.cpp
)

add_executable(OptimizedKNN ${SOURCES})