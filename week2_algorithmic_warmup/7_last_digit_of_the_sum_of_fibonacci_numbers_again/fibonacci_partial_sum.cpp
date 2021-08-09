#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long pisano_period(long m) {
    long long previous = 0;
    long long current = 1;
    long long pisano = 0;

    for (int i = 0; i < m * m; i++) {
        long long temp = current;
        current = (previous + current) % m;
        previous = temp;

        if (previous == 0 && current == 1) {
            pisano = i + 1;
        }
    }

    return pisano;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    
    if (n > m) {
        n = n % pisano_period(m);
    }    
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        if (current >= m) {
            current = current % m;
        }
    }

    return current;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int all = get_fibonacci_huge_fast(to+2, 10) - 1;
    if (all < 0) {
        all += 10;
    }
    // std::cout << all << '\n';

    int decrease = get_fibonacci_huge_fast(from+1, 10) - 1;
    if (decrease < 0) {
        decrease += 10;
    }
    // std::cout << decrease << '\n';

    int result = all - decrease;
    if (result < 0) {
        result += 10;
    }

    return result;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
