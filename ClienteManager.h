#pragma once
#include "ClienteArchivo.h"

class ClienteManager
{
private:
	ClienteArchivo _archivo;
public:
	ClienteManager();
	void Menu();
	Cliente crearCliente();
	void mostrarCliente(Cliente reg);
	void mostrarClienteEnLinea(Cliente reg);
	void agregarCliente();
	void listarClientes();
	int buscarCliente(int dni);
	void editarCliente();
	void backupArchivo();
	void restaurarBackup();
	void borrarCliente();
};

