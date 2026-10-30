#pragma once
#include "menu.h"

class menuPrincipal: public menu {
public:
    menuPrincipal();

private:

    void mostrarOpcion() override;
    void ejecutarOpcion(int opcion)override;
};
