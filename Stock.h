#pragma once

class Stock {
private:
    int _cantidad;
    int _stockMinimo;

public:
    Stock();
    Stock(int cantidad, int stockMinimo = 5);

    int getCantidad();
    int getStockMinimo();

    void setCantidad(int cantidad);
    void setStockMinimo(int stockMinimo);

    bool hayStock(int cant);
    bool agregar(int cant);
    bool descontar(int cant);
    bool estaBajoMinimo();

    void mostrar();
};
