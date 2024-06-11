#include <iostream>
#include "Sistema.h"
using namespace std;

Sistema::Sistema() : _vehiculos(), _ventas(), _clientes(), _vendedores(), _sucursales(), _informes(), _configuracion()
{
}

void Sistema::Menu()
{
    int opc;
    do {
        cout << "--- Sistema de Gestion ---" << endl;
        cout << "-----> Lab2 Grupo34 <-----" << endl;
        cout << "----- Menu Principal -----" << endl;
        cout << "--------------------------" << endl;
        cout << " 1) Vehiculos " << endl;
        cout << " 2) Ventas " << endl;
        cout << " 3) Vendedores " << endl;
        cout << " 4) Sucursales " << endl;
        cout << " 5) Clientes " << endl;
        cout << " 6) Informes " << endl;
        cout << " 7) Configuracion " << endl;
        cout << " 0) Salir " << endl;
        cout << "---------------------------" << endl;
        cout << "- Selecione una opcion: ";
        cin >> opc;
        system("cls");
        switch (opc) {
        case 1: _vehiculos.Menu();
            break;
        case 2: _ventas.Menu();
            break;
        case 3: _vendedores.Menu();
            break;
        case 4: _sucursales.Menu();
            break;
        case 5: _clientes.Menu();
            break;
        case 6: _informes.Menu();
            break;
        case 7: _configuracion.Menu();
            break;
        case 0:cout << endl << " Adios!! " << endl;
            break;
        default:cout << endl << "* Selecione una Opcion Correcta! *" << endl << endl;;
            system("pause");
        }

    } while (opc != 0);
}
