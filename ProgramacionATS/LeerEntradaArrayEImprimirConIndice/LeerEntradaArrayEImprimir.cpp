#include<iostream>
using namespace std;
int main()
{
    int t;
    cout << "Ingrese el tamano del array";
    cin>> t;

    int numeros[t];

    for (int i = 0; i < t; i++)
    {
        cout << "ingrese el digito " << i << " del array" << endl;
        cin >> numeros[i];
    }
    
    cout << "Los numeros del array con sus indices son: " << endl;

    for (int i = 0; i < t; i++)
    {
        cout << "indice: " << i << " numero: " << numeros[i] << endl;
    }
    
    return 0;
}