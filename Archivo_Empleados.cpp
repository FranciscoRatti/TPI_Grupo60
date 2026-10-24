#include "Archivo_Empleados.h"
#include "clsEmpleados.h"
#include <iostream>

using namespace std;

Archivo_Empleados::Archivo_Empleados(const char *n) { strcpy(nombre, n); }

Empleados Archivo_Empleados::leer_registro(int pos) {
  FILE *p = fopen(nombre, "rb");
  Empleados obj;
  if (p == nullptr) {
    obj.set_id_empleado(-2);
    return obj;
  }
  obj.set_id_empleado(-1);
  fseek(p, sizeof obj * pos, 0);
  fread(&obj, sizeof obj, 1, p);
  fclose(p);
  return obj;
}

bool Archivo_Empleados::modificar_empleado(Empleados obj, int pos) {
  FILE *p = fopen(nombre, "rb+");
  if (p == nullptr)
    return false;
  fseek(p, sizeof obj * pos, 0);
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

bool Archivo_Empleados::grabar_registro(Empleados obj) {
  FILE *p = fopen(nombre, "ab");
  if (p == nullptr)
    return false;
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

int Archivo_Empleados::contar_registros() {
  FILE *p = fopen(nombre, "rb");
  if (p == nullptr)
    return -1;
  fseek(p, 0, 2);
  int cant = ftell(p) / sizeof(Empleados);
  fclose(p);
  return cant;
}

int Archivo_Empleados::buscar_registro(int leg) {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Empleados obj = leer_registro(i);
    if (obj.get_id_empleado() == leg && obj.get_estado() == true) {
      return i;
    }
  }
  return -1;
}

void Archivo_Empleados::listar_registros() {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Empleados obj = leer_registro(i);
    if (obj.get_estado()) {
      obj.mostrar();
      cout << endl;
    }
  }
}

bool Archivo_Empleados::buscar_id_registro(int id) {
  Empleados obj;
  FILE *p = fopen(nombre, "rb");
  if (p == NULL)
    return false;
  while (fread(&obj, sizeof obj, 1, p) == 1) {
    if (obj.get_id_empleado() == id) {
      return true;
    }
  }
  fclose(p);
  return false;
}
