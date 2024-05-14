#include<iostream>
using namespace std;

/*
    ~Cubos Narcisistas~
    -------------------
    Son cubos narcisistas aquellos numeros enteros positivos que son 
    exactamente iguales a la suma de sus digitos elevados al cubo
*/

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        int numero = i;

        int digito3 = numero % 10;
        numero /= 10;
        int digito2 = numero % 10;
        numero /= 10;
        int digito1 = numero;

        //cout << digito1 << digito2  << digito3 << " -> " << ((digito1*digito1*digito1) + (digito2*digito2*digito2) + (digito3*digito3*digito3)) << " -> " << i << endl;

        if(((digito1*digito1*digito1) + (digito2*digito2*digito2) + (digito3*digito3*digito3)) == i)
        {
            cout << "El numero: " << i << " es un cubo narcisista."  << endl;
        }
    }
    

    return 0;
}