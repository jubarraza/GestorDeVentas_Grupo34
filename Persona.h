#pragma once
#include "Fecha.h"
#include <string>
class Persona
{
protected:
        long _dni;
        char _nombre[40];
        char _apellido[40];
        Fecha _fechaNacimiento;
public:
        Persona();
        Persona(long dni, std::string nombre, std::string apellido, Fecha fechaNacimiento);

        long getDni();
        std::string getNombre();
        std::string getApellido();
        std::string getApellidoNombre();
        Fecha getFechaNacimiento();

        void setDni(long dni); //tiene validacion para que el nro siempre sea de almenos 7 digitos
        void setNombre(std::string nombre); //tiene validacion de numero de caracteres 
        void setApellido(std::string apellido); //tiene validacion de numero de caracteres 
        void setFechaNacimiento(Fecha fechaNacimiento);

};

