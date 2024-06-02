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
    if(n == 0 || n == 1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main()
{
    cout << Fibonacci(10);

    return 0;
}