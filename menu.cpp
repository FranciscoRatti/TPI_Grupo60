#include <iostream>
#include "menu.h"

#include "rlutil.h"

using namespace std;


void menu::run()
{
    int opcion;

    do {
        mostrarOpcion();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
    } while(opcion != 0);
}

int menu::seleccionarOpcion()
{
    int opcion;

    do {
        cout<<"Opcion: ";
        cin>>opcion;

        if(opcion<0 || opcion > getCantidadOpciones())
        {
            cout<< "Ingrese una opcion correcta"<<endl;
        }
    }
    while(opcion<0 || opcion > getCantidadOpciones());

    rlutil::cls();

    return opcion;
}

void menu::setCantidadOpciones(int cantidad)
{
    _cantidadOpciones = cantidad;
}
int menu::getCantidadOpciones()
{
    return _cantidadOpciones;
}
