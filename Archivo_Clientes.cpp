#include "Archivo_Clientes.h"
#include <cstring>
#include <iostream>

using namespace std;

Archivo_Clientes::Archivo_Clientes(const char *n) { strcpy(nombre, n); }

Cliente Archivo_Clientes::leer_registro(int pos) {
  FILE *p = fopen(nombre, "rb");
  Cliente obj;
  if (p == nullptr) {
    obj.setID(-2);
    return obj;
  }
  obj.setID(-1);
  fseek(p, sizeof obj * pos, 0);
  fread(&obj, sizeof obj, 1, p);
  fclose(p);
  return obj;
}

bool Archivo_Clientes::modificar_cliente(Cliente obj, int pos) {
  FILE *p = fopen(nombre, "rb+");
  if (p == nullptr)
    return false;
  fseek(p, sizeof obj * pos, 0);
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

bool Archivo_Clientes::grabar_registro(Cliente obj) {
  FILE *p = fopen(nombre, "ab");
  if (p == nullptr)
    return false;
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

int Archivo_Clientes::contar_registros() {
  FILE *p = fopen(nombre, "rb");
  if (p == nullptr)
    return -1;
  fseek(p, 0, 2);
  int cant = ftell(p) / sizeof(Cliente);
  fclose(p);
  return cant;
}

int Archivo_Clientes::buscar_registro(int id) {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Cliente obj = leer_registro(i);
    if (obj.getID() == id && obj.getEstado() == true) {
      return i;
    }
  }
  return -1;
}

void Archivo_Clientes::listar_registros() {
  int cant_reg = contar_registros();
  for (int i = 0; i < cant_reg; i++) {
    Cliente obj = leer_registro(i);
    if (obj.getEstado()) {
      obj.mostrar();
      cout << endl;
    }
  }
}
