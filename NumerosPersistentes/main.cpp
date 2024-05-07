#include <bits/stdc++.h>

using namespace std;

int multiplyDigits(int num) {
    int product = 1;
    while (num != 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}


int main(){

    int objetivo = 0;

    for (int i = 10; i < 100; i++)
    {
        int n = i;
        int contador = 0;
        while(n >= 10){
            n = multiplyDigits(n);
            contador++;
        }
        if (contador > 3) objetivo = i;
    }
    
    cout << "unico numero entero de solo dos digitos cuyo numero persistente es mayor que 3: " << objetivo << endl;
    return 0;
}