#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "VentasArchivo.h"
using namespace std;

VentasArchivo::VentasArchivo()
{
    strcpy(_nombreArchivo, "Ventas.dat");
}

VentasArchivo::VentasArchivo(const std::string n)
{
    if (n.size() <= 40) {
        strcpy(_nombreArchivo, n.c_str());
    }
    else {
        cout << "Nombre NO Valido" << endl;
    }

}

Venta VentasArchivo::leerVenta(int pos)
{
    Venta reg;
    FILE* p;

    p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return reg;

    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
 
}

int VentasArchivo::contarVentas()
{
    FILE* p;
    p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;

    fseek(p, 0, 2);
    int tam = ftell(p) / sizeof(Venta);
    fclose(p);
    return tam;
}

bool VentasArchivo::guardarVenta(Venta reg)
{
    FILE* p;
    p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;

    bool result = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return result;
}

bool VentasArchivo::backupArchivo()
{
    return false;
}

int VentasArchivo::leerUltimoId()
{
    int cantidad = contarVentas();
    int ultimoId = 0;
    Venta reg;

    reg = leerVenta(cantidad-1);
    ultimoId = reg.getIdVenta();
    
    return ultimoId;
}


