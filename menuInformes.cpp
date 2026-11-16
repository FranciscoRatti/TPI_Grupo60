#include "menuInformes.h"
#include "Informe.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

menuInformes::menuInformes() { setCantidadOpciones(6); }

void menuInformes::mostrarOpcion() {
  rlutil::cls();
  cout << "-------INFORMES-------" << endl;
  cout << "1 - Juegos vendidos por genero" << endl;
  cout << "2 - Juegos mas vendidos" << endl;
  cout << "3 - Ventas por cliente" << endl;
  cout << "4 - Genero mas vendido por cliente" << endl;
  cout << "5 - Stock por clasificacion" << endl;
  cout << "6 - Porcentaje de ventas por metodo de pago" << endl;
  cout << "0 - Volver" << endl;
}

void menuInformes::ejecutarOpcion(int opcion) {
  Informe informe;

  switch (opcion) {
  case 1:
    informe.juegosPorGenero();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 2:
    informe.juegosMasVendidos();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 3:
    informe.ventasPorCliente();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 4:
    informe.generoMasVendidoPorCliente();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 5:
    informe.stockPorClasificacion();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 6:
    informe.ventasPorMetodoDePago();
    cin.ignore(1000, '\n');
    rlutil::anykey();
    break;
  case 0:
    cout << "volviendo al menu anterior..." << endl;
    rlutil::anykey();
    break;
  }
}
