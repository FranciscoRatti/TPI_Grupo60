#include "manager_clientes.h"
#include "Funciones.h"
#include <cstring>
#include <iostream>

using namespace std;

void Manager_cliente::consultarPorDNI() {
  cout << "=== CONSULTA DE CLIENTE POR DNI ===" << endl;

  int total = _archivo.contar_registros();
  if (total <= 0) {
    cout << "No hay clientes registrados en el sistema." << endl;
    return;
  }

  char dniBuscado[9];
  cout << "Ingrese el DNI a buscar: ";
  cargarCadena(dniBuscado, 9);

  bool encontrado = false;

  for (int i = 0; i < total; i++) {
    Cliente reg = _archivo.leer_registro(i);
    if (strcmp(reg.getDNI(), dniBuscado) == 0) {
      encontrado = true;
      if (reg.getEstado()) {
        cout << "\nCliente encontrado:" << endl;
        reg.mostrar();
      } else {
        cout << "El cliente existe pero se encuentra dado de baja." << endl;
        reg.mostrar();
      }
      break;
    }
  }

  if (!encontrado) {
    cout << "No se encontro ningun cliente con el DNI ingresado." << endl;
  }
}

void Manager_cliente::consultarPorNombre() {
  cout << "=== CONSULTA DE CLIENTE POR NOMBRE ===" << endl;

  int total = _archivo.contar_registros();
  if (total <= 0) {
    cout << "No hay clientes registrados en el sistema." << endl;
    return;
  }

  char nombreBuscado[30];
  cout << "Ingrese el Nombre a buscar (sin espacios): ";
  cargarCadena(nombreBuscado, 9);
  cin.ignore(1000, '\n');

  bool encontrado = false;

  for (int i = 0; i < total; i++) {
    Cliente reg = _archivo.leer_registro(i);
    if (reg.getEstado() && strstr(reg.getNombre(), nombreBuscado) != NULL) {
      cout << "\n----------------------------" << endl;
      reg.mostrar();
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No se encontraron clientes activos con el nombre ingresado."
         << endl;
  }
}

void Manager_cliente::listarTodos() {
  cout << "=== LISTADO DE CLIENTES ===" << endl;
  int total = _archivo.contar_registros();
  bool hayActivos = false;

  for (int i = 0; i < total; i++) {
    Cliente reg = _archivo.leer_registro(i);
    if (reg.getEstado()) {
      hayActivos = true;
      break;
    }
  }

  if (!hayActivos) {
    cout << "No hay clientes activos registrados en el sistema." << endl;
    return;
  }

  _archivo.listar_registros();
}

void Manager_cliente::modificar() {
  int idBuscado, opcion;

  do {
    cout << "\n=== MODIFICAR DATOS DE CLIENTE ===" << endl;
    cout << "Ingrese el ID del cliente a modificar (0 para salir): ";
    cin >> idBuscado;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un numero valido." << endl;
      idBuscado = -1;
      continue;
    }

    if (idBuscado == 0) {
      return;
    }

    if (idBuscado < 0) {
      cout << "Error: El ID debe ser mayor a 0." << endl;
      continue;
    }

    int pos = _archivo.buscar_registro(idBuscado);

    if (pos < 0) {
      cout << "Error: No existe ningun cliente registrado con ese ID." << endl;
      continue;
    }

    Cliente reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
      cout << "Error: El cliente ingresado esta dado de baja. No se puede "
              "modificar."
           << endl;
      continue;
    }

    cout << "\nDatos actuales del cliente:" << endl;
    reg.mostrar();

    do {
      cout << "\nQue campo desea modificar?" << endl;
      cout << "1 - Telefono" << endl;
      cout << "2 - Email" << endl;
      cout << "0 - Cancelar y elegir otro ID" << endl;
      cout << "Opcion: ";
      cin >> opcion;

      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        opcion = -1;
      }

      if (opcion < 0 || opcion > 2) {
        cout << "Error: Opcion invalida." << endl;
      }
    } while (opcion < 0 || opcion > 2);

    switch (opcion) {
    case 1: {
      char nuevoTelefono[20];
      bool telValido = false;

      do {
        cout << "Ingrese el nuevo telefono celular (solo numeros, minimo 10 "
                "digitos): ";
        cin >> nuevoTelefono;

        int largo = strlen(nuevoTelefono);
        bool soloNumeros = true;
        for (int i = 0; i < largo; i++) {
          if (nuevoTelefono[i] < '0' || nuevoTelefono[i] > '9') {
            soloNumeros = false;
            break;
          }
        }

        if (!soloNumeros || largo < 10) {
          cout << "Error: El telefono debe contener al menos 10 digitos "
                  "numericos."
               << endl;
        } else {
          telValido = true;
        }
      } while (!telValido);

      reg.setTelefono(nuevoTelefono);

      if (_archivo.modificar_cliente(reg, pos)) {
        cout << "Telefono actualizado correctamente." << endl;
      } else {
        cout << "Error al actualizar los datos en el archivo." << endl;
      }
      break;
    }
    case 2: {
      char nuevoEmail[30];
      bool emailValido = false;

      do {
        cout << "Ingrese el nuevo email: ";
        cin >> nuevoEmail;

        if (strchr(nuevoEmail, '@') == NULL ||
            strchr(nuevoEmail, '.') == NULL) {
          cout << "Error: Ingrese un email valido (debe contener '@' y '.')."
               << endl;
        } else {
          emailValido = true;
        }
      } while (!emailValido);

      reg.setEmail(nuevoEmail);

      if (_archivo.modificar_cliente(reg, pos)) {
        cout << "Email actualizado correctamente." << endl;
      } else {
        cout << "Error al actualizar los datos en el archivo." << endl;
      }
      break;
    }
    }
  } while (idBuscado != 0);
}

void Manager_cliente::agregar() {
  Cliente reg;
  int nuevoID = _archivo.contar_registros() + 1;

  char dni[9], nombre[30], apellido[30], telefono[20], email[30];

  cout << "=== AGREGAR NUEVO CLIENTE ===" << endl;

  bool dniValido = false;
  do {
    cout << "Ingrese DNI (8 digitos sin puntos): ";
    cin >> dni;

    int largo = strlen(dni);
    bool soloNumeros = true;
    for (int i = 0; i < largo; i++) {
      if (dni[i] < '0' || dni[i] > '9') {
        soloNumeros = false;
        break;
      }
    }

    if (!soloNumeros || largo != 8) {
      cout << "Error: El DNI debe contener 8 digitos numericos." << endl;
    } else {
      dniValido = true;
    }
  } while (!dniValido);

  int total = _archivo.contar_registros();
  for (int i = 0; i < total; i++) {
    Cliente aux = _archivo.leer_registro(i);
    if (strcmp(aux.getDNI(), dni) == 0) {
      cout << "Error: El DNI ya se encuentra registrado en el sistema." << endl;
      return;
    }
  }

  cout << "Ingrese Nombre (sin espacios): ";
  cin >> nombre;
  cout << "Ingrese Apellido (sin espacios): ";
  cin >> apellido;

  bool telValido = false;
  do {
    cout << "Ingrese Telefono celular (solo numeros, minimo 10 digitos): ";
    cin >> telefono;

    int largo = strlen(telefono);
    bool soloNumeros = true;
    for (int i = 0; i < largo; i++) {
      if (telefono[i] < '0' || telefono[i] > '9') {
        soloNumeros = false;
        break;
      }
    }

    if (!soloNumeros) {
      cout << "Error: El telefono admite solo digitos numericos." << endl;
    } else if (largo < 10) {
      cout << "Error: El telefono debe contener al menos 10 digitos." << endl;
    } else {
      telValido = true;
    }
  } while (!telValido);

  bool emailValido = false;
  do {
    cout << "Ingrese Email: ";
    cin >> email;

    if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
      cout << "Error: Ingrese un email valido (debe contener '@' y '.')."
           << endl;
    } else {
      emailValido = true;
    }
  } while (!emailValido);

  reg.setID(nuevoID);
  reg.setDNI(dni);
  reg.setNombre(nombre);
  reg.setApellido(apellido);
  reg.setTelefono(telefono);
  reg.setEmail(email);
  reg.setEstado(true);

  if (_archivo.grabar_registro(reg)) {
    cout << "Cliente registrado exitosamente con ID: " << nuevoID << endl;
  } else {
    cout << "Error al intentar guardar en disco." << endl;
  }
}

void Manager_cliente::eliminar() {
  int idBuscado;

  do {
    cout << "\n=== ELIMINAR CLIENTE (BAJA LOGICA) ===" << endl;
    cout << "Ingrese el ID del cliente a dar de baja (0 para cancelar): ";
    cin >> idBuscado;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Error: Debe ingresar un numero valido." << endl;
      idBuscado = -1;
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

    int pos = _archivo.buscar_registro(idBuscado);

    if (pos < 0) {
      cout << "Error: No se encontro el cliente solicitado." << endl;
      continue;
    }

    Cliente reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
      cout << "Error: El cliente ya se encuentra dado de baja." << endl;
      continue;
    }

    cout << "\nDatos del cliente a dar de baja:" << endl;
    reg.mostrar();

    char confirmacion;
    do {
      cout << "\nEsta seguro que desea dar de baja este cliente? (S/N): ";
      cin >> confirmacion;

      if (confirmacion != 's' && confirmacion != 'S' && confirmacion != 'n' &&
          confirmacion != 'N') {
        cout << "Error: Ingrese 'S' para confirmar o 'N' para cancelar."
             << endl;
      }
    } while (confirmacion != 's' && confirmacion != 'S' &&
             confirmacion != 'n' && confirmacion != 'N');

    if (confirmacion == 's' || confirmacion == 'S') {
      reg.setEstado(false);
      if (_archivo.modificar_cliente(reg, pos)) {
        cout << "Cliente dado de baja exitosamente." << endl;
      } else {
        cout << "Error al actualizar el estado en disco." << endl;
      }
    } else {
      cout << "Operacion cancelada." << endl;
    }

    return;
  } while (true);
}
