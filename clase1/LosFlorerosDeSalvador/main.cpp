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
            cout << "A Salvador le quedan: " << i << " floreros ordenados en 11 filas." << endl;
        }
    }
    */

    
    //O(n)
    for (int floreros = 100; floreros > 0; floreros--)
    {
        // A Salvador le queda una cantidad multiplo de 11 que al sumarle 8 es una cantidad multiplo de 6.

        if((floreros % 11 == 0) && ((floreros+8) % 6 == 0))
        {
            cout << "A salvador le quedan: " << floreros << " floreros ordenados en 11 filas." <<endl;
        }
    }
    
    return 0;
}