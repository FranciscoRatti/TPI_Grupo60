#ifndef ARCHIVO_DETALLE_H_INCLUDED
#define ARCHIVO_DETALLE_H_INCLUDED
#include "clsDetalle.h"

class Archivo_Detalle {
private:
  char nombre[50];

public:
  Archivo_Detalle(const char *n = "Archivo_Detalle.dat");

  Detalle leer_registro(int);
  bool grabar_registro(Detalle);
  bool modificar_detalle(Detalle, int);
  int contar_registros();
  int buscar_registro(int leg);
  void listar_registros();
};

#endif // ARCHIVO_DETALLE_H_INCLUDED
