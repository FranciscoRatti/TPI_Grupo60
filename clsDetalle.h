#ifndef CLSDETALLE_H_INCLUDED
#define CLSDETALLE_H_INCLUDED
#include "clsFecha.h"

class Detalle{
private:
    int id_venta;
    int id_detalle;
    int codigo_articulo;
    int cantidad;
    float precio_unitario;
    bool estado;
public:
    ///sets
    void set_id_venta(int id_venta);
    void set_id_detalle(int id_detalle);
    void set_codigo_articulo(int codigo_articulo);
    ///convertida en bool
    bool set_cantidad(int cantidad);
    bool set_precio_unitario(float precio_unitario);
    bool set_estado(int estado);

    ///gets
    int get_id_venta();
    int get_id_detalle();
    int get_codigo_articulo();
    int get_cantidad();
    float get_forma_pago();
    float get_precio_unitario();
    bool get_estado();

    void cargar(int id_venta, int id_detalle, int codigo_articulo, int cantidad, float precio_unitario);
    void mostrar();
};

#endif // CLSDETALLE_H_INCLUDED
