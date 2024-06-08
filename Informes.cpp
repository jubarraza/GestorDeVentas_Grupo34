#include "Informes.h"
#include <iostream>
using namespace std;

void Informes::Menu()
{
    int opcion;
    do {
        system("cls");
        cout << " INFORMES " << endl;
        cout << "********************** " << endl;
        cout << "1. Informe del Inventario " << endl;
        cout << "2. Informe de Recaudación Anual " << endl;
        cout << "3. Informe Anual de Ventas por Vendedor " << endl;
        cout << "4. Informe Mensual de Ventas para todos los Vendedores " << endl;
        cout << "5. Informe Anual de Ventas por Sucursal " << endl;
        cout << "6. Informe Ventas en todas las Sucursales (anual o mensual) " << endl;
        cout << "7. Ranking Anual de Ventas por Modelo " << endl;

        cout << endl;
        cout << "0. SALIR DEL PROGRAMA " << endl;
        cout << "********************** " << endl;
        cout << "OPCION: " << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            Inventario();
            system("pause");
            break;

        case 2:
            recaudacionAnual();
            system("pause");
            break;

        case 3:
            ventasXVendedorAnual();
            system("pause");
            break;

        case 4:
            ventasXVendedoresMensual();
            system("pause");
            break;

        case 5:
            ventasXSucursalAnual();
            system("pause");
            break;

        case 6:
        {
            int opc;
            cout << "¿Desea la version: 1 - Mensual o 2 - Anual?";
            cin >> opc;

            if (opc == 1) {
                ventasTodasLasSucursalesMensual();
            }
            if (opc == 2) {
                ventasTodasLasSucursalesAnual();
            }
            system("pause");
            break;
        }
        case 7:
            rankingVentasXModelo();
            system("pause");
            break;

        case 0:

            break;
        }
    } while (opcion != 0);
}

void Informes::Inventario()
{
}

void Informes::recaudacionAnual()
{
}

void Informes::ventasXVendedorAnual()
{
}

void Informes::ventasXVendedoresMensual()
{
}

void Informes::ventasXSucursalAnual()
{
}

void Informes::ventasTodasLasSucursalesMensual()
{
}

void Informes::ventasTodasLasSucursalesAnual()
{
}

void Informes::rankingVentasXModelo()
{
}
