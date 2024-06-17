#include<iostream>
using namespace std;

int MultiplicarDigitos(int n, int counter){
    int producto;
    int digito1 = n%10;
    int digito2 = n/=10;
    producto = digito1 * digito2;
    if(producto > 9) {
        counter++;
    }
    else{
        return counter;
    }
    return MultiplicarDigitos(producto, counter);
}

int main()
{
    int counter = 1;
    for (int i = 10; i < 100; i++)
    {
        //cout << "Numero peristente de " << i << " "<< MultiplicarDigitos(i, counter) << endl;
        if(MultiplicarDigitos(i, counter) > 3)
        {
            cout << "El unico numero entero de solo dos digitos cuyo numero persistente es mayor que 3 es: " << i;
        }
    }
    

    return 0;
}