#ifndef I_NEAREST_NEIGHBOR_HPP
#define I_NEAREST_NEIGHBOR_HPP

#include <vector>

class INearestNeighbor {
public:
    virtual ~INearestNeighbor() = default;
    virtual void build(const std::vector<std::vector<double>>& dataset) = 0;
    virtual std::vector<int> query(const std::vector<double>& target, int k) = 0;
};

#endif