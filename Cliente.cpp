#include "Cliente.h"
#include "cargarCadena.h"
#include <cstring>
#include <iostream>
using namespace std;

// Constructores
Cliente::Cliente(long id, bool estado, char dni[9], char nombre[30],
                 char apellido[30], char telefono[20], char email[30]) {
  _id = id;
  _estado = estado;
  strcpy(_dni, dni);
  strcpy(_nombre, nombre);
  strcpy(_apellido, apellido);
  strcpy(_telefono, telefono);
  strcpy(_email, email);
}

Cliente::Cliente() {}

void Cliente::cargar(int id) {
  Persona::cargar();
  _id = id;
  cout << "Numero de telefono" << endl;
  cin >> _telefono;
  cout << "Email: " << endl;
  cargarCadena(_email, 30);
  setEstado(true);
}

// Setters
void Cliente::setID(long id) { _id = id; }
void Cliente::setEstado(bool estado) { _estado = estado; }
void Cliente::setDNI(char dni[9]) { strcpy(_dni, dni); }
void Cliente::setNombre(char nombre[30]) { strcpy(_nombre, nombre); }
void Cliente::setApellido(char apellido[30]) { strcpy(_apellido, apellido); }
void Cliente::setTelefono(char telefono[20]) { strcpy(_telefono, telefono); }
void Cliente::setEmail(char email[30]) { strcpy(_email, email); }

// Getters
long Cliente::getID() { return _id; }
bool Cliente::getEstado() { return _estado; }
char *Cliente::getDNI() { return _dni; }
char *Cliente::getNombre() { return _nombre; }
char *Cliente::getApellido() { return _apellido; }
char *Cliente::getTelefono() { return _telefono; }
char *Cliente::getEmail() { return _email; }

// Mostrar
void Cliente::mostrar() {}
