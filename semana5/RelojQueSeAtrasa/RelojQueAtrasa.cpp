#include<iostream>
using namespace std;

const int horas = 24;
float Fibonacci(int n)
{
    if(n == 0 || n == 1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
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

    
    for (int i = 1; i <= horas; i++)
    {
        tiempo += ((Fibonacci(i))/(DosElevadoA(i)))*60;
    }
    

    int minutos = (int)(tiempo / 60);
    int segundos = (int)(tiempo) % 60;

    cout << "El reloj se atraso: " << minutos << " minutos y " << segundos << " segundos" << " en " << horas << " horas.";
    
    return 0;
}