#include "Ventas.h"
#include "Fecha.h"
#include <cstring>

using namespace std;

// Constructores
Venta::Venta(long id, bool estado, long cliente, Fecha fechaDeVenta,
             FormaPago formaPago, float total) {
  _id = id;
  _estado = estado;
  _idCliente = cliente;
  _fechaDeVenta = fechaDeVenta;
  _formaDePago = formaPago;
  _total = total;
}

// Setters
void Venta::setId(long id) { _id = id; }
void Venta::setEstado(bool estado) { _estado = estado; }
void Venta::setClient(long id) { _idCliente = id; }
void Venta::setFechaDeVenta(Fecha fecha) { _fechaDeVenta = fecha; }
void Venta::setFormaPago(FormaPago formaPago) { _formaDePago = formaPago; }
void Venta::setTotal(float total) { _total = total; }

// Getters
long Venta::getId() { return _id; }
bool Venta::getEstado() { return _estado; }
long Venta::getClient() { return _idCliente; }
Fecha Venta::getFechaDeVenta() { return _fechaDeVenta; }
FormaPago Venta::getFormaPago() { return _formaDePago; }
float Venta::getTotal() { return _total; }
