#include "Informes.h"
#include "VentasManager.h"
#include "VehiculosManager.h"
#include "SucursalManager.h"
#include "VendedorManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Informes::Menu()
{
    int opcion;
    do {
        system("cls");
        cout << "--- INFORMES ---" << endl;
        cout << "----------------------" << endl;
        cout << "1. Informe del Inventario " << endl;
        cout << "2. Informe de Recaudaci�n Anual " << endl;
        cout << "3. Informe Anual de Ventas por Vendedor " << endl;
        cout << "4. Informe Mensual de Ventas para todos los Vendedores " << endl;
        cout << "5. Informe Anual de Ventas por Sucursal " << endl;
        cout << "6. Informe Ventas en todas las Sucursales (mensual o anual) " << endl;
        cout << "7. Ranking Anual de Ventas por Modelo " << endl;

        cout << endl;
        cout << "0. Volver al menu principal " << endl;
        cout << "----------------------" << endl;
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
            cout << "�Desea la version: 1 - Mensual o 2 - Anual?" << endl;
            cin >> opc;
            cin.ignore();
            cout << endl;

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

//1
void Informes::Inventario()
{
}

//2
void Informes::recaudacionAnual()
{
    VentasManager vm;
    VentasArchivo va;
    int i;
    double recaudacion[13] = {0};
    string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

    int anio;

    cout << "** INFORME DE RECAUDACION ANUAL ** " << endl;
    cout << "Ingrese a�o a revisar: ";
    cin >> anio;
    system("cls");

    int cantidad = va.contarVentas();
    for (i = 0; i < cantidad; i++) {
        Venta reg = va.leerVenta(i);
        if (reg.getFechaVenta().getAnio() == anio) {
            recaudacion[reg.getFechaVenta().getMes() - 1] += reg.getTotalVenta();
            recaudacion[12] += reg.getTotalVenta();
        }

    }

    cout << "** INFORME DE RECAUDACION ANUAL ** " << endl << endl;
    cout << "A�o: " << anio << endl << endl;

    cout << left;
    cout << setw(12) << "MES";
    cout << setw(20) << "RECAUDACION" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (i = 0; i < 12; i++) {
        
        cout << setw(12) << meses[i];
        cout << "$ " << setw(20) << vm.formatearNumero(recaudacion[i]);
        cout << endl;

    }
    cout << endl << endl;

    cout << "** Total Anual : $" << vm.formatearNumero(recaudacion[12]) << " **" << endl << endl;

}

//3
void Informes::ventasXVendedorAnual()
{
}

//4
void Informes::ventasXVendedoresMensual()
{
}

//5
void Informes::ventasXSucursalAnual()
{
    VentasManager vm; 
    VentasArchivo va; 
    int i;
    double recaudacion[13] = { 0 };
    string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

    int anio, id;

    cout << "** INFORME ANUAL DE VENTAS POR SUCURSAL ** " << endl;
    cout << "Ingrese a�o a revisar: ";
    cin >> anio;
    cout << endl << "Ingrese Id de Sucursal: ";
    cin >> id;
    system("cls");

    int cantidad = va.contarVentas();
    for (i = 0; i < cantidad; i++) {
        Venta reg = va.leerVenta(i); 
        if (reg.getFechaVenta().getAnio() == anio && reg.getIdSucursal() == id) {
            recaudacion[reg.getFechaVenta().getMes() - 1] += reg.getTotalVenta(); 
            recaudacion[12] += reg.getTotalVenta(); 

        }

    }


    cout << "** INFORME ANUAL DE VENTAS POR SUCURSAL ** " << endl << endl;
    cout << "A�o: " << anio << endl;
    cout << "Sucursal: " << vm.mostrarNombreSucursal(id) << endl;
    cout << endl;

    cout << left;
    cout << setw(12) << "MES";
    cout << setw(20) << "RECAUDACION" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (i = 0; i < 12; i++) {

        cout << setw(12) << meses[i];
        cout << "$ " << setw(20) << vm.formatearNumero(recaudacion[i]);
        cout << endl;

    }
    cout << endl << endl;

    cout << "** TOTAL ANUAL : $" << vm.formatearNumero(recaudacion[12]) << " **" << endl << endl;
}

//6.1
void Informes::ventasTodasLasSucursalesMensual()
{
}

//6.2
void Informes::ventasTodasLasSucursalesAnual()
{
}

//7
void Informes::rankingVentasXModelo()
{
}
