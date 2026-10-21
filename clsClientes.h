#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
#include "clsPersona.h"

class Clientes : public Persona{
private:
    int id_cliente;
    int numero_telefono;
    char email[30];
    bool estado;
public:
    ///Sets
    void set_id_cliente(int id);
    void set_numero_telefono(int t);
    void set_email(const char* e);
    void set_estado(bool e);

    ///gets
    int get_id_cliente();
    int get_numero_telefono();
    const char *get_email();
    bool get_estado();

    void mostrar();
    void cargar(int id);

};

#endif // CLSCLIENTES_H_INCLUDED
