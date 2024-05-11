#include <bits/stdc++.h>
using namespace std;

int Fibonnaci(int n){
    if(n == 1 || n == 2) return 1;

    return Fibonnaci(n-1)+Fibonnaci(n-2);
}

float MinutoAtrasadoEnHora(int hora){
    int minutosAtrasados = Fibonnaci(hora)/2;
    return minutosAtrasados;
}

int main()
{
    cout << MinutoAtrasadoEnHora(24) << " minutos atrasados";
    return 0;
}