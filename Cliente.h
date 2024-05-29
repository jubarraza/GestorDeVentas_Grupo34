#pragma once
#include "Persona.h"
#include "Direccion.h"
class Cliente :
    public Persona
{
private:
    char _email[50];
    int _telefono;
    Direccion _direccion;
    bool _eliminado;

public:
    Cliente();
    std::string getEmail();
    int getTelefono();
    Direccion getDireccion();
    bool getEliminado();

    void setEmail(std::string e);
    void setTelefono(int tel);
    void setDireccion(Direccion d);
    void setEliminado(bool e);

};

