#pragma once

#include "Persona.h"

class Vendedor :public Persona {
private:
    int _nroLegajo;
    Fecha _fechaIngreso;
    int _antiguedad;
    bool _eliminado;
public:
    Vendedor();
    Vendedor(int nroLegajo, Fecha fechaIngreso, int antiguedad, bool eliminado);

    int getNroLegajo();
    Fecha getFechaIngreso();
    int getAntiguedad();
    bool getEliminado();

    void setNroLegajo(int nroLegajo);
    void setFechaIngreso(Fecha fechaIngreso);
    void setAntiguedad(int antiguedad); 
    int calcularAntiguedad(); //calcula segun el año de ingreso
    void setEliminado(bool eliminado);
};
