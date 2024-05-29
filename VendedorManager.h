#pragma once
#include "VendedorArchivo.h"

class VendedorManager {
private:
    VendedorArchivo _archivo;

public:
    VendedorManager();
    Vendedor CrearVendedor();
    void MostrarVendedor(Vendedor reg);
    void AgregarVendedor();
    void ListarVendedor();
    void EliminarVendedor();
    //falta editarVendedor si es que la desarrollamos.

    void Menu();
};
