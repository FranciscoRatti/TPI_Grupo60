#pragma once
#include "Archivo_Clientes.h"
#include "Archivo_DetalleVenta.h"
#include "Archivo_Juegos.h"
#include "Archivo_Ventas.h"

class Manager_venta {
private:
  Archivo_Ventas _archivoVentas;
  Archivo_DetallesVenta _archivoDetalles;
  Archivo_Clientes _archivoClientes;
  Archivo_Juegos _archivoJuegos;

public:
  void listarTodos(bool mostrarActivos);
  void registrarVenta();
  void eliminar();
  float calcularTotalVenta(int idVenta);
};
