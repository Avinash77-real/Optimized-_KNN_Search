# Optimized K-Nearest Neighbors (KNN) Search

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=flat&logo=cmake&logoColor=white)

## 📌 Project Overview
This repository contains a high-performance, object-oriented C++ implementation of the K-Nearest Neighbors (KNN) search algorithm as referenced in project files like `{C172B335-8273-491F-9D82-EB291C95266D}.png`. To overcome the computational bottlenecks of naive KNN in high-dimensional spaces, this project implements advanced spatial data structures: **k-dimensional Trees (KD-Trees)** and **Random Projection Trees (RP-Trees)**.

The project simulates performance benchmarking matching high-dimensional **Fashion MNIST** datasets (784 dimensions per sample), demonstrating robust performance improvements over brute-force search methods.

## 📂 Architecture
The project leverages an interface-driven approach for modularity:
* `INearestNeighbor`: The base interface defining the `build()` and `query()` methods.
* `KDTree`: Splits space along axis-aligned bounding boxes.
* `RPTree`: Splits space using random hyperplanes. Highly optimized for high-dimensional datasets.

## 🛠️ Build Instructions
```bash
mkdir build && cd build
cmake ..
make
./OptimizedKNN
