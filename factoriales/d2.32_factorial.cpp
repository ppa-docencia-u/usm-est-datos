#include <iostream>
#include <iomanip>

using namespace std;

int factorial(int n, int result) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * result;    
}

// Desafios 2.32
// Analizar el código y mejorar para evitar proceso repetitivo
int main() {
    int facto = 1;

    for (int n = 1; n <= 10; n++) {
        facto = factorial(n, facto);
        cout << setw(3) << n  << "! = " << setw(7) << facto << endl;
    }
    return 0;
}