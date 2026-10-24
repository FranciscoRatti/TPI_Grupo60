#ifndef CLSJUEGOS_H_INCLUDED
#define CLSJUEGOS_H_INCLUDED
#include "Enumeradores.h"
#include "Fecha.h"

class Juego {
private:
  long _id;
  bool _estado;
  char _titulo[30];
  Genero _genero;
  float _precioUnitario;
  int _stock;
  char _desarrollador[30];
  Clasificacion _clasificacion;

public:
  // Constructores
  Juego();
  Juego(int id, bool estado, char *titulo, Genero genero, float precioUnitario,
        int stock, char *desarrollador, Clasificacion clasificacion);

  // Setters
  void setId(int id);
  void setEstado(bool estado);
  void setTitulo(char *titulo);
  void setGenero(Genero genero);
  bool setPrecioUnitario(float precio);
  bool setStock(int stock);
  void setDesarrollador(const char *desarrollador);
  void setClasificacion(Clasificacion clasificacion);

  // Getters
  int getId();
  bool getEstado();
  char *getTitulo();
  Genero getGenero();
  float getPrecioUnitario();
  int getStock();
  char *getDesarrollador();
  Clasificacion getClasificacion();

  // Mostrar
  void mostrar();
};

#endif // CLSJUEGOS_H_INCLUDED
