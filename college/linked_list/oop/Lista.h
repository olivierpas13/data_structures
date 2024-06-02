#include "Node.h"
#include <stdio.h>
#include <iostream>

class Lista
{
protected:
    Node *head;

public:
    Lista()
    {
        head = nullptr;
    }
    void insertarInicio(int dato);
    void mostrarLista();
    void insertarFinal(int dato);
    void eliminarCabeza();
};

void Lista::eliminarCabeza()
{
    if(head == nullptr)
    {
        printf("Lista vacia\n");
    }
    else
    {
        Node *tmp = head;
        head = head->link;
        delete tmp;
    }
}

void Lista::insertarInicio(int dato)
{
    Node *new_node = new Node(dato);
    new_node->link = head;
    head = new_node;
};

void Lista::mostrarLista()
{
    using namespace std;
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->dato << " ";
        // printf("%d\n", tmp->dato);
        tmp = tmp->link;
    }
    cout << endl;
}

void Lista::insertarFinal(int dato)
{
    Node *new_node = new Node(dato);
    Node *tmp = head;
    
    if(head == nullptr)
    {
        printf("Lista vacia\n");
    }

    while (tmp->link != nullptr)
    {
        tmp = tmp->link;
    }
    tmp->link = new_node;
}