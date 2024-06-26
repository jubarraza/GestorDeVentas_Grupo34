#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <locale>
#include "ClienteManager.h"
#include "FuncionesGenerales.h"
using namespace std;

ClienteManager::ClienteManager() : _archivo("Clientes.dat")
{
}

void ClienteManager::Menu()
{
    int opcion;
    do {
        system("cls");
        cout << "--- Menu Clientes ---" << endl;
        cout << "----------------------" << endl;
        cout << "1. Cargar Cliente " << endl;
        cout << "2. Listar Clientes " << endl;
        cout << "3. Buscador de Clientes " << endl;
        cout << "4. Editar Cliente " << endl;
        cout << "5. Borrar Cliente " << endl;
        cout << "6. Crear backup " << endl;
        cout << "7. Restaurar backup " << endl;

        cout << endl;
        cout << "0. Regresar al menu anterior " << endl;
        cout << "----------------------" << endl;
        opcion = validarInt("Opcion: ");
        system("cls");

        switch (opcion) {
        case 1:
            agregarCliente();
            system("pause");
            break;

        case 2:
            menuListado();
            break;

        case 3:
            buscadorDeClientes();
            system("pause");
            break;

        case 4:
            editarCliente();
            system("pause");
            break;

        case 5:
            borrarCliente();
            system("pause");
            break;

        case 6:
            backupArchivo();
            system("pause");
            break;
        case 7:
            restaurarBackup();
            system("pause");
            break;

        case 0:

            break;
        }
    } while (opcion != 0);
}

Cliente ClienteManager::crearCliente()
{
    string email, tel;
    Direccion d;
    Cliente reg;
    int opc;
    cout << "------------- Ingreso de nuevo Cliente -------------" << endl;
    regreso:
    reg.CargarPersona();
    bool resultado = DniRepetido(reg.getDni());
    if (resultado) {
        std::cout << "* Cliente ya existente *";
        opc = validarInt("Desea cargar un nuevo cliente? (1)Si - (2)No : ");

        switch (opc)
        {
        case 1:
            system("cls");
            goto regreso;
            break;
        case 2:
            Menu();
            break;
        
        default:
            break;
        }

    }

    cout << "EMAIL: ";
    getline(cin, email);
    reg.setEmail(email);
    tel = validarStringNumerico("TELEFONO: ");
    reg.setTelefono(tel);
    cout << "DIRECCION: " << endl;
    d.Cargar();
    reg.setDireccion(d);
    reg.setEliminado(false);

    return reg;
}

Cliente ClienteManager::crearCliente(long long dni)
{
    string email, tel;
    Direccion d;
    Cliente reg;
    char opc;
    cout << "------------- Ingreso de nuevo Cliente -------------" << endl;
    reg.CargarPersona(dni);
    cout << "EMAIL: ";
    getline(cin, email);
    reg.setEmail(email);
    tel = validarStringNumerico("TELEFONO: ");
    reg.setTelefono(tel);
    cout << "DIRECCION: " << endl;
    d.Cargar();
    reg.setDireccion(d);
    reg.setEliminado(false);

    return reg;
}


void ClienteManager::mostrarCliente(Cliente reg)
{
    reg.MostrarPersona();
    cout << endl;
    cout << "EMAIL: " << reg.getEmail() << endl;
    cout << "TELEFONO: " << reg.getTelefono() << endl;
    cout << "DIRECCION: " << reg.getDireccion().toString();
}

void ClienteManager::mostrarClienteEnLinea(Cliente reg) 
{
    reg.MostrarPersonaEnLinea();
    cout << setw(33) << reg.getEmail();
    cout << setw(20) << reg.getTelefono();
    cout << setw(30) << reg.getDireccion().toString();
    cout << endl;
}

void ClienteManager::agregarCliente()
{
    if (_archivo.guardarCliente(crearCliente())) {
        cout << "El cliente se guard� correctamente." << endl;
    }
    else {
        cout << "No se pudo guardar el cliente." << endl;
    }
}

void ClienteManager::encabezadoClientes()
{
    cout << left;
    cout << setw(55) << " " << "* Listado de Clientes *" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(14) << "DNI";
    cout << setw(20) << "Nombre ";
    cout << setw(20) << "Apellido ";
    cout << setw(23) << "Fecha de Nacimiento ";
    cout << setw(33) << "Email ";
    cout << setw(20) << "Telefono ";
    cout << setw(30) << "Direccion ";
    cout << endl;
}

void ClienteManager::menuListado()
{
    int opc;
    cout << "Como desea ordenar el listado de Clientes?" << endl;
    cout << "(1) por orden de Carga o (2) por Apellido " << endl;
    opc = validarInt("Opcion: ");
    cout << endl;

    switch (opc)
    {
    case 1:
        listarClientes();
        system("pause");
        break;

    case 2:
        listarClientesXApellido();
        system("pause");
        break;

    default:
        break;
    }
}

void ClienteManager::listarClientes() //por oden de carga
{
    int i, cantidad = _archivo.contarClientes();
    Cliente reg;

    encabezadoClientes();

        for (i = 0; i < cantidad; i++) {
            reg = _archivo.leerCliente(i);
            if (reg.getEliminado() == false) {
                mostrarClienteEnLinea(reg);
            }
        
        }

}

void ClienteManager::listarClientesXApellido()
{

    int i, cantidad = _archivo.contarClientes();
    Cliente reg;
    vector <Cliente> vec;

    if (cantidad == 0) {
        cout << "* No hay Clientes para mostrar *" << endl;
    }
    else {
        encabezadoClientes();
        for (i = 0; i < cantidad; i++) {
            reg = _archivo.leerCliente(i);
            vec.push_back(reg);
        }
        ordenar(vec, cantidad);
        for (i = 0; i < cantidad; i++) {
            if (vec[i].getEliminado() == false) {
                mostrarClienteEnLinea(vec[i]);
            }
        }
        cout << endl;

    }
}

void ClienteManager::ordenar(vector<Cliente>& vec, int cantidad) {
    Cliente aux;

    for (int i = 0; i < cantidad; i++) {

        for (int j = i; j < cantidad; j++) {

            if (vec[i].getApellido() > vec[j].getApellido()) {

                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;

            }
        }
    }

}

int ClienteManager::buscarCliente(long dni)
{
    Cliente reg;
    FILE* p;
    int pos = 0;
    p = fopen(_archivo.getNombreArchivo().c_str(), "rb");
    if (p == nullptr) {
        return -2; //no se abrio el archivo
    }
    while (fread(&reg, sizeof reg, 1, p) == 1) {
        if (reg.getDni() == dni) {
            fclose(p); //cierro el archivo porque ya encontre la empresa
            return pos;
        }
        pos++;
    }
    fclose(p);

    return -1; //se recorrio el archivo y no existe el codigo
}

void ClienteManager::editarCliente()
{
    long long dni;
    int opcion;

    dni = validarLong("Ingrese DNI del Cliente a editar: ");
    cout << endl;

    int pos = buscarCliente(dni);

    if (pos >= 0) {
        Cliente reg;
        reg = _archivo.leerCliente(pos);

        if (reg.getEliminado() == false) {
            cout << endl << "Cliente a Editar: " << endl;
            mostrarCliente(reg);

            cout << endl << endl;
            cout << "�Que dato desea editar?" << endl;
            cout << "1 - Email" << endl;
            cout << "2 - Telefono" << endl;
            cout << "3 - Direccion" << endl;
            opcion = validarInt("Opcion: ");

            switch (opcion) {
            case 1:
            {
                string e;
                cout << "Ingrese nuevo email:";
                getline(cin, e);
                reg.setEmail(e);
                break;
            }
            case 2:
            {
                string tel;
                tel = validarStringNumerico("Ingrese nuevo telefono: ");
                reg.setTelefono(tel);
                break;
            }
            case 3:
            {
                Direccion d;
                cout << "Ingrese nueva direcci�n: ";
                d.Cargar();
                reg.setDireccion(d);
                break;
            }
            default:
                cout << "Opcion invalida.";
                break;
            }

            cout << endl;
            bool result = _archivo.sobreescribirCliente(reg, pos);

            if (result == true) {
                cout << "Se edit� correctamente el cliente." << endl;
            }
            else {
                cout << "No se pudo editar el cliente." << endl;
            }


        }
        else {
            cout << "El cliente buscado se encuentra eliminado" << endl;
        }

    }
    else {
        cout << "Error al buscar el cliente. Codigo error " << pos << endl;
    }
}

void ClienteManager::backupArchivo()
{
    string origen = "Clientes.dat";
    string copia = "Clientes.bkp";

    string comando = "copy " + origen + " " + copia; 

    int resultado = system(comando.c_str()); 

    if (resultado == 0) {
        cout << endl << "Backup realizado con exito." << endl; 
    }
    else {
        cout << "Hubo un error al copiar el archivo." << endl; 
    }
}

void ClienteManager::restaurarBackup()
{
    string origen = "Clientes.bkp";
    string copia = "Clientes.dat";

    string comando = "copy " + origen + " " + copia; 

    int resultado = system(comando.c_str()); 

    if (resultado == 0) {
        cout << endl << "Backup restaurado con exito." << endl; 
    }
    else {
        cout << "Hubo un error al restaurar el archivo." << endl; 
    }
}

void ClienteManager::borrarCliente()
{
    long long dni;
    int opc;

    dni = validarLong("Ingrese DNI del Cliente a borrar: ");
    cout << endl; 

    int pos = buscarCliente(dni);

    if (pos >= 0) {
        Cliente reg;
        reg = _archivo.leerCliente(pos);

        cout << endl << "Cliente a Borrar: " << endl << endl;
        mostrarCliente(reg);
        cout << endl;
        opc = validarInt("Confirma que desea borrar este Cliente? (1)Si - (2)No: ");

        if (opc == 1) {
            reg.setEliminado(true);
            bool result = _archivo.sobreescribirCliente(reg, pos);
            if (result) {
                cout << "* El cliente se ha borrado correctamente *" << endl;
            }
            else {
                cout << "* No se pudo eliminar el cliente *" << endl;
            }
        }
        else {
            cout << endl << "* Se cancelo el borrado del cliente *" << endl;
        }

    }
    else {
        cout << "* El cliente buscado no existe *" << endl;
    }
}

void ClienteManager::buscadorDeClientes()
{
    int cantReg = _archivo.contarClientes();
    if (cantReg == -1) {
        cout << endl << "* Error de Archivo *" << endl;
    }
    else {
        int pos;
        long long dni;
        dni = validarLong("Ingrese el DNI a buscar: ");
        cout << endl;
        
        pos = buscarCliente(dni);
        if (pos == -1) {
            cout << endl << "* No se Encontraron Clientes con el DNI buscado *" << endl;
        }
        if (pos >= 0) {
            Cliente reg = _archivo.leerCliente(pos);
            if (reg.getEliminado() == false) {
                mostrarCliente(reg);
                cout << endl;
            }
            else {
                cout << "* El Registro se Encuentra Eliminado *" << endl;
            }
        }
        cout << endl;
    
    
    }
}

bool ClienteManager::DniRepetido(long long idPersona) {
    ClienteArchivo ca;
    Cliente registro;
    int cantidad = ca.contarClientes();

    for (int i = 0; i < cantidad; i++) {
        registro = ca.leerCliente(i);

        if (registro.getDni() == idPersona) {
            return true;
        }
    }
    return false;
}