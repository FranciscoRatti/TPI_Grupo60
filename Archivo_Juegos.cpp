#include "Archivo_Juegos.h"
#include "clsJuegos.h"
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
  fseek(p, 0, 2);
  int cantReg = ftell(p) / sizeof(Juegos);
  fclose(p);
  return cantReg;
}

bool Archivo_Juegos::Agregar_Juegos(Juegos obj) {
  FILE *p = fopen(_nombre.c_str(), "ab");
  if (p == NULL) {
    return false;
  }

  bool escribio = fwrite(&obj, sizeof(Juegos), 1, p);
  fclose(p);

  return escribio;
}

bool Archivo_Juegos::listar() {

  Juegos obj;

  FILE *p;

  bool flag = false;

  p = fopen(_nombre.c_str(), "rb");

  if (p == nullptr) {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }

  while (fread(&obj, sizeof obj, 1, p) != 0) {
    if (obj.get_estado() == true) {

      obj.mostrar();

      cout << endl;

      flag = true;
    }
    cout << endl;
  }
  if (flag == false) {
    cout << "no hay registros que mostrar. " << endl;
  }

  fclose(p);

  return true;
}

bool Archivo_Juegos::buscar_id_registro(int id) {
  Juegos obj;
  FILE *p = fopen(_nombre.c_str(), "rb");
  if (p == NULL)
    return false;
  while (fread(&obj, sizeof obj, 1, p) == 1) {
    if (obj.get_codigo_articulo() == id && obj.get_estado() == true) {
      return true;
    }
  }
  fclose(p);
  return false;
}

int Archivo_Juegos::buscar_posicion(int id) {
  Juegos obj;
  int cant = contar_Registros();
  for (int i = 0; i < cant; i++) {
    obj = leer_registro(i);
    if (obj.get_codigo_articulo() == id)
      return i;
  }
  return -1;
}

bool Archivo_Juegos::modificar_registro(Juegos obj, int pos) {
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

  fseek(p, sizeof(Juegos) * pos, 0);
  Juegos obj;
  if (fread(&obj, sizeof(Juegos), 1, p) != 1) {
    fclose(p);
    return false;
  }
  obj.set_estado(false);
  fseek(p, sizeof(Juegos) * pos, SEEK_SET);
  bool escribio = fwrite(&obj, sizeof(Juegos), 1, p);
  fclose(p);

  return escribio;
}

Juegos Archivo_Juegos::leer_registro(int pos) {
  FILE *p = fopen(_nombre.c_str(), "rb");
  Juegos obj;
  if (p == nullptr) {
    obj.set_codigo_articulo(-2);
    return obj;
  }
  obj.set_codigo_articulo(-1);
  fseek(p, sizeof obj * pos, 0);
  fread(&obj, sizeof obj, 1, p);
  fclose(p);
  return obj;
}
