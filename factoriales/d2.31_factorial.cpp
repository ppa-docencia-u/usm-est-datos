#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Desafios 2.31
// 1. Implementar la función factorial de manera iterativa.
// 2. Es necesario que la función factorial sea recursiva? Por qué?
 
int main() {
    for (int n = 1; n <= 10; n++) {
        int result = factorial(n);
        cout << n << "! = " << result << endl;
    }
    return 0;
}