# include<iostream>
using namespace std;
#include"Configuracion.h"

void Configuracion::Menu() {
    int opc;
    system("cls");
    cout << "------- Configuracion -------" << endl;
    cout << "------------------------------" << endl;
    cout << "1) Realizar Backup Vehiculos " << endl;
    cout << "2) Realizar Backup Ventas " << endl;
    cout << "3) Realizar Backup Sucursales " << endl;
    cout << "4) Realizar Backup Clientes " << endl;
    cout << "5) Realizar Backup Vendedores " << endl << endl;
    cout << "6) Restaurar Backup Vehiculos " << endl;
    cout << "7) Restaurar Backup Ventas " << endl;
    cout << "8) Restaurar Backup Sucursales " << endl;
    cout << "9) Restaurar Backup Clientes " << endl;
    cout << "10) Restaurar Backup Vendedores " << endl;
    cout << "------------------------------" << endl;
    cout << "0) Volver al menu principal " << endl << endl;
    cout << "Selecion una Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc) {
    case 1:realizarBackupVehiculos();
        system("pause");
        break;
    case 2:realizarBackupVentas();
        system("pause");
        break;
    case 3:realizarBackupSucursales();
        system("pause");
        break;
    case 4:realizarBackupClientes();
        system("pause");
        break;
    case 5:realizarBackupVendedores();
        system("pause");
        break;
    case 6:restaurarBackupVehiculos();
        system("pause");
        break;
    case 7:restaurarBackupVentas();
        system("pause");
        break;
    case 8:restaurarBackupSucursales();
        system("pause");
        break;
    case 9:restaurarBackupClientes();
        system("pause");
        break;
    case 10:restaurarBackupVendedores();
        system("pause");
        break;
    case 0 : 
        system("pause");
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        system("pause");
        return;
    }
}

void Configuracion::realizarBackupVehiculos() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Vehiculos?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vehiculos.dat Vehiculos.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::realizarBackupVentas() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Ventas?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Ventas.dat Ventas.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::realizarBackupSucursales() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Sucursales?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Sucursales.dat Sucursales.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::realizarBackupClientes() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Clientes?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Clientes.dat Clientes.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::realizarBackupVendedores() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Vendedores?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vendedores.dat Vendedores.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::restaurarBackupVehiculos() {
    int opc;
    cout << "- Desea Restaurar el Archivo Vehiculos?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vehiculos.bkp Vehiculos.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::restaurarBackupVentas() {
    int opc;
    cout << "- Desea Restaurar el Archivo Ventas?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Ventas.bkp Ventas.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::restaurarBackupSucursales() {
    int opc;
    cout << "- Desea Restaurar el Archivo de Sucursales?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Sucursales.bkp Sucursales.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::restaurarBackupClientes() {
    int opc;
    cout << "- Desea Restaurar el Archivo de Clientes?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Clientes.bkp Clientes.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}

void Configuracion::restaurarBackupVendedores() {
    int opc;
    cout << "- Desea Restaurar el Archivo de Vendedores?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vendedores.bkp Vendedores.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
        break;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        break;
    }
}