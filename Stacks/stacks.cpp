#include<iostream>
#include <limits>
using namespace std;

struct Pila{
    int dato;
    Pila *siguiente;
};

void Push(Pila *&pila, int n){
    Pila *nuevoNodo = new Pila(); // reservar memoeria para un nodo
    nuevoNodo -> dato = n; // igualar el dato que el usuario envie
    nuevoNodo -> siguiente = pila; // poner le puntero e igualar a pila
    pila = nuevoNodo; // igualar a pila al nuevo nodo

    cout << "Elemento "<<n<<" agregado a Pila correctamente" << endl;
}

void Pop(Pila *&pila, int &n)
{
    if(pila == NULL){
        cout << "\nEMPTY STACK" << endl;
        return;
    }
    Pila *aux = pila; // crear nodo auxiliar e igualar a pila
    n = aux -> dato; // igualar n al dato que tiene aux
    pila = aux->siguiente; // mover pila al nodo sigguiente (anterior)

    delete aux; // eliminar aux

    cout << "" << endl;
}

void DesplegarPila(Pila *&pila, int dato)
{
    if(pila == NULL){
        cout << "EMPTY STACK" << endl;
        return;
    } 
    cout << "\nSacando los elementos de la pila: ";
    while(pila != NULL){
        Pop(pila, dato);
        if(pila != NULL){
            cout << dato << ", ";
        }
        else{
            cout << dato << "." << endl;
            cout << "EMPTY STACK" << endl;
        }
    }
}

int main()
{
    char rpt;

    Pila *pila = NULL;
    int dato;

    int opcion;

      do {
        cout << "\nIngrese una opcion: " << endl;
        cout << "1. Push." << endl;
        cout << "2. Pop." << endl;
        cout << "3. Desplegar pila." << endl;
        cout << "4. Salir." << endl;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error del flujo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar los caracteres restantes en el buffer
            cout << "Opcion no válida. Por favor, ingrese un número entre 1 y 4 para elegir sus respectivas opciones." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                do {
                    cout << "\nIngrese el dato a agregar a la pila (numero entero): ";
                    cin >> dato;

                    if (cin.fail()) {
                        cin.clear(); // Limpiar el estado de error del flujo
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar los caracteres restantes en el buffer
                        cout << "Entrada no válida. Por favor, ingrese un numero perteneciente al conjunto de los enteros." << endl;
                    } else {
                        Push(pila, dato);
                        cout << "\n¿Desea agregar otro elemento a la PILA (s/n)? ";
                        cin >> rpt;
                    }
                } while ((rpt == 's') || (rpt == 'S'));
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