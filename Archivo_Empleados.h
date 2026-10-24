#ifndef ARCHIVO_EMPLEADOS_H_INCLUDED
#define ARCHIVO_EMPLEADOS_H_INCLUDED

#include "clsEmpleados.h"
#include <cstring>
#include <iostream>
using namespace std;

class Archivo_Empleados {
private:
  char nombre[50];

public:
  Archivo_Empleados(const char *n = "Archivo_Empleados.dat");

  Empleados leer_registro(int);
  bool grabar_registro(Empleados);
  bool modificar_empleado(Empleados, int);
  int contar_registros();
  int buscar_registro(int leg);
  void listar_registros();

  bool buscar_id_registro(int id);
};

#endif // ARCHIVO_EMPLEADOS_H_INCLUDED
