#include "menuJuegos.h"
#include "manager_juegos.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

menuJuegos::menuJuegos() { setCantidadOpciones(6); }

void menuJuegos::mostrarOpcion() {
  rlutil::cls();
  cout << "-------MENU JUEGOS-------" << endl;
  cout << "1 - Consultar por titulo" << endl;
  cout << "2 - Consultar por precio" << endl;
  cout << "3 - Listar los activos" << endl;
  cout << "4 - Modificar" << endl;
  cout << "5 - Agregar" << endl;
  cout << "6 - Eliminar" << endl;
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
    j.listarTodos();
    rlutil::anykey();
    break;
  case 4:
    j.modificar();
    break;
  case 5:
    j.agregar();
    break;
  case 6:
    j.eliminar();
    break;
  case 0:
    cout << "volviendo al menu anterior..." << endl;
    rlutil::anykey();
    break;
  }
}
