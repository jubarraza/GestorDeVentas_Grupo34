#pragma once
#include "VehiculosArchivo.h"

class VehiculosManager {
private:
    VehiculosArchivo _vehiculosArchivo;
public:
    VehiculosManager(VehiculosArchivo archivo);
    void Menu();
    Vehiculo cargarVehiculo();
    void agregarVehiculo();
    void mostrarVehiculo(Vehiculo reg);
    void listarVehiculos();
    void editarVehiculo();
    void eliminarVehiculo();
    void resturarVehiculo();
    void realizarBackup();
    void restaurarBackup();
};