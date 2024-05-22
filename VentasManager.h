#pragma once
#include "VentasArchivo.h"

class VentasManager
{
private:
	VentasArchivo _archivo;
public:
	VentasManager(VentasArchivo archivo);
	void menu();
	Venta crearVenta();
	void mostrarVenta(Venta reg);
	void agregarVenta();
	void listarVentas();
	int buscarVenta(int idVenta);
	void editarVenta();
	void backupArchivo();
	void restaurarBackup();
	void borrarVenta();
};

