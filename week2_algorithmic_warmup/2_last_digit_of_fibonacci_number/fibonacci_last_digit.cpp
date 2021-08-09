#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


int get_fibonacci_last_digit_fast(int n) {
    int fib = 0;
    int next = 1;
    for (int i = 0; i < n; ++i) {
        int tmp = fib + next;
        fib = next;
        if (fib >= 10) {
            fib = fib % 10;
        }
        next = tmp;
        if (next >= 10) {
            next = next % 10;
        }
    }

    return fib;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
