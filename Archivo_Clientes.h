#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED
#include "clsClientes.h"
#include <cstring>
#include <string>
using namespace std;

class Archivo_Clientes
{
private:

char nombre[50];

public:
    Archivo_Clientes(const char *n= "Archivo_Clientes.dat");

    Clientes leer_registro(int);
    bool grabar_registro(Clientes);
    bool modificar_cliente(Clientes, int);
    int contar_registros();
    int buscar_registro(int leg);
    void listar_registros();
};


#endif // ARCHIVO_CLIENTES_H_INCLUDED
