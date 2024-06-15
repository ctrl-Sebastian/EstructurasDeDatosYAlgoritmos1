#include<iostream>
using namespace std;

const int personas = 99;



int main()
{
    int cadenaMasLarga = 0;
    int invitadoConCadenaMasLarga = 0;
    int counter = 0;
    for (int i = 1; i <= personas; i++)
    {
        int num = i;
        counter = 0;
        while (num != 4)
        {
            if(num % 2 ==0)
            {
                num /= 2;
                counter++;
            }
            else
            {
                num = (num*3)+1;
                counter++;
            }
        }
        if(counter > cadenaMasLarga){
            cadenaMasLarga = counter;
            invitadoConCadenaMasLarga = i;
        }
    }
    cout << "El invitado con la cadena mas larga es el invitado #" << invitadoConCadenaMasLarga << " con una cadena de tamaño: " << cadenaMasLarga;
    
    return 0;
}