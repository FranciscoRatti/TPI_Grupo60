#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha {
private:
  int _dia, _mes, _anio;

public:
  // Constructor
  Fecha(int dia, int mes, int anio);

  // Setters
  bool setDia(int dia);
  bool setMes(int mes);
  void setAnio(int anio);

  // Getters
  int getDia();
  int getMes();
  int getAnio();

  // Mostrar
  void Mostrar();
};

#endif // CLSFECHA_H_INCLUDED
