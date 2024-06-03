    #include <iostream>
    #include <limits>
    #include <locale.h>
    #include <stdlib.h>
    using namespace std;

    int tamanoDeCola = 0;

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

    bool ColaVacia(Nodo *frente) {
        return (frente == NULL) ? true : false;
    }

    void Enqueue(Nodo *&frente, Nodo *&fin, int n, int prioridad) {
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->dato = n;
        nuevoNodo->siguiente = NULL;

        if (prioridad > 16) {
            prioridad = 16;
        }
        tamanoDeCola++;
        int posicion = (prioridad * tamanoDeCola) / 16;

        if (ColaVacia(frente)) {
            frente = nuevoNodo;
            fin = nuevoNodo;
        } else if (posicion == 0) { // Insertar al frente si la posición es 0
            nuevoNodo->siguiente = frente;
            frente = nuevoNodo;
        } else {
            Nodo *actual = frente;
            Nodo *anterior = NULL;
            int contador = 0;
            while (actual != NULL && contador < posicion) {
                anterior = actual;
                actual = actual->siguiente;
                contador++;
            }
            
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = actual;
            if (actual == NULL) {
                fin = nuevoNodo;
            }
        }
        cout << "Elemento " << n << " insertado en la cola con prioridad " << prioridad << "." << endl;
    }

    void Dequeue(Nodo *&frente, Nodo *&fin, int &n) {
        if (ColaVacia(frente)) {
            cout << "La cola está vacía, no se puede eliminar." << endl;
            return;
        }
        n = frente->dato;
        Nodo *aux = frente;

        if (frente == fin) {
            frente = NULL;
            fin = NULL;
        } else {
            frente = frente->siguiente;
        }
        delete aux;
        tamanoDeCola--;
        cout << "[Dequeue]:  " << n << " eliminado de la cola." << endl;
    }

    void menu() {
        int opc;
        int dato;
        int prioridad;

        Nodo *frente = NULL;
        Nodo *fin = NULL;

        do {
            cout << "\n\t.:MENU:.\n";
            cout << "1. Insertar un elemento a la cola\n";
            cout << "2. Quitar un elemento de la cola\n";
            cout << "3. Mostrar todos los elementos de la cola\n";
            cout << "4. Quitar todos los elementos de la cola\n";
            cout << "5. Salir\n";
            cout << "Opcion: ";
            cin >> opc;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 5 para elegir sus respectivas opciones." << endl;
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

                    cout << "Digite la prioridad (0-16) [default 16]: ";
                    cin >> prioridad;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        prioridad = 16;
                        cout << "Añadido con prioridad 16" << endl;
                    }

                    Enqueue(frente, fin, dato, prioridad);
                    break;

                case 2:
                    Dequeue(frente, fin, dato);
                    break;

                case 3:
                    MostrarCola(frente);
                    break;

                case 4:
                    if (frente == NULL) {
                        cout << "La cola está vacía" << endl;
                        break;
                    }

                    cout << "\nQuitando los nodos de la cola: ";
                    while (frente != NULL) {
                        Dequeue(frente, fin, dato);
                        if (frente == NULL) {
                            cout << "La cola está vacía" << endl;
                            system("pause");
                        }
                    }
                    break;
                case 5:
                    break;
            }

            system("cls");
        } while (opc != 5);
    }

    int main() {
        /*
            setlocale(LC_ALL, "") establece la configuración regional del programa a la del usuario. 
            Esto afecta a:

            - Idioma: Idioma utilizado para la salida y la ordenación.
            - Región: Afecta el formato de fechas, horas, números y moneda.
            - Codificación de caracteres: Conjunto de caracteres utilizado para la entrada y la salida.
        */

        setlocale(LC_ALL, "");

        menu();
        return 0;
    }