#include "DatasetLoader.hpp"
#include <random>

std::vector<std::vector<double>> DatasetLoader::loadFashionMNIST(int numSamples, int dimensions) {
    std::vector<std::vector<double>> dataset(numSamples, std::vector<double>(dimensions));
    std::mt19937 gen(42); 
    std::uniform_real_distribution<> dis(0.0, 255.0); 

    for (int i = 0; i < numSamples; ++i) {
        for (int j = 0; j < dimensions; ++j) {
            dataset[i][j] = dis(gen);
        }
    }
    return dataset;
}