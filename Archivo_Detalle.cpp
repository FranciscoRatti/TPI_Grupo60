#include<iostream>
#include<cstring>
#include "Archivo_Detalle.h"
using namespace std;

Archivo_Detalle::Archivo_Detalle(const char *n){
    strcpy(nombre,n);
 }

 Detalle Archivo_Detalle::leer_registro(int pos){
    FILE *p = fopen(nombre, "rb");
    Detalle obj;
    if(p==nullptr){
        obj.set_id_detalle(-2);
        return obj;
    }
    obj.set_id_detalle(-1);
    fseek(p,sizeof obj*pos, 0);
    fread(&obj, sizeof obj, 1,p);
    fclose(p);
    return obj;
 }

bool Archivo_Detalle::modificar_detalle(Detalle obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p==nullptr) return false;
    fseek(p,sizeof obj*pos,0);
    bool escribio = fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}


bool Archivo_Detalle::grabar_registro(Detalle obj){
    FILE *p = fopen(nombre, "ab");
    if(p==nullptr) return false;
    bool escribio = fwrite(&obj,sizeof obj,1,p);
    fclose(p);
    return escribio;
}

int Archivo_Detalle::contar_registros(){
    FILE *p = fopen(nombre, "rb");
    if(p==nullptr) return -1;
    fseek(p,0,2);
    int cant= ftell(p)/sizeof(Detalle);
    fclose(p);
    return cant;
}

int Archivo_Detalle::buscar_registro(int leg){
    int cant_reg= contar_registros();
    for(int i=0; i<cant_reg; i++){
        Detalle obj=leer_registro(i);
        if(obj.get_id_detalle()==leg && obj.get_estado()==true){
            return i;
        }
    }
    return -1;
}

void Archivo_Detalle::listar_registros(){
    int cant_reg = contar_registros();
    for(int i=0; i<cant_reg; i++){
        Detalle obj = leer_registro(i);
        if(obj.get_estado()){
            obj.mostrar();
            cout<<endl;
        }
    }
}
