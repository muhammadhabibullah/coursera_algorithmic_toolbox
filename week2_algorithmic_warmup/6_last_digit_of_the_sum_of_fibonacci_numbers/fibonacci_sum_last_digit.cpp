#include <iostream>

int fibonacci_sum_naive(long long n) {
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

long long pisano_period(long long m) {
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
    
    n = n % pisano_period(m);

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


int fibonacci_sum_fast(long long n) {
   int lastDigit = get_fibonacci_huge_fast(n+2, 10) - 1;
   if (lastDigit == -1) {
       return 9;
   }
   return lastDigit;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
