#include <iostream>
#include "FuncionesGenerales.h"
using namespace std;

int pedirNumeroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < 0) { //pregunta si hay error en el cin y si es negativo
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora la entrada invalida limpiando el buffer para que podamos hacer un nuevo ingreso
            cout << "Ingreso invalido. Por favor, ingrese un numero valido." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
            return valor;
        }
    }
}

