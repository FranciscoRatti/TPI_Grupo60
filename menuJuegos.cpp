#include <iostream>
#include "menuJuegos.h"
#include "manager_juegos.h"
#include "rlutil.h"

using namespace std;

menuJuegos::menuJuegos()
{
    setCantidadOpciones(5);
}

void menuJuegos::mostrarOpcion()
{
    cout<< "-------MENU JUEGOS-------"<<endl;
    cout<< "1 - Consultar por titulo"<<endl;
    cout<< "2 - Consultar por precio"<<endl;
    cout<< "3 - Modificar"<<endl;
    cout<< "4 - Agregar"<<endl;
    cout<< "5 - Eliminar"<<endl;
    cout<< "0 - Volver"<<endl;
}

void menuJuegos::ejecutarOpcion(int opcion)
{
    Manager_juego j;

    switch(opcion)
    {
    case 1:
        j.consultarPorTitulo();
        rlutil::anykey();
        rlutil::cls();
        break;
    case 2:
        j.consultarPorPrecio();
        rlutil::anykey();
        rlutil::cls();
        break;
    case 3:
        j.modificar();
        rlutil::anykey();
        rlutil::cls();
        break;
    case 4:
        j.agregar();
        rlutil::anykey();
        rlutil::cls();
        break;
    case 5:
        j.eliminar();
        rlutil::anykey();
        rlutil::cls();
        break;
    case 0:
        cout<< "volviendo..." <<endl;
        rlutil::anykey();
        rlutil::cls();
        break;
    }
}
