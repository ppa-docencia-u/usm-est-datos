#include <iostream>

using namespace std;

// Implementación recursiva (top-down) de Fibonacci
// Tiempo exponencial O(2^n)
long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Ingrese n para obtener Fibonacci: " ; cin >> n;

    long long result = fibonacci(n);
    cout << "El F(" << n << ") número de Fibonacci es: " << result << endl;
    return 0;
}
