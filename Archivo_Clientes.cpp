#include <iostream>
#include <cstring>
#include "Archivo_Clientes.h"

using namespace std;

 Archivo_Clientes::Archivo_Clientes(const char *n){
    strcpy(nombre,n);
 }

 Clientes Archivo_Clientes::leer_registro(int pos){
    FILE *p = fopen(nombre, "rb");
    Clientes obj;
    if(p==nullptr){
        obj.set_id_cliente(-2);
        return obj;
    }
    obj.set_id_cliente(-1);
    fseek(p,sizeof obj*pos, 0);
    fread(&obj, sizeof obj, 1,p);
    fclose(p);
    return obj;
 }

bool Archivo_Clientes::modificar_cliente(Clientes obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p==nullptr) return false;
    fseek(p,sizeof obj*pos,0);
    bool escribio = fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}


bool Archivo_Clientes::grabar_registro(Clientes obj){
    FILE *p = fopen(nombre, "ab");
    if(p==nullptr) return false;
    bool escribio = fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}

int Archivo_Clientes::contar_registros(){
    FILE *p = fopen(nombre, "rb");
    if(p==nullptr) return -1;
    fseek(p,0,2);
    int cant= ftell(p)/sizeof(Clientes);
    fclose(p);
    return cant;
}

int Archivo_Clientes::buscar_registro(int leg){
    int cant_reg= contar_registros();
    for(int i=0; i<cant_reg; i++){
        Clientes obj=leer_registro(i);
        if(obj.get_id_cliente()==leg && obj.get_estado()==true){
            return i;
        }
    }
    return -1;
}

void Archivo_Clientes::listar_registros(){
    int cant_reg = contar_registros();
    for(int i=0; i<cant_reg; i++){
        Clientes obj = leer_registro(i);
        if(obj.get_estado()){
            obj.mostrar();
            cout<<endl;
        }
    }
}
