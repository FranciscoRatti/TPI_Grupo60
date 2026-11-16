#include "Funciones.h"
#include "Enumeradores.h"
#include <cstdio>
#include <iostream>

using namespace std;

void cargarCadena(char *palabra, int tamano) {
  int i = 0;
  fflush(stdin);
  for (i = 0; i < tamano; i++) {
    palabra[i] = cin.get();
    if (palabra[i] == '\n') {
      break;
    }
  }
  palabra[i] = '\0';
  fflush(stdin);
}

const char *obtenerNombreGenero(Genero g) {
  const char *nombre = "Desconocido";

  switch (g) {
  case Genero::RPG:
    nombre = "RPG";
    break;
  case Genero::ACCION:
    nombre = "Accion";
    break;
  case Genero::AVENTURA:
    nombre = "Aventura";
    break;
  case Genero::SIGILO:
    nombre = "Sigilo";
    break;
  case Genero::DEPORTES:
    nombre = "Deportes";
    break;
  case Genero::ROGUELITE:
    nombre = "Roguelite";
    break;
  case Genero::SOUL:
    nombre = "Soul";
    break;
  case Genero::SANDBOX:
    nombre = "Sandbox";
    break;
  case Genero::PLATAFORMERO:
    nombre = "Plataformero";
    break;
  case Genero::FPS:
    nombre = "FPS";
    break;
  case Genero::BRAWLER:
    nombre = "Brawler";
    break;
  case Genero::FIGHTER:
    nombre = "Fighter";
    break;
  case Genero::MUNDO_ABIERTO:
    nombre = "Mundo Abierto";
    break;
  case Genero::ESTRATEGIA:
    nombre = "Estrategia";
    break;
  case Genero::GRANJAS:
    nombre = "Granjas";
    break;
  case Genero::TERROR:
    nombre = "Terror";
    break;
  case Genero::PUZZLE:
    nombre = "Puzzle";
    break;
  case Genero::INCREMENTAL:
    nombre = "Incremental";
    break;
  case Genero::SIMULADOR:
    nombre = "Simulador";
    break;
  case Genero::RACING:
    nombre = "Racing";
    break;
  default:
    nombre = "Desconocido";
    break;
  }

  return nombre;
}

const int obtenerPosGenero(Genero g) {
  switch (g) {
  case Genero::RPG:
    return 0;
    break;
  case Genero::ACCION:
    return 1;
    break;
  case Genero ::AVENTURA:
    return 2;
    break;
  case Genero::SIGILO:
    return 3;
    break;
  case Genero::DEPORTES:
    return 4;
    break;
  case Genero::ROGUELITE:
    return 5;
    break;
  case Genero::SOUL:
    return 6;
    break;
  case Genero::SANDBOX:
    return 7;
    break;
  case Genero::PLATAFORMERO:
    return 8;
    break;
  case Genero::FPS:
    return 9;
    break;
  case Genero::BRAWLER:
    return 10;
    break;
  case Genero::FIGHTER:
    return 11;
    break;
  case Genero::MUNDO_ABIERTO:
    return 12;
    break;
  case Genero::ESTRATEGIA:
    return 13;
    break;
  case Genero::GRANJAS:
    return 14;
    break;
  case Genero::TERROR:
    return 15;
    break;
  case Genero::PUZZLE:
    return 16;
    break;
  case Genero::INCREMENTAL:
    return 17;
    break;
  case Genero::SIMULADOR:
    return 18;
    break;
  case Genero::RACING:
    return 19;
    break;
  default:
    return -1;
    break;
  }
}

const Genero obtenerGeneroPos(int pos) {
  switch (pos) {
  case 0:
    return Genero::RPG;
  case 1:
    return Genero::ACCION;
  case 2:
    return Genero ::AVENTURA;
  case 3:
    return Genero::SIGILO;
  case 4:
    return Genero::DEPORTES;
  case 5:
    return Genero::ROGUELITE;
  case 6:
    return Genero::SOUL;
  case 7:
    return Genero::SANDBOX;
  case 8:
    return Genero::PLATAFORMERO;
  case 9:
    return Genero::FPS;
  case 10:
    return Genero::BRAWLER;
  case 11:
    return Genero::FIGHTER;
  case 12:
    return Genero::MUNDO_ABIERTO;
  case 13:
    return Genero::ESTRATEGIA;
  case 14:
    return Genero::GRANJAS;
  case 15:
    return Genero::TERROR;
  case 16:
    return Genero::PUZZLE;
  case 17:
    return Genero::INCREMENTAL;
  case 18:
    return Genero::SIMULADOR;
  default:
    return Genero::RACING;
  }
}

const char *obtenerNombreClasificacion(Clasificacion c) {
  const char *nombre = "Desconocida";

  switch (c) {
  case Clasificacion::EVERYONE:
    nombre = "Everyone";
    break;
  case Clasificacion::EVERYONE_10:
    nombre = "Everyone 10+";
    break;
  case Clasificacion::TEEN:
    nombre = "Teen";
    break;
  case Clasificacion::MATURE:
    nombre = "Mature";
    break;
  case Clasificacion::ADULTS_ONLY:
    nombre = "Adults Only";
    break;
  case Clasificacion::RATING_PENDING:
    nombre = "Rating Pending";
    break;
  default:
    nombre = "Desconocida";
    break;
  }

  return nombre;
}

const char *obtenerNombrePlataforma(Plataforma p) {
  const char *nombre = "Desconocida";

  switch (p) {
  case Plataforma::PC:
    nombre = "PC";
    break;
  case Plataforma::PLAYSTATION:
    nombre = "PlayStation";
    break;
  case Plataforma::XBOX:
    nombre = "Xbox";
    break;
  case Plataforma::NINTENDO_SWITCH:
    nombre = "Nintendo Switch";
    break;
  default:
    nombre = "Desconocida";
    break;
  }

  return nombre;
}

const char *obtenerNombreFormaPago(FormaPago fp) {
  const char *nombre = "Desconocida";

  switch (fp) {
  case FormaPago::EFECTIVO:
    nombre = "Efectivo";
    break;
  case FormaPago::CREDITO:
    nombre = "Credito";
    break;
  case FormaPago::DEBITO:
    nombre = "Debito";
    break;
  case FormaPago::TRANSFERENCIA:
    nombre = "Transferencia";
    break;
  default:
    nombre = "Desconocida";
    break;
  }

  return nombre;
}
