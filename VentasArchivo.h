#pragma once
#include <string>
#include "Venta.h"
class VentasArchivo
{
private:
	char _nombreArchivo[40];
public:
	VentasArchivo();
	VentasArchivo(const std::string n);
	Venta leerVenta(int pos);
	int contarVentas();
	bool guardarVenta(Venta reg);
	bool backupArchivo();
	int leerUltimoId();



};

