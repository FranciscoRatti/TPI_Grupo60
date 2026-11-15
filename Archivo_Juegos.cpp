#include "Archivo_Juegos.h"
#include "Juego.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

Archivo_Juegos::Archivo_Juegos(string nombre) { _nombre = nombre; }

int Archivo_Juegos::contar_Registros() {
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == nullptr) {
    return -1;
  }
  fseek(p, 0, SEEK_END);
  int cantReg = ftell(p) / sizeof(Juego);
  fclose(p);
  return cantReg;
}

bool Archivo_Juegos::Agregar_Juegos(Juego obj) {
  FILE *p = fopen(_nombre.c_str(), "ab");
  if (p == nullptr) {
    return false;
  }

  bool escribio = fwrite(&obj, sizeof(Juego), 1, p);
  fclose(p);

  return escribio;
}

bool Archivo_Juegos::listar() {
  Juego obj;
  FILE *p;
  bool flag = false;

  p = fopen(_nombre.c_str(), "rb");

  if (p == nullptr) {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }

  while (fread(&obj, sizeof obj, 1, p) != 0) {
    if (obj.getEstado() == true) {
      obj.mostrar();
      cout << endl;
      flag = true;
    }
  }
  if (flag == false) {
    cout << "No hay registros que mostrar. " << endl;
  }

  fclose(p);
  return true;
}

bool Archivo_Juegos::buscar_id_registro(int id) {
  Juego obj;
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == nullptr)
    return false;

  while (fread(&obj, sizeof obj, 1, p) == 1) {
    if (obj.getId() == id && obj.getEstado() == true) {
      fclose(p);
      return true;
    }
  }
  fclose(p);
  return false;
}

int Archivo_Juegos::buscar_posicion(int id) {
  Juego obj;
  int cant = contar_Registros();
  for (int i = 0; i < cant; i++) {
    obj = leer_registro(i);
    if (obj.getId() == id)
      return i;
  }
  return -1;
}

bool Archivo_Juegos::modificar_registro(Juego obj, int pos) {
  FILE *p = fopen(_nombre.c_str(), "rb+");
  if (p == nullptr)
    return false;
  fseek(p, sizeof obj * pos, 0);
  bool escribio = fwrite(&obj, sizeof obj, 1, p);
  fclose(p);
  return escribio;
}

bool Archivo_Juegos::eliminar_registro(int pos) {
  FILE *p = fopen(_nombre.c_str(), "rb+");
  if (p == nullptr)
    return false;

  fseek(p, sizeof(Juego) * pos, 0);
  Juego obj;
  if (fread(&obj, sizeof(Juego), 1, p) != 1) {
    fclose(p);
    return false;
  }

  obj.setEstado(false);
  fseek(p, sizeof(Juego) * pos, SEEK_SET);
  bool escribio = fwrite(&obj, sizeof(Juego), 1, p);
  fclose(p);

  return escribio;
}

Juego Archivo_Juegos::leer_registro(int pos) {
  FILE *p = fopen(_nombre.c_str(), "rb");
  Juego obj;
  if (p == nullptr) {
    obj.setId(-2);
    return obj;
  }

  obj.setId(-1);
  fseek(p, sizeof obj * pos, 0);
  fread(&obj, sizeof obj, 1, p);
  fclose(p);
  return obj;
}
