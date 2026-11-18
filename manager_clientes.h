#pragma once
#include "Archivo_Clientes.h"
#include "Cliente.h"

class Manager_cliente {
private:
  Archivo_Clientes _archivo;

public:
  void consultarPorDNI();
  void consultarPorNombre();
  void listarTodos(bool mostrarActivos);
  void modificar();
  void agregar();
  void eliminar();
};
