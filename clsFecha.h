#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        ///Sets
        bool set_Dia(int);
        bool set_Mes(int);
        bool set_Anio(int);

        ///Gets
        int get_Dia();
        int get_Mes();
        int get_Anio();

        void Cargar();
        void Mostrar();
};


#endif // CLSFECHA_H_INCLUDED
