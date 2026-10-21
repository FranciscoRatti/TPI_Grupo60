#ifndef ARCHIVO_JUEGOS_H_INCLUDED
#define ARCHIVO_JUEGOS_H_INCLUDED

#include "clsJuegos.h"
#include <cstring>
#include <string>

using namespace std;

class Archivo_Juegos
{
private:

string _nombre;

public:

 Archivo_Juegos(string nombre = "Archivo_Juegos.dat");
    int contar_Registros();
    bool Agregar_Juegos(Juegos obj);
    bool listar();

    bool buscar_id_registro(int id);
    Juegos leer_registro(int);
    bool modificar_registro(Juegos obj, int pos);
    bool eliminar_registro(int pos);
    int buscar_posicion(int id);

};

#endif // ARCHIVO_JUEGOS_H_INCLUDED
