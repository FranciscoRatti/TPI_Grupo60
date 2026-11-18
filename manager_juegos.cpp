#include "manager_juegos.h"
#include "Archivo_Juegos.h"
#include "Funciones.h"
#include "Juego.h"
#include "rlutil.h"
#include <cstring>
#include <iostream>

using namespace std;

void Manager_juego::consultarPorTitulo() {
  char tituloBuscado[30];

  cout << "=== CONSULTA DE JUEGO POR TITULO ===" << endl;

  do {
    cout << "Ingrese el titulo a buscar: ";
    cargarCadena(tituloBuscado, 29);

    if (strlen(tituloBuscado) == 0) {
      cout << "Error: Debe ingresar al menos un caracter." << endl;
    }
  } while (strlen(tituloBuscado) == 0);

  int total = _archivo.contar_Registros();

  if (total < 0) {
    cout << "Error al abrir el archivo de juegos." << endl;
    return;
  }

  bool encontrado = false;

  for (int i = 0; i < total; i++) {
    Juego reg = _archivo.leer_registro(i);

    if (reg.getEstado() && strstr(reg.getTitulo(), tituloBuscado) != NULL) {
      cout << "\n-----------------------------------" << endl;
      reg.mostrar();
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No se encontraron juegos activos con ese titulo." << endl;
  }
}

void Manager_juego::consultarPorPrecio() {
  float precioMaximo;

  cout << "=== CONSULTA DE JUEGOS POR PRECIO ===" << endl;

  do {
    cout << "Ingrese el precio maximo a buscar (mayor a 0): ";
    cin >> precioMaximo;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      precioMaximo = -1;
    }

    if (precioMaximo <= 0) {
      cout << "Error: El precio debe ser mayor a 0." << endl;
    }
  } while (precioMaximo <= 0);

  int total = _archivo.contar_Registros();

  if (total < 0) {
    cout << "Error al abrir el archivo de juegos." << endl;
    return;
  }

  bool encontrado = false;

  cout << "\n--- Resultados de busqueda ---" << endl;

  for (int i = 0; i < total; i++) {
    Juego reg = _archivo.leer_registro(i);

    if (reg.getEstado() && reg.getPrecioUnitario() <= precioMaximo) {
      cout << "-----------------------------------" << endl;
      reg.mostrar();
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No se encontraron juegos por debajo de ese precio." << endl;
  }

  cin.ignore(10000, '\n');
}

void Manager_juego::listarTodos(bool mostrarActivos) {
  cout << "=== LISTADO DE JUEGOS ===" << endl;

  int total = _archivo.contar_Registros();

  if (total < 0) {
    cout << "Error al abrir el archivo de juegos." << endl;
    return;
  }

  if (total == 0) {
    cout << "No hay juegos registrados." << endl;
    return;
  }

  bool encontrado = false;

  for (int i = 0; i < total; i++) {
    Juego reg = _archivo.leer_registro(i);

    if (reg.getEstado() == mostrarActivos) {
      cout << "-----------------------------------" << endl;
      reg.mostrar();
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No hay juegos activos para mostrar." << endl;
  }
}

void Manager_juego::modificar() {
  int idBuscado, opcion;

  do {
    cout << "\n=== MODIFICAR DATOS DE JUEGO ===" << endl;
    cout << "Ingrese el ID del juego a modificar (0 para salir): ";
    cin >> idBuscado;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un numero valido." << endl;
      continue;
    }

    if (idBuscado == 0) {
      return;
    }

    if (idBuscado < 0) {
      cout << "Error: El ID debe ser mayor a 0." << endl;
      continue;
    }

    int pos = _archivo.buscar_posicion(idBuscado);

    if (pos < 0) {
      cout << "Error: No existe ningun juego registrado con ese ID." << endl;
      continue;
    }

    Juego reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
      cout << "Error: El juego ingresado esta dado de baja." << endl;
      continue;
    }

    cout << "\nDatos actuales del juego:" << endl;
    reg.mostrar();

    cout << "\nQue campo desea modificar?" << endl;
    cout << "1 - Precio" << endl;
    cout << "2 - Cantidad de stock" << endl;
    cout << "3 - Stock minimo" << endl;
    cout << "0 - Cancelar y elegir otro ID" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcion = -1;
    }

    switch (opcion) {
    case 1: {
      float nuevoPrecio;

      do {
        cout << "Ingrese nuevo precio (mayor a 0): $";
        cin >> nuevoPrecio;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000, '\n');
          nuevoPrecio = -1;
        }

        if (nuevoPrecio <= 0) {
          cout << "Error: El precio no puede ser negativo o cero." << endl;
        }
      } while (nuevoPrecio <= 0);

      reg.setPrecioUnitario(nuevoPrecio);

      if (_archivo.modificar_registro(reg, pos)) {
        cout << "Precio actualizado correctamente." << endl;
      } else {
        cout << "Error al grabar los datos." << endl;
      }
      break;
    }
    case 2: {
      int nuevoStock;

      do {
        cout << "Ingrese nuevo stock (mayor o igual a 0): ";
        cin >> nuevoStock;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000, '\n');
          nuevoStock = -1;
        }

        if (nuevoStock < 0) {
          cout << "Error: El stock no puede ser negativo." << endl;
        }
      } while (nuevoStock < 0);

      reg.setStock(nuevoStock);

      if (_archivo.modificar_registro(reg, pos)) {
        cout << "Stock actualizado correctamente." << endl;
      } else {
        cout << "Error al grabar los datos." << endl;
      }
      break;
    }
    case 3: {
      int nuevoMinimo;

      do {
        cout << "Ingrese nuevo stock minimo (mayor o igual a 0): ";
        cin >> nuevoMinimo;

        if (cin.fail()) {
          cin.clear();
          cin.ignore(1000, '\n');
          nuevoMinimo = -1;
        }

        if (nuevoMinimo < 0) {
          cout << "Error: El stock minimo no puede ser negativo." << endl;
        }
      } while (nuevoMinimo < 0);

      Stock stockActual = reg.getStock();
      stockActual.setStockMinimo(nuevoMinimo);
      reg.setStock(stockActual);

      if (_archivo.modificar_registro(reg, pos)) {
        cout << "Stock minimo actualizado correctamente." << endl;
      } else {
        cout << "Error al grabar los datos." << endl;
      }
      break;
    }
    default:
      cout << "Error: Opcion incorrecta." << endl;
    }
  } while (true);
}

void Manager_juego::agregar() {
  Juego reg;

  int total = _archivo.contar_Registros();

  if (total < 0) {
    total = 0;
  }

  int nuevoID = total + 1;

  char titulo[30], desarrollador[30];
  float precio;
  int opcionStock, stockMinimo;
  int opcionGenero, opcionClasificacion, opcionPlataforma;

  cout << "=== AGREGAR NUEVO JUEGO ===" << endl;

  do {
    cout << "Ingrese el Titulo: ";
    cargarCadena(titulo, 29);

    if (strlen(titulo) == 0) {
      cout << "Error: El titulo no puede estar vacio." << endl;
    }
  } while (strlen(titulo) == 0);

  do {
    cout << "Ingrese el Desarrollador: ";
    cargarCadena(desarrollador, 29);

    if (strlen(desarrollador) == 0) {
      cout << "Error: El desarrollador no puede estar vacio." << endl;
    }
  } while (strlen(desarrollador) == 0);

  do {
    cout << "Ingrese el Precio Unitario (mayor a 0): ";
    cin >> precio;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      precio = -1;
    }

    if (precio <= 0) {
      cout << "Error: El precio debe ser mayor a 0." << endl;
    }
  } while (precio <= 0);

  do {
    cout << "Ingrese Stock inicial (mayor o igual a 0): ";
    cin >> opcionStock;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcionStock = -1;
    }

    if (opcionStock < 0) {
      cout << "Error: El stock no puede ser negativo." << endl;
    }
  } while (opcionStock < 0);

  do {
    cout << "Ingrese Stock minimo (mayor o igual a 0): ";
    cin >> stockMinimo;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      stockMinimo = -1;
    }

    if (stockMinimo < 0) {
      cout << "Error: El stock minimo no puede ser negativo." << endl;
    }
  } while (stockMinimo < 0);

  do {
    cout << "Seleccione Genero:" << endl;
    cout << "0-RPG, 1-ACCION, 2-AVENTURA, 3-SIGILO" << endl;
    cout << "4-DEPORTES, 5-ROGUELITE, 6-SOUL, 7-SANDBOX" << endl;
    cout << "8-PLATAFORMERO, 9-FPS, 10-BRAWLER, 11-FIGHTER" << endl;
    cout << "12-MUNDO_ABIERTO, 13-ESTRATEGIA, 14-GRANJAS" << endl;
    cout << "15-TERROR, 16-PUZZLE, 17-INCREMENTAL" << endl;
    cout << "18-SIMULADOR, 19-RACING" << endl;

    cout << "Ingrese opcion: ";
    cin >> opcionGenero;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcionGenero = -1;
    }

    if (opcionGenero < 0 || opcionGenero > 19) {
      cout << "Error: Genero invalido." << endl;
    }
  } while (opcionGenero < 0 || opcionGenero > 19);

  do {
    cout << "Seleccione Clasificacion:" << endl;
    cout << "0-EVERYONE, 1-EVERYONE_10, 2-TEEN" << endl;
    cout << "3-MATURE, 4-ADULTS_ONLY, 5-RATING_PENDING" << endl;

    cout << "Ingrese opcion: ";
    cin >> opcionClasificacion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcionClasificacion = -1;
    }

    if (opcionClasificacion < 0 || opcionClasificacion > 5) {
      cout << "Error: Clasificacion invalida." << endl;
    }
  } while (opcionClasificacion < 0 || opcionClasificacion > 5);

  do {
    cout << "Seleccione Plataforma:" << endl;
    cout << "0-PC, 1-PLAYSTATION, 2-XBOX, 3-NINTENDO_SWITCH" << endl;

    cout << "Ingrese opcion: ";
    cin >> opcionPlataforma;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcionPlataforma = -1;
    }

    if (opcionPlataforma < 0 || opcionPlataforma > 3) {
      cout << "Error: Plataforma invalida." << endl;
    }
  } while (opcionPlataforma < 0 || opcionPlataforma > 3);

  Stock stockInicial(opcionStock, stockMinimo);

  reg.setId(nuevoID);
  reg.setTitulo(titulo);
  reg.setDesarrollador(desarrollador);
  reg.setPrecioUnitario(precio);
  reg.setStock(stockInicial);

  reg.setGenero(static_cast<Genero>(opcionGenero));
  reg.setClasificacion(static_cast<Clasificacion>(opcionClasificacion));
  reg.setPlataforma(static_cast<Plataforma>(opcionPlataforma));

  reg.setEstado(true);

  if (_archivo.Agregar_Juegos(reg)) {
    cout << "Juego registrado exitosamente con ID: " << nuevoID << endl;
  } else {
    cout << "Error al intentar guardar en disco." << endl;
  }
  cin.ignore(1000, '\n');
  rlutil::anykey("Presione una tecla para continuar...");
}

void Manager_juego::eliminar() {
  int idBuscado;

  do {
    cout << "\n=== ELIMINAR JUEGO (BAJA LOGICA) ===" << endl;
    cout << "Ingrese el ID del juego a dar de baja (0 para cancelar): ";
    cin >> idBuscado;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un numero valido." << endl;
      continue;
    }

    if (idBuscado == 0) {
      cout << "Operacion cancelada." << endl;
      return;
    }

    if (idBuscado < 0) {
      cout << "Error: El ID debe ser mayor a 0." << endl;
      continue;
    }

    int pos = _archivo.buscar_posicion(idBuscado);

    if (pos < 0) {
      cout << "Error: No se encontro ningun juego con ese ID." << endl;
      continue;
    }

    Juego reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
      cout << "Error: El juego ya se encuentra dado de baja." << endl;
      continue;
    }

    cout << "\nDatos del juego a dar de baja:" << endl;
    reg.mostrar();

    char confirmacion;
    do {
      cout << "\nEsta seguro que desea dar de baja este juego? (S/N): ";
      cin >> confirmacion;

      if (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' &&
          confirmacion != 'N') {
        cout << "Error: Ingrese 'S' para confirmar o 'N' para cancelar."
             << endl;
      }
    } while (confirmacion != 's' && confirmacion != 'S' &&
             confirmacion != 'n' && confirmacion != 'N');

    if (confirmacion == 's' || confirmacion == 'S') {
      if (_archivo.eliminar_registro(pos)) {
        cout << "Juego dado de baja exitosamente." << endl;
      } else {
        cout << "Error al actualizar el estado en disco." << endl;
      }
    } else {
      cout << "Operacion cancelada." << endl;
    }

    return;
  } while (true);
}
