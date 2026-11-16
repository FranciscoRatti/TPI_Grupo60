#include <iostream>
#include <cstring>
#include "Cliente.h"

using namespace std;

Cliente::Cliente()
{
    _id = 0;
    _estado = false;
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
}

Cliente::Cliente(long id, bool estado, char dni[9], char nombre[30],
                 char apellido[30], char telefono[20], char email[30])
{
    _id = id;
    _estado = estado;
    strcpy(_dni, dni);
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
}

void Cliente::setID(long id)
{
    _id = id;
}
void Cliente::setEstado(bool estado)
{
    _estado = estado;
}
void Cliente::setDNI(char dni[9])
{
    strcpy(_dni, dni);
}
void Cliente::setNombre(char nombre[30])
{
    strcpy(_nombre, nombre);
}
void Cliente::setApellido(char apellido[30])
{
    strcpy(_apellido, apellido);
}
void Cliente::setTelefono(char telefono[20])
{
    strcpy(_telefono, telefono);
}
void Cliente::setEmail(char email[30])
{
    strcpy(_email, email);
}

long Cliente::getID()
{
    return _id;
}
bool Cliente::getEstado()
{
    return _estado;
}
char *Cliente::getDNI()
{
    return _dni;
}
char *Cliente::getNombre()
{
    return _nombre;
}
char *Cliente::getApellido()
{
    return _apellido;
}
char *Cliente::getTelefono()
{
    return _telefono;
}
char *Cliente::getEmail()
{
    return _email;
}

void Cliente::mostrar()
{
    if (_estado)
    {
        cout << "ID: " << _id << endl;
        cout << "DNI: " << _dni << endl;
        cout << "Nombre: " << _nombre << endl;
        cout << "Apellido: " << _apellido << endl;
        cout << "Telefono: " << _telefono << endl;
        cout << "Email: " << _email << endl;
    }
    else
    {
        cout << "El cliente se encuentra dado de baja." << endl;
    }
}
