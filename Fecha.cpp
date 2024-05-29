#include "Fecha.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

Fecha::Fecha() {
    _dia = 1;
    _mes = 1;
    _anio = 1900;
  
}

void Fecha::setDia(int d) {
    if (d <= 31 && d >= 1) {
        _dia = d;
    }
    else {
        cin.ignore();
        cout << "Dia no valido. Intente nuevamente:" << endl;
        cin >> d;
        this->setDia(d);
        cin.ignore();
    }
}

void Fecha::setMes(int m) {
    if (m <= 12 && m >= 1) {
        _mes = m;
    }
    else {
        cout << "Mes no valido. Intente nuevamente:" << endl;
        cin >> m;
        this->setMes(m);
    }
}

void Fecha::setAnio(int a) {
    if (a >= 1900) {
        _anio = a;
    }
    else {
        cout << "Año no valido. Intente nuevamente:" << endl;
        cin >> a;
        this->setAnio(a);
        cin.ignore();
    }
}

int Fecha::getDia() { return _dia; }

int Fecha::getMes() { return _mes; }

int Fecha::getAnio() { return _anio; }

void Fecha::Cargar() {
    int d, m, a;
    cout << "Dia: ";
    cin >> d;
    setDia(d);
    cin.ignore();
    cout << "Mes: ";
    cin >> m;
    setMes(m);
    cin.ignore();
    cout << "Anio: ";
    cin >> a;
    setAnio(a);
    cin.ignore();
}


bool Fecha::operator>(const Fecha& otra) {
    if (this->_anio > otra._anio) {
        return true;
    }
    else {
        if (this->_anio == otra._anio) {
            if (this->_mes > otra._mes) {
                return true;
            }
            else {
                if (this->_mes == otra._mes) {
                    if (this->_dia > otra._dia) {
                        return true;
                    }
                    else {
                        if (this->_dia == otra._dia) {
                            return false;
                        }
                        else {
                            return false;
                        }
                    }


                }
                else return false;
            }

        }
        else return false;
    }
}

string Fecha::toString()
{
    string valorADevolver;
    valorADevolver = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio); 

    if (to_string(_dia).size() == 1) {
        if (to_string(_mes).size() == 1) {
            valorADevolver = "0" + to_string(_dia) + "/0" + to_string(_mes) + "/" + to_string(_anio);
        }
        else {
            valorADevolver = "0" + to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
        }
    }
    else {
        if (to_string(_mes).size() == 1) {
            valorADevolver = to_string(_dia) + "/0" + to_string(_mes) + "/" + to_string(_anio);
        }
    }
    return valorADevolver;





}

