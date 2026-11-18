#pragma once
#include "Cliente.h"
#include <cstring>
#include <string>
using namespace std;

class Archivo_Clientes {
private:
  char nombre[50];

public:
  Archivo_Clientes(const char *n = "Archivo_Clientes.dat");

  Cliente leer_registro(int);
  bool grabar_registro(Cliente);
  bool modificar_cliente(Cliente, int);
  int contar_registros();
  int buscar_registro(int leg);
};
