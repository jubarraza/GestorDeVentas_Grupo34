#include <iostream>
#include <string> 
#include "FuncionesGenerales.h"
using namespace std;

// funciona pero si ingresas por ejemplo 12r toma el 12 y no vuelve a pedir por lo que no la estoy usando en el codigo.
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

int validarInt(const std::string& mensaje) {
    string ingreso;
    int num;
    while (true) {
        bool esValido = true;
        cout << mensaje; //mensaje que pide el ingreso
        getline(cin, ingreso);
        for (int i = 0; i < ingreso.size(); i++) {//Recorre cada Caracter del Ingreso
            if (!isdigit(ingreso[i])) {//Si encuentra un caracter que no es un digito
                esValido = false;//Bandera en False
                break;//Sale del Bucle
            }
        }
        if (!esValido) {//Vuelve a pedir el Ingreso
            cout << "* Ingreso No Valido, Solo se Admiten Numeros Positivos *" << endl;
        }
        else {//Si es Valido
            num = stoi(ingreso);//Convierte el ingreso en tipo String a un a un Int y lo guarda en Num
            break;//Sale del Bucle
        }
    }
    cin.ignore(numeric_limits<size_t>::max());///Lipia el Buffer de Entrada por completo
    return num;///Si el bucle completa la iteracion sin encontrar caracteres no Numericos, la funcion devuelve Num.
}

long long validarLong(const std::string& mensaje) {
    string ingreso;
    long long num;
    while (true) {
        bool esValido = true;
        cout << mensaje; //mensaje que pide el ingreso
        getline(cin, ingreso);
        for (int i = 0; i < ingreso.size(); i++) {//Recorre cada Caracter del Ingreso
            if (!isdigit(ingreso[i])) {//Si encuentra un caracter que no es un digito
                esValido = false;//Bandera en False
                break;//Sale del Bucle
            }
        }
        if (!esValido) {//Vuelve a pedir el Ingreso
            cout << "* Ingreso No Valido, Solo se Admiten Numeros Positivos *" << endl;
        }
        else {//Si es Valido
            num = stoll(ingreso);//Convierte el ingreso en tipo String a un a un Int y lo guarda en Num
            break;//Sale del Bucle
        }
    }
    cin.ignore(numeric_limits<size_t>::max());///Lipia el Buffer de Entrada por completo
    return num;///Si el bucle completa la iteracion sin encontrar caracteres no Numericos, la funcion devuelve Num.
}

float validarFloat(const std::string& mensaje) 
{
    string ingreso; 
    float num;
    bool puntoEncontrado = false;
    while (true) {
        bool esValido = true;
        cout << mensaje; //mensaje que pide el ingreso
        getline(cin, ingreso);
        for (int i = 0; i < ingreso.size(); i++) {//Recorre cada Caracter del Ingreso
            if (!isdigit(ingreso[i])) { //Si encuentra un caracter que no es un digito
                if (ingreso[i] == '.' && puntoEncontrado == false) {
                    puntoEncontrado = true;
                }
                else {
                    esValido = false;//Bandera en False
                    break;//Sale del Bucle

                }
            }
        }
        if (!esValido) {//Vuelve a pedir el Ingreso
            cout << "* Ingreso No Valido, Solo se Admiten Numeros Positivos (acepta decimales) *" << endl;
        }
        else {//Si es Valido
            num = stof(ingreso);//Convierte el String a un a un float y lo guarda en Num
            break;//Sale del Bucle
        }
    }
    cin.ignore(numeric_limits<size_t>::max());///Lipia el Buffer de Entrada por completo
    return num;///Si el bucle completa la iteracion sin encontrar caracteres no Numericos, la funcion devuelve Num.
}

float pedirNumeroFloat(const string& mensaje) { 
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) { //pregunta si hay error en el cin y si es negativo
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