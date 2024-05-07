#include <bits/stdc++.h>

using namespace std;

int bolas = 10000;
int contador = 0;

void CalcularPiramide(int bolas) {
    int total = 0;
    int capas = 0;

    while(total <= bolas){
        capas++;
        total += (capas*capas);
    }
    capas--;
    total -= (capas*capas);

    int sobrantes = bolas - total;

    cout << "Capas: " << capas << " " << "Sobrantes: " << sobrantes << endl;
}

int main(){
    CalcularPiramide(bolas);
    return 0;
}