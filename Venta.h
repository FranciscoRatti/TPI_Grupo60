#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED
#include "Enumeradores.h"
#include "Fecha.h"
#include <cstring>

class Venta {
private:
  long _id;
  bool _estado;
  long _idCliente;
  Fecha _fechaDeVenta;
  FormaPago _formaDePago;
  float _total;

public:
  // Constructores
  Venta(long id, bool estado, long cliente, Fecha fechaDeVenta,
        FormaPago formaPago, float total);

  // Setters
  void setId(long id);
  void setEstado(bool estado);
  void setClient(long id);
  void setFechaDeVenta(Fecha fecha);
  void setFormaPago(FormaPago formaPago);
  void setTotal(float total);

  // Getters
  long getId();
  bool getEstado();
  long getClient();
  Fecha getFechaDeVenta();
  FormaPago getFormaPago();
  float getTotal();
};

#endif // CLSVENTAS_H_INCLUDED
