#define _CRT_SECURE_NO_WARNINGS 
#include "VentasManager.h"
#include "ClienteManager.h"
#include "SucursalManager.h"
#include "VendedorManager.h"
#include "VehiculosManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;


VentasManager::VentasManager() : _archivo("Ventas.dat")
{

}

void VentasManager::Menu()
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
    cout << endl;
    
    //Validacion del cliente
    int posCliente = validarCliente(dni);
    if (posCliente >= 0) {
        reg.setDniCliente(dni);
    }
    else {
        char opc;
        cout << "El cliente no existe. Desea agregarlo? S/N: " << endl;
        cin >> opc;
        switch (opc) {
        case 'S':
        case 's':
            crearNuevoCliente();
            reg.setDniCliente(dni);
            system("cls");
            break;

        case 'N':
        case 'n':
            cout << "No se pudo finalizar la creacion de la venta." << endl;
            exit(1);
        }
    }
    mostrarClienteAsociado(posCliente);
    cout << endl;
    
    cout << "Ingrese ID de Sucursal: " << endl;
    cin >> idSucursal;
    cin.ignore();
    cout << endl;
    
    //Validacion Sucursal
    int posSucursal = validarSucursal(idSucursal);
    if (posSucursal >= 0) {
        reg.setIdSucursal(idSucursal);
    }
    else {
        do {
            cout << "La sucursal no existe. Intente nuevamente: " << endl;
            cin >> idSucursal; 
            cin.ignore(); 
            posSucursal = validarSucursal(idSucursal); 
        } while (posSucursal < 0);
        system("cls");
        reg.setIdSucursal(idSucursal);
        
    }
    mostrarSucursalAsociada(posSucursal);
    cout << endl;

    
    
    cout << "Ingrese Legajo del Vendedor: " << endl;
    cin >> nroLegajo;
    cin.ignore();
    cout << endl; 

    //Validacion Vendedor
    int posVendedor = validarVendedor(nroLegajo);
    if (posVendedor >= 0) {
        reg.setNroLegajo(nroLegajo);
    }
    else {
        do {
            cout << "El vendedor no existe. Intente nuevamente: " << endl;
            cin >> nroLegajo; 
            cin.ignore();
            posVendedor = validarVendedor(nroLegajo);
        } while (posVendedor < 0);
        system("cls");
        reg.setNroLegajo(nroLegajo); 

    }
    mostrarVendedorAsociado(posVendedor);
    cout << endl;
    
    cout << "Ingrese ID del Vehiculo comprado: " << endl;
    cin >> idVehiculo;
    cin.ignore();
    cout << endl;

    //Validacion Vehiculo
    int posVehiculo = validarVehiculo(idVehiculo);
    if (posVehiculo >= 0) { 
        reg.setIdVehiculo(idVehiculo); 
    }
    else {
        do {
            cout << "El vehiculo no existe. Intente nuevamente: " << endl;
            cin >> idVehiculo; 
            cin.ignore(); 
            posVehiculo = validarVehiculo(idVehiculo);
        } while (posVehiculo < 0);
        system("cls");
        reg.setIdVehiculo(idVehiculo);

    }
    mostrarVehiculoAsociado(posVehiculo);
    cout << endl; 
    
    cout << "Gastos Administrativos: $" << endl;
    cin >> gastos;
    cin.ignore();
    reg.setGastosAdm(gastos);

    total = calcularPrecioTotal(gastos, obtenerPrecioVehiculo(posVehiculo));
    reg.setTotalVentas(total);
    cout << "Total Venta: $" << fixed << setprecision(0) << total << endl;
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
    string gastosFormateado = formatearNumero(reg.getGastosAdm());
    cout << "Gastos Administrativos: $" << gastosFormateado << endl;
    string totalFormateado = formatearNumero(reg.getTotalVenta());
    cout << "Total Venta: $" << totalFormateado << endl;
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
    string gastosFormateado = formatearNumero(reg.getGastosAdm());
    cout << setw(2) << "$ " << setw(16) << gastosFormateado;
    string totalFormateado = formatearNumero(reg.getTotalVenta());
    cout << setw(2) << "$ " << setw(16) << totalFormateado;
    
    
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
    string copia = "Ventas.bkp";

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
    string origen = "Ventas.bkp";
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

int VentasManager::validarCliente(int dni)
{
    ClienteManager cm; 
    int resultado = cm.buscarCliente(dni);
    if (resultado >= 0) {
        return resultado;
    }
    else {
        return -1;
    }
}

void VentasManager::crearNuevoCliente()
{
    ClienteManager cm;
    
    cm.crearCliente();

    
}

void VentasManager::mostrarClienteAsociado(int pos)
{
    ClienteManager cm;
    ClienteArchivo ca; 
    Cliente aux;

    aux = ca.leerCliente(pos); 
    cout << "Cliente que realiza la compra: " << endl;
    cm.mostrarCliente(aux);
    cout << endl;

}

int VentasManager::validarSucursal(int id)
{
    SucursalManager sm;
    int resultado = sm.buscarPosicion(id);
    if (resultado >= 0) {
        return resultado;
    }
    else {
        return -1;
    }
}

void VentasManager::mostrarSucursalAsociada(int pos)
{
    SucursalManager sm;
    SucursalArchivo sa;
    Sucursal aux;

    aux = sa.leerRegistro(pos); 
    cout << "Sucursal asignada: " << endl;
    sm.mostrarRegistro(aux);
    cout << endl;
}

int VentasManager::validarVendedor(int nroLegajo)
{
    VendedorArchivo va;

    int resultado = va.BuscarId(nroLegajo);
    if (resultado >= 0) {
        return resultado;
    }
    else {
        return -1;
    }
}

void VentasManager::mostrarVendedorAsociado(int pos)
{
    VendedorManager vm; 
    VendedorArchivo va; 
    Vendedor aux; 

    aux = va.leerRegistro(pos);
    cout << "Vendedor asignado: " << endl;
    vm.MostrarVendedor(aux);
    cout << endl;
}

int VentasManager::validarVehiculo(int id)
{
    VehiculosArchivo va;

    int resultado = va.buscarRegistro(id);
    if (resultado >= 0) {
        return resultado;
    }
    else {
        return -1;
    }
}

void VentasManager::mostrarVehiculoAsociado(int pos)
{
    VehiculosManager vm;
    VehiculosArchivo va;
    Vehiculo aux;

    aux = va.leerRegistro(pos); 
    cout << "Vehiculo vendido: " << endl;
    vm.mostrarVehiculo(aux);
    cout << endl;
}

float VentasManager::obtenerPrecioVehiculo(int pos)
{
    VehiculosArchivo va;
    Vehiculo aux;

    aux = va.leerRegistro(pos); 

    return aux.getPrecioUnidad();
}

float VentasManager::calcularPrecioTotal(float gastos, float precio)
{

    return gastos + precio;
}

std::string VentasManager::formatearNumero(float numero)
{
    ostringstream oss{};
    oss << fixed << setprecision(2) << numero;
    string numeroStr = oss.str();
    size_t punto = numeroStr.find('.');
    string parteEntera = numeroStr.substr(0, punto);
    string parteDecimal = numeroStr.substr(punto);
    string parteEnteraFormateada;
    int longitud = parteEntera.length();
    for (int i = 0; i < longitud; ++i) {
        parteEnteraFormateada += parteEntera[i];
        if ((longitud - i - 1) % 3 == 0 && (i != longitud - 1)) {
            parteEnteraFormateada += ',';
        }
    }
    return parteEnteraFormateada + parteDecimal;
}
