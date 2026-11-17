#include <iostream>
#include <cstdio>
#include <cstring>
#include "Archivo_Juegos.h"
#include "Juego.h"

using namespace std;

Archivo_Juegos::Archivo_Juegos(const char *nombre)
{
    strcpy(_nombre, nombre);
}

int Archivo_Juegos::contar_Registros()
{
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    if (bytes <= 0) return 0;
    return bytes / sizeof(Juego);
}

bool Archivo_Juegos::Agregar_Juegos(Juego obj)
{
    FILE *p = fopen(_nombre, "ab");
    if (p == NULL)
    {
        return false;
    }

    bool escribio = (fwrite(&obj, sizeof(Juego), 1, p) == 1);
    fclose(p);

    return escribio;
}

bool Archivo_Juegos::listar()
{
    Juego obj;
    FILE *p;
    bool flag = false;

    p = fopen(_nombre, "rb");

    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }

    while (fread(&obj, sizeof(Juego), 1, p) == 1)
    {
        if (obj.getEstado() == true)
        {
            obj.mostrar();
            cout << endl;
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "No hay registros que mostrar." << endl;
    }

    fclose(p);
    return true;
}

bool Archivo_Juegos::buscar_id_registro(int id)
{
    Juego obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
        return false;

    while (fread(&obj, sizeof(Juego), 1, p) == 1)
    {
        if (obj.getId() == id && obj.getEstado() == true)
        {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

int Archivo_Juegos::buscar_posicion(int id)
{
    Juego obj;
    int cant = contar_Registros();
    for (int i = 0; i < cant; i++)
    {
        obj = leer_registro(i);
        if (obj.getId() == id)
            return i;
    }
    return -1;
}

bool Archivo_Juegos::modificar_registro(Juego obj, int pos)
{
    if (pos < 0) return false;

    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL)
        return false;

    fseek(p, sizeof(Juego) * pos, SEEK_SET);
    bool escribio = (fwrite(&obj, sizeof(Juego), 1, p) == 1);
    fclose(p);
    return escribio;
}

bool Archivo_Juegos::eliminar_registro(int pos)
{
    if (pos < 0) return false;

    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL)
        return false;

    fseek(p, sizeof(Juego) * pos, SEEK_SET);
    Juego obj;
    if (fread(&obj, sizeof(Juego), 1, p) != 1)
    {
        fclose(p);
        return false;
    }

    obj.setEstado(false);
    fseek(p, sizeof(Juego) * pos, SEEK_SET);
    bool escribio = (fwrite(&obj, sizeof(Juego), 1, p) == 1);
    fclose(p);

    return escribio;
}

Juego Archivo_Juegos::leer_registro(int pos)
{
    Juego obj;
    if (pos < 0)
    {
        obj.setId(-1);
        return obj;
    }

    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        obj.setId(-2);
        return obj;
    }

    fseek(p, sizeof(Juego) * pos, SEEK_SET);
    if (fread(&obj, sizeof(Juego), 1, p) != 1)
    {
        obj.setId(-1);
    }

    fclose(p);
    return obj;
}
