#pragma once
#include "DetallesVenta.h"

class Archivo_DetallesVenta {
private:
  char _nombre[30];

public:
  Archivo_DetallesVenta(const char *nombre = "Archivo_DetallesVenta.dat");

  bool grabar_registro(DetallesVenta reg);
  DetallesVenta leer_registro(int pos);
  int contar_registros();
  int buscar_posicion(int idDetalle);
  bool modificar_registro(DetallesVenta reg, int pos);
};
