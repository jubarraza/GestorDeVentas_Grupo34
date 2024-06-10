#pragma once
#include "SucursalArchivo.h"

class SucursalManager
{
private:
	SucursalArchivo _archivo;
public:
	SucursalManager();
	int buscarPosicion(int codBuscado);
	void agregarRegistro();
	void listarRegistros();
	void Menu();
	Sucursal crearRegistro();
	void mostrarRegistro(Sucursal reg);
	void editarRegistro();
	void bajaLogica();
	void backupArchivo();
	void restaurarBackup();
};
