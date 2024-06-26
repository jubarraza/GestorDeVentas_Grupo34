# include<iostream>
using namespace std;
#include "VehiculosManager.h"
#include "VentasManager.h"
#include "SucursalManager.h"
#include "VendedorManager.h"
#include "ClienteManager.h"
#include "Configuracion.h"
#include "FuncionesGenerales.h"

void Configuracion::Menu() {

    int opc;
    do {
        system("cls");
        cout << "------ Configuracion ------" << endl;
        cout << "---------------------------" << endl;
        cout << "1) SubMenu Vehiculos " << endl;
        cout << "2) SubMenu Ventas " << endl;
        cout << "3) SubMenu Sucursales " << endl;
        cout << "4) SubMenu Vendedores " << endl;
        cout << "5) SubMenu Clientes " << endl << endl;
        cout << "----------------------------" << endl;
        cout << "0) Regresar al Menu Principal " << endl << endl;
        cout << "Selecione una Opcion: ";
        cin >> opc;
        switch (opc) {
        case 1:system("cls");
            subMenuVehiculos();
            break;
        case 2:system("cls");
            subMenuVentas();
            break;
        case 3:system("cls");
            subMenuSucursales();
            break;
        case 4:system("cls");
            subMenuVendedores();
            break;
        case 5:system("cls");
            subMenuClientes();
            break;
        case 0:
            return;
        default:cout << endl << "* Selecione una Opcion Correcta! *" << endl << endl;
            system("pause");
        }
    } while (opc != 0);
}

void Configuracion::subMenuVehiculos() {
    VehiculosManager vehiculos;

    int opc;
    cout << "--- Archivo Vehiculos ---" << endl;
    cout << "1) Realizar Backup " << endl;
    cout << "2) Restaurar Backup " << endl;
    cout << "0) Regresar al Menu " << endl;
    cout << "Ingrese una Opcion: ";
    do {
        cin >> opc;
        switch (opc)
        {
        case 1:
            vehiculos.realizarBackup();
            system("cls");
            return;
        case 2:
            vehiculos.restaurarBackup();
            system("cls");
            return;
        case 0:
            system("cls");
            return;
        default:
            cout << "* Opcion Incorrecta *" << endl;
            cout << "- Seleccione una Opcion Correcta: ";
        }
    } while (opc != 0);
}

void Configuracion::subMenuVentas() {
    VentasManager ventas;

    int opc;
    cout << "--- Archivo Ventas ---" << endl;
    cout << "1) Realizar Backup " << endl;
    cout << "2) Restaurar Backup " << endl;
    cout << "0) Regresar al Menu " << endl;
    cout << "Ingrese una Opcion: ";
    do {
        cin >> opc;
        switch (opc)
        {
        case 1:
            ventas.backupArchivo();
            system("cls");
            return;
        case 2:
            ventas.restaurarBackup();
            system("cls");
            return;
        case 0:
            system("cls");
            return;
        default:
            cout << "* Opcion Incorrecta *" << endl;
            cout << "- Seleccione una Opcion Correcta: ";
        }
    } while (opc != 0);
}

void Configuracion::subMenuSucursales() {
    SucursalManager sucursales;

    int opc;
    cout << "--- Archivo Sucursales ---" << endl;
    cout << "1) Realizar Backup " << endl;
    cout << "2) Restaurar Backup " << endl;
    cout << "0) Regresar al Menu " << endl;
    cout << "Ingrese una Opcion: ";
    do {
        cin >> opc;
        switch (opc)
        {
        case 1:
            sucursales.backupArchivo();
            system("cls");
            return;
        case 2:
            sucursales.restaurarBackup();
            system("cls");
            return;
        case 0:
            system("cls");
            return;
        default:
            cout << "* Opcion Incorrecta *" << endl;
            cout << "- Seleccione una Opcion Correcta: ";
        }
    } while (opc != 0);
}

void Configuracion::subMenuVendedores() {
    VendedorManager vendedores;

    int opc;
    cout << "--- Archivo Vendedores ---" << endl;
    cout << "1) Realizar Backup " << endl;
    cout << "2) Restaurar Backup " << endl;
    cout << "0) Regresar al Menu " << endl;
    cout << "Ingrese una Opcion: ";
    do {
        cin >> opc;
        switch (opc)
        {
        case 1:
            vendedores.realizarBackupVendedores();
            system("cls");
            return;
        case 2:
            vendedores.restaurarBackupVendedores();
            system("cls");
            return;
        case 0:
            system("cls");
            return;
        default:
            cout << "* Opcion Incorrecta *" << endl;
            cout << "- Seleccione una Opcion Correcta: ";
        }
    } while (opc != 0);
}

void Configuracion::subMenuClientes() {
    ClienteManager clientes;

    int opc;
    cout << "--- Archivo Clientes ---" << endl;
    cout << "1) Realizar Backup " << endl;
    cout << "2) Restaurar Backup " << endl;
    cout << "0) Regresar al Menu " << endl;
    cout << "Ingrese una Opcion: ";
    do {
        cin >> opc;
        switch (opc)
        {
        case 1:
            clientes.backupArchivo();
            system("cls");
            return;
        case 2:
            clientes.restaurarBackup();
            system("cls");
            return;
        case 0:
            system("cls");
            return;
        default:
            cout << "* Opcion Incorrecta *" << endl;
            cout << "- Seleccione una Opcion Correcta: ";
        }
    } while (opc != 0);
}