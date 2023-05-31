#include <iostream>

using namespace std;

// Desafios 2.1
// Implementar la función factorial de manera iterativa. 
int main() {
    int n, factorial=1;

    cout << "Ingrese un número, entero positivo: ";
    cin >> n;

    for (int i = 1; i <= n; i++) 
        factorial *= i;


    cout << n << "! = " << factorial << endl;
    
    return 0;
}