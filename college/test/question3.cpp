#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *sig;
    Node *prev;
    Node(int dato)
    {
        data = dato;
        sig = nullptr;
        prev = nullptr;
    }
};

Node *head = nullptr;

void crearListaOrdenada(int dato)
{
    Node *new_node = new Node(dato);
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node *tmp = head;
        Node *target = nullptr;

        if(dato > tmp->data)
        {   
            new_node->sig = tmp;
            tmp->prev = new_node;
            head = new_node;
            return;

        }

        while (tmp != nullptr)
        {
            if (dato < tmp->data)
            {
                target = tmp;
            }
            tmp = tmp->sig;
        }
        new_node->sig = target->sig;
        new_node->prev = target;
        if (target->sig != nullptr)
        {
            target->sig->prev = new_node;
        }
        target->sig = new_node;
    }
}

void imprimirLista()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << endl;
        tmp = tmp->sig;
    }
}

int main(void)
{
    cout << "Olivier Paspuel - Pregunta 3" << endl;
    cout << "Se crea la lista con elementos 10 y 5 de la siguiente manera: " << endl;
    crearListaOrdenada(10);
    crearListaOrdenada(5);
    imprimirLista();
    cout << "Se añade el elemento 8 de manera ordenada" << endl;
    crearListaOrdenada(8);
    imprimirLista();
    cout << "Test case: añadir un numero mayor, en este caso el 11" << endl;
    crearListaOrdenada(11);
    imprimirLista();

};