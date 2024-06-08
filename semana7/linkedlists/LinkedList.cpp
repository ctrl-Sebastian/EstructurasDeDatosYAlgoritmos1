#include<iostream>
#include <limits>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};


void Insertar(Nodo *&lista, int n){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo -> dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevoNodo;
    }
    else{
        aux2->siguiente = nuevoNodo;
    }

    nuevoNodo ->siguiente = aux1;

    cout << "Elemento " << n << " insertado a la lista\n";

}

void Buscar(Nodo *lista, int n){
    if(lista == NULL) cout << "La lista está vacía\n";
    bool flag = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n){
            flag = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (flag == true){
        cout << "Elemento " << n << " SI ha sido encontrado en lista\n";
    } 
    else {
        cout << "Elemento " << n << " NO ha sido encontrado en lista\n";
    }
}

void Eliminar(Nodo *&lista, int n){
    // lista no vacia
    if(lista != NULL){
        Nodo *auxBorrar;
        Nodo *anterior = NULL;

        auxBorrar = lista;

        // recorrer la lista
        while((auxBorrar != NULL) && (auxBorrar->dato != n)){
            anterior = auxBorrar;
            auxBorrar = auxBorrar -> siguiente;
        }

        if(auxBorrar == NULL)
        {
            cout << "El elemento no fue encontrado\n";
        }
        else if(anterior == NULL){
            lista = lista -> siguiente;
            delete auxBorrar;
        }
        else {
            anterior -> siguiente = auxBorrar->siguiente;
            delete auxBorrar;
        }
    }
    else
    {
        if(lista == NULL) cout << "La lista está vacía\n";
    }
}
 

void Mostrar(Nodo *&lista){
    if(lista == NULL) cout << "La lista está vacía\n";

    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL){
        cout << "[" << actual->dato << "] ->";
        actual = actual -> siguiente;
    }
    cout << "\n";
}


void menu(){
    Nodo *lista = NULL;
    int opcion;
    int dato;
    do
    {
        cout << "\n\t.:MENU:.\n";
        cout << "1. Insertar un elemento a la lista" << endl;
        cout << "2. Buscar un elemento de la lista" << endl;
        cout << "3. Eliminar un elemento de la lista" << endl;
        cout << "4. Mostrar todos los elementos de la lista" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: " << endl;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
                    "para elegir sus respectivas opciones."
                << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                cout << "Digite un numero: ";
                cin >> dato;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
                            "para elegir sus respectivas opciones."
                        << endl;
                    continue;
                }

                Insertar(lista, dato);
                break;

            case 2:

                cout << "digite numero a buscar: ";
                cin >> dato;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
                            "para elegir sus respectivas opciones."
                        << endl;
                    continue;
                }
                Buscar(lista, dato);

                //system("pause");
                break;

            case 3:
                cout << "digite numero a eliminar: ";
                cin >> dato;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 "
                            "para elegir sus respectivas opciones."
                        << endl;
                    continue;
                }
                Eliminar(lista, dato);
                break;

            case 4:
                Mostrar(lista);
                //system("pause");
                break;

            case 5:
                break;
        }

    } while (opcion != 5);
    
}

int main()
{
    menu();

    return 0;
}