#include "menuJuegos.h"
#include "manager_juegos.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

menuJuegos::menuJuegos() { setCantidadOpciones(7); }

void menuJuegos::mostrarOpcion() {
  rlutil::cls();
  cout << "-------MENU JUEGOS-------" << endl;
  cout << "1 - Consultar por titulo" << endl;
  cout << "2 - Consultar por precio" << endl;
  cout << "3 - Listar los activos" << endl;
  cout << "4 - Listar los inactivos" << endl;
  cout << "5 - Modificar" << endl;
  cout << "6 - Agregar" << endl;
  cout << "7 - Eliminar" << endl;
  cout << "0 - Volver" << endl;
}

void menuJuegos::ejecutarOpcion(int opcion) {
  Manager_juego j;

  switch (opcion) {
  case 1:
    cin.ignore(10000, '\n');
    j.consultarPorTitulo();
    rlutil::anykey();
    break;
  case 2:
    cin.ignore(10000, '\n');
    j.consultarPorPrecio();
    rlutil::anykey();
    break;
  case 3:
    cin.ignore(10000, '\n');
    j.listarTodos(true);
    rlutil::anykey();
    break;
  case 4:
    cin.ignore(10000, '\n');
    j.listarTodos(false);
    rlutil::anykey();
    break;
  case 5:
    j.modificar();
    break;
  case 6:
    j.agregar();
    break;
  case 7:
    j.eliminar();
    break;
  case 0:
    cout << "volviendo al menu anterior..." << endl;
    rlutil::anykey();
    break;
  }
}
