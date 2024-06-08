#include <iostream>
#include <cstring>

#include "VendedorManager.h"

VendedorManager::VendedorManager() : _archivo("Vendedores.dat")
{
}

Vendedor VendedorManager::CrearVendedor() {
    int numLegajo;
    Fecha fechaI;
    Vendedor vendedor;

    vendedor.CargarPersona();
    std::cout << "NUMERO DE LEGAJO: ";
    std::cin >> numLegajo;
    vendedor.setNroLegajo(numLegajo);
    std::cout << "FECHA INGRESO: " << std::endl;
    fechaI.Cargar();
    vendedor.setFechaIngreso(fechaI);
    vendedor.setAntiguedad(vendedor.calcularAntiguedad());
    std::cout << "ANTIGUEDAD: " << vendedor.getAntiguedad();
    std::cout << std::endl;
    vendedor.setEliminado(false);

    return vendedor;
}

void VendedorManager::MostrarVendedor(Vendedor reg) {
    
    reg.MostrarPersona();
    std::cout << "NUMERO DE LEGAJO: " << reg.getNroLegajo() << std::endl;
    std::cout << "FECHA INGRESO: " << reg.getFechaIngreso().toString() << std::endl;
    std::cout << "ANTIGUEDAD: " << reg.getAntiguedad() << std::endl;
}

void VendedorManager::AgregarVendedor() {
    if (_archivo.GuardarRegistro(CrearVendedor())) {
        std::cout << "El vendedor se guardo correctamente." << std::endl;
    }
    else {
        std::cout << "No se pudo guardar el vendedor." << std::endl;
    }
}

void VendedorManager::ListarVendedor() {
    int cantidad = _archivo.ContarRegistro();
    Vendedor reg;

    for (int i = 0; i < cantidad; i++) {
        reg = _archivo.leerRegistro(i);

        if (reg.getEliminado() == false) {
            MostrarVendedor(reg);
            std::cout << std::endl;
        }
    }
}

void VendedorManager::EliminarVendedor() {
    int numLegajo, indice;
    Vendedor vendedor;
    char opc;

    std::cout << "Ingrese el numero de Legajo: ";
    std::cin >> numLegajo;

    indice = _archivo.BuscarId(numLegajo);

    if (indice != -1) {
        vendedor = _archivo.leerRegistro(indice);

        MostrarVendedor(vendedor);

        std::cout << "Desea eliminar este vendedor. Confirmar? S/N" << std::endl;
        std::cin >> opc;

        if (opc == 's' || opc == 'S') {
            vendedor.setEliminado(true);

            if (_archivo.Sobreescribir(indice, vendedor)) {
                std::cout << "Se elimino con exito." << std::endl;
            }
            else {
                std::cout << "No se pudo eliminar." << std::endl;
            }
        }
        else {
            std::cout << "Cancelo el eliminado del vendedor." << std::endl;
        }
    }
    else {
        std::cout << "Numero de Legajo inexistente.";
    }
}


void VendedorManager::Menu() {
    int option;
    system("cls");
    do
    {
        system("cls");

        std::cout << "------ MENU VENDEDOR ------- " << std::endl;
        std::cout << "1- AGREGAR VENDEDOR " << std::endl;
        std::cout << "2- LISTAR TODOS LOS VENDEDORES" << std::endl;
        std::cout << "3- MODIFICAR VENDEDOR" << std::endl;
        std::cout << "4- ELIMINAR VENDEDOR" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "0- SALIR" << std::endl;
        std::cout << "Opcion: " << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
            AgregarVendedor();
            system("pause");
            break;

        case 2:
            ListarVendedor();
            system("pause");
            break;

        case 3:

            system("pause");
            break;

        case 4:
            EliminarVendedor();
            system("pause");
            break;
        }
    } while (option != 0);

}
