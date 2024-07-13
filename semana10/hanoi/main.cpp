#include <iostream>
#include <string>


using namespace std;
const int NUM_TORRES = 3;
const int NUM_DISCOS = 4;

struct Nodo {
    int disco;
    Nodo* sig;

    Nodo(int d) : disco(d), sig(nullptr) {}
};

void inicializarTorres(Nodo* torres[]) {
    for (int i = 0; i < NUM_TORRES; ++i) {
        torres[i] = nullptr; // Inicializa todas las torres como vacías
    }

    // Inicializa la primera torre con los discos
    for (int i = NUM_DISCOS; i >= 1; --i) {
        Nodo* nuevo = new Nodo(i);
        nuevo->sig = torres[0]; // Enlaza el nuevo nodo al principio de la lista
        torres[0] = nuevo; // Actualiza la cabeza de la lista
    }
}

bool validarMovimiento(Nodo* torres[], int desde, int hacia) {
    if (desde < 1 || desde > NUM_TORRES || hacia < 1 || hacia > NUM_TORRES) {
        cout << "Número de torre inválido. Elija entre 1, 2 y 3." << endl;
        system("cls");
        return false;
    }

    if (!torres[desde - 1]) {
        cout << "La torre de origen está vacía. No se puede mover." << endl;
        system("cls");
        return false;
    }

    if (torres[hacia - 1] && torres[hacia - 1]->disco < torres[desde - 1]->disco) {
        cout << "No se puede mover un disco más grande sobre un disco más pequeño." << endl;
        system("cls");
        return false;
    }
    system("cls");
    return true;
}

void mover(Nodo* torres[], int desde, int hacia) {
    if (!validarMovimiento(torres, desde, hacia)) {
        return;
    }

    Nodo* disco = torres[desde - 1];
    torres[desde - 1] = torres[desde - 1]->sig;

    disco->sig = torres[hacia - 1];
    torres[hacia - 1] = disco;

    cout << "Moviendo disco " << disco->disco << " desde Torre " << desde << " hacia Torre " << hacia << endl;
}

int main() {
    Nodo* torres[NUM_TORRES] = { nullptr };

    inicializarTorres(torres);

    int desde, hacia, opcion;
    while (true) {
        // Mostrar ubicación de los discos
        for (int i = 0; i < NUM_TORRES; ++i) {
            cout << "Torre " << i + 1 << ": ";
            Nodo* actual = torres[i];
            while (actual)
            {
                cout << actual->disco << " ";
                actual = actual->sig;
            }
            cout << endl;
        }
        cout << "1. Hacer un movimiento\n2. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;
        Nodo* temp;
        temp = torres[2]; // Accede al tercer elemento del arreglo de punteros
        int contador = 0;

        while (temp != nullptr)
        {
            temp = temp->sig; // Avanza al siguiente nodo en la lista enlazada
            contador++;

            if (contador == 4)
            {
                cout << "¡Haz ganado!";
                return 0;
            }
        }

        switch (opcion) {
        case 1:
            cout << "Mover de la torre (1-3): ";
            cin >> desde;
            cout << "Mover a la torre (1-3): ";
            cin >> hacia;
            mover(torres, desde, hacia);
            break;
        case 2:
            return 0;
        default:
            cout << "Opción inválida. Por favor, intente nuevamente." << endl;
        }
    }

    return 0;
}