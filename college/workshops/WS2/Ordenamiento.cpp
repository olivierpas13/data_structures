#include <iostream>
#include "nodo.h"
#include "ordenamiento.h"

using namespace std;

Nodo *Ordenamiento::ordenamientoMisterio(Nodo *lista)
{ // Dividir la lista en dos mitades
    Nodo *mitadIzquierda = lista;
    Nodo *mitadDerecha = lista->siguiente;
    if (mitadIzquierda->siguiente == nullptr)
    {
        return lista;
    }

    while (mitadDerecha != nullptr && mitadDerecha->siguiente != nullptr)
    {
        lista = lista->siguiente;
        mitadDerecha = mitadDerecha->siguiente->siguiente;
    }
    mitadDerecha = lista->siguiente;
    lista->siguiente = nullptr; // Separar las dos mitades
    // Llamadas recursivas para ordenar ambas mitades
    Nodo *izquierdaOrdenada = ordenamientoMisterio(mitadIzquierda);
    Nodo *derechaOrdenada = ordenamientoMisterio(mitadDerecha);
    // Fusionar las listas ordenadas
    return fusionarListas(izquierdaOrdenada, derechaOrdenada);
}

Nodo *Ordenamiento::fusionarListas(Nodo *izquierda, Nodo *derecha)
{

    Nodo *resultado = nullptr;
    if (izquierda == nullptr)
    {
        return derecha;
    }
    if (derecha == nullptr)
    {
        return izquierda;
    }
    if (izquierda->registro->dato <= derecha->registro->dato)
    {
        resultado = izquierda;
        resultado->siguiente = fusionarListas(izquierda->siguiente, derecha);
    }
    else
    {
        resultado = derecha;
        resultado->siguiente = fusionarListas(izquierda, derecha->siguiente);
    }
    return resultado;
}