#pragma once
#include "Venta.h"

class Archivo_Ventas {
private:
  char _nombre[30];

public:
  Archivo_Ventas(const char *nombre = "Archivo_Ventas.dat");

  int contar_registros();
  bool grabar_registro(Venta reg);
  int buscar_posicion(int idVenta);
  Venta leer_registro(int pos);
  bool modificar_registro(Venta reg, int pos);
  bool eliminar_registro(int pos);
};
