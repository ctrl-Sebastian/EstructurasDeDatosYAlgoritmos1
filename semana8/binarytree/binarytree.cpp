#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
    Nodo *padre;
};

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo -> dato = n;
    nuevoNodo -> izq = NULL;
    nuevoNodo -> der = NULL;
    nuevoNodo -> padre = padre;

    return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre)
{
    if(arbol == NULL)
    {
        Nodo *nuevoNodo = crearNodo(n, padre);
        arbol = nuevoNodo;
    }
    else
    {
        int valorDeLaRaiz = arbol -> dato;
        if(n < valorDeLaRaiz)
        {
            insertarNodo(arbol->izq, n, arbol);
        }
        else
        {
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->der, cont+1);
        for (int i = 0; i < cont; i++)
        {
            cout << "   ";
        }
        cout<< arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);
        
    }
}

bool busqueda(Nodo *arbol, int n)
{
    if(arbol == NULL)
    {
        return false;
    }
    else if (arbol -> dato == n)
    {
        return true;
    } 
    else if (n < arbol -> dato)
    {
        return busqueda(arbol->izq, n);
    }
    else 
    {
        return busqueda(arbol->der, n);
    }
}

void preOrden(Nodo *arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol ->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void inOrden(Nodo *arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        inOrden(arbol->izq);
        cout << arbol ->dato << " - ";
        inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol)
{
    if(arbol == NULL)
    {
        return;
    }
    else
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol ->dato << " - ";
}
    }

Nodo *minimo(Nodo* arbol)
{
    if(arbol == NULL)
    {
        return NULL;
    }
    if(arbol -> izq)
    {
        return minimo(arbol ->izq);
    }
    else {
        return arbol;
    }
}

void reemplazar(Nodo *arbol, Nodo*nuevoNodo)
{
    if(arbol -> padre)
    {
        if(arbol->dato == arbol->padre->izq->dato)
        {
            arbol ->padre->izq = nuevoNodo;
        }
        else if (arbol ->dato == arbol->padre->der->dato)
        {
            arbol -> padre -> der = nuevoNodo;
        }
    }
    if(nuevoNodo)
    {
        nuevoNodo ->padre = arbol ->padre;
    }
}

void destruir(Nodo *nodoAEliminar)
{
    nodoAEliminar ->izq = NULL;
    nodoAEliminar ->der = NULL;
    delete nodoAEliminar;
}

void eliminarNodo(Nodo *nodoAEliminar)
{
    if(nodoAEliminar ->izq && nodoAEliminar ->der)
    {
        Nodo *menor = minimo(nodoAEliminar->der);
        nodoAEliminar -> dato = menor -> dato;
        eliminarNodo(menor);
    }
    else if (nodoAEliminar ->izq)
    {
        reemplazar(nodoAEliminar,nodoAEliminar->izq);
        destruir(nodoAEliminar);
    }
    else if(nodoAEliminar ->der)
    {
        reemplazar(nodoAEliminar,nodoAEliminar->der);
        destruir(nodoAEliminar);
    }
    else
    {
        reemplazar(nodoAEliminar, NULL);
        destruir(nodoAEliminar);
    }

}


void eliminar(Nodo *arbol, int n)
{
    if(arbol == NULL)
    {
        return;
    }
    else if (n < arbol -> dato)
    {
        eliminar(arbol -> izq, n);
    }
    else if (n > arbol -> dato)
    {
        eliminar(arbol -> der, n);
    }
    else {
        eliminarNodo(arbol);
    }
}



void menu()
{
    Nodo *arbol = NULL;
    int dato, opc, contador = 0;

    do
    {
        cout << "\n\t.:MENU:.\n";
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. pre-orden" << endl;
        cout << "5. in-orden" << endl;
        cout << "6. post-orden" << endl;
        cout << "7. eliminar nodo" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;
        
        switch (opc)
        {
        case 1:
            cout << "Digite el dato: "; cin >> dato;
            insertarNodo(arbol, dato, NULL);
            cout << "\n";
            break;

        case 2:
            cout << "\nMostrando arbol completo:\n\n";
            mostrarArbol(arbol,contador);
            cout << "\n";
            system("pause");
            break;
        
        case 3:
            cout << "Digite el numero a buscar: \n\n";
            cin >> dato;
            if(busqueda(arbol, dato))
            {
                cout << "\nEl elemento " << dato << " ha sido encontrado en el arbol.\n";
                system("pause");
            }
            else
            {
                cout << "\nEl elemento " << dato << " no ha sido encontrado en el arbol.\n";
            }
            
            break;

        case 4:
            cout << "\nRecorrido en pre orden: ";
            preOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;

        case 5:
            cout << "\nRecorrido en in orden: ";
            inOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;

        case 6:
            cout << "\nRecorrido en post orden: ";
            postOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        
        case 7:
            cout << "\nDigite el nodo a eliminar: ";
            cin >> dato;
            eliminar(arbol,dato);
            cout << "\n\n";
            system("pause");
            break;
        }
        system("cls");
    } while (opc !=8);
    
}

int main()
{
    menu();

    return 0;
}