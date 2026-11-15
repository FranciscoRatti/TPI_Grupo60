#pragma once

#include "Juego.h"
#include <cstring>
#include <string>

using namespace std;

class Archivo_Juegos {
private:
  string _nombre;

public:
  Archivo_Juegos(string nombre = "Archivo_Juegos.dat");
  int contar_Registros();
  bool Agregar_Juegos(Juego obj);
  bool listar();

  bool buscar_id_registro(int id);
  Juego leer_registro(int);
  bool modificar_registro(Juego obj, int pos);
  bool eliminar_registro(int pos);
  int buscar_posicion(int id);
};

