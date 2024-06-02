#include <iostream>

int pile[10] = {};
int cima = -1;

using namespace std;

void insertarElementoEnPila(int value)
{
    printf("Insertando elemento %d en la pila\n", value);
    if (cima < 9)
    {
        cima++;
        pile[cima] = value;
        cout << "Elemento insertado correctamente" << endl;
    }
    else
    {
        cout << "La pila está llena, lo siento" << endl;
    }
}

void imprimirLista()
{
    int tmpArray[sizeof(pile)/sizeof(pile[0])];

    for (int tmp = cima; tmp >= 0; tmp--)
    {
        tmpArray[tmp] = pile[tmp];
        pile[tmp] = 0;
        cout << tmpArray[tmp] << endl;
    }
    for (int tmp = cima; tmp >= 0; tmp--)
    {
        pile[tmp] = tmpArray[tmp];
    }
}

int main(void)
{
    insertarElementoEnPila(10);
    insertarElementoEnPila(20);
    insertarElementoEnPila(30);

    imprimirLista();

};
