#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
using namespace std;
#include "SucursalManager.h"


SucursalManager::SucursalManager() : _archivo()
{
 
}

void SucursalManager::menu()
{
    int opcion;
    do {
        system("cls");
        cout << "----- MENU SUCURSAL -----" << endl;
        cout << "********************** " << endl;
        cout << endl;
        cout << "1. Agregar Registro    " << endl;
        cout << "2. Listar Registros    " << endl;
        cout << "3. Modificar Registros " << endl;
        cout << "4. Borrar Sucursal     " << endl;
        cout << "5. Backup              ";

        cout << endl;
        cout << "0. SALIR DEL PROGRAMA " << endl;
        cout << "********************** " << endl;
        cout << "OPCION: " << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            agregarRegistro();
            system("pause");
            break;

        case 2:
            listarRegistros();
            system("pause");
            break;
        case 3:
            editarRegistro();
            system("pause");
            break;
        case 4:
            bajaLogica();
            system("pause");
            break;
        case 5:
            backupArchivo();
            system("pause");
            break;
        case 0:

            break;
        }
    } while (opcion != 0);
}

int SucursalManager::buscarPosicion(int codBuscado)
{
    Sucursal reg;
    FILE* p;
    int pos = 0;
    p = fopen("Sucursal.dat", "rb");
    if (p == nullptr) {
        return -2; //no se abrio el archivo
    }
    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (reg.getIdSucursal() == codBuscado) {
            fclose(p); //cierro el archivo porque ya encontre la empresa
            return pos;
        }
        pos++;
    }
    fclose(p);

    return -1; //se recorrio el archivo y no existe el codigo
}

void SucursalManager::agregarRegistro()
{
    if (_archivo.guardarRegistro(crearRegistro())) {
        cout << "La Sucursal se guardó correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar la sucursal." << endl;
    }
}

void SucursalManager::listarRegistros()
{
    int i, cantidad = _archivo.contarRegistro();

    Sucursal reg;

    for (i = 0; i < cantidad; i++) {
        cout << "------------------------------" << endl;
        reg = _archivo.leerRegistro(i);
        if (reg.getEstado() == false) {
            mostrarRegistro(reg);
        }
        cout << "------------------------------" << endl << endl;
    }
}

Sucursal SucursalManager::crearRegistro()
{
    Sucursal reg;

    cout << "---- Crear Registro ----" << endl;
    cout << endl;
    reg.Cargar();

    return reg;
}

void SucursalManager::mostrarRegistro(Sucursal reg)
{

    cout << "---- Mostrar Registro ----" << endl;
    cout << endl;
    reg.Mostrar();

}

void SucursalManager::editarRegistro()
{
    int id, pos, opcion;
    Sucursal reg;

    cout << "Ingrese ID de la Sucursal que desea Modificar " << endl;
    cin >> id;
    cin.ignore();
    cout << endl;

    pos = buscarPosicion(id); 

    if (pos >= 0) {
        reg = _archivo.leerRegistro(pos);
        if (reg.getEstado() == false) {
            cout << endl << "Sucursal a Modificar: " << endl;
            reg.Mostrar();

            cout << endl;
            cout << "¿Que dato desea Editar? " << endl;
            cout << "1 - Nombre" << endl;
            cout << "2 - Direccion" << endl;
            cout << "3 - Telefono" << endl;
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
            case 1:
            {
                string n;
                cout << "Ingrese nuevo Nombre: ";
                getline(cin, n);
                reg.setNombre(n);
                break;
            }
            case 2:
            {
                Direccion d;
                cout << "Ingrese nueva dirección: ";
                d.Cargar();
                reg.setDireccion(d);
                break;
            }
            case 3:
            {
                int tel;
                cout << "Ingrese nuevo telefono: ";
                cin >> tel;
                cin.ignore();
                reg.setTelefono(tel);
                break;
            }
            default:
                cout << "Opcion invalida.";
                break;
            }

            cout << endl;
            bool modificacion = _archivo.sobreescribirRegistro(reg, pos);

            if (modificacion = true) {
                cout << "La sucursal se modifico correctamente." << endl;
            }
            else {
                cout << "No se pudo modificar la sucursal." << endl;
            }


        }
        else {
            cout << "La sucursal buscada se encuentra eliminada." << endl;
        }
    }
}

void SucursalManager::bajaLogica()
{
    int id;
    char op;

    cout << "Ingrese ID de la Sucursal que se desea dar de baja " << endl;
    cin >> id;
    cin.ignore();
    cout << endl;

    int pos = buscarPosicion(id); 

    if (pos >= 0) {
        Sucursal reg;
        reg = _archivo.leerRegistro(pos);

        cout << endl << "Sucursal a Eliminar: " << endl;
        mostrarRegistro(reg);
        cout << endl << "¿Confirma que desea eliminar esta Sucursal? S/N" << endl;
        cin >> op;

        if (op == 's' || op == 'S') {
            reg.setEstado(false);
            bool resultado = _archivo.sobreescribirRegistro(reg, pos);
        }
        else {
            cout << endl << "Eliminacion de la Sucursal cancelada. " << endl;
        }

    }
    else {
        cout << "La sucursal buscada no existe. " << endl;
    }
}

void SucursalManager::backupArchivo()
{
    string origen = "Sucursal.dat";
    string copia = "Sucursal.bkp";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << endl << "Backup realizado con exito. " << endl;
    }
    else{
        cout << "Hubo un error al copiar el archivo. " << endl;
    }
}

void SucursalManager::restaurarBackup()
{
    string origen = "Sucursal.dat";
    string copia = "Sucursal.bkp";

    string comando = "copy " + origen + " " + copia;

    int resultado = system(comando.c_str());

    if (resultado == 0) {
        cout << endl << "Backup realizado con exito. " << endl;
    }
    else{
        cout << "Hubo un error al copiar el archivo. " << endl;
    }
}

