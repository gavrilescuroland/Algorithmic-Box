#include <iostream>

long long fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n<= 1) return n;
    long long n1 = 1, n2 = 1, n3, sum = 0;
    for (long long i = 2; i < n; i++) {
        n3 = (n1 + n2)%10;
        std::cout << n3 << std::endl;
        n1 = n2;
        n2 = n3;
        sum = sum%10 + n3;
    }
    return sum%10;
}
int main() {
    long long n = 100;
    std::cout << fibonacci_sum_fast(n);
}
