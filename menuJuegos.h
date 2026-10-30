#pragma once
#include "menu.h"

class menuJuegos: public menu {
public:
    menuJuegos();

private:

    void mostrarOpcion() override;
    void ejecutarOpcion(int opcion)override;
};
