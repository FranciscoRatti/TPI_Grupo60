#pragma once
#include "Venta.h"

class Archivo_Ventas {
private:
  char _nombre[30];

public:
  Archivo_Ventas(const char *nombre = "Archivo_Ventas.dat");

  bool grabar_registro(Venta reg);
  Venta leer_registro(int pos);
  int contar_registros();
  int buscar_posicion(int idVenta);
  bool modificar_registro(Venta reg, int pos);
};
