#pragma once
#include "Cliente.h" 
#include <string> 

class ClienteArchivo
{
private:
	char _nombreArchivo[40];
public:
	ClienteArchivo(std::string n);
	Cliente leerCliente(int pos);
	int contarClientes();
	bool guardarCliente(Cliente reg);
	bool sobreescribirCliente(Cliente reg, int pos);
};

