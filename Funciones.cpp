#include <iostream>
#include <cstdio>
#include "Funciones.h"

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

const char* obtenerNombreGenero(Genero g) {
    const char* nombre = "Desconocido";

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

const char* obtenerNombreClasificacion(Clasificacion c) {
    const char* nombre = "Desconocida";

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

const char* obtenerNombrePlataforma(Plataforma p) {
    const char* nombre = "Desconocida";

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

const char* obtenerNombreFormaPago(FormaPago fp) {
    const char* nombre = "Desconocida";

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
