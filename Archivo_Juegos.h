#pragma once
#include "Juego.h"

class Archivo_Juegos
{
private:
    char _nombre[50];

public:
    Archivo_Juegos(const char *nombre = "juegos.dat");

    int contar_Registros();
    bool Agregar_Juegos(Juego obj);
    bool listar();
    bool buscar_id_registro(int id);
    int buscar_posicion(int id);
    bool modificar_registro(Juego obj, int pos);
    bool eliminar_registro(int pos);
    Juego leer_registro(int pos);
};
