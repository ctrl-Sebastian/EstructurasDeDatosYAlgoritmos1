#include <bits/stdc++.h>
using namespace std;

int main(){
    int cadenaMasLarga = 0;
    int invitadoConCadenaMasLarga = 0;
    for (int i = 1; i <= 99; i++)
    {
        int n = i;
        int contador = 0;
        while(n != 4){
            if(n % 2 == 0){
                n /= 2;
                contador++;
            } else {
                n = (3*n)+1;
                contador++;
            }

        }
        if (contador > cadenaMasLarga) {
            cadenaMasLarga = contador;
            invitadoConCadenaMasLarga = i;
        }
    }
    cout << "Cadena mas larga: " << cadenaMasLarga << " del invitado: " << invitadoConCadenaMasLarga << endl;
    
    return 0;
}