#define _CRT_SECURE_NO_WARNINGS 
#include "VentasManager.h"
#include <iostream>
#include <iomanip>
using namespace std;


VentasManager::VentasManager(VentasArchivo archivo)
{
    _archivo = archivo;
}

void VentasManager::menu()
{
    int opcion;
    do {
        system("cls");
        cout << "MENU VENTAS " << endl;
        cout << "********************** " << endl;
        cout << "1. Cargar Venta " << endl;
        cout << "2. Mostrar Ventas " << endl;
        cout << "3. Opcion " << endl;
        cout << "4. Opcion " << endl;
        cout << "5. Opcion " << endl;

        cout << "0. SALIR DEL PROGRAMA " << endl;
        cout << "********************** " << endl;
        cout << "OPCION: " << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            agregarVenta();
            system("pause");
            break;

        case 2:
            listarVentas();
            system("pause");
            break;

        case 3:

            system("pause");
            break;

        case 4:

            system("pause");
            break;

        case 5:

            system("pause");
            break;


        case 0:
            
            break;
        }
    } while (opcion != 0);
}

Venta VentasManager::crearVenta()
{
    int id = _archivo.leerUltimoId() + 1;
    int dni, nroLegajo, idSucursal, idVehiculo;
    float gastos, total;
    Fecha f;

    cout << "Venta: #" << id << endl;
    cout << "Ingrese fecha de Venta: " << endl;
    f.Cargar();
    cout << endl;
    cin.ignore();
    cout << "Ingrese DNI del Cliente: " << endl;
    cin >> dni;
    cin.ignore();
    cout << "Ingrese ID de Sucursal: " << endl;
    cin >> idSucursal;
    cin.ignore();
    cout << "Ingrese Legajo del Vendedor: " << endl;
    cin >> nroLegajo;
    cin.ignore();
    cout << "Ingrese ID del Vehiculo comprado: " << endl;
    cin >> idVehiculo;
    cin.ignore();
    cout << "Gastos Administrativos: $" << endl;
    cin >> gastos;
    cin.ignore();
    cout << "Total Venta: $" << endl;
    cin >> total;
    cin.ignore();
    cout << endl;

    return Venta(id, f, dni, idSucursal, nroLegajo, idVehiculo, gastos, total, false);
}

void VentasManager::mostrarVenta(Venta reg)
{
    cout << left;
    cout << setw(0) << "Venta: #" << reg.getIdVenta() << "         " << "Fecha de Venta: " << reg.getFechaVenta().toString();
    cout << endl << endl;
    cout << "Cliente: " << reg.getDniCliente() << endl;
    cout << "Sucursal: " << reg.getIdSucursal() << endl;
    cout << "Vendedor: " << reg.getNroLegajo() << endl;
    cout << "Vehiculo comprado: " << reg.getIdVehiculo() << endl;
    cout << "Gastos Administrativos: $" << reg.getGastosAdm() << endl;
    cout << "Total Venta: $" << fixed << setprecision(0) << reg.getTotalVenta() << endl;

}

void VentasManager::agregarVenta()
{
    if (_archivo.guardarVenta(crearVenta())) {
        cout << "La venta se guardó correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar la venta." << endl;
    }
}

void VentasManager::listarVentas()
{
    int i, cantidad = _archivo.contarVentas();

    for (i=0; i < cantidad; i++) {
        cout << "------------------------------" << endl;
        mostrarVenta(_archivo.leerVenta(i));
        cout << "------------------------------" << endl << endl;
    }
}

int VentasManager::buscarVenta(int idVenta)
{
    Venta reg;
    FILE* p;
    int pos = 0;
    p = fopen("Ventas.dat", "rb");
    if (p == nullptr) {
        return -2; //no se abrio el archivo
    }
    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (reg.getIdVenta() == idVenta) {
            fclose(p); //cierro el archivo porque ya encontre la empresa
            return pos;
        }
        pos++;
    }
    fclose(p);

    return -1; //se recorrio el archivo y no existe el codigo
}

bool VentasManager::sobreescribirVenta(Venta reg, int pos)
{
	return false;
}

bool VentasManager::bajaLogica()
{
	return false;
}
