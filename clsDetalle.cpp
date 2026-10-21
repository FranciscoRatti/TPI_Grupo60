#include<iostream>
#include <cstring>
#include "clsDetalle.h"
#include "clsFecha.h"

using namespace std;

///SETS

 void Detalle::set_id_venta(int id_venta){
  this->id_venta = id_venta;
 }

    void Detalle::set_id_detalle(int id_detalle){
  this->id_detalle = id_detalle;
    }

    void Detalle::set_codigo_articulo(int codigo_articulo){
  this->codigo_articulo= codigo_articulo;
    }

/// validacion convertida a bool -----------------------------------------------------------------------------------------
    bool Detalle::set_cantidad(int cantidad)
    {
    bool retorno = false;
     if(cantidad > 0)
        {
          this->cantidad = cantidad;
          retorno = true;
        }
    return retorno;
    }
///----------------------------------------------------------------------------------------------------------------------

bool Detalle::set_precio_unitario(float precio_unitario){
    bool retorno = false;
    if(precio_unitario>0){
        this->precio_unitario = precio_unitario;
        retorno=true;
        }
        return retorno;
}

bool Detalle::set_estado(int estado){
    bool retorno=false;
    if(estado==0 || estado==1){
        this->estado = estado;
        retorno=true;
        }
    return retorno;
}

///gets

int Detalle::get_id_venta(){
    return id_venta;
}

int  Detalle::get_id_detalle(){
    return id_detalle;
}

int Detalle::get_codigo_articulo(){
    return codigo_articulo;
}

int Detalle::get_cantidad(){
    return cantidad;
}

float Detalle::get_precio_unitario(){
    return precio_unitario;
}

bool Detalle::get_estado(){
    return estado;
}

void Detalle::mostrar(){

    cout<< "el ID de la venta es: "  << id_venta <<endl;

    cout<< "el ID del detalles es:  " << id_detalle <<endl;

    cout<< "el codigo de articulo es: " << codigo_articulo<<endl;

    cout<< "la cantidad es de: " << cantidad <<endl;

    cout<< "el precio unitario es de: " << precio_unitario <<endl;
}


void Detalle::cargar(int id_venta, int id_detalle, int codigo_articulo, int cantidad, float precio_unitario){
    this->id_venta=id_venta;
    this->id_detalle=id_detalle;
    this->codigo_articulo=codigo_articulo;
    this->cantidad=cantidad;
    this->precio_unitario=precio_unitario;
    estado=true;
}
