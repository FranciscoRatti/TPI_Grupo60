#pragma once
#include "menu.h"

class menuClientes: public menu {
public:
    menuClientes();

private:

    void mostrarOpcion() override;
    void ejecutarOpcion(int opcion)override;
};
