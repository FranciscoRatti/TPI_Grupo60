#include <iostream>
#include "menuClientes.h"
#include "manager_clientes.h"
#include "rlutil.h"

using namespace std;

menuClientes::menuClientes()
{
    setCantidadOpciones(6);
}

void menuClientes::mostrarOpcion()
{
    cout<< "-------MENU CLIENTES-------"<<endl;
    cout<< "1 - Consultar por DNI"<<endl;
    cout<< "2 - Consultar por nombre"<<endl;
    cout<< "3 - Listar todos los clientes activos"<<endl;
    cout<< "4 - Modificar"<<endl;
    cout<< "5 - Agregar"<<endl;
    cout<< "6 - Eliminar"<<endl;
    cout<< "0 - Volver"<<endl;
}

void menuClientes::ejecutarOpcion(int opcion)
{
    Manager_cliente cliente;

    switch(opcion)
    {
    case 1:
        cliente.consultarPorDNI();
        break;
    case 2:
        cliente.consultarPorNombre();
        break;
    case 3:
        cliente.listarTodos();
        break;
    case 4:
        cliente.modificar();
        break;
    case 5:
        cliente.agregar();
        break;
    case 6:
        cliente.eliminar();
        break;
    case 0:
        cout<< "Volviendo al menu anterior"<<endl;
        rlutil::anykey();
        rlutil::cls();
        break;
    }
}
