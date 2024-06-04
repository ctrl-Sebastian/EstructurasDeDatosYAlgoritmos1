#include<iostream>
using namespace std;

const int horas = 24;
int Fibonacci(int n)
{
    int anterior = 0, actual = 1, suma = 0; 
    if( n == 0) 
        return anterior; 
    for(int i = 2; i <= n; i++) 
    { 
       suma = anterior + actual; 
       anterior = actual; 
       actual = suma; 
    } 
    return actual; 
}

float DosElevadoA(int n)
{
    float pow = 2;
    for (int i = 1; i < n; i++)
    {
        pow *= 2;
    }
    return pow;
}

int main()
{
    float tiempo = 0;

    int j =1;
    for (int i = 0; i < horas; i++)
    {
        cout << Fibonacci(i) << "/" << DosElevadoA(j) << endl;
        tiempo += ((Fibonacci(i))/(DosElevadoA(i)))*60;
        j++;
    }
    

    int minutos = (int)(tiempo / 60);
    int segundos = (int)(tiempo) % 60;

    cout << "El reloj se atraso: " << minutos << " minutos y " << segundos << " segundos" << " en " << horas << " horas.";
    
    return 0;
}