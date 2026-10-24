#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED
#include "Fecha.h"
#include<cstring>

class Ventas{
private:
    int id_venta;
    int id_cliente;
    int id_empleado;
    Fecha fecha_de_venta;
    float importe_total;
    int forma_pago;
    bool estado;

public:
    ///sets
    void set_id_venta(int);
    void set_id_cliente(int);
    void set_id_empleado(int);
    void set_fecha_de_venta(Fecha);
    bool set_importe_total(float);
    bool set_forma_pago(int);
    void set_estado(bool);

    ///gets
    int get_id_venta();
    int get_id_cliente();
    int get_id_empleado();
    Fecha get_fecha_de_venta();
    float get_importe_total();
    bool get_forma_pago();
    bool get_estado();

    void cargar(int id_venta, int id_cliente, int id_empleado);
    void mostrar();


};

#endif // CLSVENTAS_H_INCLUDED
