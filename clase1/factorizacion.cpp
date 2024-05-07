#include<iostream>
#include <math.h>
using namespace std;

float FormulaGeneral1(float a, float b, float c, float discriminante)
{
    if(discriminante == 0){
        return (-b/2*a);
    } else if(discriminante > 0)
    {
        return (-b+(sqrt(discriminante)))/(2*a);
    } else if (discriminante < 0)
    {
        return (-b/2*a)+(sqrt(abs(discriminante))/2*a);
    }
}

float FormulaGeneral2(float a, float b, float c, float discriminante)
{
    if(discriminante == 0){
        return (-b/2*a);
    } else if(discriminante > 0)
    {
        return (-b-(sqrt(discriminante)))/(2*a);
    } else if (discriminante < 0)
    {
        return (-b/2*a)-(sqrt(abs(discriminante))/2*a);

    }
}


int main()
{
    float a,b,c;
    float x1,x2;
    float discriminante;

    cout << "Este programa resuelve ax^2+bx+c" << endl;

    cout << "Introduzca el valor de a: ";
    cin >> a;

    cout << "Introduzca el valor de b: ";
    cin >> b;

    cout << "Introduzca el valor de c: ";
    cin >> c;

    discriminante = ((b*b)-(4*a*c));

    if(a == 0)
    {
        if (b == 0)
        {
            cout << "No hay solucion";

        }
        else 
        {
            cout << "solucion unica: " << (-c/b) << endl;
        }
    }
    else if (a != 0)
    {
        if(discriminante == 0){
            cout << "La solucion es real e" << (-b/2*a);
        } else if(discriminante > 0)
        {
            cout << "x1: " << (-b+(sqrt(discriminante)))/(2*a);
        } else if (discriminante < 0)
        {
            return (-b/2*a)+(sqrt(abs(discriminante))/2*a);
        }
    }

    return 0;
}