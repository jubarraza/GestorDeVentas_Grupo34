#include "Informes.h"
#include "VentasManager.h"
#include "VehiculosManager.h"
#include "SucursalManager.h"
#include "VendedorManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Informes::Menu()
{
    int opcion;
    do {
        system("cls");
        cout << "--- INFORMES ---" << endl;
        cout << "----------------------" << endl;
        cout << "1. Informe del Inventario " << endl;
        cout << "2. Informe de Recaudaci�n Anual " << endl;
        cout << "3. Informe Anual de Ventas por Vendedor " << endl;
        cout << "4. Informe Mensual de Ventas para todos los Vendedores " << endl;
        cout << "5. Informe Anual de Ventas por Sucursal " << endl;
        cout << "6. Informe Ventas en todas las Sucursales (mensual o anual) " << endl;
        cout << "7. Ranking Anual de Ventas por Modelo " << endl;

        cout << endl;
        cout << "0. Volver al menu principal " << endl;
        cout << "----------------------" << endl;
        cout << "OPCION: " << endl;
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            Inventario();
            system("pause");
            break;

        case 2:
            recaudacionAnual();
            system("pause");
            break;

        case 3:
            ventasXVendedorAnual();
            system("pause");
            break;

        case 4:
            ventasXVendedoresMensual();
            system("pause");
            break;

        case 5:
            ventasXSucursalAnual();
            system("pause");
            break;

        case 6:
        {
            {
                int opc;
                cout << "** INFORME DE VENTAS EN TODAS LAS SUCURSALES ** " << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "Elija una opcion: " << endl;
                cout << "1. Mensual" << endl;
                cout << "2. Anual" << endl;
                cout << endl;
                cout << "Opcion: ";
                cin >> opc;
                cin.ignore();
                cout << endl;

                if (opc == 1) {
                    ventasTodasLasSucursalesMensual();
                }
                if (opc == 2) {
                    ventasTodasLasSucursalesAnual();
                }
                system("pause");
                break;
            }
        }
        case 7:
            rankingVentasXModelo();
            system("pause");
            break;

        case 0:

            break;
        }
    } while (opcion != 0);
}

//1
void Informes::Inventario()
{
    VehiculosArchivo archiV;
    Vehiculo regVeh;
    int cantReg, contDisp = 0, contAgo = 0;
    cantReg = archiV.contarRegistros();
    cout << left;
    cout << "--- Informe de Inventario ---" << endl;
    cout << "-------- Disponibles --------" << endl;
    cout << setw(9) << "Marca";
    cout << setw(15) << "Modelo";
    cout << setw(6) << "Stock";
    cout << endl;
    for (int i = 0; i < cantReg; i++) {
        regVeh = archiV.leerRegistro(i);
        if (regVeh.getEstado() == true) {
            if (regVeh.getStock() != 0) {
                cout << setw(9) << regVeh.getMarca();
                cout << setw(15) << regVeh.getModelo();
                cout << setw(6) << regVeh.getStock();
                cout << endl;
                contDisp += regVeh.getStock();
            }
        }
    }
    cout << endl;
    cout << "--------- Agotados ----------" << endl;
    cout << setw(9) << "Marca";
    cout << setw(15) << "Modelo";
    cout << setw(6) << "Stock";
    cout << endl;
    for (int j = 0; j < cantReg; j++) {
        regVeh = archiV.leerRegistro(j);
        if (regVeh.getEstado() == true) {
            if (regVeh.getStock() == 0) {
                cout << setw(9) << regVeh.getMarca();
                cout << setw(15) << regVeh.getModelo();
                cout << setw(6) << regVeh.getStock();
                cout << endl;
                contAgo++;
            }
        }
    }
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "---------- Totales ----------" << endl;
    cout << "- Autos Disponibles:    " << contDisp << endl;
    cout << "- Autos Agotados:       " << contAgo << endl;
    cout << endl;

}

//2
void Informes::recaudacionAnual()
{
    VentasManager vm;
    VentasArchivo va;
    Fecha f;
    int i;
    double recaudacion[13] = {0};
    string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

    int anio;

	cout << "** INFORME DE RECAUDACION ANUAL ** " << endl;
    do {
        cout << "Ingrese a�o a revisar: ";
        cin >> anio;

        if (anio > f.obtenerAnioActual()) {
            cout << "A�o no valido." << endl << endl;
        }

    } while (anio > f.obtenerAnioActual());

	system("cls");

	int cantidad = va.contarVentas();
	for (i = 0; i < cantidad; i++) {
		Venta reg = va.leerVenta(i);
		if (reg.getFechaVenta().getAnio() == anio) {
			recaudacion[reg.getFechaVenta().getMes() - 1] += reg.getTotalVenta();
			recaudacion[12] += reg.getTotalVenta();
		}

	}

	cout << "** INFORME DE RECAUDACION ANUAL ** " << endl << endl;
	cout << "A�o: " << anio << endl << endl;

	cout << left;
	cout << setw(12) << "MES";
	cout << setw(20) << "RECAUDACION" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (i = 0; i < 12; i++) {

		cout << setw(12) << meses[i];
		cout << "$ " << setw(20) << vm.formatearNumero(recaudacion[i]);
		cout << endl;

	}
	cout << endl << endl;

	cout << "** Total Anual : $" << vm.formatearNumero(recaudacion[12]) << " **" << endl << endl;
	
}

//3
void Informes::ventasXVendedorAnual()
{
     int numLegajo, anio, id = 0;
    Vendedor vendedor;
    Venta venta;
    VendedorArchivo va;
    VentasArchivo vs;
    VentasManager vm;
    Fecha f;

    int cantidadVendedor = va.ContarRegistro();
    int cantidadVentas = vs.contarVentas();

    string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    double recaudacion[13] = {};

    cout << "Ingrese el numero de legajo del vendedor: ";
    cin >> numLegajo;
    do {
        cout << "Ingrese el a�o a revisar: ";
        cin >> anio;

        if (anio > f.obtenerAnioActual()) {
            cout << "A�o no valido." << endl << endl;
        }

    } while (anio > f.obtenerAnioActual());
    
    system("cls");

    for (int i = 0; i < cantidadVendedor; i++)
    {
        vendedor = va.leerRegistro(i);
        id = va.BuscarId(numLegajo);

    }

    if (id > -1)
    {
        for (int i = 0; i < cantidadVentas; i++)
        {
            //TODO consultar con Yami, me parece que la venta se tiene que leer antes del if y tambien se tiene que agregar un && venta.getNroLegajo() == numLegajo
             if (venta.getFechaVenta().getAnio() == anio) {
                venta = vs.leerVenta(i);

                recaudacion[venta.getFechaVenta().getMes() - 1] += venta.getTotalVenta();
                recaudacion[12] += venta.getTotalVenta();

             }
        }
        cout << "** INFORME ANUAL DE VENTAS POR VENDEDOR ** " << endl << endl;
        cout << "Vendedor: " << vm.mostrarNombreVendedor(id) << endl;
        cout << "Nro Legajo: " << numLegajo << endl;
        cout << "A�o: " << anio << endl << endl;

        cout << left;
        cout << setw(12) << "MES";
        cout << setw(20) << "RECAUDACION" << endl;
        cout << "------------------------------------------------------------" << endl;

        for (int i = 0; i < 12; i++) {

            cout << setw(12) << meses[i];
            cout << "$ " << setw(20) << vm.formatearNumero(recaudacion[i]);
            cout << endl;

        }
        cout << endl << endl;

        cout << "** Total Anual : $" << vm.formatearNumero(recaudacion[12]) << " **" << endl << endl;

    }
    else {
            cout << "No se encontro el vendedor" << endl;
    }
}

//4
void Informes::ventasXVendedoresMensual()
{
}

//5
void Informes::ventasXSucursalAnual()
{
    VentasManager vm; 
    VentasArchivo va; 
    SucursalArchivo sa;
    SucursalManager sm;
    Sucursal s;
    int i, cant;
    double recaudacion[13] = { 0 };
    string meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    Fecha f;
    bool existeSucursal = false;

    int anio, id;

    cout << "** INFORME ANUAL DE VENTAS POR SUCURSAL ** " << endl;
    do {
        cout << "Ingrese a�o a revisar: ";
        cin >> anio;

        if (anio > f.obtenerAnioActual()) {
            cout << "A�o no valido." << endl << endl;
        }

    } while (anio > f.obtenerAnioActual());
    
    cout << endl << "Ingrese Id de Sucursal: ";
    cin >> id;

    cant = sa.contarRegistro();
    for (i = 0; i < cant; i++) {
        s = sa.leerRegistro(i);
        if (s.getIdSucursal() == id) {
            existeSucursal = true;
        }
    }

    if(existeSucursal == true){

		int cantidad = va.contarVentas();
		for (i = 0; i < cantidad; i++) {
			Venta reg = va.leerVenta(i);
			if (reg.getFechaVenta().getAnio() == anio && reg.getIdSucursal() == id) {
				recaudacion[reg.getFechaVenta().getMes() - 1] += reg.getTotalVenta();
				recaudacion[12] += reg.getTotalVenta();

			}

		}

		system("cls");

		cout << "** INFORME ANUAL DE VENTAS POR SUCURSAL ** " << endl << endl;
		cout << "A�o: " << anio << endl;
		cout << "Sucursal: " << vm.mostrarNombreSucursal(id) << endl;
		cout << endl;

		cout << left;
		cout << setw(12) << "MES";
		cout << setw(20) << "RECAUDACION" << endl;
		cout << "------------------------------------------------------------" << endl;

		for (i = 0; i < 12; i++) {

			cout << setw(12) << meses[i];
			cout << "$ " << setw(20) << vm.formatearNumero(recaudacion[i]);
			cout << endl;

		}
		cout << endl << endl;

		cout << "** TOTAL ANUAL : $" << vm.formatearNumero(recaudacion[12]) << " **" << endl << endl;

    }
    else {
        cout << "Sucursal no valida." << endl << endl;
    }

}

//6.1
void Informes::ventasTodasLasSucursalesMensual()
{
    int anio, mes, contVentas;
    double acuMes;

    Venta regV;
    VentasArchivo va;
    VentasManager vm;
    int cantV = va.contarVentas();

    Sucursal reg;
    SucursalArchivo sa;
    int cont = sa.contarRegistro();

    cout << " INFORME MENSUAL DE VENTAS POR SUCURSAL  " << endl;
    cout << "Ingrese a�o a revisar: ";
    cin >> anio;
    cout << endl << "Ingrese mes a revisar: ";
    cin >> mes;
    system("cls");


    cout << " INFORME MENSUAL DE VENTAS POR SUCURSAL  " << endl << endl;
    cout << "A�o: " << anio << endl;
    cout << "Mes: " << mes << endl;

    cout << endl;

    cout << left;
    cout << setw(20) << "SUCURSAL";
    cout << setw(20) << "CANTIDAD DE VENTAS";
    cout << setw(20) << "RECAUDACION" << endl;
    cout << "------------------------------------------------------------" << endl;

    double total = 0;
    int totalCantV = 0;
    for (int i = 0; i < cont; i++)
    {
        reg = sa.leerRegistro(i);
        acuMes = 0;
        contVentas = 0;

        for (int j = 0; j < cantV; j++)
        {
            regV = va.leerVenta(j);
            if (regV.getFechaVenta().getAnio() == anio && regV.getFechaVenta().getMes() == mes) {
                if (regV.getIdSucursal() == reg.getIdSucursal()) {
                    acuMes += regV.getTotalVenta();
                    contVentas++;
                }
            }
        }
        if (acuMes > 0) {
            cout << setw(25) << reg.getNombre();
            cout << setw(20) << contVentas;
            cout << "$ " << setw(20) << vm.formatearNumero(acuMes);
            cout << endl;
        }

        total += acuMes;
        totalCantV += contVentas;
    }
    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << setw(25) << "TOTAL : ";
    cout << setw(20) << totalCantV;
    cout << "$ " << setw(20) << vm.formatearNumero(total);
    cout << endl;

}

//6.2
void Informes::ventasTodasLasSucursalesAnual()
{
    int anio, cantAnual;
    double acuAnio;
    Fecha f;

    Venta regV;
    VentasArchivo va;
    VentasManager vm;
    int cantV = va.contarVentas();

    Sucursal reg;
    SucursalArchivo sa;
    int cont = sa.contarRegistro();

    cout << " INFORME ANUAL DE VENTAS POR SUCURSAL  " << endl;
    do {
        cout << "Ingrese el a�o a revisar: ";
        cin >> anio;

        if (anio > f.obtenerAnioActual()) {
            cout << "A�o no valido." << endl << endl;
        }

    } while (anio > f.obtenerAnioActual());
    system("cls");

    cout << " INFORME ANUAL DE VENTAS POR SUCURSAL  " << endl << endl;
    cout << "A�o: " << anio << endl;

    cout << endl;

    cout << left;
    cout << setw(20) << "SUCURSAL";
    cout << setw(27) << "CANTIDAD DE VENTAS";
    cout << setw(20) << "RECAUDACION" << endl;
    cout << "------------------------------------------------------------" << endl;

    double totalAnio = 0;
    int totalAnual = 0;

    for (int i = 0; i < cont; i++)
    {
        reg = sa.leerRegistro(i);
        cantAnual = 0;
        acuAnio = 0;

        for (int j = 0; j < cantV; j++)
        {
            regV = va.leerVenta(j);
            if (regV.getFechaVenta().getAnio() == anio) {
                if (regV.getIdSucursal() == reg.getIdSucursal()) {
                    acuAnio += regV.getTotalVenta();
                    cantAnual++;
                }
            }
        }
        if (acuAnio > 0) {
            cout << setw(25) << reg.getNombre();
            cout << setw(20) << cantAnual;
            cout << "$ " << setw(20) << vm.formatearNumero(acuAnio);
            cout << endl;
        }

        totalAnio += acuAnio;
        totalAnual += cantAnual;

    }
    if (totalAnio > 0) {
        cout << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << setw(25) << "TOTAL : ";
        cout << setw(20) << totalAnual;
        cout << "$ " << setw(20) << vm.formatearNumero(totalAnio);
        cout << endl;
    }
    else {
        cout << "No se encontraron ventas para el a�o " << anio << endl;
    }
}

//7
void Informes::rankingVentasXModelo()
{
}
