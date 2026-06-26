#ifndef NAIVE_KNN_HPP
#define NAIVE_KNN_HPP

#include "INearestNeighbor.hpp"

class NaiveKNN : public INearestNeighbor {
private:
    std::vector<std::vector<double>> data;
public:
    void build(const std::vector<std::vector<double>>& dataset) override;
    std::vector<int> query(const std::vector<double>& target, int k) override;
};

#endif