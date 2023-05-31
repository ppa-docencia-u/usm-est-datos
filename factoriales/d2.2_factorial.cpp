#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Desafios 2.2
// Implementar la función factorial de manera recursiva. 
int main() {
    int n;

    cout << "Ingrese un número, entero positivo: ";
    cin >> n;

    cout << n << "! = " << factorial(n) << endl;
    
    return 0;
}