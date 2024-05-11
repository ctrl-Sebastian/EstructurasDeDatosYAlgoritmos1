#include <iostream>
#include <string>
#include <cctype> // Para usar la función isdigit()

using namespace std;

string MasterMind(string input, string clave)
{
    string result = "";
    bool flag = false;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(i==j && input[i]==clave[j])
            {
                result +='C';
            }
            else if(i!=j &&input[i]==clave[j]){
                result += 'F';
            }
            else if(input[i]==clave[j])
            {
                continue;
            }
            
        }
        
        
    }
    return result;

}

int main() {
    string input;
    cout << "digite: ";
    cin >> input;

    string clave = "5612";

    cout << MasterMind(input, clave) << endl;

    return 0;
}
