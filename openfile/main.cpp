#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <commdlg.h>

using namespace std;

// Función para abrir el cuadro de diálogo de selección de archivos
string openFileDialog() {
    OPENFILENAME ofn;       // Estructura de selección de archivo
    char szFile[260];       // Buffer para el nombre del archivo
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "Text Files\0*.txt\0All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if (GetOpenFileName(&ofn) == TRUE) {
        return string(ofn.lpstrFile);
    }
    return "";
}

int main() {
    string filePath = openFileDialog();
    if (filePath.empty()) {
        cerr << "No se seleccionó ningún archivo." << endl;
        return 1;
    }

    // Abrir el archivo de texto seleccionado
    ifstream inputFile(filePath);

    // Verificar si el archivo se abrió correctamente
    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo: " << filePath << endl;
        return 1;
    }

    string line;
    cout << "Contenido del archivo: " << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
        system("pause");
    }

    // Cerrar el archivo
    inputFile.close();

    return 0;
}
