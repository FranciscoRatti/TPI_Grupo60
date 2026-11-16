#include <iostream>
#include "Venta.h"
#include "Funciones.h"

using namespace std;

Venta::Venta()
{
    _IDventa = 0;
    _estado = false;
    _IDcliente = 0;
    _formaDePago = static_cast<FormaPago>(0);
}

Venta::Venta(int idVenta, int idCliente, Fecha fechaDeVenta, FormaPago formaDePago)
{
    _IDventa = idVenta;
    _estado = true;
    _IDcliente = idCliente;
    _fechaDeVenta = fechaDeVenta;
    _formaDePago = formaDePago;
}

int Venta::getIDventa()
{
    return _IDventa;
}
bool Venta::getEstado()
{
    return _estado;
}
int Venta::getIDcliente()
{
    return _IDcliente;
}
Fecha Venta::getFechaDeVenta()
{
    return _fechaDeVenta;
}
FormaPago Venta::getFormaDePago()
{
    return _formaDePago;
}

void Venta::setIDventa(int idVenta)
{
    _IDventa = idVenta;
}
void Venta::setEstado(bool estado)
{
    _estado = estado;
}
void Venta::setIDcliente(int idCliente)
{
    _IDcliente = idCliente;
}
void Venta::setFechaDeVenta(Fecha fechaDeVenta)
{
    _fechaDeVenta = fechaDeVenta;
}
void Venta::setFormaDePago(FormaPago formaDePago)
{
    _formaDePago = formaDePago;
}

void Venta::mostrar()
{
    cout << "ID Venta: " << _IDventa << " | ID Cliente: " << _IDcliente << endl;
    cout << "Fecha: ";
    _fechaDeVenta.Mostrar();
    cout << " | Forma de Pago: " << obtenerNombreFormaPago(_formaDePago) << endl;
    cout << "Estado: ";
    if (_estado == true)
    {
        cout << "Activa" << endl;
    }
    else
    {
        cout << "Anulada" << endl;
    }
}
