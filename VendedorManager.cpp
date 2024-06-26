#include <iostream>
#include <cstring>
#include <iomanip>

#include "VendedorManager.h"
#include "FuncionesGenerales.h"


VendedorManager::VendedorManager(): _archivo("Vendedores.dat"){

}

void VendedorManager::PlanillaVendedor(){
    std::cout<<std::left;
    std::cout<<std::setw(14)<<"DNI ";
    std::cout<<std::setw(20)<< "NOMBRE";
    std::cout<<std::setw(20)<<"APELLIDO ";
    std::cout<<std::setw(23)<<"FECHA NACIMIENTO ";
    std::cout<<std::setw(10)<<"LEGAJO ";
    std::cout<<std::setw(20)<<"FECHA INGRESO ";
    std::cout<<std::setw(10)<<"ANTIGUEDAD ";
    std::cout<<std::endl;
}

Vendedor VendedorManager::CrearVendedor(){
    int numLegajo, anioAntiguedad;
    Fecha fechaI;
    Vendedor vendedor;
    int opc;

    std::cout<<std::setw(60)<<"--- AGREGAR VENDEDOR ---"<<std::endl;
    std::cout<<std::endl;

    regreso:
    vendedor.CargarPersona();
    bool resultado = DniRepetido(vendedor.getDni());
    if (resultado) {
        opc = validarInt("Vendedor ya existente.Desea cargar un nuevo vendedor? (1)Si - (2)No: ");

        switch (opc)
        {
        case 1:
            system("cls");
            goto regreso;
            break;
        case 2:
            Menu();
            break;

        default:
            break;
        }

    }

    numLegajo = validarInt("NUMERO DE LEGAJO: ");
    vendedor.setNroLegajo(numLegajo);
    std::cout<<"FECHA INGRESO: "<<std::endl;
    fechaI.Cargar();
    vendedor.setFechaIngreso(fechaI);
    std::cout<<"ANTIGUEDAD: ";
    anioAntiguedad=vendedor.calcularAntiguedad();
    std::cout << anioAntiguedad << " años" << std::endl;
    vendedor.setAntiguedad(anioAntiguedad);
    vendedor.setEliminado(false);
    std::cout<<std::endl;

    return vendedor;
}

void VendedorManager::MostrarVendedor(Vendedor vendedor){

    vendedor.MostrarPersonaEnLinea();

    std::cout<<std::left;
    std::cout<<std::setw(10)<<vendedor.getNroLegajo();
    std::cout<<std::setw(20)<<vendedor.getFechaIngreso().toString();
    std::cout << std::setw(0) << vendedor.getAntiguedad() << " años"; 
}

void VendedorManager::AgregarVendedor(){
    if(_archivo.GuardarRegistro(CrearVendedor())){
        std::cout<<"El vendedor se guardo correctamente!!!"<<std::endl;
    }else{
        std::cout<<"No se pudo guardar el vendedor!!!"<<std::endl;
    }
}

void VendedorManager::ListarVendedor(){

    std::cout<<std::setw(60)<<"--- LISTAR TODOS LOS VENDEDORES ---"<<std::endl;
    std::cout<<std::endl;

    PlanillaVendedor();

    int cantidad=_archivo.ContarRegistro();
    Vendedor reg;

    for(int i = 0; i < cantidad; i++){
        reg=_archivo.leerRegistro(i);

        if(reg.getEliminado()==false){
            MostrarVendedor(reg);
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}

void VendedorManager::BuscarVendedor(){
    int numLegajo, indice;
    Vendedor vendedor;
    std::cout<<std::setw(60)<<"--- BUSCAR VENDEDOR ---"<<std::endl;
    std::cout<<std::endl;

    numLegajo = validarInt("Ingrese el numero de legajo del vendedor que desea buscar: ");
    std::cout<<std::endl;
    system("cls");

    indice=_archivo.BuscarId(numLegajo);

    if(indice != -1){
        vendedor=_archivo.leerRegistro(indice);

        std::cout<<"LEGAJO: "<<vendedor.getNroLegajo();
        std::cout<<std::endl<<std::endl;

        PlanillaVendedor();

        MostrarVendedor(vendedor);
    }else{
        std::cout<<"No se encuentra ningun vendedor con ese numero de legajo!!!"<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

void VendedorManager::EditarVendedor(){
    int legajo;
    int opcion;
    std::cout<<std::setw(60)<<"--- EDITAR VENDEDOR ---"<<std::endl;
    std::cout<<std::endl;

    legajo = validarInt("Ingrese Legajo del Vendedor a editar: ");
    std::cout << std::endl;
    system("cls");

    int indice = _archivo.BuscarId(legajo);

    Vendedor vendedor;
    vendedor = _archivo.leerRegistro(indice);

    if(indice != -1){
        vendedor=_archivo.leerRegistro(indice);

        PlanillaVendedor();
        MostrarVendedor(vendedor);

        std::cout << std::endl<<std::endl;
        std::cout << "¿Desea editar la Fecha de Ingreso? (1)Si - (2)No: " << std::endl;
        opcion = validarInt("Opcion: ");
        system("cls");

        if(opcion == 1){
            std::cout<<std::endl;
            Fecha f;
            std::cout << "Ingrese nueva fecha: "<<std::endl;
            f.Cargar();
            system("cls");
            vendedor.setFechaIngreso(f);
            int newA=vendedor.calcularAntiguedad();
            vendedor.setAntiguedad(newA);

            bool result = _archivo.Sobreescribir(indice, vendedor);

            if (result == true) {
                std::cout<<"Se edito correctamente el vendedor."<<std::endl;
            }

        }else{
            std::cout<<"Cancelo el modificar del vendedor."<<std::endl;
        }
    }else{
        std::cout<<"Numero de Legajo inexistente."<<std::endl;
    }

}

void VendedorManager::EliminarVendedor(){
    int numLegajo, indice;
    Vendedor vendedor;
    int opcion;

    std::cout<<std::setw(60)<<"--- ELIMINAR VENDEDOR ---"<<std::endl;
    std::cout<<std::endl;

    numLegajo = validarInt("Ingrese el numero de Legajo: ");

    indice=_archivo.BuscarId(numLegajo);

    if(indice != -1){
        vendedor=_archivo.leerRegistro(indice);

        std::cout<<std::endl;
        PlanillaVendedor();
        MostrarVendedor(vendedor);
        std::cout<<std::endl<<std::endl;

        std::cout<< "Desea eliminar este vendedor? (1)Si - (2)No: " << std::endl;
        opcion = validarInt("Opcion: ");
        system("cls");

        if(opcion == 1){ 
            vendedor.setEliminado(true);

            if(_archivo.Sobreescribir(indice, vendedor)){
                std::cout<<"Se elimino con exito."<<std::endl;
            }else{
                std::cout<<"No se pudo eliminar."<<std::endl;
            }
        }else{
            std::cout<<"Cancelo el eliminado del vendedor."<<std::endl;
        }
    }else{
        std::cout<<"Numero de Legajo inexistente."<<std::endl;
    }
}

void VendedorManager::realizarBackupVendedores() {
    int opc;
    std::cout<<std::setw(60)<<"--- REALIZAR BACKUP ---"<<std::endl;
    std::cout<<std::endl;

    std::cout << "- Desea Relizar Backup del Archivo Vendedores?" << std::endl;
    std::cout << " (1)SI (2)NO " << std::endl;
    opc = validarInt("Selecione una Opcion: ");
    system("cls");
    
    switch (opc) {
    case 1:
        system("copy Vendedores.dat Vendedores.bkp");
        std::cout << "* Backup Realizado con Exito! *" << std::endl;
        break;
    case 2:
        return;
    default:
        std::cout << std::endl << "* Opcion Incorrecta! *" << std::endl;
        return;
    }
}

void VendedorManager::restaurarBackupVendedores() {
    int opc;
    std::cout<<std::setw(60)<<"--- RESTAURAR BACKUP ---"<<std::endl;
    std::cout<<std::endl;

    std::cout << "- Desea Restaurar el Archivo de Vendedores?" << std::endl;
    std::cout << " (1)SI (2)NO " << std::endl;
    opc = validarInt("Selecione una Opcion: ");
    system("cls");

    switch (opc) {
    case 1:
        system("copy Vendedores.bkp Vendedores.dat");
        std::cout << "* Restauracion Realizado con Exito! *" << std::endl;
        break;
    case 2:
        break;
    default:
        std::cout << std::endl << "* Opcion Incorrecta! *" << std::endl;
        return;
    }
}

void VendedorManager::Menu(){
    int option;
    system("cls");
    while(true)
    {
        system("cls");

        std::cout<<"------ MENU VENDEDOR ------- "<<std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout<<"1- AGREGAR VENDEDOR"<<std::endl;
        std::cout<<"2- LISTAR TODOS LOS VENDEDORES"<<std::endl;
        std::cout<<"3- BUSCAR VENDEDOR"<<std::endl;
        std::cout<<"4- EDITAR VENDEDOR"<<std::endl;
        std::cout<<"5- ELIMINAR VENDEDOR"<<std::endl;
        std::cout<<"6- BACKUP"<<std::endl;
        std::cout<<"0- REGRESAR AL MENU ANTERIOR"<<std::endl;
        std::cout<<"-----------------------------"<<std::endl;
        option = validarInt("Opcion: ");
        system("cls");

        switch(option){
            case 1:
                AgregarVendedor();
                system("pause");
                break;
            case 2:
                int  opc1;
                while (true) {

                    system("cls");
                    std::cout << "------ MENU LISTAR VENDEDORES ------- " << std::endl;
                    std::cout << "1- LISTAR POR ANTIGUEDAD" << std::endl;
                    std::cout << "2- LISTAR POR APELLIDO" << std::endl;
                    std::cout << "0- VOLVER AL MENU PRINCIPAL" << std::endl;
                    opc1 = validarInt("Opcion: ");
                    system("cls");

                    switch (opc1) {
                    case 1:
                        ListarAntiguedad();
                        system("pause");
                        break;
                    case 2:
                        ListarApellido();
                        system("pause");
                        break;
                    case 0:
                        break;
                    }
                    if (opc1 == 0) {// Salir del bucle del submenú si se elige la opción 3
                        break;
                    }
                }
                break;
            case 3:
                BuscarVendedor();
                system("pause");
                break;
            case 4:
                EditarVendedor();
                system("pause");
                break;
            case 5:
                EliminarVendedor();
                system("pause");
                break;
            case 6:
                int  opc2;
                while(true){

                    system("cls");
                    std::cout<<"------ MENU BACKUP ------- "<<std::endl;
                    std::cout<<"1- REALIZAR BACKUP VENDEDORES"<<std::endl;
                    std::cout<<"2- RESTAURAR BUCKUP VENDEDORES"<<std::endl;
                    std::cout<<"0- VOLVER AL MENU PRINCIPAL"<<std::endl;
                    opc2 = validarInt("Opcion: ");
                    system("cls");

                    switch(opc2){
                        case 1:
                            realizarBackupVendedores();
                            system("pause");
                            break;
                        case 2:
                            restaurarBackupVendedores();
                            system("pause");
                            break;
                        case 0:
                            break;
                    }
                    if (opc2 == 0) {// Salir del bucle del submenú si se elige la opción 3
                        break;
                    }
                }
                break;
            case 0:
            return;
        }
    }

}

bool VendedorManager::LegajoRepetido(int idLegajo) {
    Vendedor registro;
    int cantidad = _archivo.ContarRegistro();

    for (int i = 0; i < cantidad; i++) {
        registro = _archivo.leerRegistro(i);

        if (registro.getNroLegajo() == idLegajo) {
            return true;
        }
    }
    return false;
}

bool VendedorManager::DniRepetido(long long idPersona) {
    VendedorArchivo va;
    Vendedor registro;
    int cantidad = va.ContarRegistro();

    for (int i = 0; i < cantidad; i++) {
        registro = va.leerRegistro(i);

        if (registro.getDni() == idPersona) {
            return true;
        }
    }
    return false;
}

void VendedorManager::OrdenarPorAntiguedad(Vendedor* obj, int cantidad, bool criterio(int, int)) {
    Vendedor aux;

    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (criterio(obj[j].getAntiguedad(), obj[i].getAntiguedad())) {
                aux = obj[j];
                obj[j] = obj[i];
                obj[i] = aux;
            }
        }
    }
}

void VendedorManager::ListarAntiguedad() {
    int cantidad = _archivo.ContarRegistro();
    Vendedor* vec, reg;

    vec = new Vendedor[cantidad];
    if (vec == nullptr) {
        std::cout << "No hay memoria.";
    }

    if (cantidad == 0) {
        std::cout << "No hay Vendedores para mostrar." << std::endl;
    }
    else {
         MostrarPantalla(); 
        for (int i = 0; i < cantidad; i++) {
            reg = _archivo.leerRegistro(i);
            vec[i] = reg;
        }

        OrdenarPorAntiguedad(vec, cantidad, creciente);  

        for (int i = 0; i < cantidad; i++) {
            if (vec[i].getEliminado() == false) {
                MostrarVendedor(vec[i]);
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    delete[]vec;
}

void VendedorManager::OrdenarPorApellido(Vendedor* obj, int cantidad, bool criterio(std::string, std::string)) {
    Vendedor aux;

    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (criterio(obj[j].getApellido(), obj[i].getApellido())) {
                aux = obj[j];
                obj[j] = obj[i];
                obj[i] = aux;
            }
        }
    }
}

void VendedorManager::ListarApellido() {
    int cantidad = _archivo.ContarRegistro();
    Vendedor* vec, reg;

    vec = new Vendedor[cantidad];
    if (vec == nullptr) {
        std::cout << "No hay memoria.";
    }

    if (cantidad == 0) {
        std::cout << "No hay Vendedores para mostrar." << std::endl;
    }
    else {
        MostrarPantalla();
        for (int i = 0; i < cantidad; i++) {
            reg = _archivo.leerRegistro(i);
            vec[i] = reg;
        }

        OrdenarPorApellido(vec, cantidad, creciente);

        for (int i = 0; i < cantidad; i++) {
            if (vec[i].getEliminado() == false) {
                MostrarVendedor(vec[i]);
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    delete[]vec;
}

void VendedorManager::MostrarPantalla() {
    std::cout << std::left;
    std::cout << std::setw(14) << "DNI ";
    std::cout << std::setw(20) << "NOMBRE";
    std::cout << std::setw(20) << "APELLIDO ";
    std::cout << std::setw(23) << "FECHA NACIMIENTO ";
    std::cout << std::setw(10) << "LEGAJO ";
    std::cout << std::setw(20) << "FECHA INGRESO ";
    std::cout << std::setw(10) << "ANTIGUEDAD ";
    std::cout << std::endl;
}