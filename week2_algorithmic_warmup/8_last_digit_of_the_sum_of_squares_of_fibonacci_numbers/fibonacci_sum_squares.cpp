#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fib_sum_squares_fast(long long n) {
    int firstLastDigit = get_fibonacci_huge_fast(n, 10);
    if (firstLastDigit < 0) {
        firstLastDigit += 10;
    } 
    int secondLastDigit = get_fibonacci_huge_fast(n+1, 10);
    if (secondLastDigit < 0) {
        secondLastDigit += 10;
    } 
    
    int lastDigit = firstLastDigit * secondLastDigit;
    if (lastDigit >= 10) {
        lastDigit = lastDigit % 10;
    }
   return lastDigit;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fib_sum_squares_fast(n) << '\n';
}
