#include<iostream>
using namespace std;

/*
    Serie de Fibonacci:
    1 1 2 3 5 8 13 21 34 55 89 144 233 377 610, 987 ...
    dkonde cada termino se define en termino de sus dos anteriores

    f(n) = f(n-1)+f(n-2)
*/

int Fibonacci(int n)
{
    int anterior = 0, actual = 1, suma; 
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

int main()
{
    for (int i = 0; i < 200; i++)
    {
        cout << i << " - " << Fibonacci(i) << endl;
    }
    

    return 0;
}