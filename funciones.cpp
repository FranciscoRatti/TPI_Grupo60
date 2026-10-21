#include<iostream>
#include"funciones.h"

#include"Archivo_Juegos.h"
#include"Archivo_Clientes.h"
#include"Archivo_Empleados.h"
#include"Archivo_Ventas.h"
#include"Archivo_Detalle.h"

using namespace std;

void menu_principal()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"1. MENU de JUEGOS"<<endl;
        cout<<"2. MENU de CLIENTES"<<endl;
        cout<<"3. MENU de EMPLEADO"<<endl;
        cout<<"4. MENU de VENTAS"<<endl;
        cout<<"5. MENU de REPORTES"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            menu_juegos();
            break;
        case 2:
            menu_clientes();
            break;
        case 3:
            menu_empleados();
            break;
        case 4:
            menu_ventas();
            break;
        case 5:
            menu_reportes();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}



void menu_juegos()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU JUEGOS"<<endl;
        cout<<"1 - Listar Juegos"<<endl;
        cout<<"2 - Agregar Juego"<<endl;
        cout<<"3 - Modificar Juego"<<endl;
        cout<<"4 - Eliminar Juego"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            listar_stock();
            break;
        case 2:
            agregar_stock();
            break;
        case 3:
            modificar_stock();
            break;
        case 4:
            eliminar_stock();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}



void menu_clientes()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU CLIENTES"<<endl;
        cout<<"1 - Listar clientes"<<endl;
        cout<<"2 - Agregar cliente"<<endl;
        cout<<"3 - Modificar cliente"<<endl;
        cout<<"4 - Eliminar cliente"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            listar_clientes();
            break;
        case 2:
            agregar_cliente();
            break;
        case 3:
            modificar_cliente();
            break;
        case 4:
            eliminar_cliente();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}


void menu_empleados()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU EMPLEADOS"<<endl;
        cout<<"1 - Listar Empleados"<<endl;
        cout<<"2 - Agregar Empleado"<<endl;
        cout<<"3 - Modificar Empleado"<<endl;
        cout<<"4 - Eliminar Empleado"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            listar_empleados();
            break;
        case 2:
            agregar_empleado();
            break;
        case 3:
            modificar_empleado();
            break;
        case 4:
            eliminar_empleado();
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}


void menu_ventas()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU VENTAS"<<endl;
        cout<<"1 - Listar ventas"<<endl;
        cout<<"2 - Agregar una venta"<<endl;
        cout<<"3 - Listar detalle por venta"<<endl;
        cout<<"4 - Eliminar venta"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            listar_ventas();
            break;
        case 2:
            agregar_venta();
            break;
        case 3:
            listar_detalle_por_venta();
            break;
        case 4:
            eliminar_venta();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}


void menu_reportes()
{
    int opc;
    while(true)
    {
        cout<<"=================="<<endl;
        cout<<"MENU REPORTES"<<endl;
        cout<<"1 - Reporte de venta x genero de videojuego"<<endl;
        cout<<"2 - Reporte de cantidad de juegos vendidos x empleado"<<endl;
        cout<<"3 - Reporte de mayor juego vendido x desarrolladora"<<endl;
        cout<<"4 - Reporte de Juego mas caro vendido"<<endl;
        cout<<"5 - Reporte de Clientes del mes"<<endl;
        cout<<"6 - Reporte de Juegos x desarrolladora"<<endl;
        cout<<"7 - Reporte de Juegos nunca vendidos"<<endl;
        cout<<"8 - Reporte de Reembolso x Cliente"<<endl;
        cout<<"0 - Volver al menu principal"<<endl;
        cout<<"=================="<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cout<<"=================="<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            reporte_1();
            break;
        case 2:
            reporte_2();
            break;
        case 3:
            reporte_3();
            break;
        case 4:
            reporte_4();
            break;
        case 5:
            reporte_5();
            break;
        case 6:
            ///reporte_6();
            break;
        case 7:
            reporte_7();
            break;
        case 8:
            ///reporte_8();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"CARACTER INCORRECTO"<<endl;
            break;
        }
        system("cls");
    }
}


///DESARROLLO DEL MENU JUEGOS
void listar_stock()
{
    Archivo_Juegos reg;
    reg.listar();
    system("pause");
}

void agregar_stock()
{
    int codigo_articulo;

    Archivo_Juegos arc;

    codigo_articulo=arc.contar_Registros();

    if(codigo_articulo == -1)
    {
        codigo_articulo = 0;
    }
    codigo_articulo++;

    Juegos obj;

    cout<<"codigo de articulo: " << codigo_articulo << endl;

    obj.cargar(codigo_articulo);


    if(arc.Agregar_Juegos(obj)==true)
    {
        cout<<"Juego cargado correctamente"<<endl;
        system("pause");
    }
    else
    {
        cout<<"ERROR al cargar"<<endl;
        system("pause");
    }
}

void modificar_stock()
{
    int codigo_articulo;

    Archivo_Juegos arc;

    bool flag = false;

    while(flag == false)
    {
        cout<<"Ingrese el codigo del articulo: "<<endl;

        cin>>codigo_articulo;

        if(arc.buscar_id_registro(codigo_articulo)==false)
        {

            system("cls");

            cout<<"El codigo de articulo ingresado no existe, ingrese de nuevo. "<<endl;

            system("pause");
        }
        else
        {
            flag = true;
        }
    }
    int pos=arc.buscar_posicion(codigo_articulo);

    int cantidad;
    cout<<"Ingrese la cantidad a aniadir al stock"<<endl;
    cin>>cantidad;

    while(cantidad<0){
        cout<<"Cantidad invalida, ingrese nuevamente"<<endl;
        cin>>cantidad;
    }

    Juegos obj;
    obj=arc.leer_registro(pos);
    int cantidad_stock=obj.get_cantidad();
    int nuevo_stock=cantidad_stock+cantidad;
    obj.set_cantidad(nuevo_stock);

    if(arc.modificar_registro(obj,pos)==true)
    {
        cout<<"Modificacion cargada correctamente"<<endl;
        system("pause");
    }
    else
    {
        cout<<"ERROR Modificacion cargada incorrectamente"<<endl;
        system("pause");
    }
}

void eliminar_stock()
{
    int codigo_articulo;
    bool flag = false;

    Archivo_Juegos arc;
    while (flag == false)
    {
        cout<<"Ingrese el id del articulo a eliminar: "<<endl;
        cin>>codigo_articulo;
        if(arc.buscar_id_registro(codigo_articulo)==false)
        {
            system("cls");

            cout<<"El codigo de articulo ingresado no existe, ingrese de nuevo. "<<endl;
        }
        else
        {
            flag = true;
        }
    }
    int pos=arc.buscar_posicion(codigo_articulo);

    if(arc.eliminar_registro(pos)==true)
    {
        cout<<"EL ARITICULO FUE ELIMINADO CORRECTAMENTE"<<endl;
        system("pause");
    }

    return;
}

///DESARROLLO DEL MENU CLIENTES
void listar_clientes()
{
    Archivo_Clientes arc;
    arc.listar_registros();
    system("pause");
}

void agregar_cliente()
{
    int id;
    Archivo_Clientes arc;
    id = arc.contar_registros();
    if(id == -1)
    {
        id = 0;
    }
    id++;
    Clientes obj;
    cout<<"ID de cliente: "<<id<<endl;
    obj.cargar(id);

      if(arc.grabar_registro(obj)==true)
    {
        cout<<"Cliente cargado correctamente"<<endl;
        system("pause");
    }
    else
    {
        cout<<"ERROR al cargar"<<endl;
        system("pause");
    }
}

void modificar_cliente()
{
    int id;
    cout<<"Ingrese el id de cliente: "<<endl;
    cin>>id;
    Archivo_Clientes arc;
    int pos = arc.buscar_registro(id);

    if(pos<0)
    {
        cout<<"El id de cliente no existe"<<endl;
        system("pause");
        return;
    }

    Clientes obj;
    obj=arc.leer_registro(pos);

    if(obj.get_estado()==false)
    {
        cout<<"El cliente ya esta dado de baja"<<endl;
        system("pause");
        return;
    }

    int numero_telefono;
    cout<<"Ingrese el nuevo numero de telefono"<<endl;
    cin>>numero_telefono;

    obj.set_numero_telefono(numero_telefono);
    if(arc.modificar_cliente(obj,pos)){
        cout<<"Se cargo correctamente"<<endl;
        system("pause");
    }else{
        cout<<"ERROR en la carga"<<endl;
        system("pause");
    }
}

void eliminar_cliente()
{
    int id;
    cout<<"Ingrese el id de cliente: "<<endl;
    cin>>id;
    Archivo_Clientes arc;
    int pos = arc.buscar_registro(id);

    if(pos<0)
    {
        cout<<"El id de cliente no existe"<<endl;
        system("pause");
        return;
    }

    Clientes obj;
    obj=arc.leer_registro(pos);

    if(obj.get_estado()==false)
    {
        cout<<"El cliente ya esta dado de baja"<<endl;
        system("pause");
        return;
    }

    obj.set_estado(false);
    if(arc.modificar_cliente(obj,pos)){
        cout<<"Se elimino correctamente"<<endl;
        system("pause");
    }else{
        cout<<"ERROR en eliminar"<<endl;
        system("pause");
    }

}

///DESARROLLO DEL MENU EMPLEADOS
void listar_empleados()
{
    Archivo_Empleados reg;
    reg.listar_registros();
    system("pause");
}

void agregar_empleado()
{
    int id;
    Archivo_Empleados arc;
    id = arc.contar_registros();
    if(id == -1)
    {
        id = 0;
    }
    id++;
    Empleados obj;
    cout<<"ID de empleado: "<<id<<endl;
    obj.cargar(id);

      if(arc.grabar_registro(obj)==true)
    {
        cout<<"Empleado cargado correctamente"<<endl;
        system("pause");
    }
    else
    {
        cout<<"ERROR al cargar"<<endl;
        system("pause");
    }
}

void modificar_empleado()
{
    int id;
    cout<<"Ingrese el id de empleado: "<<endl;
    cin>>id;
    Archivo_Empleados arc;
    int pos = arc.buscar_registro(id);

    if(pos<0)
    {
        cout<<"El id de empleado no existe"<<endl;
        system("pause");
        return;
    }

    Empleados obj;
    obj=arc.leer_registro(pos);

    if(obj.get_estado()==false)
    {
        cout<<"El Empleado ya esta dado de baja"<<endl;
        system("pause");
        return;
    }

    int sueldo;
    cout<<"Ingrese el nuevo sueldo: "<<endl;
    cin>>sueldo;

    obj.set_sueldo(sueldo);
    if(arc.modificar_empleado(obj,pos)){
        cout<<"Se cargo correctamente"<<endl;
        system("pause");
    }else{
        cout<<"ERROR en la modificacion"<<endl;
        system("pause");
    }

}

void eliminar_empleado()
{
    int id;
    cout<<"Ingrese el id de empleado: "<<endl;
    cin>>id;
    Archivo_Empleados arc;
    int pos = arc.buscar_registro(id);

    if(pos<0)
    {
        cout<<"El id de empleado no existe"<<endl;
        system("pause");
        return;
    }

    Empleados obj;
    obj=arc.leer_registro(pos);

    if(obj.get_estado()==false)
    {
        cout<<"El empleado ya esta dado de baja"<<endl;
        system("pause");
        return;
    }

    obj.set_estado(false);
    if(arc.modificar_empleado(obj,pos)){
        cout<<"Se elimino correctamente"<<endl;
        system("pause");
    }else{
        cout<<"ERROR en eliminar"<<endl;
        system("pause");
    }
}


///DESARROLLO DEL MENU VENTAS
void listar_ventas()
{
    Archivo_Ventas arc;
    arc.listar_registros();
    system("pause");
}

void agregar_venta()
{
    int id_venta;
    Archivo_Ventas arc;
    id_venta=arc.contar_registros();
    if(id_venta==-1)
    {
        id_venta=0;
    }
    id_venta++;
    Ventas obj;
    cout<<"id de venta: "<<id_venta<<endl;

    ///INGRESO DEL CLIENTE
    int id_cliente;
    cout<<"Ingrese el id de cliente: "<<endl;
    cin>>id_cliente;

    Archivo_Clientes arc_cliente;

    while(arc_cliente.buscar_registro(id_cliente)==-1)
    {
        cout<<"El cliente no existe, ingrese nuevamente el id o ingrese -2 para salir: "<<endl;
        cin>>id_cliente;
        if(id_cliente==-2)
        {
            return;
        }
    }

    ///INGRESO DEL EMPLEADO
    int id_empleado;
    cout<<"Ingrese el id de empleado: "<<endl;
    cin>>id_empleado;

    Archivo_Empleados arc_empleado;

    while(arc_empleado.buscar_id_registro(id_empleado)==-1)
    {
        cout<<"El empleado no existe, ingrese nuevamente el id o ingrese -2 para salir: "<<endl;
        cin>>id_empleado;
        if(id_empleado==-2)
        {
            return;
        }
    }

    obj.cargar(id_venta,id_cliente,id_empleado);
    int opc = 1;
    float total = 0;
    int vueltas=0;
    while(opc!=0){
        if(vueltas>0){
            cout<<"Quiere agregar otro producto a la venta? (1 = si - 0 = no)"<<endl;
            cin>>opc;
            while(opc!=0 && opc!=1){
                cout<<"Opcion incorrecta, ingrese nuevamente (1 = si - 0 = no)"<<endl;
                cin>>opc;
            }
        }

        if(opc==1){
            total += alta_detalle(id_venta);
            if(total==0){
                cout<<"Error en la carga de la venta"<<endl;
                system("pause");
                return;
                }
        }

        vueltas++;
    }

    obj.set_importe_total(total);

    arc.grabar_registro(obj);
}


void listar_detalle_por_venta()
{
    int id_venta;
    cout<<"Ingrese el id de venta que desea: "<<endl;
    cin>>id_venta;

    Archivo_Ventas arc_ventas;
    Ventas obj_ventas;

    int pos_venta=arc_ventas.buscar_registro(id_venta);

    if(pos_venta<0)
    {
        cout<<"El id de venta ingresado no existe"<<endl;
        system("pause");
        return;
    }


    obj_ventas=arc_ventas.leer_registro(pos_venta);

    if(obj_ventas.get_estado()){
        obj_ventas.mostrar();

    Archivo_Detalle arc_detalle;
    Detalle obj_detalle;

    int cantidad=arc_detalle.contar_registros();

    cout<<endl;

    for(int i=0; i<cantidad ; i++)
    {
        obj_detalle=arc_detalle.leer_registro(i);

        if(obj_detalle.get_id_venta()==id_venta)
        {
           obj_detalle.mostrar();
            cout<<endl;
        }
    }

    }else{
        cout<<"La venta esta dada de baja"<<endl;
    }
    system("pause");
}

void eliminar_venta()
{
    int id;
    cout<<"Ingrese el id de venta: "<<endl;
    cin>>id;
    Archivo_Ventas arc;
    int pos = arc.buscar_registro(id);

    if(pos<0)
    {
        cout<<"El id de venta no existe"<<endl;
        system("pause");
        return;
    }

    Ventas obj;
    obj=arc.leer_registro(pos);

    if(obj.get_estado()==false)
    {
        cout<<"La venta ya esta dado de baja"<<endl;
        system("pause");
        return;
    }

    obj.set_estado(false);
    if(arc.modificar_venta(obj,pos)){
        cout<<"Se elimino correctamente"<<endl;
        system("pause");
    }else{
        cout<<"ERROR en el eliminado"<<endl;
        system("pause");
    }
}

///DESARROLLO DE DETALLE

float alta_detalle(int id_venta)
{
    int id_detalle;
    Archivo_Detalle arc;
    id_detalle = arc.contar_registros();
    if(id_detalle == -1)
    {
        id_detalle = 0;
    }
    id_detalle++;
    Detalle obj;
    cout<<"ID de detalle: "<<id_detalle<<endl;

    Archivo_Juegos arc_juegos;
    int codigo_articulo;
    cout<<"Ingrese el codigo de articulo: "<<endl;
    cin>>codigo_articulo;

    int pos = arc_juegos.buscar_posicion(codigo_articulo);
    if(pos<0)
    {
        cout<<"El codigo de articulo no existe"<<endl;
        system("pause");
        return 0;
    }

    Juegos obj_juego;
    obj_juego=arc_juegos.leer_registro(pos);
    if(obj_juego.get_estado() == false)
    {
        cout<<"EL JUEGO ESTA DADO DE BAJA"<<endl;
        system("pause");
        return 0;
    }
    if(obj_juego.get_cantidad()==0)
    {
        cout<<"El codigo de articulo ingresado no tiene stock"<<endl;
        system("pause");
        return 0;
    }

    int cantidad;
    cout<<"Ingrese la cantidad a vender: "<<endl;
    cin>>cantidad;

    while(cantidad<=0 || obj_juego.get_cantidad()<cantidad)
    {
        cout<<"La cantidad en stock es de "<<obj_juego.get_cantidad()<<" ";
        cout<<"Ingrese una cantidad valida: "<<endl;
        cin>>cantidad;
    }

    obj_juego.set_cantidad(obj_juego.get_cantidad()-cantidad);

    arc_juegos.modificar_registro(obj_juego,pos);

    float precio_unitario=obj_juego.get_precio_unitario();

    float importe=precio_unitario*cantidad;

    obj.cargar(id_venta,id_detalle,codigo_articulo,cantidad,precio_unitario);

    arc.grabar_registro(obj);
    return importe;
}


///LLAMADO DEL MENU REPORTES
void reporte_1()
{
/// cantidad vendida por genero: se listara el genero del videojuego
///seguido por la cantidad total vendida.

    const int tam = 20;

    int vec_cant_vend_generos[tam]= {0};

    Archivo_Juegos arc_juegos;

    Juegos obj_juegos;

    Archivo_Detalle arc_detalle;

    Detalle obj_detalle;

    int cantidad_registros_juegos = arc_juegos.contar_Registros();

    for(int j = 0; j < arc_detalle.contar_registros(); j++)
    {

        obj_detalle = arc_detalle.leer_registro(j);





        for(int i = 0; i < cantidad_registros_juegos; i++)
        {
            obj_juegos = arc_juegos.leer_registro(i);

            if(obj_detalle.get_codigo_articulo() == obj_juegos.get_codigo_articulo())
            {


                vec_cant_vend_generos[obj_juegos.get_genero()-1]+=obj_detalle.get_cantidad();


            }

        }


    }



    for(int k = 0; k < tam; k++)
    {
        cout<<"el genero numero " << k+1 << " que es el genero " << obj_juegos.get_genero(k) << " su cantidad total vendida es: " << vec_cant_vend_generos[k] <<endl;

    }
    system("pause");
}


void reporte_2()
{

    int anio_buscado;
    cout << "Ingrese el anio a consultar: ";
    cin >> anio_buscado;

    Archivo_Empleados arc_emp;
    Archivo_Ventas arc_ventas;
    Archivo_Detalle arc_det;

    int id_emp_ganador = -1;
    int max_cantidad_juegos = 0;

    int cant_empleados = arc_emp.contar_registros();
    for (int i = 0; i < cant_empleados; i++){

        Empleados emp = arc_emp.leer_registro(i);
        int total_juegos_empleado_actual = 0;
        int cant_ventas = arc_ventas.contar_registros();

        for (int j = 0; j < cant_ventas; j++) {
            Ventas ven = arc_ventas.leer_registro(j);
            if (ven.get_id_empleado() == emp.get_id_empleado() && ven.get_fecha_de_venta().get_Anio() == anio_buscado) {

                int cant_detalles = arc_det.contar_registros();
                for (int k = 0; k < cant_detalles; k++) {

                        Detalle d = arc_det.leer_registro(k);
                        if (d.get_id_venta() == ven.get_id_venta()) {
                        total_juegos_empleado_actual += d.get_cantidad();
                        }
                    }
            }
        }

        if (total_juegos_empleado_actual > max_cantidad_juegos) {
            max_cantidad_juegos = total_juegos_empleado_actual;
            id_emp_ganador = emp.get_id_empleado();
        }
    }

    if (id_emp_ganador != -1) {
        cout <<endl << "El empleado con mas ventas es el ID: " << id_emp_ganador << endl;
        cout << "Total de juegos vendidos: " << max_cantidad_juegos << endl;
        }
        else{
        cout <<endl << "No se encontraron ventas para ese anio." << endl;
    }

}
///Reporte 3
struct MejorJuegoPorDesarrolladora{
    char desarrolladora[50];
    char nombre_juego[50];
    int max_vendido = -1;
};

void reporte_3()
{
    Archivo_Juegos arc_jue;
    Archivo_Detalle arc_det;

    int cant_juegos = arc_jue.contar_Registros();
    int cant_detalles = arc_det.contar_registros();

    MejorJuegoPorDesarrolladora* lista_desarrolladoras = new MejorJuegoPorDesarrolladora[cant_juegos];
    int cant_desarrolladoras = 0;

    for (int i = 0; i < cant_juegos; i++) {
        Juegos jue = arc_jue.leer_registro(i);
        int total_vendido_juego = 0;

        for (int j = 0; j < cant_detalles; j++) {
            Detalle det = arc_det.leer_registro(j);
            if (jue.get_codigo_articulo() == det.get_codigo_articulo()) {
                total_vendido_juego += det.get_cantidad();
            }
        }

        const char* des_actual = jue.get_desarrolladora();
        bool encontrada = false;


        for (int k = 0; k < cant_desarrolladoras; k++) {
            if (strcmp(lista_desarrolladoras[k].desarrolladora, des_actual) == 0) {
                encontrada = true;

                if (total_vendido_juego > lista_desarrolladoras[k].max_vendido) {
                    lista_desarrolladoras[k].max_vendido = total_vendido_juego;
                    strcpy(lista_desarrolladoras[k].nombre_juego, jue.get_nombre());
                }
                break;
            }
        }
        if (!encontrada) {
            strcpy(lista_desarrolladoras[cant_desarrolladoras].desarrolladora, des_actual);
            strcpy(lista_desarrolladoras[cant_desarrolladoras].nombre_juego, jue.get_nombre());
            lista_desarrolladoras[cant_desarrolladoras].max_vendido = total_vendido_juego;
            cant_desarrolladoras++;
        }
    }

    for (int i = 0; i < cant_desarrolladoras; i++) {
        cout<<"Desarrolladora: " << lista_desarrolladoras[i].desarrolladora<<endl;
        cout<<"Juego mas vendido: "<< lista_desarrolladoras[i].nombre_juego
        <<" "<< lista_desarrolladoras[i].max_vendido<<endl<<endl;
    }

    delete[] lista_desarrolladoras;
}

void reporte_4()
{

    Archivo_Detalle arc_detalle;
    int cantidad_detalle=arc_detalle.contar_registros();


    Archivo_Juegos arc_juegos;
    int cantidad_juegos=arc_juegos.contar_Registros();

    float *vecDinamico_juegos=nullptr;
    vecDinamico_juegos = new float[cantidad_juegos]{};

    int id=0;
    for(int i=0; i<cantidad_detalle; i++){
        Detalle obj;
        obj=arc_detalle.leer_registro(i);
        id=obj.get_codigo_articulo();

        if(obj.get_precio_unitario() > vecDinamico_juegos[id-1]){
            vecDinamico_juegos[id-1] = obj.get_precio_unitario();
        }
    }

    float max_precio;
    int id_max;
    for(int i=0; i<cantidad_juegos; i++){
        if(i==0){
            id_max=i+1;
            max_precio=vecDinamico_juegos[i];
        }
        if(vecDinamico_juegos[i]>max_precio){
            id_max=i+1;
            max_precio=vecDinamico_juegos[i];
        }
    }

    if(max_precio==0){
        cout<<"No hubo juegos vendidos"<<endl;
        system("pause");
    }else{
        cout<<"El juego mas caro vendido es el ID: "<<id_max<<endl;
        system("pause");
    }

    delete [] vecDinamico_juegos;
}

void reporte_5()
{
    int mes;
    cout<<"Ingrese el mes: ";
    cin>>mes;

    while(mes<=0 || mes>=13){
        cout<<"Mes invalido, ingrese un mes valido"<<endl;
        cin>>mes;
    }

    Archivo_Clientes arc_clientes;
    int cantidad_clientes=arc_clientes.contar_registros();

    int *vecDinamico_clientes=nullptr;
    vecDinamico_clientes = new int [cantidad_clientes]{};

    Archivo_Ventas arc_ventas;
    int cantidad_ventas=arc_ventas.contar_registros();

    int id;
    for(int i=0; i<cantidad_ventas;i++){
        Ventas obj;
        obj=arc_ventas.leer_registro(i);

        if(obj.get_fecha_de_venta().get_Mes()==mes){
            id=obj.get_id_cliente();
            vecDinamico_clientes[id-1]++;
        }
    }

    int maximo;
    int id_max;
    for(int i=0; i<cantidad_clientes; i++){
        if(i==0){
            id_max=i+1;
            maximo=vecDinamico_clientes[i];
        }
        if(vecDinamico_clientes[i]>maximo){
            id_max=i+1;
            maximo=vecDinamico_clientes[i];
        }
    }

    if(maximo==0){
        cout<<"No hubo ninguna venta ingresada ese mes"<<endl;
        system("pause");
    }else{
    cout<<"El id de cliente que realizo mayor numero de compras en el mes ingresado es: "<<id_max<<endl;
    system("pause");
    }
    delete [] vecDinamico_clientes;
}

void reporte_6()
{

}

void reporte_7()
{


///reporte de juegos nunca vendidos en un anio
/// el usuario ingresa el anio y muestro los juegos que no se vendieron ese anio.

///trabajo del reporte actualizado: reporte de juegos nunca vendidos en un anio
/// el usuario ingresa el anio y muestro los juegos que no se vendieron ese anio.
///

    /**
    ir juego por juego, por id, chequear el anio de la venta, luego ir a venta,y comparar el anio del juego con el de la venta.


    ----------
    juego
    if detallexjuego(IDjuego, anio)
        mostrar
    ----------
    detalle

    if IDdetalleJuego == IDjuego and juego.getanio == anio

    ------------
    /// CLAVE: hacer una funcion que reciba el detalle de venta y el vector, y luego recorrer el archivo de detalle de ventas.

    */

///Archivo_Juegos arc_juegos;

///Juegos obj_juego;

///Fecha obj_fecha;

    Archivo_Ventas arc_ventas;

    Ventas obj_ventas;

    Archivo_Detalle arc_detalle;

    Detalle obj_Detalle;

    Archivo_Juegos arc_juegos;

    Juegos obj_juegos;


    int tam = arc_juegos.contar_Registros();

    int *vec_juegos_sin_venta = new int [tam] {0};

    int anio;

    int posicion = 0;

    cout<< "ingrese un anio: " <<endl;

    cin>> anio;

    while(anio <=0)
    {
        cout<<"anio no valido, ingrese de nuevo. " <<endl;
        cin>>anio;
    }
    int guardar_registros_venta = arc_ventas.contar_registros();

    int guardar_registros_detalle = arc_detalle.contar_registros();


    for(int i = 0; i< guardar_registros_venta; i++)
    {
        obj_ventas = arc_ventas.leer_registro(i);

        if(anio == obj_ventas.get_fecha_de_venta().get_Anio())
        {

            for(int j = 0; j <guardar_registros_detalle; j++)
            {
                obj_Detalle = arc_detalle.leer_registro(j);

                if(obj_Detalle.get_id_venta() == obj_ventas.get_id_venta())
                {
                    int guardar_posicion = obj_Detalle.get_codigo_articulo() -1;

                    vec_juegos_sin_venta[guardar_posicion] +=1;



                }
            }

        }


    }

    for(int j = 0; j < tam; j++)
    {
        if(vec_juegos_sin_venta[j] == 0)
        {
            cout<< " el juego " << j+1 << " no realizo ninguna venta "<<endl;

            for(int k = 0; k <tam ; k++)
            {
                obj_juegos = arc_juegos.leer_registro(k);

                /// obj_juegos.mostrar();

                ///   system("pause");

                if(j+1 == obj_juegos.get_codigo_articulo())
                {
                    cout<<" el nombre del juego es: " << obj_juegos.get_nombre() <<endl;

                }

            }


        }



    }

    system("pause");

    delete [] vec_juegos_sin_venta;

}
void reporte_8()
{

}
