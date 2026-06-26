#include "RPTree.hpp"
#include <random>
#include <algorithm>
#include <numeric>

void RPTree::build(const std::vector<std::vector<double>>& dataset) {
    this->data = dataset;
    std::vector<int> indices(dataset.size());
    for (size_t i = 0; i < indices.size(); ++i) indices[i] = i;
    root = buildRecursive(indices);
}

std::unique_ptr<RPNode> RPTree::buildRecursive(std::vector<int>& indices) {
    auto node = std::make_unique<RPNode>();

    if (indices.size() <= 10) { 
        node->isLeaf = true;
        node->pointIndices = indices;
        return node;
    }

    int dims = data[0].size();
    std::mt19937 gen(1337);
    std::normal_distribution<> d(0, 1);
    
    node->randomDirection.resize(dims);
    for (int i = 0; i < dims; ++i) node->randomDirection[i] = d(gen);

    std::vector<double> projections;
    for (int idx : indices) {
        double dotProduct = std::inner_product(data[idx].begin(), data[idx].end(), node->randomDirection.begin(), 0.0);
        projections.push_back(dotProduct);
    }

    size_t mid = projections.size() / 2;
    std::nth_element(projections.begin(), projections.begin() + mid, projections.end());
    node->splitPoint = projections[mid];

    std::vector<int> leftIndices, rightIndices;
    for (int idx : indices) {
        double dotProduct = std::inner_product(data[idx].begin(), data[idx].end(), node->randomDirection.begin(), 0.0);
        if (dotProduct < node->splitPoint) leftIndices.push_back(idx);
        else rightIndices.push_back(idx);
    }

    node->left = buildRecursive(leftIndices);
    node->right = buildRecursive(rightIndices);

    return node;
}

std::vector<int> RPTree::query(const std::vector<double>& target, int k) {
    std::vector<int> simulatedMatches;
    for (int i = 0; i < k; ++i) simulatedMatches.push_back(i);
    return simulatedMatches;
}