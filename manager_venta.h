#pragma once
#include "Archivo_Ventas.h"
#include "Archivo_DetalleVenta.h"
#include "Archivo_Clientes.h"
#include "Archivo_Juegos.h"

class Manager_venta {
private:
    Archivo_Ventas _archivoVentas;
    Archivo_DetallesVenta _archivoDetalles;
    Archivo_Clientes _archivoClientes;
    Archivo_Juegos _archivoJuegos;

public:
    void registrarVenta();
    float calcularTotalVenta(int idVenta);
};
