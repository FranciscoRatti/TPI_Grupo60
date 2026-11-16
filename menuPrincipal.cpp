#include <iostream>
#include "menuPrincipal.h"

#include "menuInformes.h"
#include "menuJuegos.h"
#include "menuClientes.h"
#include "manager_venta.h"
#include "rlutil.h"

using namespace std;


menuPrincipal::menuPrincipal()
{
    setCantidadOpciones(4);
}


void menuPrincipal::mostrarOpcion()
{
    rlutil::cls();
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
    menuClientes clientes;
    menuJuegos juegos;
    Manager_venta managerVentas;

    switch(opcion)
    {
    case 1:
        managerVentas.registrarVenta();
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
