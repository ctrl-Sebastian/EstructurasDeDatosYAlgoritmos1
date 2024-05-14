#include<iostream>
using namespace std;

/*
    Haga un programa cpp que imprima los primeros 100 enteros, 
    en el caso de que el entero sea:
    multiplo de 3: sustituya el numero por la palabra coca.
    multiplo de 5: sustituya el numero por la palabra cola.
    multiplo de 3 y 5: sustituya el numero por la palabra cocacola.

*/

int main()
{
    bool flag = false;
    for (int i = 1; i < 100; i++)
    {   
        if(i % 3 == 0)
        {
            cout << "coca";
            flag = true;
        }
        if(i % 5 == 0)
        {
            cout << "cola";
            flag = true;
        } 
        if(!flag)
        {
            cout << i;
        }
        flag = false;
        cout << endl;

        //i % 3 == 0 ? cout << "coca" << endl : i % 5 == 0 ? cout << "cola" << endl : cout << i << endl;
    }
    

    return 0;
}