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

    void Cuentafrecuencia() 
    {
        // Arrays para almacenar las frecuencias, palabras y sus índices
        int frecuencias[tableSize];
        string palabras[tableSize];
        int indices[tableSize];
        int count = 0;

        for (int index = 0; index < tableSize; index++) 
        {
            item* Ptr = HashTable[index];
            while (Ptr != NULL && Ptr->palabra != "") 
            {
                frecuencias[count] = Ptr->frecuencia;
                palabras[count] = Ptr->palabra;
                indices[count] = index; 
                count++;
                Ptr = Ptr->siguiente;
            }
        }

        // Arrays para almacenar las 10 mayores frecuencias, palabras y sus índices
        int topFrecuencias[10];
        string topPalabras[10];
        int topIndices[10];

        // Inicializamos los arrays con las primeras 10 frecuencias encontradas
        for (int i = 0; i < 10; i++) 
        {
            if (i < count) {
                topFrecuencias[i] = frecuencias[i];
                topPalabras[i] = palabras[i];
                topIndices[i] = indices[i];
            }
            else 
            {
                topFrecuencias[i] = 0; 
                topPalabras[i] = "";
                topIndices[i] = -1;
            }
        }

        // Actualizamos las 10 mayores frecuencias, palabras y sus índices si encontramos mayores
        for (int i = 10; i < count; i++) 
        {
            int currentFreq = frecuencias[i];
            string currentWord = palabras[i];
            int currentIndex = indices[i];

            // Buscamos la posición en topFrecuencias donde el currentFreq debería ir
            for (int j = 0; j < 10; j++) 
            {
                if (currentFreq > topFrecuencias[j]) 
                {
                    // Desplazamos las frecuencias menores hacia la derecha
                    for (int k = 9; k > j; k--) 
                    {
                        topFrecuencias[k] = topFrecuencias[k - 1];
                        topPalabras[k] = topPalabras[k - 1];
                        topIndices[k] = topIndices[k - 1];
                    }
                    topFrecuencias[j] = currentFreq;
                    topPalabras[j] = currentWord;
                    topIndices[j] = currentIndex;
                    break;
                }
            }
        }

        // Imprimir las 10 mayores frecuencias, palabras y sus índices
        cout << "Las 10 palabras con mayor frecuencia son:" << endl;
        for (int i = 0; i < 10; i++) 
        {
            if (topFrecuencias[i] > 0) 
            { 
                cout << "Índice: " << topIndices[i] << ", Palabra: " << topPalabras[i] << ", Frecuencia: " << topFrecuencias[i] << endl;
            }
        }
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
        Cuentafrecuencia();  // Llamar a Cuentafrecuencia para imprimir las 10 palabras más frecuentes
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
};

int main() 
{
    hashtable TablaHash;

    // Abrir el archivo de entrada llamado "input.txt"
    ifstream inputFile("input.txt");

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

    TablaHash.ImprimirTabla();

    return 0;
}