#pragma once
#include "Fecha.h"
class Venta
{
private:
	int _idVenta;
	Fecha _fechaVenta;
	int _dniCliente;
	int _idSucursal;
	int _nroLegajo;
	int _idVehiculo;
	float _gastosAdm;
	float _totalVenta;
	bool _eliminado;
public:
	Venta();
	Venta(int idVenta, Fecha fechaVenta, int dni, int idSucursal, int nroLegajo, int idVehiculo, float gastos, float total, bool eliminado);
	int getIdVenta();
	Fecha getFechaVenta();
	int getDniCliente();
	//Cliente getCliente(int dniCliente);
	int getIdSucursal();
	//Sucursal getSucursal(int idSucursal);
	int getNroLegajo();
	//Vendedor getVendedor(int nroLegajo);
	int getIdVehiculo();
	//Vehiculo getVehiculoComprado(int idVehiculo);
	float getGastosAdm();
	float getTotalVenta();
	bool getEliminado();
	void setIdVenta(int id);
	void setFechaVenta(Fecha f);
	//void setCliente(Cliente c);
	//void setSucursal(Sucursal s);
	//void setVendedor(Vendedor v);
	//void setVehiculoComprado(Vehiculo v);
	void setGastosAdm(float gastos);
	void setTotalVentas(float total);
	void setEliminado(bool e);




};

