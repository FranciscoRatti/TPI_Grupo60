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
    cout<< "1 - Ultimas ventas"<<endl;
    cout<< "2 - Ventas en un mes"<<endl;
    cout<< "3 - Ventas por mes"<<endl;
    cout<< "4 - Ventas por anio"<<endl;
    cout<< "5 - Juegos vendidos por genero"<<endl;
    cout<< "6 - Juegos mas vendidos"<<endl;
    cout<< "7 - Juegos sin stock"<<endl;
    cout<< "8 - Ventas por cliente"<<endl;
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
