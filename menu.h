#pragma once

class menu{

public:
    void run();
protected:
    void setCantidadOpciones(int cantidad);
    int getCantidadOpciones();

private:

    virtual void mostrarOpcion() = 0;
    virtual void ejecutarOpcion(int opcion) = 0;

    int seleccionarOpcion();

    int _cantidadOpciones;

};
