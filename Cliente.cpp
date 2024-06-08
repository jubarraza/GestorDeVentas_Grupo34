#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() : _direccion()
{
    setNombre("NN");
    setApellido("NN");
    setDni(1111111);
    strcpy(_email ,"nn");
    _telefono = 1;
    _eliminado = false;

}

string Cliente::getEmail()
{
	return _email;
}

int Cliente::getTelefono()
{
	return _telefono;
}

Direccion Cliente::getDireccion()
{
	return _direccion;
}

bool Cliente::getEliminado()
{
    return _eliminado;
}

void Cliente::setEmail(string e)
{
    if (e.size() < 50) {
	    strcpy(_email, e.c_str());
    }
    else {
        cout << "Email excede limite de caracteres (50). Intente nuevamente:" << endl;
        getline(cin, e); 
        this->setEmail(e);
    }
}

void Cliente::setTelefono(int tel)
{
    _telefono = tel;
}

void Cliente::setDireccion(Direccion d)
{
    _direccion = d;
}

void Cliente::setEliminado(bool e)
{
    _eliminado = e;
}

