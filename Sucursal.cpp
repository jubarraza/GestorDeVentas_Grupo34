#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Sucursal.h"
using namespace std;


Sucursal::Sucursal() :_direccion("Calle", 0, "Provincia", 0) {
    _idSucursal = 0;
    strcpy(_nombre,"Sucursal");
    _telefono = 0;
    _estado = 0;
}

Sucursal::Sucursal(int idSucursal, string nombre, Direccion direccion, int telefono, bool estado) {
    _idSucursal = idSucursal;
    strcpy(_nombre, nombre.c_str());
    _direccion = direccion;
    _telefono = telefono;
    _estado = estado;

}

int Sucursal::getIdSucursal() {
    return _idSucursal;
}

string Sucursal::getNombre() {
    return _nombre;
}

Direccion Sucursal::getDireccion() {
    return _direccion;
}

int Sucursal::getTelefono() {
    return _telefono;
}

bool Sucursal::getEstado() {
    return _estado;
}

void Sucursal::setIdSucursal(int s) {
    if (s > 0) {
       _idSucursal = s;
    }
    else {
        cout << "Id de Sucursal incorrecto. Intente nuevamente #:" << endl;
        cin >> s;
    }
}

void Sucursal::setNombre(string n) {
    strcpy(_nombre, n.c_str());
}

void Sucursal::setDireccion(Direccion d) {
    _direccion = d;
}

void Sucursal::setTelefono(int t) {
    _telefono = t;
}

void Sucursal::setEstado(bool e) {
    _estado = e;
}

void Sucursal::Mostrar()
{
    cout << "Id Sucursal #" << _idSucursal << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Dirección: ";
    _direccion.MostrarEnLinea();
    cout << endl;
    cout << "Telefono: " << _telefono << endl << endl;
}

void Sucursal::Cargar()
{
    int id, telefono;
    string nombre;
    Direccion d;

    cout << "Ingrese Id Sucursal: ";
    cin >> id;
    cin.ignore();
    setIdSucursal(id);
    cout << "Ingrese Nombre de Sucursal: ";
    getline(cin, nombre);
    setNombre(nombre);
    cout << "Ingrese Dirección: ";
    d.Cargar();
    setDireccion(d);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    setTelefono(telefono);
}
