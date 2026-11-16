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
    rlutil::cls();
    cout << "-------MENU CLIENTES-------" << endl;
    cout << "1 - Consultar por DNI" << endl;
    cout << "2 - Consultar por nombre" << endl;
    cout << "3 - Listar los activos"<<endl;
    cout << "4 - Modificar" << endl;
    cout << "5 - Agregar" << endl;
    cout << "6 - Eliminar" << endl;
    cout << "0 - Volver" << endl;
}

void menuClientes::ejecutarOpcion(int opcion)
{
    Manager_cliente c;

    switch (opcion)
    {
    case 1:
        cin.ignore(10000, '\n');
        c.consultarPorDNI();
        rlutil::anykey();
        break;
    case 2:
        cin.ignore(10000, '\n');
        c.consultarPorNombre();
        rlutil::anykey();
        break;
    case 3:
        cin.ignore(10000, '\n');
        c.listarTodos();
        rlutil::anykey();
        break;
    case 4:
        c.modificar();
        rlutil::anykey();
        break;
    case 5:
        c.agregar();
        rlutil::anykey();
        break;
    case 6:
        c.eliminar();
        rlutil::anykey();
        break;
    case 0:
        cout<< "volviendo al menu anterior..." <<endl;
        rlutil::anykey();
        break;
    }
}
