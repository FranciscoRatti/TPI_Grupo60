#include <iostream>
#include "DetallesVenta.h"

using namespace std;

DetallesVenta::DetallesVenta()
{
    _IDdetalle = 0;
    _estado = false;
    _IDventa = 0;
    _IDjuego = 0;
    _cantidad = 0;
    _precioUnitario = 0;
}

DetallesVenta::DetallesVenta(int idDetalle, int idVenta, int idJuego, int cantidad, float precioVenta)
{
    _IDdetalle = idDetalle;
    _estado = true;
    _IDventa = idVenta;
    _IDjuego = idJuego;
    _cantidad = cantidad;
    _precioUnitario = precioVenta;
}

int DetallesVenta::getIDdetalle()
{
    return _IDdetalle;
}
bool DetallesVenta::getEstado()
{
    return _estado;
}
int DetallesVenta::getIDventa()
{
    return _IDventa;
}
int DetallesVenta::getIDjuego()
{
    return _IDjuego;
}
int DetallesVenta::getCantidad()
{
    return _cantidad;
}
float DetallesVenta::getPrecioUnitario()
{
    return _precioUnitario;
}

void DetallesVenta::setIDdetalle(int idDetalle)
{
    _IDdetalle = idDetalle;
}
void DetallesVenta::setEstado(bool estado)
{
    _estado = estado;
}
void DetallesVenta::setIDventa(int idVenta)
{
    _IDventa = idVenta;
}
void DetallesVenta::setIDjuego(int idJuego)
{
    _IDjuego = idJuego;
}
void DetallesVenta::setCantidad(int cantidad)
{
    _cantidad = cantidad;
}
void DetallesVenta::setPrecioUnitario(float precioVenta)
{
    _precioUnitario = precioVenta;
}

void DetallesVenta::mostrar()
{
    cout << "Detalle #" << _IDdetalle << " | Venta #" << _IDventa
         << " | ID Juego: " << _IDjuego << " | Cant: " << _cantidad
         << " | Precio Unit: $" << _precioUnitario
         << " | Subtotal: $" << (_cantidad * _precioUnitario) << endl;
}
