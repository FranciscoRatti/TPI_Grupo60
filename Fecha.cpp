#include "Fecha.h"
#include <iostream>
#include <ctime>

using namespace std;

Fecha::Fecha()
{
    time_t t = time(NULL);
    tm* f = localtime(&t);

    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = 1;
    _mes = 1;
    _anio = 2000;

    setAnio(anio);
    setMes(mes);
    setDia(dia);
}

bool Fecha::setDia(int dia)
{
    if (dia > 0)
    {
        int ultimoDia = 0;

        switch (_mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ultimoDia = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            ultimoDia = 30;
            break;
        case 2:
            if ((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0))
            {
                ultimoDia = 29;
            }
            else
            {
                ultimoDia = 28;
            }
            break;
        }

        if (dia <= ultimoDia)
        {
            _dia = dia;
            return true;
        }
    }
    return false;
}

bool Fecha::setMes(int mes)
{
    if (mes > 0 && mes <= 12)
    {
        _mes = mes;
        return true;
    }
    return false;
}

void Fecha::setAnio(int anio)
{
    if (anio > 0)
    {
        _anio = anio;
    }
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

void Fecha::Mostrar()
{
    cout << _dia << "/" << _mes << "/" << _anio;
}
