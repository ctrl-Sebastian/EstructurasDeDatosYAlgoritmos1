#include<iostream>
using namespace std;

int main()
{
    //O(8)
    int floreros = 100;
    int multiplos[] = {11,22,33,44,55,66,77,88};

    for (int i = 0; i < 8; i++)
    {
        if((multiplos[i]+8) % 6 == 0)
        {
            cout << "A Salvador le quedan: " << multiplos[i] << "Floreros por vender";
        }
    }
    

/*
    O(n)
    for (int i = 0; i < floreros; ++i) {
        // Salvador vendio una cantidad de floreros y le quedó cierta cantidad menor de 100 y multiplo de 6
        if ((floreros - i) % 6 == 0) {
            // Hago la variable florerosRestantes igual a esta cantidad que cumple la condicion
            int florerosRestantes = floreros - i;
            
            //Salvador vendio 8 floreros de los que le quedaban y le quedo una cantidad multiplo de 11
            if ((florerosRestantes - 8) % 11 == 0) {
                cout << "A salvador le quedan por vender: " << florerosRestantes - 8 << endl;
            }
        }
    }
*/
    return 0;
}