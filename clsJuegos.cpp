#include<iostream>
#include<cstring>
#include "clsJuegos.h"
#include "cargarCadena.h"
#include "generos.h"

using namespace std;
///SETS---------------------------------------------------------------------------------------------------------------------------

void Juegos::set_codigo_articulo(int codA)
{
  codigo_articulo=codA;
}

void Juegos::set_nombre(const char *n)
{
    strcpy(nombre,n);
}

bool Juegos::set_genero(int genero){
    bool retorno=false;

    if(genero>0 && genero<21){
        this->genero=genero;
        retorno=true;
    }
    return retorno;
}

void Juegos::set_desarrolladora(const char *d)
{

strcpy(desarrolladora, d);

}

bool Juegos::set_precio_unitario(float precio)
{
    bool retorno=false;
    if(precio>0){
        this->precio_unitario=precio;
        retorno=true;
    }
    return retorno;
}

void Juegos::set_publisher(const char *p)
{

strcpy(publisher, p);

}

void Juegos::set_fecha_lanzamiento(Fecha fL)
{

fecha_lanzamiento=fL;

}

bool Juegos::set_clasificacion(int clasificacion){
    bool retorno=false;
    if(clasificacion>0 && clasificacion<6){
        this->clasificacion=clasificacion;
        retorno=true;
    }
    return retorno;
}


void Juegos::set_digital(bool d)
{
    digital=d;
}

bool Juegos::set_cantidad(int cantidad){
    bool retorno=false;
    if(cantidad>=0){
        this->cantidad=cantidad;
        retorno=true;
    }
    return retorno;
}

void Juegos::set_estado(bool bP)
{

estado=bP;

}

///GETS---------------------------------------------------------------------------------------------------------------------------

int Juegos::get_codigo_articulo()
{
    return codigo_articulo;
}

const char* Juegos::get_nombre()
{
    return nombre;
}

const char* Juegos::get_genero(int genero)
{
    return GENERO[genero];
}

int Juegos::get_genero()
{
    return genero;
}

const char *Juegos::get_desarrolladora()
{
    return desarrolladora;
}

float Juegos::get_precio_unitario()
{
    return precio_unitario;
}

const char *Juegos::get_publisher()
{
    return publisher;
}

Fecha Juegos::get_fecha_lanzamiento(Fecha)
{
    return fecha_lanzamiento;
}

bool Juegos::get_digital(bool digital)
{
    return digital;
}

int Juegos::get_cantidad()
{
    return cantidad;
}


bool Juegos::get_estado()
{
    return estado;
}

void Juegos::cargar(int codigo_articulo)
{
    this->codigo_articulo=codigo_articulo;

    cout<<" nombre: ";

    cargarCadena(nombre,30);

    cout<<" genero: ";
    for(int i=0; i<20; i++)
        {
            cout<<"|"<<i+1<<".";
            cout<<GENERO[i];
        }
    cout<<"|"<<endl;
    cin>>genero;

    while(set_genero(genero)==false)
    {
        cout<<"Ingrese un numero de genero valido: ";
        cin>>genero;
    }

    cout<<" desarolladora: ";

    cargarCadena(desarrolladora,30);

    cout<< " precio unitario: ";
    cin>> precio_unitario;

    while(set_precio_unitario(precio_unitario)==false)
        {
        cout<<"Ingrese un precio valido: ";
        cin>>precio_unitario;
    }

    cout<< " publisher: ";

    cargarCadena(publisher,30);

    cout<< " fecha: ";

    fecha_lanzamiento.Cargar();

    cout<<" Clasificacion: ";
    for(int i=0; i<5; i++)
    {
        cout<<"|"<<i+1<<"=";
        cout<<CLASIFICACION[i];
    }
    cout<<"|"<<endl;
    cin>>clasificacion;

    while(set_clasificacion(clasificacion)==false)
    {
        cout<<"Ingrese un numero de clasificacion valido: ";
        cin>>clasificacion;
    }

    cout<< "¿Se trata de una copia digital o fisica?(1.digital - 0.fisica): ";
    cin>> digital;

    cout<<"Ingrese la cantidad de copias: ";
    cin>>cantidad;
    while(set_cantidad(cantidad)==false)
    {
        cout<<"Ingrese un numero de cantidad valido: ";
        cin>>cantidad;
    }

    estado=true;
}

void Juegos::mostrar()
{
    cout<<"codigo de articulo:" << codigo_articulo <<endl;

    cout<<"nombre: " << nombre <<endl;

    cout<<"genero: " << GENERO[genero-1] <<endl;

    cout<<"desarolladora: " << desarrolladora <<endl;

    cout<<"precio unitario: " << precio_unitario <<endl;

    cout<<"publisher: " << publisher <<endl;

    cout<<"fecha de lanzamiento: ";
    fecha_lanzamiento.Mostrar();
    cout<<endl;

    cout<<"Clasificacion: "<< CLASIFICACION[clasificacion-1]<<endl;

    if(digital==1)
    {
        cout<<"Copia Digital"<<endl;
    }
    else
    {
        cout<<"Copia Fisica"<<endl;
    }

    if(cantidad>0)
    {
        cout<<"Copias en stock: "<<cantidad;
    }
    else
    {
        cout<<"No hay copias en stock"<<endl;
    }
}
