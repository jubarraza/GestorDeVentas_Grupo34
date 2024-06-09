#define _CRT_SECURE_NO_WARNINGS 
#include "VentasManager.h"
#include <iostream>
#include <iomanip>
using namespace std;


VentasManager::VentasManager() : _archivo("Ventas.dat")
{

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
        cout << "3. Crear backup " << endl;
        cout << "4. Restaurar backup " << endl;
        cout << "5. Editar Venta " << endl;
        cout << "6. Borrar Venta " << endl;

        cout << endl;
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
            backupArchivo();
            system("pause");
            break;

        case 4:
            restaurarBackup();
            system("pause");
            break;

        case 5:
            editarVenta();
            system("pause");
            break;

        case 6:
            borrarVenta();
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
    Fecha f(1,1,1990);
    Venta reg;

    cout << "Venta: #" << id << endl;
    reg.setIdVenta(id);
    cout << "Ingrese fecha de Venta: " << endl;
    f.Cargar();
    reg.setFechaVenta(f);
    cout << endl;
    cout << "Ingrese DNI del Cliente: " << endl;
    cin >> dni;
    cin.ignore();
    reg.setDniCliente(dni);
    cout << "Ingrese ID de Sucursal: " << endl;
    cin >> idSucursal;
    cin.ignore();
    reg.setIdSucursal(idSucursal);
    cout << "Ingrese Legajo del Vendedor: " << endl;
    cin >> nroLegajo;
    cin.ignore();
    reg.setNroLegajo(nroLegajo);
    cout << "Ingrese ID del Vehiculo comprado: " << endl;
    cin >> idVehiculo;
    cin.ignore();
    reg.setIdVehiculo(idVehiculo);
    cout << "Gastos Administrativos: $" << endl;
    cin >> gastos;
    cin.ignore();
    reg.setGastosAdm(gastos);
    cout << "Total Venta: $" << endl;
    cin >> total;
    cin.ignore();
    reg.setTotalVentas(total);
    cout << endl;
    reg.setEliminado(false);

    return reg;
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

void VentasManager::mostrarVentaEnLinea(Venta reg)
{
    cout << left;
    cout << endl;
    cout << setw(5) << reg.getIdVenta();
    cout << setw(14) << reg.getFechaVenta().toString();
    cout << setw(15) << reg.getDniCliente();
    cout << setw(16) << reg.getIdSucursal();
    cout << setw(17) << reg.getNroLegajo();
    cout << setw(17) << reg.getIdVehiculo();
    cout << setw(2) << "$ " << setw(16) << fixed << setprecision(2) << reg.getGastosAdm();
    cout << setw(2) << "$ " << setw(16) << fixed << setprecision(2) << reg.getTotalVenta();
    cout << endl;
    
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
    Venta reg;
    cout << left;
    cout << setw(45) << " " << "* Listado de Ventas *" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << "#ID";
    cout << setw(14) << "Fecha Venta ";
    cout << setw(13) << "Dni Cliente ";
    cout << setw(14) << "Id Sucursal ";
    cout << setw(18) << "Legajo Vendedor ";
    cout << setw(20) << "Vehiculo comprado ";
    cout << setw(19) << "Gastos Adm ";
    cout << setw(16) << "Total Venta ";
    cout << endl;

    for (i=0; i < cantidad; i++) {
        
        reg = _archivo.leerVenta(i);
        if (reg.getEliminado() == false) {
            mostrarVentaEnLinea(reg); 
        }
        cout << endl;
    }
}

int VentasManager::buscarVenta(int idVenta)
{
    Venta reg;
    FILE* p;
    int pos = 0;
    p = fopen(_archivo.getNombreArchivo().c_str(), "rb");
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

void VentasManager::editarVenta()
{
    int id, opcion;
    
    cout << "Ingrese ID de Venta a editar: ";
    cin >> id;
    cin.ignore();
    cout << endl;
    
    int pos = buscarVenta(id);
    
    if (pos >= 0) {
        Venta reg;
        reg = _archivo.leerVenta(pos);

        if (reg.getEliminado() == false) {
            cout << endl << "Venta a Editar: " << endl;
            mostrarVenta(reg);

            cout << endl;
            cout << "¿Que dato desea editar?" << endl;
            cout << "1 - Fecha de Venta" << endl;
            cout << "2 - Gastos Administrativos" << endl;
            cin >> opcion;

            switch (opcion) {
            case 1:
            {
                Fecha f;
                f.Cargar();
                reg.setFechaVenta(f);
                break;
            }
            case 2:
            {
                float gastos;
                cout << "Ingrese nuevo valor de Gastos Administrativos: ";
                cin >> gastos;
                reg.setGastosAdm(gastos);
                break;

            default:
                cout << "Opcion invalida.";
                break;
            }
            }
            cout << endl;
            bool result = _archivo.sobreescribirVenta(reg, pos);

            if (result == true) {
                cout << "Se editó correctamente la venta." << endl;
            }
            else {
                cout << "No se pudo editar la venta." << endl;
            }


        }
        else {
            cout << "La venta buscada se encuentra eliminada" << endl;
        }
    
    }
    else {
        cout << "Error al buscar la venta. Codigo " << pos << endl;
    }
}

void VentasManager::backupArchivo()
{
    string origen = "Ventas.dat";
    string copia = "Ventas.bak";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());
    
    if (resultado == 0) {
        cout << endl << "Backup realizado con exito." << endl;
    }
    else {
        cout << "Hubo un error al copiar el archivo." << endl;
    }
   
}

void VentasManager::restaurarBackup()
{
    string origen = "Ventas.bak";
    string copia = "Ventas.dat";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << endl << "Backup restaurado con exito." << endl;
    }
    else {
        cout << "Hubo un error al restaurar el archivo." << endl;
    }

}

void VentasManager::borrarVenta()
{
    int id;
    char opc;

    cout << "Ingrese ID de Venta a borrar: ";
    cin >> id; 
    cin.ignore(); 
    cout << endl; 

    int pos = buscarVenta(id); 

    if (pos >= 0) {
        Venta reg;
        reg = _archivo.leerVenta(pos);

        cout << endl << "Venta a Borrar: " << endl;
        mostrarVenta(reg);
        cout << endl << "Confirma que desea borrar esta venta? S/N" << endl;
        cin >> opc;

        if (opc == 's' || opc == 'S') {
            reg.setEliminado(true);
            bool result = _archivo.sobreescribirVenta(reg, pos);
        }
        else {
            cout << endl << "Se cancelo el borrado de la venta." << endl;
        }

    }
    else {
        cout << "La venta buscada no existe" << endl;
    }

}
