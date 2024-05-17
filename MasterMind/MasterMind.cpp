#include <iostream>
#include <limits>
#include <cctype> // Para usar la función isdigit()

using namespace std;

void MostrarInstrucciones() {
    // Definir las instrucciones del juego en una cadena de caracteres
    string instrucciones = "Master Mind es un juego que consiste en adivinar 4 numeros ocultos. Los numeros estan en un rango de 1 a 6. Tendras 10 intentos para adivinar la clave oculta de 4 numeros entre 1 y 6. La mejor calificacion se obtendra haciendo el minimo de intentos para adivinar la clave.\n"
    "Para guiarse de que acerto o no:\n"
    "   a. X si el digito no esta en la clave seleccionada.\n"
    "   b. C si el digito esta en la misma posicion que la clave.\n"
    "   c. F si el digito esta en la clave seleccionada pero no en la posicion correcta.\n"
    "Si todos los digitos son 'C', entonces ganas. La puntuacion es 11 menos el numero de intentos.\n";

    // Imprimir las instrucciones del juego
    cout << instrucciones;
}

// funcion MasterMind que retorna una string respuesta en funcion del input y la clave
string MasterMind(int input, int* claveArr)
{
    
    int input4 = input %10;
    input /= 10;
    int input3 = input %10;
    input /= 10;
    int input2 = input %10;
    input /= 10;
    int input1 = input %10;

    int inputArr[4] = {input1, input2, input3, input4};

    // declaramos la variable result para irle agregando las letras de la respuesta
    string result = "";

    // loop de 4 iteraciones para iterar por cada numero de la entrada del usuario
    for (int i = 0; i < 4; i++)
    {
       if (inputArr[i] == claveArr[i]) {
            result += "C";
        }
        else if (inputArr[i] == claveArr[0] || inputArr[i] == claveArr[1] || inputArr[i] == claveArr[2] || inputArr[i] == claveArr[3]) {
            result += "F";
        }
        else {
            result += "X";
        }

    }

    // Luego de comparar todas las letras, devuelve el string result
    return result;
}

// Funcion generadora de clave que devuelve el pointer que guarda la posicion del arreglo clave[4]
int* GeneradorClave()
{
    static int clave[4];
    //creamos otro array de 6 elementos booleanos, incialmente todos son false
    bool DigitosUsados[6] = { false };

     //Creamos la semilla para la funcion rand()
    srand(time(NULL));
    
    for (int k = 0; k < 4; k++)
    {
        int num;
        do
        {
            //generamos un numero random entre 1 y 6, se lo asignamos a una variable local num
            num = 1 + (rand() % 6);
        } while (DigitosUsados[num - 1]);

        //introducimos el numero aleatorio creado en la posicion k del array clave
        clave[k] = num;

        // establecemos true la posicion en el array de boolanos que coincida 
        // con el numero aleatorio generado, de esta forma los digitos no se repiten
        DigitosUsados[num - 1] = true;
    }
    
    // devuolvemos el pointer que guarda la posicion del arreglo clave[4]
    return clave;
}

// Valida que el usuario no haga una entrada incorrecta
bool ValidarEntrada(const string& input)
{
    bool esValida = true;
    // Verificar si la longitud de la entrada es igual a 4
    if (input.length() != 4) {
        cout << "Entrada no valida. Por favor digitar exactamente 4 digitos y por favor usar solo numeros entre 1 y 6." << endl;
        // Limpiar el flujo de entrada
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    // Verificar si cada carácter es un dígito y está en el rango del 1 al 6
    for (char c : input) {
        if (!isdigit(c) || c < '1' || c > '6') {
            cout << "Entrada no valida. Por favor digitar exactamente 4 digitos y por favor usar solo numeros entre 1 y 6." << endl;
            // Limpiar el flujo de entrada
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
    }
    

    // Si pasa todas las verificaciones, la entrada es válida
    return true;
}

int main() {
    int intentos = 10;
    int* clave = GeneradorClave(); // la clave es igual al pointer qque retorna la funcion GeneradorClave() al array clave
    int input;
    string respuestasPasadas[10];
    //int j = 0; // variable contador que inicia en 0 e incrementara en 1 cada bucle del juego
    
    bool haPerdido = true;

    MostrarInstrucciones();

    // for loop de 10 a 0 para los ciclos del juego y puntuar al jugador.
    for (int i = intentos; i > 0; i--)
    {
        //j++;
        cout << endl;
        cout << "--------------" << endl;

        do{

            // si es la primera jugada no imprimir la respuesta pasada y pedir la entrada del jugador
            if(i == intentos) {
                cout << i << ".     |"; cin >> input;
            }
            else {

                // imprime i. accede al array de respuestasPasadas y busca el valor que se entro en la iteracion pasada
                // luego permite la entrada al usuario

                cout << i << ". " << respuestasPasadas[intentos-i - 1] << " | "; cin >> input;
            }

        // El programa repetira este bucle hasta que la entrada del usuario sea correcta. Se hara por lo menos una validacion, la cual ocurre al final del bucle.
        }while(!ValidarEntrada(to_string(input)));


        // Agregamos la respuesta generada al array de respuestasPasadas
        respuestasPasadas[intentos-i] = MasterMind(input, clave);

        // Si la respuesta es  CCCC, el jugador ganó y se le muestra su puntaje
        if (respuestasPasadas[intentos-i] == "CCCC") {
            cout << "Felicidades! ha ganado con un puntaje de: " << i << " puntos" << endl;
            haPerdido = false;
            
            // Espera que el usuario presione enter para salir del programa
            system("pause");
            break;
        }

    }

    if(haPerdido== true){
        // Si llegase a terminarse el loop y el jugador no ganó, se le muestra la clave y que perdió.
        cout << "--------------" << endl;
        cout << "Ha perdido, la clave era: " << clave << endl;

        // Espera que el usuario presione enter para salir del programa
        system("pause"); 
    }

    return 0;
}