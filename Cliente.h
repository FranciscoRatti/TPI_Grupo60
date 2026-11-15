#pragma once
class Cliente {
private:
  long _id;
  bool _estado;
  char _dni[9];
  char _nombre[30];
  char _apellido[30];
  char _telefono[20];
  char _email[30];

public:
  Cliente();
  Cliente(long id, bool estado, char dni[9], char nombre[30], char apellido[30],
          char telefono[20], char email[30]);

  void setID(long id);
  void setEstado(bool estado);
  void setDNI(char dni[9]);
  void setNombre(char nombre[30]);
  void setApellido(char apellido[30]);
  void setTelefono(char telefono[20]);
  void setEmail(char email[30]);

  long getID();
  bool getEstado();
  char *getDNI();
  char *getNombre();
  char *getApellido();
  char *getTelefono();
  char *getEmail();

  void mostrar();
};
