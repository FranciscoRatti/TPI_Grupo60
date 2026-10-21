#ifndef CLSJUEGOS_H_INCLUDED
#define CLSJUEGOS_H_INCLUDED
#include "clsFecha.h"
#include "generos.h"


class Juegos{
private:
    int codigo_articulo;
    char nombre[30];
    int genero;
    char desarrolladora[30];
    float precio_unitario;
    char publisher[30];
    Fecha fecha_lanzamiento;
    int clasificacion;
    bool digital;
    int cantidad;
    bool estado;
public:
    ///SETS
    void set_codigo_articulo(int codA);
    void set_nombre(const char *n);
    bool set_genero(int genero);
    void set_desarrolladora(const char *d);
    bool set_precio_unitario(float precio);
    void set_publisher(const char *p);
    void set_fecha_lanzamiento(Fecha);
    bool set_clasificacion(int clasificacion);
    void set_digital(bool d);
    bool set_cantidad(int cantidad);
    void set_estado(bool bP);

    ///gets
    int get_codigo_articulo();
    const char* get_nombre();
    const char *get_genero(int genero);
    int get_genero();
    const char *get_desarrolladora();
    float get_precio_unitario();
    const char *get_publisher();
    Fecha get_fecha_lanzamiento(Fecha);
    bool get_digital(bool digital);
    int get_cantidad();
    bool get_estado();

    void mostrar();
    void cargar(int codigo_articulo);
};



#endif // CLSJUEGOS_H_INCLUDED
