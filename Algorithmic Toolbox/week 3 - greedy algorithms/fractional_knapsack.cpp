#include <iostream>
#include <vector>

using std::vector;

int get_max_index(vector<int> weights, vector<int> values) {
    int max_i = 0;
    double max_ratio = 0;
    
    // find the best object to steal
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] && (double) values[i] / weights[i] > max_ratio) {
            max_ratio = (double) values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return value;
        int index = get_max_index(weights, values);
        int weight = std::min(capacity, weights[index]);
        value += weight * (double) values[index] / weights[index];
        weights[index] = 0;
        capacity -= weight;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cout << "n, capacity: ";
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Value, weight: ";
        std::cin >> values[i] >> weights[i];
    }

//    std::cout.precision(10);
    std::cout << get_optimal_value(capacity, weights, values) << std::endl;
    return 0;
}
