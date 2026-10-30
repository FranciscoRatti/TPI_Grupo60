#include <iostream>
#include "menuClientes.h"

using namespace std;

menuClientes::menuClientes()
{
    setCantidadOpciones(5);
}

void menuClientes::mostrarOpcion()
{
    cout<< "-------MENU CLIENTES-------"<<endl;
    cout<< "1 - Consultar por DNI"<<endl;
    cout<< "2 - Consultar por nombre"<<endl;
    cout<< "3 - Modificar"<<endl;
    cout<< "4 - Agregar"<<endl;
    cout<< "5 - Eliminar"<<endl;
    cout<< "0 - Volver"<<endl;
}

void menuClientes::ejecutarOpcion(int opcion)
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
