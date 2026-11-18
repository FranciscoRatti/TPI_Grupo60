#include "menuVentas.h"
#include "manager_venta.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

menuVentas::menuVentas() { setCantidadOpciones(3); }

void menuVentas::mostrarOpcion() {
  rlutil::cls();
  cout << "-------MENU VENTAS-------" << endl;
  cout << "1 - Listas los activos" << endl;
  cout << "2 - Registrar venta" << endl;
  cout << "3 - Eliminar" << endl;
  cout << "0 - Volver" << endl;
}

void menuVentas::ejecutarOpcion(int opcion) {
  Manager_venta v;

  switch (opcion) {
  case 1:
    cin.ignore(10000, '\n');
    v.listarTodos();
    rlutil::anykey();
    break;
  case 2:
    cin.ignore(10000, '\n');
    v.registrarVenta();
    rlutil::anykey();
    break;
  case 3:
    cin.ignore(10000, '\n');
    v.eliminar();
    rlutil::anykey();
    break;
  case 0:
    cout << "volviendo al menu anterior..." << endl;
    rlutil::anykey();
    break;
  }
}
