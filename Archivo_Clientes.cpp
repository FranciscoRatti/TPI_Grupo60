#include "Archivo_Clientes.h"
#include <cstring>
#include <iostream>

using namespace std;

Archivo_Clientes::Archivo_Clientes(const char *n) { strcpy(nombre, n); }

Cliente Archivo_Clientes::leer_registro(int pos) {
  Cliente obj;
  if (pos < 0) {
    obj.setID(-1);
    return obj;
  }

  FILE *p = fopen(nombre, "rb");
  if (p == nullptr) {
    obj.setID(-2);
    return obj;
  }

  fseek(p, sizeof(Cliente) * pos, SEEK_SET);
  if (fread(&obj, sizeof(Cliente), 1, p) != 1) {
    obj.setID(-1);
  }

  fclose(p);
  return obj;
}

bool Archivo_Clientes::modificar_cliente(Cliente obj, int pos) {
  if (pos < 0)
    return false;

  FILE *p = fopen(nombre, "rb+");
  if (p == nullptr)
    return false;

  fseek(p, sizeof(Cliente) * pos, SEEK_SET);
  bool escribio = (fwrite(&obj, sizeof(Cliente), 1, p) == 1);
  fclose(p);
  return escribio;
}

bool Archivo_Clientes::grabar_registro(Cliente obj) {
  FILE *p = fopen(nombre, "ab");
  if (p == nullptr)
    return false;

  bool escribio = (fwrite(&obj, sizeof(Cliente), 1, p) == 1);
  fclose(p);
  return escribio;
}

int Archivo_Clientes::contar_registros() {
  FILE *p = fopen(nombre, "rb");
  if (p == nullptr)
    return 0;

  fseek(p, 0, SEEK_END);
  int bytes = ftell(p);
  fclose(p);

  if (bytes <= 0)
    return 0;
  return bytes / sizeof(Cliente);
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
