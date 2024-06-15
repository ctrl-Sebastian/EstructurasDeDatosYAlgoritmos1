#include<iostream>
#include<limits>
using namespace std;

int main() {
    int numero;

    cout << "Factores primos de un numero" << endl;
    cout << "Ingrese un numero: ";
    cin >> numero;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
      cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
              "para elegir sus respectivas opciones."
           << endl;
    }

    cout << "\nFactores de " << numero << ": ";

    for (int i=2; numero>1; i++) {

        if ((numero % i == 0) && (numero != i)) {
            cout << i << "*";
            numero /= i;
        }
        if (numero == i) break; 
    }
    cout << numero << endl;
    return 0;
}