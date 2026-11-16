#pragma once
#include "Fecha.h"
#include "Enumeradores.h"

class Venta {
private:
    int _IDventa;
    bool _estado;
    int _IDcliente;
    Fecha _fechaDeVenta;
    FormaPago _formaDePago;

public:
    Venta();
    Venta(int idVenta, int idCliente, Fecha fechaDeVenta, FormaPago formaDePago);

    int getIDventa();
    bool getEstado();
    int getIDcliente();
    Fecha getFechaDeVenta();
    FormaPago getFormaDePago();

    void setIDventa(int idVenta);
    void setEstado(bool estado);
    void setIDcliente(int idCliente);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setFormaDePago(FormaPago formaDePago);

    void mostrar();
};
