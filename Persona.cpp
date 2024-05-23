#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Persona.h"

//Constructores

Persona::Persona() {
    _dni = 0;
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _fechaNacimiento = Fecha();
}

Persona::Persona(int dni, std::string nombre, std::string apellido, Fecha fechaNacimiento) {
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
}

//Getters

int Persona::getDni() {
    return _dni;
}

std::string Persona::getNombre() {
    return _nombre;
}

std::string Persona::getApellido() {
    return _apellido;
}

std::string Persona::getApellidoNombre() {
    return strcat(_apellido, _nombre);
}

Fecha Persona::getFechaNacimiento() {
    return _fechaNacimiento;
}

//Setters

void Persona::setDni(int dni) {
    _dni = dni;
}

void Persona::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Persona::setApellido(std::string apellido) {
    strcpy(_apellido, apellido.c_str());
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento) {
    _fechaNacimiento = fechaNacimiento;
}

void Persona::Cargar() {
    std::cout << "DNI: ";
    std::cin >> _dni;
    std::cin.ignore();
    std::cout << "NOMBRE: ";
    std::cin.getline(_nombre, 24);
    std::cout << "APELLIDO: ";
    std::cin.getline(_apellido, 24);
    std::cout << "FECHA NACIMIENTO: " << std::endl;
    _fechaNacimiento.Cargar();
}

void Persona::Mostrar() {
    std::cout << "DNI: " << _dni << std::endl;
    std::cout << "NOMBRE: " << _nombre << std::endl;
    std::cout << "APELLIDO: " << _apellido << std::endl;
    std::cout << "FECHA NACIMIENTO: ";
    std::cout << _fechaNacimiento.toString() << std::endl;
}
