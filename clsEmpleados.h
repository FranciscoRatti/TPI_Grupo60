#ifndef CLSEMPLEADOS_H_INCLUDED
#define CLSEMPLEADOS_H_INCLUDED
#include "clsPersona.h"


class Empleados : public Persona{
    private:
    int id_empleado;
    int numero_telefono;
    char email[40];
    float sueldo;
    char direccion[40];
    bool estado;

    public:

        ///sets
        void set_id_empleado(int);
        void set_numero_telefono(int);
        void set_email(const char *);
        bool set_sueldo(float);
        void set_direccion(const char *);
        void set_estado(bool);

        ///gets
        int get_id_empleado();
        int get_numero_telefono();
        const char *get_email();
        float get_sueldo();
        const char *get_direccion();
        bool get_estado();

        void mostrar();
        void cargar(int id);
};

#endif // CLSEMPLEADOS_H_INCLUDED
