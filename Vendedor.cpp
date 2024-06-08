#include <iostream>
#include "Vendedor.h"

//Constructores

Vendedor::Vendedor() {
    _nroLegajo = 0;
    _fechaIngreso = Fecha();
    _antiguedad = 0;
    _eliminado = false;
}

Vendedor::Vendedor(int nroLegajo, Fecha fechaIngreso, int antiguedad, bool eliminado) {
    setNroLegajo(nroLegajo);
    setFechaIngreso(fechaIngreso);
    setAntiguedad(antiguedad);
    eliminado = eliminado;
}

//Getters

int Vendedor::getNroLegajo() {
    return _nroLegajo;
}

Fecha Vendedor::getFechaIngreso() {
    return _fechaIngreso;
}

int Vendedor::getAntiguedad() {
    return _antiguedad;
}

bool Vendedor::getEliminado() {
    return _eliminado;
}

//Setters

void Vendedor::setNroLegajo(int nroLegajo) {
    _nroLegajo = nroLegajo;
}

void Vendedor::setFechaIngreso(Fecha fechaIngreso) {
    _fechaIngreso = fechaIngreso;
}

void Vendedor::setAntiguedad(int antiguedad) {
    
    _antiguedad = antiguedad;
}

int Vendedor::calcularAntiguedad()
{
    int antiguedad = _fechaIngreso.obtenerAnioactual() - _fechaIngreso.getAnio();

    return antiguedad;
}

void Vendedor::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}
