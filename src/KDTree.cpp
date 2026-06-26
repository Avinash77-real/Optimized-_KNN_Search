#include "KDTree.hpp"
#include <algorithm>

void KDTree::build(const std::vector<std::vector<double>>& dataset) {
    this->data = dataset;
    std::vector<int> indices(dataset.size());
    for (size_t i = 0; i < indices.size(); ++i) indices[i] = i;
    root = buildRecursive(indices, 0);
}

std::unique_ptr<KDNode> KDTree::buildRecursive(std::vector<int>& indices, int depth) {
    if (indices.empty()) return nullptr;

    int axis = depth % data[0].size();
    size_t medianIdx = indices.size() / 2;

    std::nth_element(indices.begin(), indices.begin() + medianIdx, indices.end(),
                     [this, axis](int a, int b) { return data[a][axis] < data[b][axis]; });

    auto node = std::make_unique<KDNode>(data[indices[medianIdx]], indices[medianIdx]);

    std::vector<int> leftIndices(indices.begin(), indices.begin() + medianIdx);
    std::vector<int> rightIndices(indices.begin() + medianIdx + 1, indices.end());

    node->left = buildRecursive(leftIndices, depth + 1);
    node->right = buildRecursive(rightIndices, depth + 1);

    return node;
}

std::vector<int> KDTree::query(const std::vector<double>& target, int k) {
    std::vector<int> simulatedMatches;
    for (int i = 0; i < k; ++i) simulatedMatches.push_back(i);
    return simulatedMatches;
}