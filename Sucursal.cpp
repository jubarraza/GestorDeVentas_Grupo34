#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Sucursal.h"
#include "SucursalManager.h"
using namespace std; 


Sucursal::Sucursal() :_direccion("Calle", 0, "Provincia", 0) {
    _idSucursal = 0;
    strcpy(_nombre, "Sucursal");
    strcpy(_telefono, "");
    _estado = 0; 
}

Sucursal::Sucursal(int idSucursal, string nombre, Direccion direccion, string telefono, bool estado) {
    _idSucursal = idSucursal;
    strcpy(_nombre, nombre.c_str());
    _direccion = direccion;
    strcpy(_telefono, telefono.c_str());
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

string Sucursal::getTelefono() {
    return _telefono;
}

bool Sucursal::getEstado() {
    return _estado;
}

void Sucursal::setIdSucursal(int s) {
    SucursalManager sm;
    while (!validar(s) || sm.validarIDUnico(s)) {
        cin.clear();//limpia el estado de error
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "ID no valido. Ingrese nuevo ID: ";
        cin >> s;
        cin.ignore();
    }
    _idSucursal = s;

}

void Sucursal::setNombre(string n) {
    if (n.size() <= 40) {
        strcpy(_nombre, n.c_str());
    }

}

void Sucursal::setDireccion(Direccion d) {
    _direccion = d;

}

void Sucursal::setTelefono(string t) {
    if (t.size() <= 15) {
        strcpy(_telefono, t.c_str());
    }
}

void Sucursal::setEstado(bool e) {
     _estado = e;
}

void Sucursal::Mostrar()
{
	cout << "Id Sucursal #" << _idSucursal << endl;
	cout << "Nombre: " << _nombre << endl;
	cout << "Direcci�n: ";
	_direccion.MostrarEnLinea();
	cout << endl;
	cout << "Telefono: " << _telefono << endl << endl;
}

void Sucursal::Cargar()
{
	int id;
	string nombre;
	string telefono;
	Direccion d;

	cout << "Ingrese Id Sucursal: ";
	cin >> id;
	cin.ignore();
	setIdSucursal(id);
	cout << "Ingrese Nombre de Sucursal: ";
	getline(cin, nombre);
	setNombre(nombre);
	cout << "Ingrese Direcci�n: ";
	d.Cargar();
	setDireccion(d);
	cout << "Ingrese Telefono: ";
	getline(cin, telefono);
	setTelefono(telefono);
}

int Sucursal::contarDigitos(int num) {
    int contador = 0;
    while (num > 0) {
        num /= 10;
        contador++;
    }
    return contador;
}

bool Sucursal::validar(int id) {
    int numDigitos = contarDigitos(id);
    int minimoDigito = 1;
    int maximoDigito = 6;

    if (numDigitos >= minimoDigito && numDigitos <= maximoDigito) {
        return true;
    }
    return false;
}