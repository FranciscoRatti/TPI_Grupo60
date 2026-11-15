#include <iostream>
#include "menuInformes.h"

using namespace std;

menuInformes::menuInformes()
{
    setCantidadOpciones(8);
}

void menuInformes::mostrarOpcion()
{
    cout<< "-------INFORMES-------"<<endl;
    cout<< "1 - Juegos vendidos por genero" <<endl;
    cout<< "2 - Juegos mas vendidos" <<endl;
    cout<< "3 - ventas por cliente" <<endl;
    cout<< "4 - genero mas vendido por cliente" <<endl;
    cout<< "5 - stock por clasificacion" <<endl;
    cout<< "6 - porcentaje de ventas por metodo de pago" <<endl;
    cout<< "0 - Volver"<<endl;
}

void menuInformes::ejecutarOpcion(int opcion)
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
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 0:
        break;
    }
}
