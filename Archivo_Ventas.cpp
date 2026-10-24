#include "Archivo_Ventas.h"
#include "clsVentas.h"
#include <iostream>

using namespace std;

Archivo_Ventas::Archivo_Ventas(const char *n) { strcpy(nombre, n); }

Ventas Archivo_Ventas::leer_registro(int pos) {
  FILE *p = fopen(nombre, "rb");
  Ventas obj;
  if (p == nullptr) {
    obj.set_id_venta(-2);
    return obj;
  }
  obj.set_id_venta(-1);
  fseek(p, sizeof obj * pos, 0);
  fread(&obj, sizeof obj, 1, p);
  fclose(p);
  return obj;
}

bool Archivo_Ventas::modificar_venta(Ventas obj, int pos) {
  FILE *p = fopen(nombre, "rb+");
  if (p == nullptr)
    return false;
  fseek(p, sizeof obj * pos, 0);
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

bool Archivo_Ventas::grabar_registro(Ventas obj) {
  FILE *p = fopen(nombre, "ab");
  if (p == nullptr)
    return false;
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

int Archivo_Ventas::contar_registros() {
  FILE *p = fopen(nombre, "rb");
  if (p == nullptr)
    return -1;
  fseek(p, 0, 2);
  int cant = ftell(p) / sizeof(Ventas);
  fclose(p);
  return cant;
}

int Archivo_Ventas::buscar_registro(int leg) {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Ventas obj = leer_registro(i);
    if (obj.get_id_venta() == leg) {
      return i;
    }
  }
  return -1;
}

void Archivo_Ventas::listar_registros() {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Ventas obj = leer_registro(i);
    if (obj.get_estado()) {
      obj.mostrar();
      cout << endl;
    }
  }
}

bool Archivo_Ventas::buscar_id_registro(int id) {
  Ventas obj;
  FILE *p = fopen(nombre, "rb");
  if (p == NULL)
    return false;
  while (fread(&obj, sizeof obj, 1, p) == 1) {
    if (obj.get_id_venta() == id) {
      return true;
    }
  }
  fclose(p);
  return false;
}
