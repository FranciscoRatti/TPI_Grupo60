#pragma once
#include "Archivo_Juegos.h"
#include "Juego.h"

class Manager_juego {
private:
  Archivo_Juegos _archivo;

public:
  void consultarPorTitulo();
  void consultarPorPrecio();
  void listarTodos(bool mostrarActivos);
  void modificar();
  void agregar();
  void eliminar();
};
