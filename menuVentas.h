#pragma once
#include "menu.h"

class menuVentas : public menu {
public:
  menuVentas();

private:
  void mostrarOpcion() override;
  void ejecutarOpcion(int opcion) override;
};
