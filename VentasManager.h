#pragma once
#include "VentasArchivo.h"

class VentasManager
{
private:
	VentasArchivo _archivo;
public:
	VentasManager();
	void Menu();
	Venta crearVenta();
	void mostrarVenta(Venta reg);
	void mostrarVentaEnLinea(Venta reg);
	void agregarVenta();
	void listarVentas();
	int buscarVenta(int idVenta);
	void editarVenta();
	void backupArchivo();
	void restaurarBackup();
	void borrarVenta();
	int validarCliente(int dni);
	void crearNuevoCliente();
	void mostrarClienteAsociado(int pos);
	int validarSucursal(int id);
	void mostrarSucursalAsociada(int pos);
	int validarVendedor(int nroLegajo);
	void mostrarVendedorAsociado(int pos);
	int validarVehiculo(int id);
	void mostrarVehiculoAsociado(int pos);
	float obtenerPrecioVehiculo(int pos);
	float calcularPrecioTotal(float gastos, float precio);
};

