#include "Juego.h"
#include <cstring>

using namespace std;

// Constructores
Juego::Juego() {}
Juego::Juego(int id, bool estado, char *titulo, Genero genero,
             float precioUnitario, int stock, char *desarrollador,
             Clasificacion clasificacion) {
  _id = id;
  _estado = estado;
  strcpy(_titulo, titulo);
  _genero = genero;
  _precioUnitario = precioUnitario;
  _stock = stock;
  strcpy(_desarrollador, desarrollador);
  _clasificacion = clasificacion;
}

// Setters
void Juego::setId(int id) { _id = id; }
void Juego::setEstado(bool estado) { _estado = estado; }
void Juego::setTitulo(char *titulo) { strcpy(_titulo, titulo); }
void Juego::setGenero(Genero genero) { _genero = genero; }
bool Juego::setPrecioUnitario(float precio) {
  if (precio > 0) {
    _precioUnitario = precio;
    return true;
  } else {
    return false;
  }
}
bool Juego::setStock(int stock) {
  if (stock > 0) {
    _stock = stock;
    return true;
  } else {
    return false;
  }
}
void Juego::setDesarrollador(const char *desarrollador) {
  strcpy(_desarrollador, desarrollador);
}
void Juego::setClasificacion(Clasificacion clasificacion) {
  _clasificacion = clasificacion;
}

// Getters
int Juego::getId() { return _id; }
bool Juego::getEstado() { return _estado; }
char *Juego::getTitulo() { return _titulo; }
Genero Juego::getGenero() { return _genero; }
float Juego::getPrecioUnitario() { return _precioUnitario; }
int Juego::getStock() { return _stock; }
char *Juego::getDesarrollador() { return _desarrollador; }
Clasificacion Juego::getClasificacion() { return _clasificacion; }

// Mostrar
void mostrar();
