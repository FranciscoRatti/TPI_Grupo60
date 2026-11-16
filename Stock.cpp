#include <iostream>
#include "Stock.h"

using namespace std;

Stock::Stock() {
    _cantidad = 0;
    _stockMinimo = 5;
}

Stock::Stock(int cantidad, int stockMinimo) {
    if (cantidad >= 0) {
        _cantidad = cantidad;
    } else {
        _cantidad = 0;
    }

    if (stockMinimo >= 0) {
        _stockMinimo = stockMinimo;
    } else {
        _stockMinimo = 0;
    }
}

int Stock::getCantidad() {
    return _cantidad;
}

int Stock::getStockMinimo() {
    return _stockMinimo;
}

void Stock::setCantidad(int cantidad) {
    if (cantidad >= 0) {
        _cantidad = cantidad;
    }
}

void Stock::setStockMinimo(int stockMinimo) {
    if (stockMinimo >= 0) {
        _stockMinimo = stockMinimo;
    }
}

bool Stock::hayStock(int cant) {
    if (cant > 0 && _cantidad >= cant) {
        return true;
    }
    return false;
}

bool Stock::agregar(int cant) {
    if (cant > 0) {
        _cantidad += cant;
        return true;
    }
    return false;
}

bool Stock::descontar(int cant) {
    if (hayStock(cant)) {
        _cantidad -= cant;
        return true;
    }
    return false;
}

bool Stock::estaBajoMinimo() {
    if (_cantidad <= _stockMinimo) {
        return true;
    }
    return false;
}

void Stock::mostrar() {
    cout << "Stock disponible: " << _cantidad << " (Minimo: " << _stockMinimo << ")";
    if (estaBajoMinimo()) {
        cout << " [ALERTA: STOCK BAJO]";
    }
    cout << endl;
}
