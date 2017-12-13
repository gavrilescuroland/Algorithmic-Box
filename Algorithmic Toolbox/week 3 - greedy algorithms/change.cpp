#include <iostream>


// The goal in this problem is to  nd the minimum number of coins needed to change the input value (an integer)
// into coins with denominations 1, 5, and 10.

int get_change(int m) {
    int num_of_coins = 0;
    while (m) {
        if (m >= 10) {m -= 10; num_of_coins++; std::cout << 10 << " ";}
        else if (m >= 5) {m -= 5; num_of_coins++; std::cout << 5 << " ";}
        else {m -= 1; num_of_coins++; std::cout << 1 << " ";}
    }
    std::cout << std::endl;
    return num_of_coins;
}

int main() {
    int m = 67;
//    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
