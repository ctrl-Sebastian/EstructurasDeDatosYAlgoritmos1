#include <iostream>
#include <string>
#include <cctype> // Para usar la función isdigit()

using namespace std;

string MasterMind(string input, string clave)
{
    string result = "";
    for (int i = 0; i < 4; i++)
    {
        bool flag = false;
        for (int j = 0; j < 4; j++)
        {
            if(i==j && input[i]==clave[j])
            {
                result +='C';
                flag = true;
                continue;
            }
            else if(i!=j && input[i]==clave[j]){
                result += 'F';
                flag = true;
                continue;
            }
        }
        if (!flag) {
            result += 'X';
        }
        
    }
    return result;

}

int main() {
    string clave = "5612";
    string input;
    string inputsPasados[10];
    string respuestasPasadas[10];
    int j=0;

    for (int i = 10; i > 0; i--)
    {
        if(i == 10)
        {
            j++;
            cout << endl;
            cout << "--------------" << endl;
            cout <<i<<".     |"; cin>> input;

            inputsPasados[j] = input;
            respuestasPasadas[j] = MasterMind(input, clave);

            if(MasterMind(input, clave) == "CCCC"){
                cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
                break;
            }
        } else {
            j++;
            cout << "--------------" << endl;
            cout <<i<<". " << respuestasPasadas[j-1] << " | "; cin>> input;

            inputsPasados[j] = input;
            respuestasPasadas[j] = MasterMind(input, clave);
            if(MasterMind(input, clave) == "CCCC"){
                cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
                break;
            }
        }
        
    }
    
    
    return 0;
}
