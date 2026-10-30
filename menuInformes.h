#pragma once
#include "menu.h"

class menuInformes: public menu {
public:
    menuInformes();

private:

    void mostrarOpcion() override;
    void ejecutarOpcion(int opcion)override;
};
