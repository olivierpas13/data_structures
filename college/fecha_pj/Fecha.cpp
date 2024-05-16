#include "Fecha.h"
#include <iostream>

// constructor de la clase fecha
Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha Fecha::incrementar(int numDias)
{
    // se añade al atributo dia la cantidad de dias a incrementar
    dia += numDias;
    // se calcula si el dia es mayor a los dias del mes
    if (dia > diasEnMes(mes, anio))
    {
        // se resta la cantidad de dias del mes en caso de que la cantidad de días sea mayor a los días del mes
        dia -= diasEnMes(mes, anio);
        // se incrementa el mes
        mes++;
        // se comprueba si el mes es mayor a 12
        if (mes > 12)
        {
            // en caso de que el mes sea mayor a 12 se añade un año y se reinicia el mes
            mes = 1;
            anio++;
        }
    }
    return Fecha(dia, mes, anio);
}

int Fecha::distancia(Fecha fin)
{
    // se calcula la cantidad de días desde 1900 hasta la fecha actual
    int diasInicio = diasDesde1900(dia, mes, anio);
    // se calcula la cantidad de días desde 1900 hasta la fecha final
    int diasFin = diasDesde1900(fin.dia, fin.mes, fin.anio);
    // se retorna la diferencia entre los días finales y los días iniciales
    return diasFin - diasInicio;
}

// funcion getter del valor mes debido a que es privado
int Fecha::obtenerMes()
{
    return mes;
}

int Fecha::diasEnMes(int m, int a)
{
    // se comprueba si el mes es febrero
    if (m == 2)
    {
        // se comprueba si el año es bisiesto si es que el modulo del año entre 4 es 0 y 
        // el modulo del año entre 100 es diferente de 0 o el modulo del año entre 400 es 0
        if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0))
        {
            // si es bisiesto se retorna 29
            return 29;
        }
        else
        {
            // si no es bisiesto se retorna 28 (año normal)
            return 28;
        }
    }
    // se comprueba si el mes es abril, junio, septiembre o noviembre
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        // si es uno de estos meses se retorna 30
        return 30;
    }
    else
    {
        // si no es uno de los meses anteriores se retorna 31
        return 31;
    }
}


int Fecha::diasDesde1900(int d, int m, int a)
{
    // se inicializan los dias como un entero 0
    int dias = 0;
    // se recorren los años desde 1900 hasta el año actual
    for (int i = 1900; i < a; i++)
    {
        // se comprueba si el año es bisiesto
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
        {
            // si es bisiesto se añaden 366 días
            dias += 366;
        }
        else
        {
            // si no es bisiesto se añaden 365 días
            dias += 365;
        }
    }
    // se recorren los meses desde enero hasta el mes actual
    for (int i = 1; i < m; i++)
    {
        // se añaden los días de cada mes
        dias += diasEnMes(i, a);
    }
    // se añaden los días del mes actual
    dias += d - 1;
    return dias;
}
