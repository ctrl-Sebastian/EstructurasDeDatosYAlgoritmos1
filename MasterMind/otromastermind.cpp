/*
Master Mind es un juego que consiste en adivinar 4 números ocultos. Los números están en un
rango de 1 a 6. Tendrá 10 intentos para adivinar a clave oculta de 4 números (o dígitos) entre 1
y 6. La mejor calificación se obtendrá haciendo el mínimo de intentos para adivinar la clave.

RESTRICCIONES:
A. El algoritmo puede generar la clave de manera aleatoria, sin embargo, no debe repetirse
ningún número en celdas distintas, pues de ser así, el nivel no sería para beginners.
B. El algoritmo debe validar la entrada de datos del usuario para indicar si no es válida o si
esta fuera de rango
C. El programa en cada paso deberá colocar las pistas adecuadas:
a. X si el digito no está en la clave seleccionada
b. C si el digito está en la misma posición que la clave, es decir, frente a frente.
c. F si el digito está en la clave seleccionada pero no en la posición correcta

Martes 6 de Febrero del 2024
*/
#include<iostream>//Sirve para la entrada/salida estandar.
#include<stdlib.h>// Se utiliza Para la función system("pause").
#include<ctime>//Para trabajar con funciones relacionadas con el tiempo.
#include<limits>//Para manejar limites de entrada.
using namespace std;

int main() {

    //se utiliza para inicializar la semilla del generador de numeros aleatorios
    srand(time(NULL));

    //c es el numero de intentos del jugador, r es el numero aleatorio que se genera en la clave
    int clave[4] = { 0, 0, 0, 0 }, c = 1, r;

    //Arreglo que almacena la cantidad jugadas que hace el jugador. 
    int jugadas[4] = { 0, 0, 0, 0 };
    string pista[4] = { " ", " ", " ", " " };

    //Inicia un bucle for que se ejecutará cuatro veces, una vez para cada elemento del arreglo clave.
    for (int i = 0; i < 4; i++) {
        //Bucle que comprobara cuando i sea menor a 4
        while (clave[i] == 0) {
            // Asegura que el número este en el rango de 0 a 5, y luego se suma 1 para obtener un número en el rango de 1 a 6.
            r = rand() % 6 + 1;
            if (clave[0] != r && clave[1] != r && clave[2] != r && clave[3] != r) {
                clave[i] = r;
            }
        }
    }

    // El mensaje que se presentara al momento de iniciar el codigo
    cout << "Bienvenido a MASTERMIND." << endl;
    cout << "Master Mind es un juego que consiste en adivinar 4 numeros ocultos que varian del rango de 1 a 6 en maximo 10 intentos." << endl;
    cout << "La mejor calificacion se obtendra haciendo el minimo de intentos para adivinar la clave. " << endl;
    cout << "La dificultad esta puesta en principiante, entonces el mismo numero no puede aparecer mas de una vez en la clave." << endl;
    cout << "Pistas: C (digito en posicion correcta), X (el digito incorrecto), F (digito en posicion incorrecta)" << endl;

    //La cantidad de jugadas
    while (c <= 10) {
        //Presenta en el codigo por cual jugada va el jugador 
        cout << "Jugada #" << c << endl;

        for (int i = 0; i < 4; i++) {
            cout << "Ingrese el digito " << i + 1 << ": ";
            cin >> jugadas[i];

            /*Esta condicional se usa para en caso de que se digite un entero que no sea del 1 al 6.
             O si no es un int, imprima el mensaje, y luego con el cin.clear haga un reinicio en ese intento en especifico,
             y con  el cin.ignore toma todos
             los datos escritos y los borre como intento para luego en la siguiente linea como \n, vuelves a escribir*/

            if (cin.fail() || jugadas[i] < 1 || jugadas[i] > 6) {
                cout << "Entrada invalida. Debe ser un numero entre 1 y 6." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
            }
        }
        //Bucle en donde se comprueban los valores de los arreglos de "jugadas" y "clave"
        for (int i = 0; i < 4; i++) {
            if (jugadas[i] == clave[i]) {
                pista[i] = "C";
            }
            else if (jugadas[i] == clave[0] || jugadas[i] == clave[1] || jugadas[i] == clave[2] || jugadas[i] == clave[3]) {
                pista[i] = "F";
            }
            else {
                pista[i] = "X";
            }
        }
        cout << "Pistas: " << pista[0] << "-" << pista[1] << "-" << pista[2] << "-" << pista[3] << endl;

        if (pista[0] == "C" && pista[1] == "C" && pista[2] == "C" && pista[3] == "C") {
            cout << " Felicidades! Has adivinado la clave!" << endl;
            cout << "Tuviste una calificacion de " << 11 - c << "/10" << endl;
            break;
        }
        c++;
    }
    if (c > 10) {
        cout << "Perdiste. La clave correcta era: " << clave[0] << "-" << clave[1] << "-" << clave[2] << "-" << clave[3] << endl;

    }
    system("pause");
    return 0;
}