#include <iostream>
#include <string>

// Tamaño de la tabla
const int tamanoTabla = 100;

// Estructura que contiene a una llave y su respectivo valor
struct HashStruct
{
    int id_key;
    std::string name;
};

// Función Hash que devuelve el índice en el cual está alojado el valor que buscamos
int Hash(int key)
{
    const int prime = 31;  // Elegimos un número primo para la constante

    // Algoritmo de hashing
    // El índice será la llave multiplicada por la constante prime dividido modularmente por el int tamanoTabla + 1

    int hash = key * prime % (tamanoTabla + 1);

    return hash;
}

int main()
{
    // Nuestros IDs con los respectivos nombres
    HashStruct ids[] = {
      {1117460, "Sebastian Manuel Marrera Santos"},
      {1115549, "Felsi Arno Ramirez"},
      {1116417, "Angel Manuel Dipre Mateo"},
      {1113816, "Kiamely Pereyra Villar"},
      {1119712, "Luis Miguel Heyaime"},
      {1113930, "Lewdys Aquino Mendez (Llave"},
      {1116226, "Antony Ricardo Cabrera Nina"},
      {1117848, "Obal Abimael Nina Montas"},
      {1118857, "Jose Javier Otazu Gonzalez"},
      {1108962, "Ronaldo Peralta Jovine"},
      {1121531, "Miguel Angel Filpo Madera"},
      {1115670, "Elian Armani D'Oleo Cuello"},
      {1117463, "Eduardo Encarnacion Del Toro"},
      {1121598, "Frank Delvys Coste Alvarez"},
      {1115719, "Ismael Moquete Eduardo"},
      {1114995, "Valerie Davielis Belliard Rosario"},
      {1121028, "Angel Manuel Medina Binet"},
      {1114670, "Pedro Pablo Martinez Jimenez"},
      {1107744, "Alexander Monegro Del Rosario"},
    };

    // Las tablas que contienen a las llaves y a los nombres, originalmente todos sus elementos son NULL y un string vacío respectivamente
    int tablaLlaves[tamanoTabla] = { 0 };
    std::string tablaValores[tamanoTabla] = { "" };

    // Por cada elemento del array ids
    for (HashStruct element : ids) {
        // En el índice indicado por la función Hash evaluada con el elemento, se ubicará el valor que corresponde
        int pos = Hash(element.id_key);
        tablaLlaves[pos] = element.id_key;
        tablaValores[pos] = element.name;
    }
    // Mostrar tabla
    for (int i = 0; i < tamanoTabla; i++)
    {
        if (tablaLlaves[i] != 0)
        {
            std::cout << "Llave: " << tablaLlaves[i] << "|" << i << " -> " << tablaValores[i] << std::endl;
        }
        else
        {
            std::cout << "              |" << i << " -> " << tablaValores[i] << std::endl;
        }
    }
    return 0;
}