#include <iostream>
#include <string>
#include <cctype> // Para usar la función isdigit()

using namespace std;

// funcion MasterMind que retorna una string respuesta en funcion del input y la clave
string MasterMind(string input, string clave)
{
    // declaramos la variable result para irle agregando las letras de la respuesta
    string result = "";

    // loop de 4 iteraciones para iterar por cada numero de la entrada del usuario
    for (int i = 0; i < 4; i++)
    {
        // booleano flag para verificar si se lhizo una operación.
        bool flag = false;
        // loop de 4 iteraciones para comparar las letras de la entrada con las letras de la clave y sus posiciones
        for (int j = 0; j < 4; j++)
        {
            // si las letras están en la misma posición y son iguales se le agregua una C a la respuesta
            // flag se hace true para indicar que se hizo una operación
            if (i == j && input[i] == clave[j])
            {
                result += 'C';
                flag = true;
                // si se cumple, continua a la siguiente iteración.
                continue;
            }
            // si no están en la misma posición y los numeros son iguales, agrega una F a la respuesta.
            // flag se hace true para indicar que se hizo una operación
            else if (i != j && input[i] == clave[j]) {
                result += 'F';
                flag = true;
                // si se cumple, continua a la siguiente iteración.
                continue;
            }
        }

        // si se termina de comparar la letra de la entrada con todas 
        // las letras de la clave y no se agregó ni una C o F, se agrega la X
        if (!flag) {
            result += 'X';
        }

    }

    // Luego de comparar todas las letras, devuelve el string result
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


// Valida que el usuario no haga una entrada incorrecta
bool ValidarEntrada(bool entradaValida, string input)
{
    entradaValida = true;
    
    //La funcion asume que todo esta bien hasta que se encuentra un problema en la entrada
    // Valida que la entrada incluya exactamente 4 caracteres

    if (input.size() != 4)
    {
        entradaValida = false;
    }
    else
    {
        // Este conjunto for-else valida que el usuario no introduzca algun caracter no permitido,
        // comparando los valores de la tabla ASCII

        for (char c : input)
        {
            if (int(c) < 49 || int(c) > 54)
            {
                entradaValida = false;
            }
        }
    }
    // Cuando el programa ya sabe que hay algun problema, se le pide al usuario que lo corrija, 
    // dandole pautas en lo que se pudo haber equivocado

    if (entradaValida == false)
    {
        cout << "Entrada no valida. Por favor digitar exactamente 4 digitos y por favor usar solo numeros entre 1 y 6." << endl;
    }

    return entradaValida;
}

int main() {
    string clave = GeneradorClave(); // la clave es igual al string que retorna la funcion GeneradorClave()
    string input;
    string inputsPasados[10];
    string respuestasPasadas[10];
    int j = 0; // variable contador que inicia en 0 e incrementara en 1 cada bucle del juego
    
    bool entradaValida;
    bool haPerdido = true;

    // for loop de 10 a 0 para los ciclos del juego y puntuar al jugador.
    for (int i = 10; i > 0; i--)
    {
        j++;
        cout << endl;
        cout << "--------------" << endl;

        do
        {
            entradaValida = false;

            // si es la primera jugada no imprimir la respuesta pasada y pedir la entrada del jugador
            if(i == 10) {
                cout << i << ".     |"; cin >> input;
            }
            else {

                // imprime i. accede al array de respuestasPasadas y busca el valor que se entro en la iteracion pasada
                // luego permite la entrada al usuario

                cout << i << ". " << respuestasPasadas[j - 1] << " | "; cin >> input;
            }

        // El programa repetira este bucle hasta que la entrada del usuario sea correcta. Se hara por lo menos una validacion, la cual ocurre al final del bucle.
        } while (!ValidarEntrada(entradaValida, input));


        // Agregamos el input y la respuesta generada al array de inputsPasados y de respuestasPasadas respectivamente
        inputsPasados[j] = input;
        respuestasPasadas[j] = MasterMind(input, clave);

        // Si la respuesta es  CCCC, el jugador ganó y se le muestra su puntaje
        if (MasterMind(input, clave) == "CCCC") {
            cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
            haPerdido = false;
            break;
        }

    }

    if(haPerdido== true){
        // Si llegase a terminarse el loop y el jugador no ganó, se le muestra la clave y que perdió.
        cout << "--------------" << endl;
        cout << "Ha perdido, la clave era: " << clave << endl;
    }

    return 0;
}
