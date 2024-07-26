#include <iostream>
#include <vector>
#include "registro.h"
#include "nodo.h"
#include "ordenamiento.h"
// Función para imprimir una lista simple de registros

Ordenamiento* ord = new Ordenamiento();
void imprimirLista(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        std::cout << actual->registro->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<Registro *> registros;
    int n;
    std::cout << "Ingrese la cantidad de registros: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int valor;
        std::cout << "Ingrese el valor del registro " << (i + 1) << ": ";
        std::cin >> valor;
        registros.push_back(new Registro(valor));
    }
    Nodo *lista = nullptr;
    for (Registro *reg : registros)
    {
        Nodo *nuevoNodo = new Nodo(reg);
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    std::cout << "Lista original: ";
    imprimirLista(lista);

    // llegamos hasta aqui
    lista = Ordenamiento::ordenamientoMisterio(lista);
    std::cout << "Lista ordenada: ";
    imprimirLista(lista);
    // Liberar la memoria de los nodos y registros (esto puede hacerse de manera más robusta en un programa real)
    // while (lista != nullptr)
    // {
    //     Nodo *tempNodo = lista;
    //     lista = lista->siguiente;
    //     delete tempNodo->registro;
    //     delete tempNodo;
    // }
    // for (Registro *reg : registros)
    // {
    //     delete reg;
    // }
    return 0;
}