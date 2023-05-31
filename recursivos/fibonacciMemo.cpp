#include <iostream>
#include <vector>

//using namespace std;

std::vector<long long> memo;

long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n = 10;
    memo.resize(n + 1, -1);  // Inicialuza memo en -1

    long long result = fibonacci(n);
    std::cout << "El F(" << n << ") número de Fibonacci es: " << result << std::endl;
    return 0;
}
