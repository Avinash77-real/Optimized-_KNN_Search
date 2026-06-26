#include <iostream>
#include <chrono>
#include "DatasetLoader.hpp"
#include "NaiveKNN.hpp"
#include "KDTree.hpp"
#include "RPTree.hpp"

int main() {
    const int SAMPLES = 5000;
    const int DIMENSIONS = 784; 
    const int K = 5;

    std::cout << "========================================\n";
    std::cout << "Loading Simulated Fashion MNIST Dataset...\n";
    std::cout << "========================================\n";
    auto dataset = DatasetLoader::loadFashionMNIST(SAMPLES, DIMENSIONS);
    std::vector<double> targetQuery = dataset[0]; 
    
    std::cout << "[INFO] Dataset loaded with " << SAMPLES << " samples, " << DIMENSIONS << " dimensions.\n\n";

    // 1. Naive KNN Benchmarking
    NaiveKNN naive;
    auto start = std::chrono::high_resolution_clock::now();
    naive.build(dataset);
    naive.query(targetQuery, K);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> naiveTime = end - start;
    std::cout << " [✓] Naive Brute Force KNN Time: " << naiveTime.count() << " ms\n";

    // 2. KD-Tree Benchmarking
    KDTree kdTree;
    start = std::chrono::high_resolution_clock::now();
    kdTree.build(dataset);
    kdTree.query(targetQuery, K);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> kdTime = end - start;
    std::cout << " [✓] Optimized KD-Tree Construction & Query: " << kdTime.count() << " ms\n";

    // 3. RP-Tree Benchmarking
    RPTree rpTree;
    start = std::chrono::high_resolution_clock::now();
    rpTree.build(dataset);
    rpTree.query(targetQuery, K);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> rpTime = end - start;
    std::cout << " [✓] Optimized RP-Tree Construction & Query: " << rpTime.count() << " ms\n";
    std::cout << "========================================\n";

    return 0;
}