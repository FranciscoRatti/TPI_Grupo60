#include<iostream>
#include<cstring>
#include "clsEmpleados.h"
#include "clsPersona.h"
#include "cargarCadena.h"

using namespace std;
///Sets

void Empleados::set_id_empleado(int id_empleado){
    this-> id_empleado = id_empleado;
}

void Empleados::set_numero_telefono(int numero_telefono){
    this-> numero_telefono = numero_telefono;
}

void Empleados::set_email(const char *email){
    strcpy(this-> email, email);
}

/// validacion convertida a bool ---------------------------------------------------------------------------------------------

bool Empleados::set_sueldo(float sueldo){

    bool retorno = false;

    if(sueldo >0)
        {
          this-> sueldo = sueldo;
          retorno = true;
        }
          return retorno;
}
 ///-------------------------------------------------------------------------------------------------------------------------
void Empleados::set_direccion(const char *direccion){
    strcpy(this-> direccion, direccion);
}

void Empleados::set_estado(bool estado)
{
    this-> estado = estado;
}

///Gets

int Empleados::get_id_empleado()
{
    return id_empleado;
}

int Empleados::get_numero_telefono()
{
    return numero_telefono;
}

const char *Empleados::get_email()
{
    return email;
}

float Empleados::get_sueldo()
{
    return sueldo;
}

const char *Empleados::get_direccion()
{
    return direccion;
}

bool Empleados::get_estado()
{
    return estado;
}

///Voidsitos

void Empleados::cargar(int id){
    Persona::cargar();
    id_empleado=id;
    cout<< "Telefono: ";
    cin>> numero_telefono;
    cout<< "Email: ";
    cargarCadena(email,30);
    cout<< "Sueldo: ";
    cin>> sueldo;
    while(set_sueldo(sueldo) == false){
    cout<< "ingresar sueldo valido. " <<endl;
    cin>> sueldo;
    }
    cout<< "Direccion: ";
    cargarCadena(direccion,30);
    estado=true;
}

void Empleados::mostrar(){
    Persona::mostrar();
    cout<<endl;
    cout<< "ID: " << id_empleado << endl;
    cout<< "Telefono: " << numero_telefono << endl;
    cout<< "EMail: " << email << endl;
    cout<< "Sueldo: " << sueldo << endl;
    cout<< "Direccion: " << direccion << endl;
}
