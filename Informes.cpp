#include "Archivo_DetalleVenta.h"
#include "Cliente.h"
#include "DetallesVenta.h"
#include "Funciones.h"
#include "Informe.h"
#include "Juego.h"
#include <iostream>

void Informe::juegosPorGenero() {
  float *totales = new float[20];
  for (int i = 0; i < 20; i++) {
    totales[i] = 0;
  }

  // Sumar totales
  for (int i = 0; i < _archivoDetalles.contar_registros(); i++) {
    DetallesVenta reg = _archivoDetalles.leer_registro(i);

    Juego juego = _archivoJuegos.leer_registro(
        _archivoJuegos.buscar_posicion(reg.getIDjuego()));
    if (juego.getId() > 0) {
      int indice = obtenerPosGenero(juego.getGenero());
      totales[indice] += reg.getPrecioUnitario() * reg.getCantidad();
    }
  }

  // Mostrar
  for (int i = 0; i < 20; i++) {
    cout << " - " << obtenerNombreGenero(obtenerGeneroPos(i)) << "  $ "
         << totales[i] << endl;
  }

  delete[] totales;
}

void Informe::juegosMasVendidos() {
  int cantJuegos = _archivoJuegos.contar_Registros();
  float *totales = new float[cantJuegos];
  int *ids = new int[cantJuegos];
  for (int i = 0; i < cantJuegos; i++) {
    ids[i] = i + 1;
    totales[i] = 0;
  }

  // Obtener
  for (int i = 0; i < _archivoDetalles.contar_registros(); i++) {
    DetallesVenta reg = _archivoDetalles.leer_registro(i);
    if (reg.getIDdetalle() > 0) {
      totales[reg.getIDjuego() - 1] +=
          reg.getPrecioUnitario() * reg.getCantidad();
    }
  }

  // Ordenar
  for (int i = 0; i < cantJuegos - 1; i++) {
    bool huboCambio = false;
    for (int j = 0; j < cantJuegos - i - 1; j++) {
      if (totales[j] < totales[j + 1]) {
        float aux1 = totales[j];
        totales[j] = totales[j + 1];
        totales[j + 1] = aux1;

        int aux2 = ids[j];
        ids[j] = ids[j + 1];
        ids[j + 1] = aux2;

        huboCambio = true;
      }
    }
    if (!huboCambio)
      break;
  }

  // Mostrar
  for (int i = 0; i < cantJuegos; i++) {
    if (totales[i] > 0) {
      Juego juego =
          _archivoJuegos.leer_registro(_archivoJuegos.buscar_posicion(ids[i]));
      if (juego.getId() > 0) {
        cout << juego.getTitulo() << "  $" << totales[i] << endl;
      }
    }
  }
}

void Informe::ventasPorCliente() {
  int cantClientes = _archivoClientes.contar_registros();
  float *totales = new float[cantClientes];
  for (int i = 0; i < cantClientes; i++) {
    totales[i] = 0;
  }

  int cantVentas = _archivoDetalles.contar_registros();

  // Obtener
  for (int i = 0; i < cantVentas; i++) {
    DetallesVenta reg = _archivoDetalles.leer_registro(i);
    Venta venta = _archivoVentas.leer_registro(
        _archivoVentas.buscar_posicion(reg.getIDventa()));

    totales[venta.getIDcliente() - 1] +=
        reg.getPrecioUnitario() * reg.getCantidad();
  }

  // Mostrar
  for (int i = 0; i < cantClientes; i++) {
    if (totales[i] > 0) {
      Cliente cliente = _archivoClientes.leer_registro(
          _archivoClientes.buscar_registro(i + 1));
      if (cliente.getID() > 0) {
        cout << cliente.getNombre() << " " << cliente.getApellido() << "  $"
             << totales[i] << endl;
      }
    }
  }
}

void Informe::generoMasVendidoPorCliente() {}

void Informe::stockPorClasificacion() {}

void Informe::ventasPorMetodoDePago() {}
