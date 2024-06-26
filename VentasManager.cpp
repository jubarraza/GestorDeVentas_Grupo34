#define _CRT_SECURE_NO_WARNINGS 
#include "FuncionesGenerales.h"
#include "VentasManager.h"
#include "ClienteManager.h"
#include "SucursalManager.h"
#include "VendedorManager.h"
#include "VehiculosManager.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;


VentasManager::VentasManager() : _archivo("Ventas.dat")
{

}

void VentasManager::Menu()
{
    int opcion;
    do {
        system("cls");
        cout << "--- Menu Ventas ---" << endl;
        cout << "----------------------" << endl;
        cout << "1. Cargar Venta " << endl;
        cout << "2. Listar Ventas " << endl;
        cout << "3. Busqueda de Ventas " << endl;
        cout << "4. Editar Venta " << endl;
        cout << "5. Borrar Venta " << endl;
        cout << "6. Restaurar Venta borrada" << endl;
        cout << "7. Crear backup " << endl;
        cout << "8. Restaurar backup " << endl;

        cout << endl;
        cout << "0. Regresar al menu anterior " << endl;
        cout << "----------------------" << endl;
        opcion = validarInt("Opcion: ");
        system("cls");

        switch (opcion) {
        case 1:
            agregarVenta();
            system("pause");
            break;

        case 2:
            menuListados();
            break;

        case 3:
            buscadorDeVentas();
            system("pause");
            break;

        case 4:
            editarVenta();
            system("pause");
            break;

        case 5:
            borrarVenta();
            system("pause");
            break;

        case 6:
            restaurarVentaBorrada();
            system("pause");
            break;

        case 7:
            backupArchivo();
            system("pause");
            break;

        case 8: 
            restaurarBackup();
            system("pause");
            break;

        case 0:
            break;

        default:
            cout << endl << "* Selecione una Opcion Correcta! *" << endl << endl;;
            system("pause");
        }
    } while (opcion != 0);
}

Venta VentasManager::crearVenta()
{
    int id = _archivo.leerUltimoId() + 1;
    int nroLegajo, idSucursal, idVehiculo;
    long long dni;
    float gastos, total = 0;
    Fecha f(1,1,1990);
    Venta reg;

    cout << "Venta: #" << id << endl;
    reg.setIdVenta(id);
    
    cout << "* Ingrese fecha de Venta: " << endl;
    f.Cargar();
    reg.setFechaVenta(f);
    cout << endl;
    
    dni = validarLong("* Ingrese DNI del Cliente: ");
    cout << endl;
    
    //Validacion del cliente
    int posCliente = validarCliente(dni);
    if (posCliente >= 0) {
        reg.setDniCliente(dni);
    }
    else {
        int opc;
        opc = validarInt("El cliente no existe. Desea agregarlo? (1)Si - (2)No: ");
        cout << endl;
        switch (opc) {
        case 1:
            crearNuevoCliente(dni);
            reg.setDniCliente(dni);
            posCliente = validarCliente(dni); 
            system("cls");
            break;

        case 2:
            cout << "* No se pudo finalizar la creacion de la venta *" << endl;
            exit(1);
        }
    }
    mostrarClienteAsociado(posCliente);
    cout << endl;
    
    idSucursal = validarInt("* Ingrese ID de Sucursal: ");
    cout << endl;
    
    //Validacion Sucursal
    int posSucursal = validarSucursal(idSucursal);
    if (posSucursal >= 0) {
        reg.setIdSucursal(idSucursal);
    }
    else {
        do {
            cout << "* La sucursal no existe. Intente nuevamente *" << endl;
            idSucursal = validarInt("* Ingrese ID de Sucursal: ");
            posSucursal = validarSucursal(idSucursal); 
        } while (posSucursal < 0);
        system("cls");
        reg.setIdSucursal(idSucursal);
        
    }
    mostrarSucursalAsociada(posSucursal);
    cout << endl;

    
    
    nroLegajo = validarInt("* Ingrese Legajo del Vendedor: ");
    cout << endl; 

    //Validacion Vendedor
    int posVendedor = validarVendedor(nroLegajo);
    if (posVendedor >= 0) {
        reg.setNroLegajo(nroLegajo);
    }
    else {
        do {
            cout << "* El vendedor no existe. Intente nuevamente *" << endl;
            nroLegajo = validarInt("* Ingrese Legajo del Vendedor: ");
            posVendedor = validarVendedor(nroLegajo);
        } while (posVendedor < 0);
        system("cls");
        reg.setNroLegajo(nroLegajo); 

    }
    mostrarVendedorAsociado(posVendedor);
    cout << endl;
    
    idVehiculo = validarInt("* Ingrese ID del Vehiculo adquirido: ");
    cout << endl;

    //Validacion Vehiculo
    bool vehiculoDisponible = validarVehiculo(idVehiculo);
    
    if (vehiculoDisponible == true) { 
        reg.setIdVehiculo(idVehiculo);
    }
    mostrarVehiculoAsociado(idVehiculo);
    cout << endl; 
    
    gastos = pedirNumeroFloat("* Ingrese Gastos Administrativos: $");
    reg.setGastosAdm(gastos); 

    total = calcularPrecioTotal(reg.getGastosAdm(), obtenerPrecioVehiculo(idVehiculo));
    reg.setTotalVentas(total);
    cout << endl;
    cout << "* Total Venta: $" << formatearNumero(reg.getTotalVenta()) << endl; 
    cout << endl;
    reg.setEliminado(false);

    return reg;
}

void VentasManager::mostrarVenta(Venta reg)
{
    cout << left;
    cout << setw(0) << "Venta: #" << reg.getIdVenta() << "         " << "Fecha de Venta: " << reg.getFechaVenta().toString();
    cout << endl << endl;
    cout << "Cliente: " << mostrarNombreCliente(reg.getDniCliente()) << " - DNI: " << reg.getDniCliente() << endl;
    cout << "Sucursal: " << mostrarNombreSucursal(reg.getIdSucursal()) << endl;
    cout << "Vendedor: " << mostrarNombreVendedor(reg.getNroLegajo()) << endl;
    cout << "Vehiculo comprado: " << mostrarNombreVehiculo(reg.getIdVehiculo()) << endl;
    string gastosFormateado = formatearNumero(reg.getGastosAdm());
    cout << "Gastos Administrativos: $" << gastosFormateado << endl;
    string totalFormateado = formatearNumero(reg.getTotalVenta());
    cout << "Total Venta: $" << totalFormateado << endl;
}

void VentasManager::encabezadoListadoVentas() 
{
    cout << left;
    cout << setw(55) << " " << "* Ventas *" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(5) << "#ID";
    cout << setw(14) << "Fecha Venta ";
    cout << setw(19) << "Cliente ";
    cout << setw(25) << "Sucursal ";
    cout << setw(20) << "Vendedor ";
    cout << setw(26) << "Vehiculo comprado ";
    cout << setw(19) << "Gastos Adm ";
    cout << setw(16) << "Total Venta ";
    cout << endl;

}

void VentasManager::mostrarVentaEnLinea(Venta reg)
{
    cout << left;
    cout << endl;
    cout << setw(5) << reg.getIdVenta();
    cout << setw(14) << reg.getFechaVenta().toString();
    cout << setw(19) << mostrarNombreCliente(reg.getDniCliente());
    cout << setw(25) << mostrarNombreSucursal(reg.getIdSucursal());
    cout << setw(20) << mostrarNombreVendedor(reg.getNroLegajo());
    cout << setw(26) << mostrarNombreVehiculo(reg.getIdVehiculo());
    string gastosFormateado = formatearNumero(reg.getGastosAdm());
    cout << setw(2) << "$ " << setw(16) << gastosFormateado;
    string totalFormateado = formatearNumero(reg.getTotalVenta());
    cout << setw(2) << "$ " << setw(16) << totalFormateado;
    
    
}

void VentasManager::agregarVenta()
{
    if (_archivo.guardarVenta(crearVenta())) {
        cout << "* La venta se guardo correctamente *" << endl;
    }
    else {
        cout << "* No se pudo guardar la venta *" << endl;
    }
}


void VentasManager::menuListados()
{
    int opc;
    cout << "Como desea ordenar el listado de Ventas?" << endl;
    cout << "(1) por ID" << endl;
    cout << "(2) por Fecha de Venta " << endl << endl;
    opc = validarInt("Ingrese opcion: ");
    cout << endl;

    switch (opc)
    {
    case 1:
        listarVentas();
        system("pause");
        break;

    case 2:
        listarVentasXFecha();
        system("pause");
        break;

    default:
        cout << endl << "* Selecione una Opcion Correcta! *" << endl << endl;
        system("pause");
    }
}

void VentasManager::listarVentas()
{
    int i, cantidad = _archivo.contarVentas();
    Venta reg;

    if (cantidad == 0) {
        cout << "* No hay Ventas para mostrar *" << endl;
    }
    else {
        encabezadoListadoVentas();

        for (i=0; i < cantidad; i++) {
        
            reg = _archivo.leerVenta(i);
            if (reg.getEliminado() == false) {
                mostrarVentaEnLinea(reg); 
            }
        
        }
        cout << endl;

    }
    cout << endl;
    
}

void VentasManager::ordenar(vector<Venta>& vec, int cantidad) {
    Venta aux;

    for (int i = 0; i < cantidad; i++) {

        for (int j = i; j < cantidad; j++) {

            if (vec[i].getFechaVenta() > vec[j].getFechaVenta()) {
                 
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }
}

void VentasManager::listarVentasXFecha()
{
    int i, cantidad = _archivo.contarVentas();
    Venta reg;
    vector <Venta> vec;

    if (cantidad == 0) {
        cout << "* No hay Ventas para mostrar *" << endl;
    }
    else {
        encabezadoListadoVentas();
        for (i = 0; i < cantidad; i++) {
            reg = _archivo.leerVenta(i);
            vec.push_back(reg);
        }

        ordenar(vec, cantidad); 
        for (i = 0; i < cantidad; i++) {
            if (vec[i].getEliminado() == false) {
                mostrarVentaEnLinea(vec[i]);
            }
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
    
    id = validarInt("Ingrese ID de Venta a editar: ");
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
            opcion = validarInt("Opcion: ");
            cout << endl;

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
				gastos = validarFloat("Ingrese nuevo valor de Gastos Administrativos: $");
				reg.setGastosAdm(gastos);
				break;

            default:
                cout << "* Opcion invalida *";
                break;
            }
            }
            cout << endl;
            bool result = _archivo.sobreescribirVenta(reg, pos);

            if (result == true) {
                cout << "* Se edito correctamente la venta *" << endl;
            }
            else {
                cout << "* No se pudo editar la venta *" << endl;
            }


        }
        else {
            cout << "* La venta buscada se encuentra eliminada *" << endl;
        }
    
    }
    else {
        cout << "* Error al buscar la venta. Codigo: (";
        if (pos == -1) {
            cout << pos << ") La venta no existe *" << endl;
        }
        if (pos == -2) {
            cout << pos << ") No se pudo abrir el archivo *" << endl;

        }
    }
}

void VentasManager::backupArchivo()
{
    string origen = "Ventas.dat";
    string copia = "Ventas.bkp";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());
    
    if (resultado == 0) {
        cout << endl << "* Backup realizado con exito *" << endl;
    }
    else {
        cout << "* Hubo un error al copiar el archivo *" << endl;
    }
   
}

void VentasManager::restaurarBackup()
{
    string origen = "Ventas.bkp";
    string copia = "Ventas.dat";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << endl << "* Backup restaurado con exito *" << endl;
    }
    else {
        cout << "* Hubo un error al restaurar el archivo *" << endl;
    }

}

void VentasManager::borrarVenta()
{
    int id;
    int opc;

    id = validarInt("Ingrese ID de Venta a borrar: ");
    cout << endl; 

    int pos = buscarVenta(id); 

    if (pos >= 0) {
        Venta reg;
        reg = _archivo.leerVenta(pos);

        cout << endl << "Venta a Borrar: " << endl;
        mostrarVenta(reg);
        cout << endl;

        opc =  validarInt("Confirma que desea borrar esta venta? (1)Si - (2)No");

        if (opc == 1) {
            reg.setEliminado(true);
            bool result = _archivo.sobreescribirVenta(reg, pos);
            if (result) {
                cout << "* La venta se ha borrado correctamente *" << endl;
            }
            else {
                cout << "* No se pudo eliminar la venta *" << endl;
            }
        }
        else {
            cout << endl << "* Se cancelo el borrado de la venta *" << endl;
        }

    }
    else {
        cout << "* La venta buscada no existe *" << endl;
    }

}

void VentasManager::restaurarVentaBorrada() {
    int cantReg = _archivo.contarVentas();
    if (cantReg == -1) {
        cout << endl << "* Error de Archivo *" << endl;
    }
    else {
        int id, pos, opc;
        id = validarInt("Ingrese el ID de la Venta: ");
        system("cls");
        
        pos = buscarVenta(id);
        if (pos == -1) {
            cout << endl << "* No Existe ese ID de Venta *" << endl << endl;
        }
        if (pos >= 0) {
            Venta reg;
            reg = _archivo.leerVenta(pos);
            if (reg.getEliminado() == true) {
                cout << "Desea Restaurar el Registro? (1)Si (2)NO " << endl;
                opc = validarInt("Seleccione una Opcion: ");
                system("cls");

                switch (opc) {
                case 1: {
                    reg.setEliminado(false);
                    cout << endl;
                    mostrarVenta(reg);
                    bool restaurar = _archivo.sobreescribirVenta(reg, pos);
                    if (restaurar == true) {
                        cout << endl << setw(25) << " " << "* Registro Restaurado con Exito *" << endl << endl;
                    }
                    else {
                        cout << endl << "* No se Pudo Restaurar el Registro *" << endl;
                    }
                        system("pause");
                }
                case 2:
                    break;
                default:cout << endl << "* Opcion Incorrecta! *" << endl << endl;
                    return;
                }
            }
            else {
                cout << endl << "* El Registro Se Restauro con Exito *" << endl << endl;
                system("pause");
            }
        }
    }
    cout << endl;
}

int VentasManager::validarCliente(long long dni)
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

void VentasManager::crearNuevoCliente(long long dni)
{
    ClienteManager cm;
    ClienteArchivo ca;
    
    ca.guardarCliente(cm.crearCliente(dni));

    
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

std::string VentasManager::mostrarNombreCliente(long long dni)
{
    ClienteManager cm;
    ClienteArchivo ca;
    

    int pos = cm.buscarCliente(dni);

    Cliente aux = ca.leerCliente(pos);
    
    return aux.getApellidoNombre();


}

int VentasManager::validarSucursal(int id)
{
    SucursalArchivo sa;
    int resultado = sa.buscarPosicion(id);
    if (resultado >= 0) {
        return resultado;
    }
    else {
        return -1;
    }
}

void VentasManager::mostrarSucursalAsociada(int pos)
{
    SucursalArchivo sa;
    Sucursal aux;

    aux = sa.leerRegistro(pos); 
    cout << "Sucursal asignada: " << endl;
    cout << "Id Sucursal: #" << aux.getIdSucursal() << endl;
    cout << "Nombre: " << aux.getNombre() << endl;
    cout << "Dirección: " << aux.getDireccion().toString();
    cout << endl;
    cout << "Telefono: " << aux.getTelefono() << endl << endl;
}

std::string VentasManager::mostrarNombreSucursal(int id)
{
    SucursalManager sm;
    SucursalArchivo sa; 
    

    int pos = sa.buscarPosicion(id);

    Sucursal aux = sa.leerRegistro(pos); 

    string valor = to_string(aux.getIdSucursal()) + " - " + aux.getNombre();
    
    return valor;
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
    aux.MostrarPersona();
    cout << endl;
    cout << "NRO LEGAJO: " << aux.getNroLegajo() << endl;
    cout << "FECHA DE INGRESO: " << aux.getFechaIngreso().toString() << endl;
    cout << "ANTIGUEDAD: " << aux.getAntiguedad();
    cout << endl;
}

std::string VentasManager::mostrarNombreVendedor(int nrolegajo)
{
    VendedorArchivo va;
    int pos = va.BuscarId(nrolegajo);

    Vendedor aux = va.leerRegistro(pos);

    string valor = aux.getApellido() + ", " + aux.getNombre();

    return valor;
}

bool VentasManager::validarVehiculo(int& id)
{
    VehiculosArchivo va;
    bool resultado = false;

    int pos = va.buscarRegistro(id);
    
    if (pos >= 0) {
        Vehiculo aux = va.leerRegistro(pos);
        if (aux.getStock() > 0) {
            aux.setStock(aux.getStock() - 1);
            va.modificarRegistro(aux, pos);
            return true;

        }
        else {
            do {
                cout << "* El vehiculo no tiene stock y no puede ser vendido. *" << endl;
                id = validarInt("* Ingrese un nuevo id de vehiculo: ");
                resultado = validarVehiculo(id);

            } while (resultado == false);
            system("cls");
        }
        

    }
    else {
        do {
            cout << "* El vehiculo ingresado no existe *" << endl;
            id = validarInt("* Ingrese un nuevo id de vehiculo: ");
            resultado = validarVehiculo(id);
        } while (resultado == false);
        
    }
    
}

void VentasManager::mostrarVehiculoAsociado(int id)
{
    VehiculosManager vm;
    VehiculosArchivo va;
    Vehiculo aux;
    int pos = va.buscarRegistro(id);

    aux = va.leerRegistro(pos); 
    cout << "Vehiculo vendido: " << endl;
    cout << "ID Vehiculo: " << aux.getIdVehiculo() << endl;
    cout << "Marca y Modelo: " << aux.getMarca() << " " << aux.getModelo() << endl;
    cout << "Version: " << aux.getVersion() << endl;
    cout << "Color: " << aux.getColor() << endl;
    cout << "Año de fabricación: " << aux.getAnioFabricacion() << endl;
    //cout << "Stock actualizado: " << aux.getStock() << endl;
    cout << "Precio unidad: $" << formatearNumero(aux.getPrecioUnidad());
    cout << endl;
}

std::string VentasManager::mostrarNombreVehiculo(int id)
{
    VehiculosArchivo va;
    VehiculosManager vm;

    int pos = va.buscarRegistro(id);

    Vehiculo aux = va.leerRegistro(pos);

    string valor = to_string(id)+ " - " + aux.getMarca() + " " + aux.getModelo();

    return valor;
}

float VentasManager::obtenerPrecioVehiculo(int id)
{
    VehiculosArchivo va;
    Vehiculo aux;
    int pos = va.buscarRegistro(id);
    aux = va.leerRegistro(pos); 

    return aux.getPrecioUnidad();
}

float VentasManager::calcularPrecioTotal(float gastos, float precio)
{
    return gastos + precio;
}

std::string VentasManager::formatearNumero(double numero)
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

void VentasManager::buscadorDeVentas()
{
    int cantReg = _archivo.contarVentas();
    if (cantReg == -1) {
        cout << endl << "* Error de Archivo *" << endl;
    }
    else {
        int opc;
        cout << "- Buscar Venta -" << endl;
        cout << "-------------------" << endl;
        cout << "1) Por ID " << endl;
        cout << "2) Por Fecha de Venta " << endl;
        cout << endl;
        cout << "0) Salir " << endl << endl;
        opc = validarInt("Opcion: ");
        system("cls");
        switch (opc) {
        
        case 1:buscarVentaPorID();
            break;
        case 2:buscarVentaPorFecha();
            break;
        case 0:
            break;

        default:cout << endl << "* Opcion Incorrecta! *" << endl << endl;
            return;
        }
    }
    cout << endl;
}

void VentasManager::buscarVentaPorID()
{
    int id, pos; 
    id = validarInt("Ingrese el ID a buscar: ");
    cout << endl;
    pos = buscarVenta(id);
    if (pos == -1) {
        cout << endl << "* No se Encontraron Registros *" << endl;
    }
    if (pos >= 0) {
        Venta reg;
        reg = _archivo.leerVenta(pos);
        if (reg.getEliminado() == false) {
            mostrarVenta(reg);
            cout << endl;
        }
        else {
            cout << "* El Registro se Encuentra Eliminado *" << endl;
        }
    }
    cout << endl;
}

void VentasManager::buscarVentaPorFecha()
{
    Fecha f;
    Venta reg;
    int cantReg, contador = 0;

    cout << "Ingrese fecha a buscar:" << endl;
    f.Cargar();
    cout << endl;

    cantReg = _archivo.contarVentas();
    for (int i = 0; i < cantReg; i++) {
        reg = _archivo.leerVenta(i);
        if (reg.getEliminado() == false && reg.getFechaVenta().getAnio() == f.getAnio() && reg.getFechaVenta().getMes() == f.getMes() && reg.getFechaVenta().getDia() == f.getDia()) {
            if (contador == 0) {
                encabezadoListadoVentas();
                mostrarVentaEnLinea(reg);
                contador++;
            }
            else {
                mostrarVentaEnLinea(reg);
                contador++;

            }
        }
    }
    if (contador == 0) {
        cout << "* No hay ventas para la fecha buscada * " << endl;
    }

}

 