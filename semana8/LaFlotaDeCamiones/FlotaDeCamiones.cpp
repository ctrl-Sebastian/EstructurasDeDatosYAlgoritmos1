#include<iostream>
using namespace std;

int main()
{
    for (int i = 0; i <= 500; i++)
    {
        int num = i;
        int cuadrado = num*num;

        if(i < 100)
        {
            if(cuadrado % 100 == num)
            {
                cout << num << " forma parte de la flota"<< "(" << cuadrado << ")"  << endl;
            }
        }
        else {
            if(cuadrado % 1000 == num)
            {
                cout << num << " forma parte de la flota"  << "(" << cuadrado << ")" << endl;
            }
        }
    }
    

    return 0;
}