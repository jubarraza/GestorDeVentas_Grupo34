#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Direccion.h"
#include "Sucursal.h"
#include "VentasManager.h"
#include "VendedorManager.h"
#include "ClienteManager.h"
#include "VehiculosManager.h"
#include "SucursalManager.h"
#include "Informes.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "Spanish_Spain.1252");
    VentasManager ventam;
    VendedorManager vendedorm;
    ClienteManager clientem;
    VehiculosManager vehiculom;
    SucursalManager sucursalm; 
    Informes inf;

    //inf.Menu();

    //vehiculom.Menu();
    //clientem.Menu();
    ventam.Menu();
    //vendedorm.Menu();
    //sucursalm.Menu();

    return 0;
}

