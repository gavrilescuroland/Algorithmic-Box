#include <iostream>
#include <vector>

using std::vector;

int maxRevenue(vector<int> profits, vector<int> clicks){
    int revenue = 0;
    // sort the vectors and then add to 'revenue' the products for each index
    return 0;
}



int main() {
    int n;
    std::cout << "n: ";
    std::cin >> n;
    vector<int> profits(n);
    vector<int> clicks(n);
    for (int i = 0; i < n; i++) {
        std::cout << "profits:";
        std::cin >> profits[i];
    }
    for (int i = 0; i < n; i++) {
        std::cout << "clicks:";
        std::cin >> clicks[i];
    }

    std::cout << maxRevenue(profits, clicks) << std::endl;
}
