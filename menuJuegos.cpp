#include <iostream>
#include "menuJuegos.h"

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
    switch(opcion)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 0:
        break;
    }
}
