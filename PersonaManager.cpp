#include <iostream>
#include <cstring>
#include <iomanip>

#include "PersonaManager.h"


void PersonaManager::CargarPersona() {
    long dni;
    std::string nombre, apellido;
    Fecha fechaN;

    std::cout << "DNI: ";
    std::cin >> dni;
    setDni(dni);
    std::cin.ignore();
    std::cout << "NOMBRE: ";
    std::getline(std::cin, nombre);
    setNombre(nombre);
    std::cout << "APELLIDO: ";
    std::getline(std::cin, apellido);
    setApellido(apellido);
    std::cout << "FECHA NACIMIENTO: " << std::endl;
    fechaN.Cargar();
    setFechaNacimiento(fechaN);
}

void PersonaManager::MostrarPersona() 
{
    std::cout << "DNI: " << getDni() << std::endl;
    std::cout << "NOMBRE: " << getNombre() << std::endl;
    std::cout << "APELLIDO: " << getApellido() << std::endl;
    std::cout << "FECHA NACIMIENTO: " << getFechaNacimiento().toString();
}

void PersonaManager::MostrarPersonaEnLinea() {

    std::cout << std::left;
    std::cout << std::setw(14) << getDni();
    std::cout << std::setw(20) << getNombre();
    std::cout << std::setw(20) << getApellido();
    std::cout << std::setw(23) << getFechaNacimiento().toString();

}

