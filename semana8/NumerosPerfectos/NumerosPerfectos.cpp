#include<iostream>
using namespace std;

int main()
{
    int sum = 0;
    int i = 1;
    for (int n = 0; n < 1000; n++){
        sum = 0;
        i = 1;
        while(i < n)
        {
            if(n % i == 0)
            {
                sum += i;
                //cout << "divisor " << i << " divide " << n << " -> " << n/i << " suma "<< sum << endl;
            }
            i++;
        }
        if(sum == n)
        {
            cout << n << " es un numero perfecto" << endl;
        }
        
    }


    return 0;
}