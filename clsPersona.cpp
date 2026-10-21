#include<iostream>
#include<cstring>
#include "clsPersona.h"
#include "clsFecha.h"
#include "cargarCadena.h"

using namespace std;

///sets
void Persona::set_dni(int d){
    dni=d;
}

void Persona::set_apellidos(const char *a){
    strcpy(apellidos, a);
}

void Persona::set_nombres(const char *n){
    strcpy(nombres, n);
}

void Persona::set_fecha_nacimiento(Fecha){

}

///gets

int Persona::get_dni(int dni){
    return dni;
}

const char *Persona::get_apellido(){
    return apellidos;
}

const char *Persona::get_nombre(){
    return nombres;
}

Fecha Persona::get_fecha_nacimiento(Fecha fecha_nacimiento){
    return fecha_nacimiento;
}

void Persona::cargar(){
    cout<<"Ingrese el dni: ";
    cin>>dni;
    cout<<"Ingrese el apellido: ";
    cargarCadena(apellidos, 30);
    cout<<"Ingrese el nombre: ";
    cargarCadena(nombres,30);
    cout<<"Ingrese la fecha de nacimiento"<<endl;
    fecha_nacimiento.Cargar();
}

void Persona::mostrar(){
    cout<<"DNI: "<<dni<<endl;
    cout<<"Apellido: "<<apellidos<<endl;
    cout<<"Nombre: "<<nombres<<endl;
    cout<<"Fecha de nacimiento: ";
    fecha_nacimiento.Mostrar();

}

