#include <iostream>
#include <limits>
#include <chrono>  // Incluir la biblioteca chrono
using namespace std;

const int tamanoArr = 20;
int quickSortSwaps = 0;
int quickSortComparaciones = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    quickSortComparaciones++;

    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortSwaps++;
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void BubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    int swaps = 0;
    int comparaciones = 0;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            comparaciones++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                swaps++;
            }
        }

        if (swapped == false)
            break;
    }
    cout << "swaps: " << swaps << endl;
    cout << "comparaciones: " << comparaciones << endl;
}

void Mostrar(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int opcion;
    do
    {
        int arr[tamanoArr] = {5, 4, 9, 20, 45, 65, 78, 12, 2, 7, 87, 24, 32, 16, 69, 951, 753, 654, 258, 246};

        cout << "\n\t.:MENU:.\n";
        cout << "1. Bubble Sort" << endl;
        cout << "2. Quick Sort" << endl;
        cout << "3. Mostrar Array" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 para elegir sus respectivas opciones." << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            auto start = chrono::high_resolution_clock::now();  // Iniciar el temporizador
            BubbleSort(arr, tamanoArr);
            auto end = chrono::high_resolution_clock::now();  // Detener el temporizador
            chrono::duration<double> duration = end - start;
            cout << "Tiempo de ejecución de Bubble Sort: " << duration.count() << " segundos" << endl;
            Mostrar(arr, tamanoArr);
            system("pause");
            break;
        }

        case 2:
        {
            quickSortComparaciones = 0;
            quickSortSwaps = 0;
            auto start = chrono::high_resolution_clock::now();  // Iniciar el temporizador
            QuickSort(arr, 0, tamanoArr - 1);
            auto end = chrono::high_resolution_clock::now();  // Detener el temporizador
            chrono::duration<double> duration = end - start;
            cout << "Tiempo de ejecución de Quick Sort: " << duration.count() << " segundos" << endl;
            cout << "swaps: " << quickSortSwaps << endl;
            cout << "comparaciones: " << quickSortComparaciones << endl;
            Mostrar(arr, tamanoArr);
            system("pause");
            break;
        }

        case 3:
            Mostrar(arr, tamanoArr);
            system("pause");
            break;

        case 4:
            break;

        default:
            cout << "\nOpción no válida. Por favor, ingrese un numero entre 1 y 4 para elegir sus respectivas opciones." << endl;
            break;
        }
        system("cls");
    } while (opcion != 4);

    return 0;
}
