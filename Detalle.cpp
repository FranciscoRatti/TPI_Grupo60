#include "Detalle.h"
#include <cstring>

using namespace std;

// Constructores

Detalle::Detalle(long id, bool estado, long idVenta, long idJuego, int cantidad,
                 float precioVenta) {
  _id = id;
  _estado = estado;
  _idVenta = idVenta;
  _idJuego = idJuego;
  _cantidad = cantidad;
  _precioVenta = precioVenta;
}

// Setters

void Detalle::setId(long id) { _id = id; }
void Detalle::setEstado(bool estado) { _estado = estado; }
void Detalle::setVenta(long id) { _idVenta = id; }
void Detalle::setJuego(long id) { _idJuego = id; }
void Detalle::setCantidad(int cantidad) {
  if (cantidad < 0) {
    _cantidad = 0;
  } else {
    _cantidad = cantidad;
  }
}
void Detalle::setPrecioVenta(float precioVenta) {
  if (precioVenta < 0) {
    _precioVenta = 0.0;
  } else {
    _precioVenta = precioVenta;
  }
}

// Getters

long Detalle::getId() { return _id; }
bool Detalle::getEstado() { return _estado; }
long Detalle::getVenta() { return _idVenta; }
long Detalle::getJuego() { return _idJuego; }
int Detalle::getCantidad() { return _cantidad; }
float Detalle::getPrecioVenta() { return _precioVenta; }

void Detalle::mostrar() {}
