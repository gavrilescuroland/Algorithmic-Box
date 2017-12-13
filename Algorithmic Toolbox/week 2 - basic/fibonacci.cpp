#include <iostream>
#include <cassert>

int fibonacci_naive(int n) {
    if (n <= 1) return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    if (n <= 1) return n;
    int n1 = 1, n2 = 1, n3;
    for (int i = 2; i < n; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; n++) {assert(fibonacci_fast(n) == fibonacci_naive(n));}
}

int main() {
    int n;
    test_solution();
    std::cout << fibonacci_fast(n) << '\n';
}


