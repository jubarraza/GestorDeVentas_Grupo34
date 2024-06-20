#pragma once
#include "VendedorArchivo.h"

class VendedorManager {
private:
    VendedorArchivo _archivo;
public:
    VendedorManager();

    Vendedor CrearVendedor();
    void MostrarVendedor(Vendedor vendedor);
    void AgregarVendedor();
    void ListarVendedor();
    void BuscarVendedor();
    void EditarVendedor();
    void EliminarVendedor();
    void realizarBackupVendedores();
    void restaurarBackupVendedores();

    void Menu();
    bool LegajoRepetido(int idLegajo);
    bool DniRepetido(long long idPersona);

    bool creciente(int num, int num2);
    bool decreciente(int num, int num2);
    void OrdenarPorAntiguedad(Vendedor* obj, int cantidad, bool criterio(int, int));
    void ListarAntiguedad();
    bool creciente(std::string n, std::string m);
    bool decreciente(std::string n, std::string m);
    void OrdenarPorApellido(Vendedor* obj, int cantidad, bool criterio(std::string, std::string));
    void ListarApellido();
};
