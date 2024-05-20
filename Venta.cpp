#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Venta.h"
using namespace std;

Venta::Venta()
{
    _idVenta = 0;
    _fechaVenta = Fecha(0,0,0);
    _dniCliente = 0;
    _idSucursal = 0;
    _nroLegajo = 0;
    _idVehiculo = 0;
    _gastosAdm = 0;
    _totalVenta = 0;
    _eliminado = 0;
}

Venta::Venta(int idVenta, Fecha fechaVenta, int dni, int idSucursal, int nroLegajo, int idVehiculo, float gastos, float total, bool eliminado)
{
    _idVenta = idVenta;
    _fechaVenta = fechaVenta;
    _dniCliente = dni;
    _idSucursal = idSucursal;
    _nroLegajo = nroLegajo;
    _idVehiculo = idVehiculo;
    _gastosAdm = gastos;
    _totalVenta = total;
    _eliminado = eliminado;

}

int Venta::getIdVenta()
{
    return _idVenta;
}

Fecha Venta::getFechaVenta()
{
    return _fechaVenta;
}

int Venta::getDniCliente()
{
    return _dniCliente;
}

int Venta::getIdSucursal()
{
    return _idSucursal;
}

int Venta::getNroLegajo()
{
    return _nroLegajo;
}

int Venta::getIdVehiculo()
{
    return _idVehiculo;
}

float Venta::getGastosAdm()
{
    return _gastosAdm;
}

float Venta::getTotalVenta()
{
    return _totalVenta;
}

bool Venta::getEliminado()
{
    return _eliminado;
}

void Venta::setIdVenta(int id)
{
    if (id > 0) {
        _idVenta = id; 
    }
    else {
        cout << "Id de Venta incorrecto. Intente nuevamente:" << endl;
        cin >> id;
        this->setIdVenta(id);
    }
}

void Venta::setFechaVenta(Fecha f)
{
    _fechaVenta = f;
}

void Venta::setGastosAdm(float gastos)
{
    _gastosAdm = gastos;
}

void Venta::setTotalVentas(float total)
{
    _totalVenta = total;
}

void Venta::setEliminado(bool e)
{
    _eliminado = e;
}
