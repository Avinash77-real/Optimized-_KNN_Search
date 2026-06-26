#ifndef RP_TREE_HPP
#define RP_TREE_HPP

#include "INearestNeighbor.hpp"
#include <memory>

struct RPNode {
    std::vector<double> randomDirection;
    double splitPoint;
    bool isLeaf;
    std::vector<int> pointIndices;
    std::unique_ptr<RPNode> left;
    std::unique_ptr<RPNode> right;
    RPNode() : splitPoint(0.0), isLeaf(false), left(nullptr), right(nullptr) {}
};

class RPTree : public INearestNeighbor {
private:
    std::vector<std::vector<double>> data;
    std::unique_ptr<RPNode> root;
    std::unique_ptr<RPNode> buildRecursive(std::vector<int>& indices);

public:
    void build(const std::vector<std::vector<double>>& dataset) override;
    std::vector<int> query(const std::vector<double>& target, int k) override;
};

#endif