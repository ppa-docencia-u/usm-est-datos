#include <iostream>

using namespace std;

int main() {
    int suma = 10, contador = 20, y = 10, x;
    
    //suma += ++contador; // 31
    suma += contador++; // 30
    cout << "Suma: " << suma << endl;

    //y = y++;
    //int z = ++y;
    int z = y + 1;
    x = z + y; // 22
    cout << "x: " << x << endl;

    return 0;
}