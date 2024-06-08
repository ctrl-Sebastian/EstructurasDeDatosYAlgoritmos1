#include<iostream>
using namespace std;

int main() {
    int numero;

    cout << "Factores primos de un numero" << endl;
    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << "\nFactores de " << numero << ": ";

    for (int i=2; numero>1; i++) {

        while ((numero % i == 0) && (numero != i)) {
            cout << i << "*";
            numero /= i;
        }
        if (numero == i) break; 
    }
    cout << numero << endl;
    return 0;
}