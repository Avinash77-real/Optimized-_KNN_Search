#include "NaiveKNN.hpp"
#include <cmath>
#include <algorithm>

double calculateDistance(const std::vector<double>& a, const std::vector<double>& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        double diff = a[i] - b[i];
        sum += diff * diff;
    }
    return std::sqrt(sum);
}

void NaiveKNN::build(const std::vector<std::vector<double>>& dataset) {
    this->data = dataset;
}

std::vector<int> NaiveKNN::query(const std::vector<double>& target, int k) {
    std::vector<std::pair<double, int>> distances;
    for (size_t i = 0; i < data.size(); ++i) {
        distances.push_back({calculateDistance(data[i], target), static_cast<int>(i)});
    }
    std::sort(distances.begin(), distances.end());
    
    std::vector<int> result;
    for (int i = 0; i < k && i < (int)distances.size(); ++i) {
        result.push_back(distances[i].second);
    }
    return result;
}