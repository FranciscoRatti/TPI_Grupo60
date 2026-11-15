#pragma once
#include "Archivo_Clientes.h"
#include "Cliente.h"

class Manager_cliente {
private:
    Archivo_Clientes _archivo;

public:
    void agregar();
    void consultarPorDNI();
    void consultarPorNombre();
    void modificar();
    void eliminar();
    void listarTodos();
};
