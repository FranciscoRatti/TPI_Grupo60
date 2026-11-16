#pragma once
#include "Enumeradores.h"

void cargarCadena(char *palabra, int tamano);

const char *obtenerNombreGenero(Genero g);
const Genero obtenerGeneroPos(int pos);
const int obtenerPosGenero(Genero g);

const char *obtenerNombreClasificacion(Clasificacion c);
const char *obtenerNombrePlataforma(Plataforma p);
const char *obtenerNombreFormaPago(FormaPago fp);
