#include <iostream>
#include "clsFecha.h"
using namespace std;

///Sets
bool Fecha::set_Dia(int dia){
   bool retorno = false;

   if(dia>0 && dia < 32)
    {
    this->dia = dia;

    retorno = true;
    }
   return retorno;
}

bool Fecha::set_Mes(int mes){

    bool retorno = false;

    if(mes>0 && mes<13)
    {
        this->mes = mes;

        retorno = true;
    }

    return retorno;
}

bool Fecha::set_Anio(int anio){

    bool retorno = false;

    if(anio >= 1900)
        {
            this->anio = anio;

            retorno = true;
        }
    return retorno;
}

int Fecha::get_Dia(){

    return dia;
}

int Fecha::get_Mes(){
    return mes;
}

int Fecha::get_Anio(){
    return anio;
}

void Fecha::Cargar(){

   int auxiliar;
    cout<<"DIA: ";
    cin>>auxiliar;
    while(set_Dia(auxiliar)==false)
    {
        cout<< "dia invalido, ingresar fecha valida. " <<endl;
        cin>>auxiliar;
    }

    cout<<"MES: ";
    cin>>auxiliar;
    while(set_Mes(auxiliar)==false)
    {
        cout<<"mes invalido, ingresar fecha valida. " <<endl;
        cin>>auxiliar;
    }

    cout<<"ANIO: ";
    cin>>auxiliar;
    while(set_Anio(auxiliar)==false)
    {
        cout<<"anio invalido, ingresar fecha valida. " <<endl;
        cin>>auxiliar;
    }
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
