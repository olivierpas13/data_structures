#include <iostream>
#include "Node.h"
#include "Lista.h"
#include "DoubleLinkList.h"

using namespace std;

int main(void)
{
    Lista list;
    int dato = 7;
    cout << "Lista simple enlazada" << endl;
    list.insertarInicio(dato);
    list.insertarInicio(10);
    list.insertarInicio(321);
    list.mostrarLista();

    cout << "Lista doblemente enlazada" << endl;

    DoubleLinkList doubleList;
    int firstData = 10;
    int secondData = 20;
    cout << "Se inserta al final el dato: " << firstData << endl;
    doubleList.insertarAlFinal(firstData);
    doubleList.mostrarListaInicio();
    cout << "Se inserta al inicio el dato: " << secondData << endl;
    doubleList.insertarAlInicio(secondData);
    doubleList.mostrarListaInicio();

    cout << "Lista doblemente enlazada recorriendo desde el final" << endl;
    doubleList.mostrarListaFinal(); 
    return 0;
}