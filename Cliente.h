#ifndef CLSCliente_H_INCLUDED
#define CLSCliente_H_INCLUDED
#include "clsPersona.h"

class Cliente : public Persona {
private:
  long _id;
  bool _estado;
  char _dni[9];
  char _nombre[30];
  char _apellido[30];
  char _telefono[20];
  char _email[30];

public:
  // Constructores
  Cliente();
  Cliente(long id, bool estado, char dni[9], char nombre[30], char apellido[30],
          char telefono[20], char email[30]);

  // Setters
  void setID(long id);
  void setEstado(bool estado);
  void setDNI(char dni[9]);
  void setNombre(char nombre[30]);
  void setApellido(char apellido[30]);
  void setTelefono(char telefono[20]);
  void setEmail(char email[30]);

  // Getters
  long getID();
  bool getEstado();
  char *getDNI();
  char *getNombre();
  char *getApellido();
  char *getTelefono();
  char *getEmail();

  // Mostrar
  void mostrar();
  void cargar(int id);
};

#endif // CLSCliente_H_INCLUDED
