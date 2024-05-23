#pragma once
#include "Fecha.h"
#include <string>
class Persona
{
private:
        int _dni;
        char _nombre[25];
        char _apellido[25];
        Fecha _fechaNacimiento;
public:
        Persona();
        Persona(int dni, std::string nombre, std::string apellido, Fecha fechaNacimiento);

        int getDni();
        std::string getNombre();
        std::string getApellido();
        std::string getApellidoNombre();
        Fecha getFechaNacimiento();

        void setDni(int dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setFechaNacimiento(Fecha fechaNacimiento);

        void Cargar();
        void Mostrar();

};

