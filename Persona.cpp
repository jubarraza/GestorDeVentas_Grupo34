#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

//Constructores

Persona::Persona() : _fechaNacimiento()
{
    setDni(1000000);
    strcpy(_nombre, "NN");
    strcpy(_apellido, "NN");
}

Persona::Persona(long long dni, std::string nombre, std::string apellido, Fecha fechaNacimiento) {
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
}

//Getters

long long Persona::getDni() {
    return _dni;
}

std::string Persona::getNombre() {
    return _nombre;
}

std::string Persona::getApellido() {
    return _apellido;
}

std::string Persona::getApellidoNombre() {

    string nombreCompleto;
    nombreCompleto = getApellido()+", " + getNombre();
    return nombreCompleto;
}

Fecha Persona::getFechaNacimiento() {
    return _fechaNacimiento;
}

//Setters

void Persona::setDni(long long dni) {
    
    while (!validar(dni)) {
        cin.clear();//limpia el estado de error
        cin.ignore(numeric_limits<long long>::max(), '\n');
        cout << "DNI no valido. Intente nuevamente: " << endl;
        cin >> dni;
    }

    _dni = dni;
    
}

void Persona::setNombre(std::string nombre) {
    if (nombre.size() <= 39) { 
        strcpy(_nombre, nombre.c_str()); 
    }
    else {
        cout << "Nombre no valido (hasta 40 caracteres). Intente nuevamente:" << endl;
        cin >> nombre; 
        this->setNombre(nombre); 
    }
}

void Persona::setApellido(std::string apellido) {
    if (apellido.size() <= 39) {
        strcpy(_apellido, apellido.c_str()); 
    }
    else {
        cout << "Apellido no valido (hasta 40 caracteres). Intente nuevamente:" << endl;
        cin >> apellido;
        this->setApellido(apellido); 
    }
    
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento) {
    _fechaNacimiento = fechaNacimiento;
}

int Persona::contarDigitos(long long num)
{
    int contador = 0;
    while (num > 0) {
        num /= 10;
        contador++;
    }
    return contador;
}

bool Persona::validar(long long  dni) {
    int numDigitos = contarDigitos(dni);
    int  minimoDigito = 7;
    int maximoDigito = 10;

    if (numDigitos >= minimoDigito && numDigitos <= maximoDigito) {
        return true;
    }
    return false;
}