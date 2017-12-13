#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int num_of_candies) {
    vector<int> summands;
    int sum = 0;
    int current_prize = 1;
    while (num_of_candies != sum){
        if (num_of_candies - sum >= current_prize){
            sum += current_prize;
            summands.push_back(current_prize);
            current_prize++;
        }
        else {
            summands.back() += num_of_candies - sum;
            return summands;
        }

    }
    return summands;
}

int main() {
    int num_of_candies = 19;
//    std::cin >> n;
    vector<int> summands = optimal_summands(num_of_candies);
    std::cout << summands.size() << '\n';
    for (int i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
