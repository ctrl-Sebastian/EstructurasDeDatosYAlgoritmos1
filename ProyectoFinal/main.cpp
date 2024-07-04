#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>  // Para transform
#include <cctype>     // Para tolower y ispunct

using namespace std;

// Función para limpiar una palabra, convirtiéndola a minúsculas y eliminando símbolos
string cleanWord(const string& word) 
{
    string clean;
    for (char ch : word) 
    {
        if (!ispunct(ch)) 
        {
            clean += tolower(ch);
        }
    }
    return clean;
}



class hashtable 
{
private:
    static const int tableSize = 1000;

    struct item 
    {
        string palabra;
        int frecuencia;
        item* siguiente;
    };

    item* HashTable[tableSize];

public:
    hashtable() {
        for (int i = 0; i < tableSize; i++) 
        {
            HashTable[i] = new item;
            HashTable[i]->palabra = "";
            HashTable[i]->frecuencia = 0;
            HashTable[i]->siguiente = NULL;
        }
    }

    int Hash(string key) 
    {
        int hash = 0;
        int index;

        for (int i = 0; i < key.length(); i++) 
        {
            hash = (hash + (int)key[i]);
        }

        index = hash % tableSize;
        return index;
    }

    void AddItem(string palabra) 
    {
        int index = Hash(palabra);
        if (HashTable[index]->palabra == "") 
        {
            HashTable[index]->palabra = palabra;
            HashTable[index]->frecuencia++;
        }
        else if (HashTable[index]->palabra == palabra) 
        {
            HashTable[index]->frecuencia++;
        }
        else {
            item* Ptr = HashTable[index];
            while (Ptr->siguiente != NULL) 
            {
                if (Ptr->palabra == palabra) 
                {
                    Ptr->frecuencia++;
                    return;
                }
                Ptr = Ptr->siguiente;
            }
            if (Ptr->palabra == palabra) 
            {
                Ptr->frecuencia++;
                return;
            }
            item* n = new item;
            n->palabra = palabra;
            n->frecuencia = 1;
            n->siguiente = NULL;
            Ptr->siguiente = n;
        }
    }

    int NumeroDeItemsEnIndice(int index) 
    {
        int count = 0;
        if (HashTable[index]->palabra == "") 
        {
            return count;
        }
        else 
        {
            count++;
            item* Ptr = HashTable[index];
            while (Ptr->siguiente != NULL) 
            {
                count++;
                Ptr = Ptr->siguiente;
            }
        }
        return count;
    }

    void ImprimirTabla() 
    {
        for (int i = 0; i < tableSize; i++) 
        {
            int num = NumeroDeItemsEnIndice(i);
            if (num != 0) 
            {
                ImprimirItemsEnIndice(i);
            }
        }
    }

    void ImprimirItemsEnIndice(int index) 
    {
        item* Ptr = HashTable[index];

        cout << "\n\n\n\nIndice = " << index << endl;
        while (Ptr != NULL) 
        {
            cout << "---------------------" << endl;
            cout << "palabra: " << Ptr->palabra << endl;
            cout << "frecuencia: " << Ptr->frecuencia << endl;
            cout << "---------------------\n";
            Ptr = Ptr->siguiente;
        }
    }

    void FillArray(item* palabras[], int& count) {
        count = 0;
        for (int i = 0; i < tableSize; i++) {
            item* Ptr = HashTable[i];
            while (Ptr != NULL && Ptr->palabra != "") {
                palabras[count++] = Ptr;
                Ptr = Ptr->siguiente;
            }
        }
    }
    
    int Partition(item* palabras[], int low, int high) {
        int pivot = palabras[high]->frecuencia;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (palabras[j]->frecuencia > pivot) {
                i++;
                swap(palabras[i], palabras[j]);
            }
        }
        swap(palabras[i + 1], palabras[high]);
        return i + 1;
    }

    void QuickSort(item* palabras[], int low, int high) {
        if (low < high) {
            int pi = Partition(palabras, low, high);
            QuickSort(palabras, low, pi - 1);
            QuickSort(palabras, pi + 1, high);
        }
    }

    void ImprimirTopFrecuencias() {
        item* palabras[tableSize];
        int count;
        FillArray(palabras, count);
        QuickSort(palabras, 0, count-1);

        cout << "Las 10 palabras con mayor frecuencia son:" << endl;
        for (int i = 0; i < 10 && i < count; i++) {
            cout << "Palabra: " << palabras[i]->palabra << ", Frecuencia: " << palabras[i]->frecuencia << endl;
        }
    }
};



int main() 
{
    hashtable TablaHash;

    // Abrir el archivo de entrada llamado "input.txt"
    ifstream inputFile("palabras.txt");

    // Verificar si el archivo se abrió correctamente
    if (!inputFile.is_open()) 
    {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    string line; // Declarar una variable de tipo string para almacenar cada línea del archivo

    // Leer cada línea del archivo
    cout << "Contenido del archivo: " << endl;
    while (getline(inputFile, line)) 
    {
        stringstream ss(line); // Crear un stringstream a partir de la línea
        string word;
        // Leer cada palabra del stringstream y limpiarla
        while (ss >> word) 
        {
            string clean = cleanWord(word); // Limpiar la palabra
            if (!clean.empty()) 
            {
                TablaHash.AddItem(clean);
            }
        }
    }

    // Cerrar el archivo
    inputFile.close();

    TablaHash.ImprimirTopFrecuencias();

    return 0;
}