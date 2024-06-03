#include <iostream>
#include <limits>
#include <locale.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
  int dato;
  Nodo *siguiente;
};

void MostrarCola(Nodo *frente) {
  if (frente == NULL) {
    cout << "La cola está vacía" << endl;
  } else {
    while (frente != NULL) {
      cout << "[" << frente->dato << "]->";
      frente = frente->siguiente;
    }
  }
  cout << "\n";
  system("pause");
}

bool ColaVacia(Nodo *frente) { return (frente == NULL) ? true : false; }

void Enqueue(Nodo *&frente, Nodo *&fin, int n) {
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = n;
  nuevoNodo->siguiente = NULL;

  if (ColaVacia(frente)) {
    frente = nuevoNodo;
  } else {
    fin->siguiente = nuevoNodo;
  }

  fin = nuevoNodo;

  cout << "Elemento " << n << " insertado en la cola." << endl;
}

void Dequeue(Nodo *&frente, Nodo *&fin, int &n) {
  n = frente->dato;
  Nodo *aux = frente;

  if (frente == fin) {
    frente = NULL;
    fin = NULL;
  } else {
    frente = frente->siguiente;
  }
  delete aux;
  cout << "Elemento " << n << " eliminado de la cola." << endl;
}

void menu() {
  int opc;
  int dato;

  Nodo *frente = NULL;
  Nodo *fin = NULL;

  do {
    cout << "\n\t.:MENU:.\n";
    cout << "1. Insertar un elemento a la cola" << endl;
    cout << "2. Quitar un elemento de la cola" << endl;
    cout << "3. Mostrar todos los elementos de la cola" << endl;
    cout << "4. Quitar todos los elementos de la cola" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: " << endl;
    cin >> opc;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
              "para elegir sus respectivas opciones."
           << endl;
      continue;
    }

    switch (opc) {
        case 1:
            cout << "Digite un numero: ";
            cin >> dato;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nOpción no válida. Por favor, ingrese un número entero." << endl;
                continue;
            }

            // Si la entrada no es valida el menu se repite infinitamente (Otazu)
            Enqueue(frente, fin, dato);
            break;

        case 2:
            Dequeue(frente, fin, dato);
            system("pause");
            break;

        case 3:
            MostrarCola(frente);
            break;

        case 4:
            // INFORMAR QUE LA COLA ESTA VACIA
            if (frente == NULL) {
                cout << "La cola está vacía" << endl;
                system("pause");
                break;
            }

            cout << "\nQuitando los nodos de la cola: \n";

            while (frente != NULL) {

                Dequeue(frente, fin, dato);

                if (frente == NULL) 
                {
                    // INFORMAR QUE LA COLA ESTA VACIA
                    cout << "La cola está vacía" << endl;
                } 
            }

            system("pause");
            break;

        case 5:
            break;
    }

    system("cls");
  } while (opc != 5);
}

int main() {
  setlocale(LC_ALL, "");
  menu();

  return 0;
}