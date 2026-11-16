#include <iostream>
#include "menu.h"
#include "rlutil.h"

using namespace std;

void menu::run()
{
    int opcion;

    do
    {
        mostrarOpcion();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);
    } while (opcion != 0);
}

int menu::seleccionarOpcion()
{
    int opcion;
    bool valido = false;

    do
    {
        cout << "opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "ingrese una opcion correcta" << endl;
        }
        else if (opcion < 0 || opcion > getCantidadOpciones())
        {
            cout << "ingrese una opcion correcta" << endl;
        }
        else
        {
            valido = true;
        }
    } while (!valido);

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
