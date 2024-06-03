/*
DOCUMENTACIÓN

ENUNCIADO:
    Una pila (stack) es una estructura de datos en donde el último en entrar es el primero en salir. 
    Construir un programa C++ que simule una pila, utilizando una estructura de datos como la que 
    sigue para los nodos: 
    struct Pila { 
        int dato; 
        Pila *next; 
    }; 

    RESTRICCIONES: 
    A. La pila debe poder realizar las operaciones de Push y Pop. 

    B. Tener en consideración de desplegar un mensaje de “Empty Stack”, cuando se trate de 
    hacer un Pop cuando la pila este vacía. 

    C. El programa debe tener un menú para realizar las operaciones de Push, Pop y Desplegar 
    toda la pila realizando Pops hasta el último nodo. Además, debe tener una opción de 
    salir del programa.

PARTICIPANTES:
    José Javier Otazu Gonzalez - ID: 1118857
    Luis Miguel Heyaime Bayonet - ID: 1119712
    Sebastian Manuel Marrera Santos - ID: 1117460
    Armani DOleo - ID: 1115670
    Antony Cabrera- ID: 1116226
    Eduardo Encarnación - ID: 1117463

FECHA:
    20 DE MAYO 2024
*/

#include<iostream>
#include <limits>
#include <locale.h>
using namespace std;

struct Pila {
    int dato;
    Pila* siguiente;
};

void Push(Pila*& pila, int n) {
    Pila* nuevoNodo = new Pila(); // reservar memoeria para un nodo
    nuevoNodo->dato = n; // igualar el dato que el usuario envie
    nuevoNodo->siguiente = pila; // poner le puntero e igualar a pila
    pila = nuevoNodo; // igualar a pila al nuevo nodo

    cout << "\nElemento " << n << " agregado a Pila correctamente" << endl;
}

void Pop(Pila*& pila, int& n)
{
    if (pila == NULL) {
        cout << "\nEMPTY STACK" << endl;
        return;
    }
    Pila* aux = pila; // crear nodo auxiliar e igualar a pila
    n = aux->dato; // igualar n al dato que tiene aux
    pila = aux->siguiente; // mover pila al nodo sigguiente (anterior)

    delete aux; // eliminar aux

    cout << "\nSe ha eliminado el elemento " << n << " de la pila." << endl;
}

void DesplegarPila(Pila*& pila, int dato)
{
    if (pila == NULL) {
        cout << "EMPTY STACK" << endl;
        return;
    }
    cout << "\nSacando los elementos de la pila: ";
    while (pila != NULL) {
        Pila* aux = pila; // crear nodo auxiliar e igualar a pila
        dato = aux->dato; // igualar n al dato que tiene aux
        pila = aux->siguiente; // mover pila al nodo sigguiente (anterior)

        delete aux; // eliminar aux
        if (pila != NULL) {
            cout << dato << ", ";
        }
        else {
            cout << dato << "." << endl;
            cout << "EMPTY STACK" << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");

    Pila* pila = NULL;
    int dato;

    int opcion;

    bool opcionValida = false;

    do {
        cout << "\nIngrese una opcion: " << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Desplegar pila." << endl;
        cout << "4. Salir.\n" << endl;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error del flujo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar los caracteres restantes en el buffer
            cout << "Opcion no válida. Por favor, ingrese un número entre 1 y 4 para elegir sus respectivas opciones." << endl;
            continue;
        }

        switch (opcion) {
        case 1:
            cout << "\nIngrese el dato a agregar a la pila (numero entero): ";
            cin >> dato;
            if (cin.fail()) {
                cin.clear(); // Limpiar el estado de error del flujo
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar los caracteres restantes en el buffer
                cout << "Entrada no válida. Por favor, ingrese un numero perteneciente al conjunto de los enteros." << endl;
            }
            else {
                Push(pila, dato);
            }
            break;
        case 2:
            Pop(pila, dato);
            break;
        case 3:
            DesplegarPila(pila, dato);
            break;
        case 4:
            cout << "\nUsted eligió salir..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, ingrese un número entre 1 y 4 para elegir sus respectivas opciones." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}