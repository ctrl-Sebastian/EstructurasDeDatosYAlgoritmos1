#include<iostream>
using namespace std;

int main()
{
    for (int i = 0000; i < 2500; i++)
    {
        int num = i;
        int digitosMinutos = num%100;
        num/=100;
        int digitosHora = num%100;

        if(((digitosHora*digitosHora)+(digitosMinutos*digitosMinutos)) == i)
        {
            if(digitosHora < 10 && digitosMinutos <10)
            {
                cout << "Eran las: " << "0"<< digitosHora << ":" << "0"<<digitosMinutos << endl;
            }
            else if (digitosHora < 10)
            {
                cout << "Eran las: " << "0"<< digitosHora << ":" <<digitosMinutos << endl;

            }
            else if(digitosMinutos <10)
            {
                cout << "Eran las: " << digitosHora << ":" << "0"<<digitosMinutos << endl;
            }
            else{
                cout << "Eran las: " << digitosHora << ":" << digitosMinutos << endl;

            }
        }

        //cout << i << " -> " << "Hora: " << digitosHora << " Minutos: " << digitosMinutos << "->" << ((digitosHora*digitosHora)+(digitosMinutos*digitosMinutos)) <<endl;
    }
    

    return 0;
}