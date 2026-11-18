#include "manager_venta.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

void Manager_venta::listarTodos() {
  cout << "=== LISTADO DE VENTAS ===" << endl;

  int total = _archivoVentas.contar_registros();

  if (total < 0) {
    cout << "Error al abrir el archivo de ventas." << endl;
    return;
  }

  if (total == 0) {
    cout << "No hay ventas registradas." << endl;
    return;
  }

  bool encontrado = false;

  for (int i = 0; i < total; i++) {
    Venta reg = _archivoVentas.leer_registro(i);

    cout << "-----------------------------------" << endl;
    reg.mostrar();
    encontrado = true;
  }

  if (!encontrado) {
    cout << "No hay ventas activas para mostrar." << endl;
  }
}

void Manager_venta::registrarVenta() {
  int idCliente;
  int posCliente = -1;
  Cliente regCli;

  cout << "=== REGISTRAR NUEVA VENTA ===" << endl;

  do {
    cout << "Ingrese el ID del cliente (0 para cancelar): ";
    cin >> idCliente;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un ID numerico valido." << endl;
      continue;
    }

    if (idCliente == 0) {
      cout << "Operacion cancelada." << endl;
      return;
    }

    if (idCliente < 0) {
      cout << "Error: El ID debe ser mayor a 0." << endl;
      continue;
    }

    posCliente = _archivoClientes.buscar_registro(idCliente);

    if (posCliente < 0) {
      cout << "Error: No existe un cliente registrado con ese ID." << endl;
      continue;
    }

    regCli = _archivoClientes.leer_registro(posCliente);

    if (!regCli.getEstado()) {
      cout << "Error: El cliente ingresado se encuentra dado de baja." << endl;
      continue;
    }

    break;
  } while (true);

  cout << "Cliente: " << regCli.getNombre() << " " << regCli.getApellido()
       << endl;

  int opcionPago;
  do {
    cout << "\nSeleccione Forma de Pago:" << endl;
    cout << "0-EFECTIVO, 1-CREDITO, 2-DEBITO, 3-TRANSFERENCIA" << endl;
    cout << "Ingrese opcion: ";
    cin >> opcionPago;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcionPago = -1;
    }

    if (opcionPago < 0 || opcionPago > 3) {
      cout << "Error: Opcion de pago invalida." << endl;
    }
  } while (opcionPago < 0 || opcionPago > 3);

  cin.ignore(1000, '\n');

  int nuevoIDVenta = _archivoVentas.contar_registros() + 1;
  int itemsCargados = 0;
  float totalTicket = 0;
  char continuar = 's';

  do {
    int idJuego, cantidad;

    cout << "\n--- Agregar juego al ticket ---" << endl;
    cout << "Ingrese ID del juego: ";
    cin >> idJuego;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un ID numerico valido." << endl;
      idJuego = -1;
      continue;
    }

    if (idJuego <= 0) {
      cout << "Error: El ID del juego debe ser mayor a 0." << endl;
      continue;
    }

    int posJuego = _archivoJuegos.buscar_posicion(idJuego);

    if (posJuego < 0) {
      cout << "Error: No existe ningun juego con ese ID." << endl;
      continue;
    }

    Juego regJuego = _archivoJuegos.leer_registro(posJuego);

    if (!regJuego.getEstado()) {
      cout << "Error: El juego seleccionado se encuentra dado de baja." << endl;
      continue;
    } else if (regJuego.getStock().getCantidad() <= 0) {
      cout << "Error: El juego seleccionado no tiene stock disponible." << endl;
      continue;
    }

    float precioVenta = regJuego.getPrecioUnitario();
    Stock stockActual = regJuego.getStock();

    cout << "Juego: " << regJuego.getTitulo() << " | Precio unitario: $"
         << precioVenta << endl;
    stockActual.mostrar();

    do {
      cout << "Ingrese cantidad a vender (mayor a 0): ";
      cin >> cantidad;
      cin.ignore(1000, '\n');

      if (cin.fail()) {
        cin.clear();
        cantidad = -1;
      }

      if (cantidad <= 0) {
        cout << "Error: La cantidad debe ser mayor a 0." << endl;
      } else if (!stockActual.hayStock(cantidad)) {
        cout << "Error: Stock insuficiente." << endl;
        cantidad = 0;
      }
    } while (cantidad <= 0);

    stockActual.descontar(cantidad);
    regJuego.setStock(stockActual);

    if (_archivoJuegos.modificar_registro(regJuego, posJuego)) {
      int nuevoIDDetalle = _archivoDetalles.contar_registros() + 1;

      DetallesVenta detalle(nuevoIDDetalle, nuevoIDVenta, idJuego, cantidad,
                            precioVenta);

      if (_archivoDetalles.grabar_registro(detalle)) {
        itemsCargados++;
        totalTicket += (cantidad * precioVenta);
        cout << "Item agregado correctamente. Subtotal: $"
             << (cantidad * precioVenta) << endl;
      } else {
        cout << "Error al grabar el detalle de venta en disco." << endl;
      }
    } else {
      cout << "Error al actualizar el stock del juego en disco." << endl;
    }

    do {
      cout << "\nDesea agregar otro juego a esta venta? (S/N): ";
      cin >> continuar;

      if (continuar != 's' && continuar != 'S' && continuar != 'n' &&
          continuar != 'N') {
        cout << "Error: Ingrese 'S' para continuar o 'N' para finalizar el "
                "ticket."
             << endl;
      }
    } while (continuar != 's' && continuar != 'S' && continuar != 'n' &&
             continuar != 'N');

  } while (continuar == 's' || continuar == 'S');

  Fecha fechaActual;
  Venta nuevaVenta(nuevoIDVenta, idCliente, fechaActual,
                   static_cast<FormaPago>(opcionPago));

  if (_archivoVentas.grabar_registro(nuevaVenta)) {
    cout << "\n===================================" << endl;
    cout << "VENTA REGISTRADA EXITOSAMENTE" << endl;
    cout << "ID Venta: " << nuevoIDVenta << endl;
    cout << "Fecha: ";
    fechaActual.Mostrar();
    cout << endl;
    cout << "Cantidad de items: " << itemsCargados << endl;
    cout << "Monto total: $" << totalTicket << endl;
    cout << "===================================" << endl;
  } else {
    cout << "Error critico: No se pudo guardar la cabecera de la venta."
         << endl;
  }

  cin.ignore(1000, '\n');
  rlutil::anykey();
}

void Manager_venta::eliminar() {
  int idBuscado;

  do {
    cout << "\n=== ELIMINAR VENTA (BAJA LOGICA) ===" << endl;
    cout << "Ingrese el ID de la venta a dar de baja (0 para cancelar): ";
    cin >> idBuscado;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un numero valido." << endl;
    }

    if (idBuscado == 0) {
      cout << "Operacion cancelada." << endl;
      return;
    }

    if (idBuscado < 0) {
      cout << "Error: El ID debe ser mayor a 0." << endl;
      continue;
    }

    int pos = _archivoVentas.buscar_posicion(idBuscado);

    if (pos < 0) {
      cout << "Error: No se encontro ninguna venta con ese ID." << endl;
      continue;
    }

    Venta reg = _archivoVentas.leer_registro(pos);

    if (!reg.getEstado()) {
      cout << "Error: La venta ya se encuentra dada de baja." << endl;
      continue;
    }

    cout << "\nDatos de la venta a dar de baja:" << endl;
    reg.mostrar();

    char confirmacion;
    do {
      cout << "\nEsta seguro que desea dar de baja esta venta? (S/N): ";
      cin >> confirmacion;

      if (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' &&
          confirmacion != 'N') {
        cout << "Error: Ingrese 'S' para confirmar o 'N' para cancelar."
             << endl;
      }
    } while (confirmacion != 's' && confirmacion != 'S' &&
             confirmacion != 'n' && confirmacion != 'N');

    if (confirmacion == 's' || confirmacion == 'S') {
      if (_archivoVentas.eliminar_registro(pos)) {
        cout << "Venta dada de baja exitosamente." << endl;
      } else {
        cout << "Error al actualizar el estado en disco." << endl;
      }
    } else {
      cout << "Operacion cancelada." << endl;
    }
  } while (true);
}

float Manager_venta::calcularTotalVenta(int idVenta) {
  if (idVenta <= 0)
    return 0;

  int totalDetalles = _archivoDetalles.contar_registros();
  float acumulador = 0;

  for (int i = 0; i < totalDetalles; i++) {
    DetallesVenta det = _archivoDetalles.leer_registro(i);
    if (det.getIDventa() == idVenta && det.getEstado()) {
      acumulador += (det.getCantidad() * det.getPrecioUnitario());
    }
  }

  return acumulador;
}
