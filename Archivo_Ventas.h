#ifndef ARCHIVO_VENTAS_H_INCLUDED
#define ARCHIVO_VENTAS_H_INCLUDED
#include "clsVentas.h"
#include <cstring>
#include <string>

using namespace std;

class Archivo_Ventas {
private:
  char nombre[50];

public:
  Archivo_Ventas(const char *n = "Archivo_Ventas.dat");

  Ventas leer_registro(int);
  bool grabar_registro(Ventas);
  bool modificar_venta(Ventas, int);
  int contar_registros();
  int buscar_registro(int leg);
  void listar_registros();

  bool buscar_id_registro(int id);
};

#endif // ARCHIVO_VENTAS_H_INCLUDED
