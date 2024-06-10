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
	void encabezadoListadoVentas();
	void listarVentas();
	int buscarVenta(int idVenta);
	void editarVenta();
	void backupArchivo();
	void restaurarBackup();
	void borrarVenta();
	
	int validarCliente(long dni);
	void crearNuevoCliente();
	void mostrarClienteAsociado(int pos);
	std::string mostrarNombreCliente(long dni);
	
	int validarSucursal(int id);
	void mostrarSucursalAsociada(int pos);
	std::string mostrarNombreSucursal(int id);
	
	int validarVendedor(int nroLegajo);
	void mostrarVendedorAsociado(int pos);
	std::string mostrarNombreVendedor(int nrolegajo);
	
	int validarVehiculo(int id);
	void mostrarVehiculoAsociado(int pos);
	std::string mostrarNombreVehiculo(int id);
	
	float obtenerPrecioVehiculo(int pos);
	float calcularPrecioTotal(float gastos, float precio);
	
	std::string formatearNumero(float numero);

	void buscadorDeVentas();
	void buscarVentaPorID();
	void buscarVentaPorFecha();


};


