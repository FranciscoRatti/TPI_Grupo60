#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED

#include "Archivo_Clientes.h"
#include "Archivo_DetalleVenta.h"
#include "Archivo_Juegos.h"
#include "Archivo_Ventas.h"

class Informe {
private:
  Archivo_Ventas _archivoVentas;
  Archivo_DetallesVenta _archivoDetalles;
  Archivo_Clientes _archivoClientes;
  Archivo_Juegos _archivoJuegos;

public:
  void juegosPorGenero();
  void juegosMasVendidos();
  void ventasPorCliente();
  void generoMasVendidoPorCliente();
  void stockPorClasificacion();
  void ventasPorMetodoDePago();
};

#endif // INFORME_H_INCLUDED
