#ifndef CLSDETALLE_H_INCLUDED
#define CLSDETALLE_H_INCLUDED
#include "Fecha.h"

class Detalle {
private:
  long _id;
  bool _estado;
  long _idVenta;
  long _idJuego;
  int _cantidad;
  float _precioVenta;

public:
  // Constructores
  Detalle();
  Detalle(long id, bool estado, long idVenta, long idJuego, int cantidad,
          float precioVenta);

  // Setters
  void setId(long id);
  void setEstado(bool estado);
  void setVenta(long id);
  void setJuego(long id);
  void setCantidad(int cantidad);
  void setPrecioVenta(float precioVenta);

  // Getters
  long getId();
  bool getEstado();
  long getVenta();
  long getJuego();
  int getCantidad();
  float getPrecioVenta();

  // Mostrar
  void mostrar();
};

#endif // CLSDETALLE_H_INCLUDED
