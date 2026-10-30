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
    cout<< "1 - registrar venta"<<endl;
    cout<< "2 - informes"<<endl;
    cout<< "3 - juegos"<<endl;
    cout<< "4 - clientes"<<endl;
    cout<< "0 - salir"<<endl;

}
void menuPrincipal::ejecutarOpcion(int opcion)
{

menuInformes informes;
menuClientes clientes;
menuJuegos juegos;

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
        cout<< "saliendo del sistema..."<<endl;
        break;
    }


}
