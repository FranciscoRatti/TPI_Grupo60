#pragma once

class DetallesVenta {
private:
    int _IDdetalle;
    bool _estado;
    int _IDventa;
    int _IDjuego;
    int _cantidad;
    float _precioUnitario;

public:
    DetallesVenta();
    DetallesVenta(int idDetalle, int idVenta, int idJuego, int cantidad, float precioUnotario);

    int getIDdetalle();
    bool getEstado();
    int getIDventa();
    int getIDjuego();
    int getCantidad();
    float getPrecioUnitario();

    void setIDdetalle(int idDetalle);
    void setEstado(bool estado);
    void setIDventa(int idVenta);
    void setIDjuego(int idJuego);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);

    void mostrar();
};
