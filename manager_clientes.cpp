#include <iostream>
#include <cstring>
#include "manager_clientes.h"

using namespace std;

void Manager_cliente::agregar() {
    Cliente reg;
    int nuevoID = _archivo.contar_registros() + 1;

    char dni[9], nombre[30], apellido[30], telefono[20], email[30];

    cout << "=== AGREGAR NUEVO CLIENTE ===" << endl;
    cout << "Ingrese DNI: ";
    cin >> dni;

    int total = _archivo.contar_registros();
    for (int i = 0; i < total; i++) {
        Cliente aux = _archivo.leer_registro(i);
        if (strcmp(aux.getDNI(), dni) == 0 && aux.getEstado()) {
            cout << "Error: El DNI ya esta registrado." << endl;
            return;
        }
    }

    cout << "Ingrese Nombre: ";
    cin >> nombre;
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cout << "Ingrese Email: ";
    cin >> email;

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

void Manager_cliente::consultarPorDNI() {
    char dniBuscado[9];
    cout << "=== CONSULTA DE CLIENTE POR DNI ===" << endl;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dniBuscado;

    int total = _archivo.contar_registros();
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
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun cliente con el DNI ingresado." << endl;
    }
}

void Manager_cliente::consultarPorNombre() {
    char nombreBuscado[30];
    cout << "=== CONSULTA DE CLIENTE POR NOMBRE ===" << endl;
    cout << "Ingrese el Nombre a buscar: ";
    cin >> nombreBuscado;

    int total = _archivo.contar_registros();
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
        cout << "No se encontraron clientes activos con el nombre ingresado." << endl;
    }
}

void Manager_cliente::modificar() {
    int idBuscado;
    cout << "=== MODIFICAR DATOS DE CLIENTE ===" << endl;
    cout << "Ingrese el ID del cliente a modificar: ";
    cin >> idBuscado;

    int pos = _archivo.buscar_registro(idBuscado);

    if (pos < 0) {
        cout << "No existe ningun cliente registrado con ese ID." << endl;
        return;
    }

    Cliente reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
        cout << "El cliente ingresado esta dado de baja. No se puede modificar." << endl;
        return;
    }

    cout << "\nDatos actuales del cliente:" << endl;
    reg.mostrar();

    char nuevoTelefono[20], nuevoEmail[30];
    cout << "\nIngrese el nuevo telefono: ";
    cin >> nuevoTelefono;
    cout << "Ingrese el nuevo email: ";
    cin >> nuevoEmail;

    reg.setTelefono(nuevoTelefono);
    reg.setEmail(nuevoEmail);

    if (_archivo.modificar_cliente(reg, pos)) {
        cout << "Registro modificado correctamente." << endl;
    } else {
        cout << "Error al actualizar los datos en el archivo." << endl;
    }
}

void Manager_cliente::eliminar() {
    int idBuscado;
    cout << "=== ELIMINAR CLIENTE (BAJA LOGICA) ===" << endl;
    cout << "Ingrese el ID del cliente a dar de baja: ";
    cin >> idBuscado;

    int pos = _archivo.buscar_registro(idBuscado);

    if (pos < 0) {
        cout << "No se encontro el cliente solicitado." << endl;
        return;
    }

    Cliente reg = _archivo.leer_registro(pos);

    if (!reg.getEstado()) {
        cout << "El cliente ya se encuentra dado de baja." << endl;
        return;
    }

    cout << "\nDatos del cliente a dar de baja:" << endl;
    reg.mostrar();

    char confirmacion;
    cout << "\nEsta seguro que desea dar de baja este cliente? (S/N): ";
    cin >> confirmacion;

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
}

void Manager_cliente::listarTodos() {
    cout << "=== LISTADO DE CLIENTES ACTIVOS ===" << endl;
    _archivo.listar_registros();
}
