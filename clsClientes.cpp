#include<iostream>
#include <cstring>
#include "clsClientes.h"
#include "cargarCadena.h"
using namespace std;

///SETS

void Clientes::set_id_cliente(int id){
    id_cliente=id;
}

void Clientes::set_numero_telefono(int t){
    numero_telefono=t;
}

void Clientes::set_email(const char* e){
    strcpy(email,e);
}

void Clientes::set_estado(bool e){
    estado=e;
}


///gets

int Clientes::get_id_cliente(){
    return id_cliente;
}

int Clientes::get_numero_telefono(){
    return numero_telefono;
}

const char *Clientes::get_email(){
    return email;
}

bool Clientes::get_estado(){
    return estado;
}



void Clientes::cargar(int id){
    Persona::cargar();
    id_cliente=id;
    cout<<"Numero de telefono"<<endl;
    cin>>numero_telefono;
    cout<<"Email: "<<endl;
    cargarCadena(email, 30);
    set_estado(true);
}

void Clientes::mostrar(){
    Persona::mostrar();
    cout<<endl;
    cout<<"Id de cliente: "<<id_cliente<<endl;
    cout<<"Numero de telefono: "<<numero_telefono<<endl;
    cout<<"Email: "<<email<<endl;
}

