#include <bits/stdc++.h>

using namespace std;

void CalcularPiramide(int bolas) {
    int bolasUsadas = 0;
    int capas = 0;

    while(bolasUsadas <= bolas){
        capas++;
        bolasUsadas += (capas*capas);
    }
    capas--;
    bolasUsadas -= (capas*capas);

    int sobrantes = bolas - bolasUsadas;

    cout << "Capas: " << capas << " " << "Sobrantes: " << sobrantes << endl;
}

int main(){
    int bolas = 10000;
    CalcularPiramide(bolas);
    return 0;
}