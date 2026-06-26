#ifndef KD_TREE_HPP
#define KD_TREE_HPP

#include "INearestNeighbor.hpp"
#include <memory>

struct KDNode {
    std::vector<double> point;
    int index;
    std::unique_ptr<KDNode> left;
    std::unique_ptr<KDNode> right;
    KDNode(std::vector<double> p, int idx) : point(p), index(idx), left(nullptr), right(nullptr) {}
};

class KDTree : public INearestNeighbor {
private:
    std::vector<std::vector<double>> data;
    std::unique_ptr<KDNode> root;
    std::unique_ptr<KDNode> buildRecursive(std::vector<int>& indices, int depth);

public:
    void build(const std::vector<std::vector<double>>& dataset) override;
    std::vector<int> query(const std::vector<double>& target, int k) override;
};

#endif