#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
#include "clsFecha.h"
#include <cstring>

class Persona{
private:
    int dni;
    char apellidos[50];
    char nombres[50];
    Fecha fecha_nacimiento;
public:
    ///sets
    void set_dni(int d);
    void set_apellidos(const char *a);
    void set_nombres(const char *n);
    void set_fecha_nacimiento(Fecha);
    ///gets
    int get_dni(int dni);
    const char *get_apellido();
    const char *get_nombre();
    Fecha get_fecha_nacimiento(Fecha fecha_nacimiento);

    void mostrar();
    void cargar();
};




#endif // CLSPERSONA_H_INCLUDED
