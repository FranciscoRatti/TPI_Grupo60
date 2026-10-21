#include<iostream>
#include<cstring>
#include"clsVentas.h"
#include"clsFecha.h"

#include "Archivo_Clientes.h"
#include "Archivo_Empleados.h"
#include "Archivo_Juegos.h"

using namespace std;

///sets
void Ventas::set_id_venta(int id_venta)
{
    this-> id_venta = id_venta;
}

void Ventas::set_id_cliente(int id_cliente)
{
    this-> id_cliente = id_cliente;
}

void Ventas::set_id_empleado(int id_empleado)
{
    this-> id_empleado = id_empleado;
}

void Ventas::set_fecha_de_venta(Fecha fecha_de_venta)
{
    this-> fecha_de_venta = fecha_de_venta;
}
///validacion convertida en bool --------------------------------------------------------------------------------------------------------------
bool Ventas::set_importe_total(float importe_total)
{
    bool retorno = false;
        if(importe_total >0)
        {
          this-> importe_total = importe_total;
          retorno = true;
        }
    return retorno;
}

 ///-------------------------------------------------------------------------------------------------------------------------------------------

bool Ventas::set_forma_pago(int forma_pago)
{
    bool retorno = false;
        if(forma_pago>=1 && forma_pago<=3)
        {
            this->forma_pago=forma_pago;
            retorno = true;
        }
    return retorno;
}

void Ventas::set_estado(bool estado)
{
    this-> estado = estado;
}

///gets
int Ventas::get_id_venta()
{
    return id_venta;
}
int Ventas::get_id_cliente()
{
    return id_cliente;
}
int Ventas::get_id_empleado()
{
    return id_empleado;
}
Fecha Ventas::get_fecha_de_venta()
{
    return fecha_de_venta;
}
float Ventas::get_importe_total()
{
    return importe_total;
}
bool Ventas::get_forma_pago()
{
    return forma_pago;
}
bool Ventas::get_estado()
{
    return estado;
}

void Ventas::cargar(int id_venta, int id_cliente, int id_empleado)
{
    this->id_venta=id_venta;
    this->id_cliente=id_cliente;
    this->id_empleado=id_empleado;

    cout <<"Fecha: "<< endl;
    fecha_de_venta.Cargar();

    cout<<"Ingrese la forma de pago (1. Efectivo | 2. Debito | 3. Credito)"<<endl;
    cin>>forma_pago;
    while(set_forma_pago(forma_pago)==false){
        cout<<"Ingrese una forma de pago valida (1. Efectivo | 2. Debito | 3. Credito)"<<endl;
        cin>>forma_pago;
        }
    estado=true;
}

void Ventas::mostrar()
{
    cout<<"ID de la venta: " << id_venta << endl;
    cout<<"ID del cliente: " <<id_cliente << endl;
    cout<<"ID del empleado: " <<id_empleado << endl;
    cout<<"Fecha: ";
    fecha_de_venta.Mostrar();
    cout<<endl;
    cout<<"Importe total: " << importe_total << endl;
    cout<<"Forma de pago: ";
    if(forma_pago==1)
        {
        cout<<"Efectivo"<<endl;
        }
    else if(forma_pago==2)
        {
        cout<<"Debito"<<endl;
        }
    else if(forma_pago==3)
        {
        cout<<"Credito"<<endl;
        }
}
