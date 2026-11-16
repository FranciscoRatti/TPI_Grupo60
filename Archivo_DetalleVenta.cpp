#include <cstdio>
#include <cstring>
#include "Archivo_DetalleVenta.h"

Archivo_DetallesVenta::Archivo_DetallesVenta(const char* nombre)
{
    strcpy(_nombre, nombre);
}

bool Archivo_DetallesVenta::grabar_registro(DetallesVenta reg)
{
    FILE* p = fopen(_nombre, "ab");
    if (p == NULL) return false;

    bool escribio = (fwrite(&reg, sizeof(DetallesVenta), 1, p) == 1);
    fclose(p);
    return escribio;
}

DetallesVenta Archivo_DetallesVenta::leer_registro(int pos)
{
    DetallesVenta reg;
    if (pos < 0) return reg;

    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return reg;

    fseek(p, pos * sizeof(DetallesVenta), SEEK_SET);
    if (fread(&reg, sizeof(DetallesVenta), 1, p) != 1)
    {
        fclose(p);
        return DetallesVenta();
    }

    fclose(p);
    return reg;
}

int Archivo_DetallesVenta::contar_registros()
{
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    if (bytes <= 0) return 0;
    return bytes / sizeof(DetallesVenta);
}

int Archivo_DetallesVenta::buscar_posicion(int idDetalle)
{
    DetallesVenta reg;
    FILE* p = fopen(_nombre, "rb");
    if (p == NULL) return -1;

    int pos = 0;
    while (fread(&reg, sizeof(DetallesVenta), 1, p) == 1)
    {
        if (reg.getIDdetalle() == idDetalle)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

bool Archivo_DetallesVenta::modificar_registro(DetallesVenta reg, int pos)
{
    if (pos < 0) return false;

    FILE* p = fopen(_nombre, "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(DetallesVenta), SEEK_SET);
    bool escribio = (fwrite(&reg, sizeof(DetallesVenta), 1, p) == 1);
    fclose(p);
    return escribio;
}
