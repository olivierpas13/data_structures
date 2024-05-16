#ifndef FECHA_H
#define FECHA_H
//  ADT para representar una fecha, con atributos dia, mes y anio
class Fecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        // constructor
        Fecha(int d, int m, int a);
        // incrementar la fecha en un valor de numDias
        Fecha incrementar(int numDias);
        // calcular la distancia entre dos fechas
        int distancia(Fecha fin);
        // obtener el mes de la fecha
        int obtenerMes();
    private:
        // calcular los dias en un mes
        int diasEnMes(int m, int a);
        // calcular los dias desde el 1 de enero de 1900
        int diasDesde1900(int d , int m, int a);
}; 

#endif