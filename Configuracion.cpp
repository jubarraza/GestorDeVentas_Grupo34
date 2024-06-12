# include<iostream>
using namespace std;
#include"Configuracion.h"

void Configuracion::Menu() {
    int opc;
    cout << "------- Confirugarcion -------" << endl;
    cout << "------------------------------" << endl;
    cout << "1) Realizar Backup Vehiculos " << endl;
    cout << "2) Realizar Backup Ventas " << endl;
    cout << "3) Realizar Backup Sucursales " << endl;
    cout << "4) Realizar Backup Clientes " << endl;
    cout << "5) Realizar Backup Vendedores " << endl;
    cout << "6) Restaurar Backup Vehiculos " << endl;
    cout << "7) Restaurar Backup Ventas " << endl;
    cout << "8) Restaurar Backup Sucursales " << endl;
    cout << "9) Restaurar Backup Clientes " << endl;
    cout << "10) Restaurar Backup Vendedores " << endl;
    cout << "------------------------------" << endl;
    cout << "0) Volver al menu principal " << endl << endl;
    cout << "Selecion una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1:realizarBackupVehiculos();
        break;
    case 2:realizarBackupVentas();
        break;
    case 3:realizarBackupSucursales();
        break;
    case 4:realizarBackupClientes();
        break;
    case 5:realizarBackupVendedores();
        break;
    case 6:restaurarBackupVehiculos();
        break;
    case 7:restaurarBackupVentas();
        break;
    case 8:restaurarBackupSucursales();
        break;
    case 9:restaurarBackupClientes();
        break;
    case 10:restaurarBackupVendedores();
        break;
    case 0 : 
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
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
    case 2:
        return;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        return;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        return;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        return;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        return;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
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
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! *" << endl;
        return;
    }
}