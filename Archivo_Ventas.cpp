#include "Archivo_Ventas.h"
#include "Venta.h"
#include <cstdio>
#include <cstring>

Archivo_Ventas::Archivo_Ventas(const char *nombre) { strcpy(_nombre, nombre); }

bool Archivo_Ventas::grabar_registro(Venta reg) {
  FILE *p = fopen(_nombre, "ab");
  if (p == NULL)
    return false;

  bool escribio = (fwrite(&reg, sizeof(Venta), 1, p) == 1);
  fclose(p);
  return escribio;
}

Venta Archivo_Ventas::leer_registro(int pos) {
  Venta reg;
  if (pos < 0)
    return reg;

  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
    return reg;

  fseek(p, pos * sizeof(Venta), SEEK_SET);
  if (fread(&reg, sizeof(Venta), 1, p) != 1) {
    fclose(p);
    return Venta();
  }

  fclose(p);
  return reg;
}

int Archivo_Ventas::contar_registros() {
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
    return 0;

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  if (bytes <= 0)
    return 0;
  return bytes / sizeof(Venta);
}

int Archivo_Ventas::buscar_posicion(int idVenta) {
  Venta reg;
  FILE *p = fopen(_nombre, "rb");
  if (p == NULL)
    return -1;

  int pos = 0;
  while (fread(&reg, sizeof(Venta), 1, p) == 1) {
    if (reg.getIDventa() == idVenta) {
      fclose(p);
      return pos;
    }
    pos++;
  }

  fclose(p);
  return -1;
}

bool Archivo_Ventas::modificar_registro(Venta reg, int pos) {
  if (pos < 0)
    return false;

  FILE *p = fopen(_nombre, "rb+");
  if (p == NULL)
    return false;

  fseek(p, pos * sizeof(Venta), SEEK_SET);
  bool escribio = (fwrite(&reg, sizeof(Venta), 1, p) == 1);
  fclose(p);
  return escribio;
}

bool Archivo_Ventas::eliminar_registro(int pos) {
  if (pos < 0)
    return false;

  FILE *p = fopen(_nombre, "rb+");
  if (p == NULL)
    return false;

  fseek(p, sizeof(Venta), SEEK_SET);
  Venta obj;
  if (fread(&obj, sizeof(Venta), 1, p) != 1) {
    fclose(p);
    return false;
  }

  obj.setEstado(false);
  fseek(p, sizeof(Venta) * pos, SEEK_SET);
  bool escribio = (fwrite(&obj, sizeof(Venta), 1, p) == 1);
  fclose(p);

  return escribio;
}
