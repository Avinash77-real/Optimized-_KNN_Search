#ifndef DATASET_LOADER_HPP
#define DATASET_LOADER_HPP

#include <vector>

class DatasetLoader {
public:
    
    static std::vector<std::vector<double>> loadFashionMNIST(int numSamples, int dimensions);
};

#endif