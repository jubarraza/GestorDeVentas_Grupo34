#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include "SucursalArchivo.h"
using namespace std;

SucursalArchivo::SucursalArchivo()
{
    strcpy(_nombreArchivo, "Sucursales.dat");
}


SucursalArchivo::SucursalArchivo(std::string n = "Sucursales.dat")
{
    if (n.size() <= 40)
    {
        strcpy(_nombreArchivo, n.c_str());
    }
    else
    {
        cout << "Nombre de Sucursal NO Valido" << endl;
    }

}

Sucursal SucursalArchivo::leerRegistro(int pos) 
{
    Sucursal reg;
    FILE* p;

    p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return reg;
    }
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

bool SucursalArchivo::sobreescribirRegistro(Sucursal reg, int pos)
{
    FILE* p; 
    p = fopen(_nombreArchivo, "rb+"); 
    if (p == NULL)return false;
    fseek(p, sizeof reg * pos, 0); 
    bool modifico = fwrite(&reg, sizeof(Sucursal), 1, p); 
    fclose(p); 
    return modifico; 
}

int SucursalArchivo::contarRegistro()
{
    FILE* p;

    p = fopen(_nombreArchivo, "rb");
    if (p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p) / sizeof(Sucursal);
    fclose(p);
    return tam;
}

bool SucursalArchivo::guardarRegistro(Sucursal reg)
{
    FILE* p;
    p = fopen(_nombreArchivo, "ab");
    if (p == nullptr)
    {
        return false;
    }
    bool resultado = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return resultado;
}
