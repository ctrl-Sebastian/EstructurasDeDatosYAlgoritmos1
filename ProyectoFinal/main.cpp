#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>  // Para transform
#include <cctype>     // Para tolower y ispunct

using namespace std;

// Función para limpiar una palabra, convirtiéndola a minúsculas y eliminando símbolos
string cleanWord(const string &word) {
    string clean;
    for (char ch : word) {
        if (!ispunct(ch)) {
            clean += tolower(ch);
        }
    }
    return clean;
}


class hashtable{
  private:
    static const int tableSize = 10000;

    struct item{
      string palabra;
      int frecuencia;
      item* siguiente;
    };

    item* HashTable[tableSize];
  
  public:
    hashtable()
    {
        for(int i = 0; i < tableSize; i++)
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

    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]);
    }

    index = hash % tableSize;
    return index;
    }
    
    void AddItem(string palabra)
    {
    int index = Hash(palabra);
    if(HashTable[index]->palabra == "")
    {
        HashTable[index]->palabra = palabra;
        HashTable[index]->frecuencia++;
    }
    // ---------------------------------------------
    else if(HashTable[index]->palabra == palabra){
        HashTable[index]->frecuencia++;
    }
        //--------------------------------------------
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->palabra = palabra;
        n->frecuencia = 1;
        n->siguiente = NULL;
        while(Ptr->siguiente != NULL)
        {
        //---------------------------------------------------------------
        if(Ptr->palabra == palabra){
            Ptr->frecuencia++;
            break;
        }
        //---------------------------------------------------------------
        Ptr = Ptr->siguiente;  
        }
        Ptr->siguiente = n;
    }
    }
    
    int NumeroDeItemsEnIndice(int index)
    {
    int count = 0;
    if(HashTable[index]->palabra == ""){
        return count;
    }
    else{
        count++;

        item* Ptr = HashTable[index];
        while(Ptr->siguiente != NULL)
        {
        count++;
        Ptr = Ptr->siguiente;
        }
    }
    return count;
    }
    
    void ImprimirTabla()
    {
    int num;
    for(int i = 0; i < tableSize; i++)
    {
        num = NumeroDeItemsEnIndice(i);
        if(num != 0)
        {
        ImprimirItemsEnIndice(i);
        /*
        cout << "---------------------" << endl;
        cout << "Indice = " << i << endl;
        cout << "palabra: " << HashTable[i]->palabra << endl;
        cout << "frecuencia: " << HashTable[i]->frecuencia << endl;
        cout << "# of items = " << num << endl;
        cout << "---------------------" << endl;
        */
        }
        else{
        continue;
        }
    }
    }
    
    void ImprimirItemsEnIndice(int index)
    {
    item* Ptr = HashTable[index];
    if(Ptr->palabra == "")
    {
        cout << "Indice = " << index << " vacio" <<endl;
    }
    else
    {
        cout << "\n\n\n\nIndice = " << index << endl;
        
        while(Ptr != NULL)
        {
            cout << "---------------------" << endl;
            cout << "palabra: " << Ptr->palabra << endl;
            cout << "frecuencia: " << Ptr->frecuencia << endl;
            cout << "---------------------\n";

            Ptr = Ptr->siguiente;
        }
    }
    }
};


int main() {
    hashtable TablaHash;

    // Abrir el archivo de entrada llamado "palabras.txt"
    ifstream inputFile("palabras.txt");

    // Verificar si el archivo se abrió correctamente
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo!" << endl;
        return 1;
    }

    string line; // Declarar una variable de tipo string para almacenar cada línea del archivo

    // Leer cada línea del archivo
    cout << "Contenido del archivo: " << endl;
    while (getline(inputFile, line)) {
        stringstream ss(line); // Crear un stringstream a partir de la línea
        string word;
        // Leer cada palabra del stringstream y limpiarla
        while (ss >> word) {
            string clean = cleanWord(word); // Limpiar la palabra
            if (!clean.empty()) {

                
                //-----------------------------------------------------------------------------
                TablaHash.AddItem(clean);
                //-----------------------------------------------------------------------------


                
            }
        }
    }

    // Cerrar el archivo
    inputFile.close();

    
    //-----------------------------------------------------------------------------------
    TablaHash.ImprimirTabla();
    //-----------------------------------------------------------------------------------

    
    return 0;
}
