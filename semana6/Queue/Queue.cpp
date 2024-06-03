#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

bool ColaVacia(Nodo *frente)
{
    return (frente == NULL) ? true : false;
}

void Enqueue(Nodo *&frente, Nodo *&fin, int n)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo -> dato = n;
    nuevoNodo -> siguiente = NULL;

    if(ColaVacia(frente))
    {
        frente = nuevoNodo;
    }
    else
    {
        fin -> siguiente = nuevoNodo;
    }

    fin = nuevoNodo;

    cout << "Elemento "<< n << " insertado en la cola." << endl;
}

void Dequeue(Nodo *&frente, Nodo *&fin, int &n)
{
    n = frente -> dato;
    Nodo *aux = frente;

    if(frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente ->siguiente;
    }
    delete aux;
}

void menu()
{
    int opc;
    
    int dato;

    Nodo *frente = NULL;
    Nodo *fin = NULL;

    do{
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar un elemento a la cola" << endl;
        cout << "2. Quitar un elemento de la cola" << endl;
        cout << "3. Mostrar todos los elementos de la cola" << endl;
        cout << "4. Quitar todos los elementos de la cola" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;

        switch(opc)
        {
            case 1: 
                cout << "Digite un numero: ";
                // TODO - VALIDACION DE DATO

                cin >> dato;


                Enqueue(frente, fin, dato);
                break;
            
            case 2: 
                Dequeue(frente, fin, dato);
                break;

            case 3:
                // TODO - FUNCION PARA SOLO MOSTRAR LOS DATOS SIN ELIMINARLOS
                break;

            case 4: 
                cout << "Quitando los nodos de la cola: ";

                // TODO - INFORMAR QUE LA COLA ESTA VACIA

                while(frente != NULL)
                {
                    Dequeue(frente, fin, dato);
                    if(frente != NULL)
                    {
                        cout << dato << " , ";
                    }
                    else
                    {
                        cout << dato << ".";
                        // TODO - INFORMAR QUE LA COLA ESTA VACIA
                    }
                }
                system("pause");
                break;

            case 5: break;
        }
        system("cls");
    }while(opc != 5);
}

int main()
{
    menu();

    return 0;
}