#include <iostream>
#include <cstring>
#include "Juego.h"
#include "Funciones.h"

using namespace std;

Juego::Juego()
{
    _id = 0;
    _estado = false;
    strcpy(_titulo, "");
    _genero = static_cast<Genero>(0);
    _precioUnitario = 0;
    _stock.setCantidad(0);
    _stock.setStockMinimo(0);
    strcpy(_desarrollador, "");
    _clasificacion = static_cast<Clasificacion>(0);
    _plataforma = static_cast<Plataforma>(0);
}

Juego::Juego(int id, bool estado, char *titulo, Genero genero,
             float precioUnitario, int stock, char *desarrollador,
             Clasificacion clasificacion, Plataforma plataforma)
{
    _id = id;
    _estado = estado;
    strcpy(_titulo, titulo);
    _genero = genero;

    if (precioUnitario > 0)
    {
        _precioUnitario = precioUnitario;
    }
    else
    {
        _precioUnitario = 0;
    }

    if (stock >= 0)
    {
        _stock.setCantidad(stock);
    }
    else
    {
        _stock.setCantidad(0);
    }

    _stock.setStockMinimo(0);
    strcpy(_desarrollador, desarrollador);
    _clasificacion = clasificacion;
    _plataforma = plataforma;
}

void Juego::setId(int id)
{
    _id = id;
}

void Juego::setEstado(bool estado)
{
    _estado = estado;
}

void Juego::setTitulo(char *titulo)
{
    strcpy(_titulo, titulo);
}

void Juego::setGenero(Genero genero)
{
    _genero = genero;
}

bool Juego::setPrecioUnitario(float precio)
{
    if (precio > 0)
    {
        _precioUnitario = precio;
        return true;
    }
    return false;
}

bool Juego::setStock(Stock stock)
{
    if (stock.getCantidad() >= 0 && stock.getStockMinimo() >= 0)
    {
        _stock = stock;
        return true;
    }
    return false;
}

bool Juego::setStock(int cantidad)
{
    if (cantidad >= 0)
    {
        _stock.setCantidad(cantidad);
        return true;
    }
    return false;
}

void Juego::setDesarrollador(const char *desarrollador)
{
    strcpy(_desarrollador, desarrollador);
}

void Juego::setClasificacion(Clasificacion clasificacion)
{
    _clasificacion = clasificacion;
}

void Juego::setPlataforma(Plataforma plataforma)
{
    _plataforma = plataforma;
}

int Juego::getId()
{
    return _id;
}

bool Juego::getEstado()
{
    return _estado;
}

char* Juego::getTitulo()
{
    return _titulo;
}

Genero Juego::getGenero()
{
    return _genero;
}

float Juego::getPrecioUnitario()
{
    return _precioUnitario;
}

Stock Juego::getStock()
{
    return _stock;
}

char* Juego::getDesarrollador()
{
    return _desarrollador;
}

Clasificacion Juego::getClasificacion()
{
    return _clasificacion;
}

Plataforma Juego::getPlataforma()
{
    return _plataforma;
}

void Juego::mostrar()
{
    cout << "ID: " << _id << " | Titulo: " << _titulo << endl;
    cout << "Desarrollador: " << _desarrollador << " | Plataforma: " << obtenerNombrePlataforma(_plataforma) << endl;
    cout << "Genero: " << obtenerNombreGenero(_genero) << " | Clasificacion: " << obtenerNombreClasificacion(_clasificacion) << endl;
    cout << "Precio: $" << _precioUnitario << " | ";
    _stock.mostrar();
    cout << "Estado: ";

    if (_estado == true)
    {
        cout << "Activo" << endl;
    }
    else
    {
        cout << "Inactivo" << endl;
    }
}
