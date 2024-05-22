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
	
	//getters
	int getIdVenta();
	Fecha getFechaVenta();
	int getDniCliente();
	int getIdSucursal();
	int getNroLegajo();
	int getIdVehiculo();
	float getGastosAdm();
	float getTotalVenta();
	bool getEliminado();
	//Cliente getCliente(int dniCliente);
	//Sucursal getSucursal(int idSucursal);
	//Vendedor getVendedor(int nroLegajo);
	//Vehiculo getVehiculoComprado(int idVehiculo);
	
	//setters
	void setIdVenta(int id); // hay que hacer validacion para que sea unico
	void setFechaVenta(Fecha f);
	void setDniCliente(int dni); //7 digitos - Si el cliente existe debe encontrarlo, si no existe debera dejar registrarlo.
	void setIdSucursal(int id); //se tiene que hacer validacion para que sea una sucursal existente
	void setNroLegajo(int nro);//se tiene que hacer validacion para que sea un vendedor existente
	void setIdVehiculo(int id); //se tiene que hacer validacion para que sea un vehiculo existente
	void setGastosAdm(float gastos);
	void setTotalVentas(float total);
	void setEliminado(bool e);
	//void setCliente(Cliente c);
	//void setSucursal(Sucursal s);
	//void setVendedor(Vendedor v);
	//void setVehiculoComprado(Vehiculo v);




};

