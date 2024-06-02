// Double link list;
#pragma once
#include <iostream>
#include "DoubleNode.h"

class DoubleLinkList
{
protected:
    DoubleNode *head;
    DoubleNode *tail;

public:
    DoubleLinkList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertarAlFinal(int dato);
    void insertarAlInicio(int dato);
    void mostrarListaInicio();
    void mostrarListaFinal();
};

void DoubleLinkList::mostrarListaFinal()
{
    using namespace std;
    DoubleNode *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->dato << " ";
        temp = temp->before;
    }
    cout << endl;
}

void DoubleLinkList::mostrarListaInicio()
{
    using namespace std;
    DoubleNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->dato << " ";
        temp = temp->next;
    }
    cout << endl;
}
void DoubleLinkList::insertarAlFinal(int dato)
{
    DoubleNode *new_node = new DoubleNode(dato);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->before = tail;
        tail = new_node;
    }
}

void DoubleLinkList::insertarAlInicio(int dato)
{
    DoubleNode *new_node = new DoubleNode(dato);
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->before = new_node;
        head = new_node;
    }
}
