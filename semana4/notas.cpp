#include<iostream>
#include<cmath>
using namespace std;

/*
    Desarrollar programa c++ que realice lo siguiente:
    1. Lea o Genere de manera aleatoria 20 notas (0-100) 
    2. Determine la nota mas alta y la mas baja
    3. Encuentre la moda de las notas
    4. calcule el promedio de las notas
    5. establezca la desviacion estandar de las notas
    6. clasifique las notas
*/
const int numeroDeNotas = 20;

 void BubbleSort(int a[], int n){
    int sube, baja; 
    for(sube=0;sube < n;sube++) { 
        for(baja=n-1; baja > sube; baja--) { 
            if(a[sube] > a[baja]) {
                int temp = a[sube]; 
                a[sube] = a[baja]; 
                a[baja] = temp; 
            } 
        }
    }
 }

void GenerarNotas(int notas[])
{
    srand(time(NULL));
    for (int i = 0; i < numeroDeNotas; i++)
    {
        int num = (rand() % 101);
        notas[i] = num;
    }
    BubbleSort(notas, numeroDeNotas);
    
}

void DeterminarAltaYBaja(int notas[])
{
    int masAlta = notas[0];
    int masBaja = notas[0];

    for (int i = 0; i < numeroDeNotas; i++)
    {
        if(notas[i] > masAlta) masAlta = notas[i];
        if(notas[i] < masBaja) masBaja = notas[i];
    }

    cout << "Nota mas alta: " << masAlta << endl;
    cout << "Nota mas baja: " << masBaja << endl;
    
}

void Moda(int notas[])
{
    int moda = NULL;
    int maxRepeticiones = 1;

    int contador = 1;
    for (int i = 1; i < numeroDeNotas; i++) {
        if (notas[i] == notas[i - 1]) {
            contador++;
        } else {
            if (contador > maxRepeticiones) {
                maxRepeticiones = contador;
                moda = notas[i - 1];
            }
            contador = 1;
        }
    }

    if (contador > maxRepeticiones) {
        moda = notas[numeroDeNotas - 1];
    }

    if(maxRepeticiones == 1)
    {
        cout << "No hay moda";
    }

    cout << "La moda es: " << moda << endl;
    
}

float Promedio(int notas[])
{
    int sum = 0;
    for (int i = 0; i < numeroDeNotas; i++)
    {
        sum += notas[i];
    }
    return sum/numeroDeNotas;
    
}

float DesviacionEstandar(int notas[], float promedio)
{
    float sum = 0;
    for (int i = 0; i < numeroDeNotas; i++)
    {
        sum += (notas[i]-promedio) * (notas[i]-promedio);
    }
    float varianza = sum/numeroDeNotas;
    return sqrt(varianza);
    
}

void MostrarCalificaciones(int notas[])
{
    cout << "-------------------------------" << endl;
    for (int i = 0; i < numeroDeNotas; i++)
    {
        char calificacion = 'S';
        if(notas[i] >=0 && notas[i] <= 59) {
            calificacion = 'F';
        }
        else if(notas[i] >=60 && notas[i] <= 69){
            calificacion = 'D';

        } 
        else if(notas[i] >=70 && notas[i] <= 79) {
            calificacion = 'C';
        }
        else if(notas[i] >=80 && notas[i] <= 89) {
            calificacion = 'B';
        }
        else if(notas[i] >=90 && notas[i] <= 100) {
            calificacion = 'A';
        }
        cout << notas[i] << " - " << calificacion << endl;
    }
    cout << "-------------------------------" << endl;
}

int main()
{
    int notas[numeroDeNotas];
    GenerarNotas(notas);
    float promedio = Promedio(notas);
    
    MostrarCalificaciones(notas);

    DeterminarAltaYBaja(notas);
    Moda(notas);
    cout << "El promedio es: " << promedio << endl;
    DesviacionEstandar(notas, promedio);
      

    return 0;
}