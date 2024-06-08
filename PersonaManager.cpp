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
    std::cin.ignore();
    _persona.setDni(dni);
    std::cin.ignore();
    std::cout << "NOMBRE: ";
    std::getline(std::cin, nombre);
    _persona.setNombre(nombre);
    std::cout << "APELLIDO: ";
    std::getline(std::cin, apellido);
    _persona.setApellido(apellido);
    std::cout << "FECHA NACIMIENTO: " << std::endl;
    fechaN.Cargar();
    _persona.setFechaNacimiento(fechaN);
}

void PersonaManager::MostrarPersona() {

    std::cout << std::left;
    std::cout << std::setw(10) << _persona.getDni();
    std::cout << std::setw(12) << _persona.getNombre();
    std::cout << std::setw(12) << _persona.getApellido();
    std::cout << std::setw(20) << _persona.getFechaNacimiento().toString();

}
