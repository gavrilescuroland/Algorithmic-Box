#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search_iterative(const vector<int> &numbers, int x) {
    int left = 0, right = (int) numbers.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x == numbers[mid]) return mid;
        else if (x < numbers[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    vector<int> numbers(n);
    std::cout << "\nEnter elements: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cin >> numbers[i];
    }
    int m;
    std::cout << "\nEnter num of elements to be searched: ";
    std::cin >> m;
    vector<int> b(m);
    std::cout << "\nEnter elements to be searched: ";
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search_iterative(numbers, b[i]) << ' ';
    }

}