#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "VehiculosManager.h"
using namespace std;

VehiculosManager::VehiculosManager() : _vehiculosArchivo("Vehiculos.dat")
{
    
}

void VehiculosManager::Menu() {
    int opc;
    do {
        system("cls");
        cout << "--- Menu Vehiculos ---" << endl;
        cout << "----------------------" << endl;
        cout << "1) Cargar " << endl;
        cout << "2) Listar " << endl;
        cout << "3) Editar " << endl;
        cout << "4) Eliminar " << endl;
        cout << "5) Restaurar Vehiculo" << endl;
        cout << "6) Realizar Backup " << endl;
        cout << "7) Restaurar Backup " << endl;
        cout << "0) Salir " << endl;
        cout << "----------------------" << endl;
        cout << "Selecione una Opcion: ";
        cin >> opc;
        system("cls");
        switch (opc) {
        case 1: agregarVehiculo();
            system("pause");
            break;
        case 2: listarVehiculos();
            system("pause");
            break;
        case 3: editarVehiculo();
            system("pause");
            break;
        case 4: eliminarVehiculo();
            system("pause");
            break;
        case 5: resturarVehiculo();
            system("pause");
            break;
        case 6: realizarBackup();
            system("pause");
            break;
        case 7: restaurarBackup();
            system("pause");
            break;
        case 0:cout << endl << " Adios!! " << endl;
            break;
        default:cout << endl << "* Selecione una Opcion Correcta! " << endl << endl;;
            system("pause");
        }
    } while (opc != 0);

}

void VehiculosManager::agregarVehiculo() {
    if (_vehiculosArchivo.guardarRegistro(cargarVehiculo())) {
        cout << " * Registro Agregado! * " << endl;
    }
    else {
        cout << " * No se Pudo Agregar el Registro * " << endl;
    }
}

Vehiculo VehiculosManager::cargarVehiculo() {
    string marca, modelo, version, color;
    int id, anio, stock;
    float precio;
    VehiculosArchivo archivo;
    int cantReg = archivo.contarRegistros();
    Vehiculo reg;
    id = ++cantReg;
    cout << "- Ingrese Los Datos del Vehiculo -" << endl;
    cout << "- ID: ";
    cout << id << endl;
    reg.setIdVehiculo(id);
    cin.ignore();
    cout << "- Marca: ";
    getline(cin, marca);
    reg.setMarca(marca);
    cout << "- Modelo: ";
    getline(cin, modelo);
    reg.setModelo(modelo);
    cout << "- Version: ";
    getline(cin, version);
    reg.setVersion(version);
    cout << "- Color: ";
    getline(cin, color);
    reg.setColor(color);
    cout << "- Anio de Fabricacion: ";
    cin >> anio;
    reg.setAnioFabricacion(anio);
    cout << "- Stock: ";
    cin >> stock;
    reg.setStock(stock);
    cout << "- Precio por Unidad: $ ";
    cin >> precio;
    reg.setPrecioUnidad(precio);
    reg.setEstado(true);
    return reg;
}

void VehiculosManager::mostrarVehiculo(Vehiculo reg) {
    if (reg.getEstado() == true) {
        cout << left;
        cout << setw(4) << reg.getIdVehiculo();
        cout << setw(10) << reg.getMarca();
        cout << setw(14) << reg.getModelo();
        cout << setw(12) << reg.getVersion();
        cout << setw(10) << reg.getColor();
        cout << setw(8) << reg.getAnioFabricacion();
        cout << setw(8) << reg.getStock();
        cout << setw(2) << "$ " << setw(18) << fixed << setprecision(2) << reg.getPrecioUnidad();
        cout << endl;
    }
    else {
        cout << reg.getIdVehiculo() << "   Este Registro se Encuentra Eliminado! " << endl;
    }
}

void VehiculosManager::listarVehiculos() {
    int cantReg = _vehiculosArchivo.contarRegistros();
    Vehiculo reg;
    cout << left;
    cout << setw(26) << " " << "* Datos de Vehiculos *" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << setw(4) << "ID ";
    cout << setw(10) << "Marca ";
    cout << setw(14) << "Modelo ";
    cout << setw(12) << "Version ";
    cout << setw(10) << "Color ";
    cout << setw(8) << "Anio ";
    cout << setw(8) << "Stock ";
    cout << setw(20) << "Precio por Unidad ";
    cout << endl;
    for (int i = 0; i < cantReg; i++) {
        reg = _vehiculosArchivo.leerRegistro(i);
        mostrarVehiculo(reg);
    }
    cout << endl;
}

void VehiculosManager::editarVehiculo() {
    int id, opc, pos;
    Vehiculo reg;
    cout << "- Ingrese el ID del Vehiculo que desea Editar: ";
    cin >> id;
    cout << endl;
    pos = _vehiculosArchivo.buscarRegistro(id);
    if (pos == -1) {
        cout << "* No Existe ese ID de Vehiculo *" << endl << endl;
    }
    if (pos == -2) {
        cout << "* Error de Archivo *" << endl;
    }
    if (pos >= 0) {
        Vehiculo reg;
        reg = _vehiculosArchivo.leerRegistro(pos);
        if (reg.getEstado() == true) {
            cout << left;
            cout << setw(30) << " " << "* Datos deL Vehiculo *" << endl;
            cout << setw(4) << "ID ";
            cout << setw(10) << "Marca ";
            cout << setw(14) << "Modelo ";
            cout << setw(12) << "Version ";
            cout << setw(10) << "Color ";
            cout << setw(8) << "Anio ";
            cout << setw(8) << "Stock ";
            cout << setw(20) << "Precio por Unidad ";
            cout << endl;
            mostrarVehiculo(reg);
            cout << endl << "- Que desea Editar? -" << endl;
            cout << "1) Marca " << endl;
            cout << "2) Modelo " << endl;
            cout << "3) Version " << endl;
            cout << "4) Color " << endl;
            cout << "5) Anio " << endl;
            cout << "6) Stock " << endl;
            cout << "7) Precio " << endl;
            cout << "8) Todo " << endl;
            cout << "0) Salir " << endl;
            cout << "Seleccion una Opcion: ";
            cin >> opc;
            switch (opc) {
            case 1: {
                string nuevaMarca;
                cin.ignore();
                cout << "- Ingrese la Nueva Marca: ";
                getline(cin, nuevaMarca);
                reg.setMarca(nuevaMarca);
                break;
            }
            case 2: {
                string nuevoModelo;
                cin.ignore();
                cout << "- Ingrese el Nuevo Modelo: ";
                getline(cin, nuevoModelo);
                reg.setModelo(nuevoModelo);
                break;
            }
            case 3: {
                string nuevaVersion;
                cin.ignore();
                cout << "- Ingrese la Nueva Version: ";
                getline(cin, nuevaVersion);
                reg.setVersion(nuevaVersion);
                break;
            }
            case 4: {
                string nuevoColor;
                cin.ignore();
                cout << "- Ingrese Nuevo Color: ";
                getline(cin, nuevoColor);
                reg.setColor(nuevoColor);
                break;
            }
            case 5: {
                int nuevoAnio;
                cout << "- Ingrese Nuevo Anio: ";
                cin >> nuevoAnio;
                reg.setAnioFabricacion(nuevoAnio);
                break;
            }
            case 6: {
                int nuevoStock;
                cout << "-Ingrese Nuevo Stock: ";
                cin >> nuevoStock;
                reg.setStock(nuevoStock);
                break;
            }
            case 7: {
                float nuevoPrecio;
                cout << "-Ingrese Nuevo Precio: ";
                cin >> nuevoPrecio;
                reg.setPrecioUnidad(nuevoPrecio);
                break;
            }
            case 8: {
                string nuevaMarca, nuevoModelo, nuevaVersion, nuevoColor;
                int nuevoAnio, nuevoStock;
                float nuevoPrecio;
                cin.ignore();
                cout << "- Nueva Marca: ";
                getline(cin, nuevaMarca);
                cout << "- Nuevo Modelo: ";
                getline(cin, nuevoModelo);
                cout << "- Nueva Version: ";
                getline(cin, nuevaVersion);
                cout << "- Nuevo Color: ";
                getline(cin, nuevoColor);
                cout << "- Ingrese Nuevo Anio: ";
                cin >> nuevoAnio;
                cout << "- Nuevo Stock: ";
                cin >> nuevoStock;
                cout << "- Precio: ";
                cin >> nuevoPrecio;
                reg.setMarca(nuevaMarca);
                reg.setModelo(nuevoModelo);
                reg.setVersion(nuevaVersion);
                reg.setColor(nuevoColor);
                reg.setAnioFabricacion(nuevoAnio);
                reg.setStock(nuevoStock);
                reg.setPrecioUnidad(nuevoPrecio);
                break;
            }
            case 0:
                return;
            default:cout << endl << "* Opcion Inorrecta! " << endl << endl;
                return;
            }
            bool modifico = _vehiculosArchivo.modificarRegistro(reg, pos);
            if (modifico == true) cout << "* Registro Modificado con Exito *" << endl;
            else cout << "* No se Pudo Modificar el Registro *" << endl;
        }
        else {
            cout << "* El Registro se Encuentra Eliminado *" << endl;
        }
    }
}


void VehiculosManager::eliminarVehiculo() {
    int id, pos, opc;
    cout << "- Ingrese el ID del Vehiculo: ";
    cin >> id;
    cout << endl;
    pos = _vehiculosArchivo.buscarRegistro(id);
    if (pos == -1) {
        cout << "* No Existe ese ID de Vehiculo *" << endl << endl;
    }
    if (pos == -2) {
        cout << "* Error de Archivo *" << endl;
    }
    if (pos >= 0) {
        Vehiculo reg;
        reg = _vehiculosArchivo.leerRegistro(pos);
        if (reg.getEstado() == true) {
            cout << left;
            cout << setw(30) << " " << "* Datos deL Vehiculo *" << endl;
            cout << setw(4) << "ID ";
            cout << setw(10) << "Marca ";
            cout << setw(14) << "Modelo ";
            cout << setw(12) << "Version ";
            cout << setw(10) << "Color ";
            cout << setw(8) << "Anio ";
            cout << setw(8) << "Stock ";
            cout << setw(20) << "Precio por Unidad ";
            cout << endl;
            mostrarVehiculo(reg);
            cout << endl;
            cout << "- Desea Eliminar el Registro? (1)Si (2)NO " << endl;
            cout << "Seleccione una Opcion: ";
            cin >> opc;
            switch (opc) {
            case 1: {
                reg.setEstado(false);
                bool elimino = _vehiculosArchivo.modificarRegistro(reg, pos);
                if (elimino == true) cout << "* Registro Eliminado *" << endl;
                else cout << "* No se Pudo Eliminar el Registro *" << endl;
                break;
            }
            case 2:
                break;
            default:cout << "* Opcion Inorrecta! " << endl;;
            }
        }
        else {
            cout << "* El Registro ya se Encuentra Eliminado *" << endl << endl;
        }
    }
}

void VehiculosManager::resturarVehiculo() {
    int id, pos, opc;
    cout << "- Ingrese el ID del Vehiculo: ";
    cin >> id;
    cout << endl;
    pos = _vehiculosArchivo.buscarRegistro(id);
    if (pos == -1) {
        cout << "* No Existe ese ID de Vehiculo *" << endl << endl;
    }
    if (pos == -2) {
        cout << "* Error de Archivo *" << endl;
    }
    if (pos >= 0) {
        Vehiculo reg;
        reg = _vehiculosArchivo.leerRegistro(pos);
        if (reg.getEstado() == false) {
            cout << "- Desea Restaurar el Registro? (1)Si (2)NO " << endl;
            cout << "- Seleccione una Opcion: ";
            cin >> opc;
            switch (opc) {
            case 1:
                reg.setEstado(true);
                cout << left;
                cout << setw(30) << " " << "* Datos deL Vehiculo *" << endl;
                cout << setw(4) << "ID ";
                cout << setw(10) << "Marca ";
                cout << setw(14) << "Modelo ";
                cout << setw(12) << "Version ";
                cout << setw(10) << "Color ";
                cout << setw(8) << "Anio ";
                cout << setw(8) << "Stock ";
                cout << setw(20) << "Precio por Unidad ";
                cout << endl;
                mostrarVehiculo(reg);
            case 2:
                break;
            default:cout << endl << "* Opcion Inorrecta! " << endl << endl;
                return;
            }
            bool restaurar = _vehiculosArchivo.modificarRegistro(reg, pos);
            if (restaurar == true) cout << setw(25) << " " << "* Registro Restaurado con Exito *" << endl;
            else cout << "* No se Pudo Restaurar el Registro *" << endl;
        }
        else {
            cout << "* El Registro ya Se Encuentra Disponible *" << endl << endl;
        }
    }
}

void VehiculosManager::realizarBackup() {
    int opc;
    cout << "- Desea Relizar Backup del Archivo Vehiculo?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vehiculos.dat Vehiculos.bkp");
        cout << "* Backup Realizado con Exito! *" << endl;
    case 2:
        break;
    default:cout << endl << "* Opcion Incorrecta! " << endl << endl;;
    }
}

void VehiculosManager::restaurarBackup() {
    int opc;
    cout << "- Desea Restaurar del Archivo Vehiculo?" << endl;
    cout << " (1)SI (2)NO " << endl;
    cout << "Selecione una Opcion: ";
    cin >> opc;
    switch (opc) {
    case 1: system("copy Vehiculos.bkp Vehiculos.dat");
        cout << "* Restauracion Realizado con Exito! *" << endl;
    case 2:
        break;
    default:cout << endl << "* Opcion Inorrecta! " << endl << endl;;
    }
}