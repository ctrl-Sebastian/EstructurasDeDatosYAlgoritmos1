#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>  // Para transform
#include <cctype>     // Para tolower y ispunct
#include <Windows.h>
#include <ShlObj.h>   // Para SHBrowseForFolder
#include <iomanip>    // Para usar setw
#include <filesystem> // Para listar archivos

using namespace std;
namespace fs = std::filesystem;

// Función para limpiar una palabra, convirtiéndola a minúsculas y eliminando símbolos
string cleanWord(const string& word) {
    string clean;
    for (char ch : word) {
        if (!ispunct(ch)) {
            clean += tolower(ch);
        }
    }
    return clean;
}

// Función para abrir el cuadro de diálogo de selección de carpetas
string openFolderDialog() {
    BROWSEINFO bi;
    ZeroMemory(&bi, sizeof(bi));
    TCHAR path[MAX_PATH];

    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    bi.lpfn = NULL;
    bi.lpszTitle = "Seleccione una carpeta";
    bi.pszDisplayName = path;

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
    if (pidl != NULL) {
        SHGetPathFromIDList(pidl, path);
        return string(path);
    }
    return "";
}

class hashtable {
private:
    static const int tableSize = 5000;

    struct item {
        string palabra;
        int frecuencia;
        item* siguiente;
    };

    item* HashTable[tableSize];

public:
    hashtable() {
        for (int i = 0; i < tableSize; i++) {
            HashTable[i] = new item;
            HashTable[i]->palabra = "";
            HashTable[i]->frecuencia = 0;
            HashTable[i]->siguiente = NULL;
        }
    }

    int Hash(string key) {
        int hash = 0;
        int index;

        for (int i = 0; i < key.length(); i++) {
            hash = (hash + (int)key[i]);
        }

        index = hash % tableSize;
        return index;
    }

    void AddItem(string palabra) {
        int index = Hash(palabra);
        if (HashTable[index]->palabra == "") {
            HashTable[index]->palabra = palabra;
            HashTable[index]->frecuencia++;
        } else if (HashTable[index]->palabra == palabra) {
            HashTable[index]->frecuencia++;
        } else {
            item* Ptr = HashTable[index];
            while (Ptr->siguiente != NULL) {
                if (Ptr->palabra == palabra) {
                    Ptr->frecuencia++;
                    return;
                }
                Ptr = Ptr->siguiente;
            }
            if (Ptr->palabra == palabra) {
                Ptr->frecuencia++;
                return;
            }
            item* nuevoItem = new item;
            nuevoItem->palabra = palabra;
            nuevoItem->frecuencia = 1;
            nuevoItem->siguiente = NULL;
            Ptr->siguiente = nuevoItem;
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
        QuickSort(palabras, 0, count - 1);

        const int palabraWidth = 20;  // Ancho de la columna para palabras
        const int frecuenciaWidth = 10;  // Ancho de la columna para frecuencias

        cout << "Las 10 palabras con mayor frecuencia son:" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "| " << setw(palabraWidth) << left << "Palabra"
             << " | " << setw(frecuenciaWidth) << right << "Frecuencia" << " |" << endl;
        cout << "-----------------------------------------" << endl;

        for (int i = 0; i < 10 && i < count; i++) {
            cout << "| " << setw(palabraWidth) << left << palabras[i]->palabra
                 << " | " << setw(frecuenciaWidth) << right << palabras[i]->frecuencia << " |" << endl;
        }
        cout << "-----------------------------------------" << endl;
    }
};

void procesarArchivosEnCarpeta(const string& carpeta, hashtable& TablaHash) {
    for (const auto& entry : fs::directory_iterator(carpeta)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {

            ifstream inputFile(entry.path().string());

            // Verificar si el archivo se abrió correctamente
            if (!inputFile.is_open()) {
                cerr << "No se pudo abrir el archivo: " << entry.path().string() << endl;
                continue;
            }

            cout << entry.path().filename() << endl; 

            string line;
            while (getline(inputFile, line)) {
                stringstream ss(line);
                string word;
                while (ss >> word) {
                    string clean = cleanWord(word);
                    if (!clean.empty()) {
                        TablaHash.AddItem(clean);
                    }
                }
            }

            inputFile.close();
        }
    }
}

int main() {
    hashtable TablaHash;

    string carpetaPath = openFolderDialog();
    if (carpetaPath.empty()) {
        cerr << "No se seleccionó ninguna carpeta." << endl;
        system("pause");
        return 1;
    }

    procesarArchivosEnCarpeta(carpetaPath, TablaHash);

    
    TablaHash.ImprimirTopFrecuencias();
    system("pause");

    return 0;
}
