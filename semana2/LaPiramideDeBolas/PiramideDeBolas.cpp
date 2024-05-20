#include <iostream>

using namespace std;


void CalcularPiramide(int bolas) {
    int totalBolas = bolas;
    int bolasUsadas = 0;
    int capas = 0;

    while(bolasUsadas < bolas){
        if((bolasUsadas + (capas*capas)) > bolas){
            break;
        } else{
            capas++;
            bolasUsadas += (capas*capas);
            totalBolas -= (capas*capas);
        }
    }

    cout << "Se pueden hacer " << capas << " capas." << endl;
    cout << "Sobraran " << totalBolas << " bolas." << endl;
    //cout << "Se usaran " << bolasUsadas << " bolas." <<endl;
}

int main(){
    int bolas = 10000;
    CalcularPiramide(bolas);
    return 0;
}