#pragma once
#include "Direccion.h"
class Sucursal
{
private:
    int _idSucursal;
    char _nombre[40];
    Direccion _direccion;
    int _telefono;
    bool _estado;
public:
    Sucursal();
    Sucursal(int idSucursal, std::string nombre, Direccion direccion, int telefono, bool estado);
    int getIdSucursal();
    std::string getNombre();
    Direccion getDireccion();
    int getTelefono();
    bool getEstado();
    void setIdSucursal(int s);
    void setNombre(std::string n);
    void setDireccion(Direccion d);
    void setTelefono(int t);
    void setEstado(bool e);
    void Mostrar();
    void Cargar();
};

