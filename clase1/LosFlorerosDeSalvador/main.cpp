#include<iostream>
using namespace std;

int main()
{
    /*
    //O(9)
    for (int i = 11; i <= 88; i+=11)
    {
        if((i+8) % 6 == 0)
        {
            cout << "A Salvador le quedan: " << i << " floreros por vender" << endl;
        }
    }
    */


    //O(n)
    int floreros = 100;
    for (int i = 0; i < floreros; ++i)
    {
        // Salvador vendio una cantidad de floreros y le quedó cierta cantidad menor de 100 y multiplo de 6
        //luego vendio 8 floreros de los que le quedaban y le quedo una cantidad multiplo de 11

        // A Salvador le queda una cantidad multiplo de 11 que al sumarle 8 es una cantidad multiplo de 6.
        if((i % 11 == 0) && ((i+8) % 6 == 0))
        {
            cout << "A salvador le quedan: " << i << " floreros por vender." <<endl;
        }
    }

    return 0;
}