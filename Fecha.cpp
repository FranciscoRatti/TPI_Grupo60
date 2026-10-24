#include "Fecha.h"
#include <iostream>
using namespace std;

// Constructor
Fecha::Fecha() {
  _dia = 0;
  _mes = 0;
  _anio = 0;
}
Fecha::Fecha(int dia, int mes, int anio) {
  setAnio(anio);
  setMes(mes);
  setDia(dia);
}

// Setters
bool Fecha::setDia(int dia) {
  if (dia > 0) {
    int ultimoDia = 0;

    switch (_mes) {
    case (1):
      ultimoDia = 31;
      break;
    case (2):
      if (_anio % 4 == 0) {
        ultimoDia = 29;
      } else {
        ultimoDia = 28;
      }
      break;
    case (3):
      ultimoDia = 31;
      break;
    case (4):
      ultimoDia = 30;
      break;
    case (5):
      ultimoDia = 31;
      break;
    case (6):
      ultimoDia = 30;
      break;
    case (7):
      ultimoDia = 31;
      break;
    case (8):
      ultimoDia = 31;
      break;
    case (9):
      ultimoDia = 30;
      break;
    case (10):
      ultimoDia = 31;
      break;
    case (11):
      ultimoDia = 30;
      break;
    case (12):
      ultimoDia = 31;
      break;
    }

    if (dia <= ultimoDia) {
      _dia = dia;
      return true;
    }
  }
  return false;
}
bool Fecha::setMes(int mes) {
  if (mes > 0 && mes <= 12) {
    _mes = mes;
    return true;
  }
  return false;
}
void Fecha::setAnio(int anio) { _anio = anio; }

// Getters
int Fecha::getDia() { return _dia; }
int Fecha::getMes() { return _mes; }
int Fecha::getAnio() { return _anio; }

// Mostrar
void Fecha::Mostrar() { cout << _dia << "/" << _mes << "/" << _anio; }
