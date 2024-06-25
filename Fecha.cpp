#define _CRT_SECURE_NO_WARNINGS
#include "Fecha.h"
#include "FuncionesGenerales.h"
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
    setDia(1);
    setMes(1);
    setAnio(1900);

}

void Fecha::setDia(int d) {
    if (d <= 31 && d >= 1) {
        _dia = d;
    }
    else {
        cout << "Dia no valido. Intente nuevamente." << endl;
        d = pedirNumeroPositivo("Dia: ");
        this->setDia(d);
    }
}

void Fecha::setMes(int m) {
    if (m <= 12 && m >= 1) {
        _mes = m;
    }
    else {
        cout << "Mes no valido. Intente nuevamente." << endl;
        m = pedirNumeroPositivo("Mes: ");
        this->setMes(m);
    }
}

void Fecha::setAnio(int a) {
    if (a >= 1900) {
        _anio = a;
    }
    else {
        cout << "A�o no valido. Intente nuevamente." << endl;
        a = pedirNumeroPositivo("A�o: ");
        this->setAnio(a);
    }
}

int Fecha::getDia() { return _dia; }

int Fecha::getMes() { return _mes; }

int Fecha::getAnio() { return _anio; }

void Fecha::Cargar() {
    int dia, mes, anio;
    dia = pedirNumeroPositivo("Dia: ");
    setDia(dia);
    mes = pedirNumeroPositivo("Mes: ");
    setMes(mes);
    anio = pedirNumeroPositivo("A�o: ");
    setAnio(anio);
    time_t now = time(0);
    tm* f = localtime(&now);
    
    /// Verificacion de si la fecha es anterior o igual a la fecha actual:
    if (anio > f->tm_year + 1900 || (anio == f->tm_year + 1900 && mes > f->tm_mon + 1) || (anio == f->tm_year + 1900 && mes == f->tm_mon + 1 && dia > f->tm_mday)) {
        cout << "Fecha No Valida, Ingresela Nuevamente " << endl;
        Fecha::Cargar();
    }

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

bool Fecha::operator>=(const Fecha& otra) {
    if (this->_anio > otra._anio) {
        return true;
    }
    else if (this->_anio == otra._anio) {
        if (this->_mes > otra._mes) {
            return true;
        }
        else if (this->_mes == otra._mes) {
            if (this->_dia >= otra._dia) {
                return true;
            }
        }
    }
    return false;
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

int Fecha::obtenerAnioActual()
{
    time_t t = time(0);
    tm* tiempoLocal = localtime(&t);
    return 1900 + tiempoLocal->tm_year;  // tm_year es el numero de a�os desde 1900

    /*
    primera linea; obtiene el tiempo actual en segundos desde el 1 de enero de 1970.
    segunda linea; convierte este tiempo en una estructura tm que contiene informacion de fecha y hora desglosada.
    tercer linea; obtiene el a�o actual, ya que tm_year representa el numero de a�os transcurridos desde 1900.
    */
}

int Fecha::obtenerMesActual()
{
    time_t t = time(0);
    tm* tiempoLocal = localtime(&t);
    return tiempoLocal->tm_mon+1;
}

int Fecha::obtenerDiaActual()
{
    time_t t = time(0);
    tm* tiempoLocal = localtime(&t);
    return tiempoLocal->tm_mday;
}

Fecha Fecha::obtenerFechaActual() 
{
    time_t t = time(0);
    tm* tiempoLocal = localtime(&t);

    return Fecha(tiempoLocal->tm_mday, tiempoLocal->tm_mon+1, tiempoLocal->tm_year+1900);

}