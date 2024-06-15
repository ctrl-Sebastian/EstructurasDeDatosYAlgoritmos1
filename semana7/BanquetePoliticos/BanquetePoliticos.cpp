#include <iostream>
using namespace std;

int main() {
    int pagaSenadores = 75;
    int pagaCongresista = 99;
    int pagaInvitado = 40;

    int totalRecaudado = 7869;
    int totalDePersonas = 100;

    int cantidadDeSenadores = 0;
    int cantidadDeCongresistas = 0;
    int cantidadDeInvitados = 0;

    for (int senadores = 0; senadores <= totalDePersonas; senadores++) 
    {
        for (int congresistas = 0; congresistas <= totalDePersonas - senadores; congresistas++) 
        {
            int invitados = totalDePersonas - senadores - congresistas;
            int recaudado = (senadores * pagaSenadores) + (congresistas * pagaCongresista) + (invitados * pagaInvitado);

            if (recaudado == totalRecaudado) 
            {
                cantidadDeSenadores = senadores;
                cantidadDeCongresistas = congresistas;
                cantidadDeInvitados = invitados;
                break;
            }
        }
    }

    cout << "Cantidad de Senadores: " << cantidadDeSenadores << endl;
    cout << "Cantidad de Congresistas: " << cantidadDeCongresistas << endl;
    cout << "Cantidad de Invitados: " << cantidadDeInvitados << endl;

    return 0;
}
