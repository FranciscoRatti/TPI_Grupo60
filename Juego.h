#pragma once
#include "Enumeradores.h"
#include "Stock.h"

class Juego
{
private:
    long _id;
    bool _estado;
    char _titulo[30];
    Genero _genero;
    float _precioUnitario;
    Stock _stock;
    char _desarrollador[30];
    Clasificacion _clasificacion;
    Plataforma _plataforma;

public:
    Juego();
    Juego(int id, bool estado, char *titulo, Genero genero,
      float precioUnitario, int stock, char *desarrollador,
      Clasificacion clasificacion, Plataforma plataforma);



    void setId(int id);
    void setEstado(bool estado);
    void setTitulo(char *titulo);
    void setGenero(Genero genero);
    bool setPrecioUnitario(float precio);
    bool setStock(Stock stock);
    bool setStock(int cantidad);
    void setDesarrollador(const char *desarrollador);
    void setClasificacion(Clasificacion clasificacion);
    void setPlataforma(Plataforma plataforma);

    int getId();
    bool getEstado();
    char *getTitulo();
    Genero getGenero();
    float getPrecioUnitario();
    Stock getStock();
    char *getDesarrollador();
    Clasificacion getClasificacion();
    Plataforma getPlataforma();

    void mostrar();
};
