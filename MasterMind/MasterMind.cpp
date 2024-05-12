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
            if (i == j && input[i] == clave[j])
            {
                result += 'C';
                flag = true;
                continue;
            }
            else if (i != j && input[i] == clave[j]) {
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

int GeneradorNumeros()
{
    return 1 + (rand() % 6);
}


string GeneradorClave()
{
    string clave = "";
    bool DigitosUsados[6] = { false };
    srand(time(NULL));
    
    for (int k = 0; k < 4; k++)
    {
        int num;
        do
        {
            num = GeneradorNumeros();
        } while (DigitosUsados[num - 1]);

        clave += to_string(num);
        DigitosUsados[num - 1] = true;
    }

    return clave;
}

bool ValidarEntrada(bool entradaValida, string input)
{
    entradaValida = true;
    if (input.size() != 4)
    {
        entradaValida = false;
    }
    else
    {
        for (char c : input)
        {
            if (int(c) < 49 || int(c) > 54)
            {
                entradaValida = false;
            }
        }
    }
    if (entradaValida == false)
    {
        cout << "Entrada no valida. Por favor digitar exactamente 4 digitos y por favor usar solo numeros entre 1 y 6." << endl;
    }

    return entradaValida;
}

int main() {
    string clave = GeneradorClave();
    string input;
    string inputsPasados[10];
    string respuestasPasadas[10];
    int j = 0;
    bool entradaValida;

    for (int i = 10; i > 0; i--)
    {
        if (i == 10)
        {
            j++;
            cout << endl;
            cout << "--------------" << endl;
            do
            {
                entradaValida = false;
                cout << i << ".     |"; cin >> input;
            } while (!ValidarEntrada(entradaValida, input));

            inputsPasados[j] = input;
            respuestasPasadas[j] = MasterMind(input, clave);

            if (MasterMind(input, clave) == "CCCC") {
                cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
                break;
            }
        }
        else {
            j++;
            cout << "--------------" << endl;
            do
            {
                entradaValida = true;
                cout << i << ". " << respuestasPasadas[j - 1] << " | "; cin >> input;
            } while (!ValidarEntrada(entradaValida, input));

            inputsPasados[j] = input;
            respuestasPasadas[j] = MasterMind(input, clave);
            if (MasterMind(input, clave) == "CCCC") {
                cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
                break;
            }
        }

    }

    return 0;
}
