#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "VentasManager.h"
using namespace std;



int main()
{
    VentasManager vm(VentasArchivo("Ventas.dat"));

    vm.menu();

    return 0;
}

