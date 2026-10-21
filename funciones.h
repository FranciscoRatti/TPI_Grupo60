#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///MENUS
void menu_principal();
void menu_juegos();
void menu_clientes();
void menu_empleados();
void menu_ventas();
void menu_reportes();

///DESARROLLO DEL MENU JUEGOS
void listar_stock();
void agregar_stock();
void modificar_stock();
void eliminar_stock();


///LLAMADO DEL MENU CLIENTES
void listar_clientes();
void agregar_cliente();
void modificar_cliente();
void eliminar_cliente();

///LLAMADO DEL MENU EMPLEADOS
void listar_empleados();
void agregar_empleado();
void modificar_empleado();
void eliminar_empleado();


///LLAMADO DEL MENU VENTAS
void listar_ventas();
void agregar_venta();
void listar_detalle_por_venta();
void eliminar_venta();
float alta_detalle(int id_venta);

///LLAMADO DEL MENU REPORTES
void reporte_1();
void reporte_2();
void reporte_3();
void reporte_4();
void reporte_5();
void reporte_6();
void reporte_7();
void reporte_8();


#endif // FUNCIONES_H_INCLUDED
