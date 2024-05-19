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
    _dia = 0;
    _mes = 0;
    _anio = 0;
  
}

void Fecha::setDia(int d) {
    if (d <= 31 && d >= 1) {
        _dia = d;
    }
    else {
        _dia = 0;
    }
}

void Fecha::setMes(int m) {
    if (m <= 12 && m >= 1) {
        _mes = m;
    }
    else {
        _mes = 0;
    }
}

void Fecha::setAnio(int a) {
    if (a >= 1900) {
        _anio = a;
    }
    else {
        _anio = 0;
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
    cout << "Mes: ";
    cin >> m;
    setMes(m);
    cout << "Anio: ";
    cin >> a;
    setAnio(a);
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

