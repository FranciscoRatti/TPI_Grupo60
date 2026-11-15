#include <iostream>
#include "menuPrincipal.h"

#include "menuInformes.h"
#include "menuJuegos.h"
#include "menuClientes.h"

using namespace std;

menuPrincipal::menuPrincipal()
{
    setCantidadOpciones(4);
}

void menuPrincipal::mostrarOpcion()
{
    cout<< "-------MENU PRINCIPAL-------"<<endl;
    cout<< "1 - Registrar venta"<<endl;
    cout<< "2 - Informes"<<endl;
    cout<< "3 - Juegos"<<endl;
    cout<< "4 - Clientes"<<endl;
    cout<< "0 - Salir"<<endl;

}

void menuPrincipal::ejecutarOpcion(int opcion)
{
    menuInformes informes;
    menuJuegos juegos;
    menuClientes clientes;

    switch(opcion)
    {
    case 1:

        break;
    case 2:
        informes.run();
        break;
    case 3:
        juegos.run();
        break;
    case 4:
        clientes.run();
        break;
    case 0:
        cout<< "Saliendo del sistema..."<<endl;
        break;
    }


}
