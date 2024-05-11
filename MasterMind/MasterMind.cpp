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
    string inputs[10];

    int t = 10, i = 0;

    while(t--)
    {
        cout << t << ". "; cin >> input;
        inputs[i] = input;
    }
    
    do
    {
        cout << "digite: ";
        cin >> input;


        cout << MasterMind(input, clave) << endl;
    } while (MasterMind(input, clave) != "CCCC");
    

    return 0;
}
