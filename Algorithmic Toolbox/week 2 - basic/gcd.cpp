#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int gcd_fast (int a, int b) {
    if (a < b) {int temp = b; b = a; a = temp;}
    while (b) {
        int temp = b;
        b = a%b;
        a = temp;
        std::cout << "(" << a << ", " << b << ")" << std::endl;
    }
    return a;
}

int main() {
    int a = 3918848, b = 1653264;
    std::cout << gcd_fast(a, b) << std::endl;
}
