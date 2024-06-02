#include <iostream>
struct DoubleLinkedList
{
    int dato;
    DoubleLinkedList *siguiente;
    DoubleLinkedList *anterior;
};

DoubleLinkedList *head = nullptr;
DoubleLinkedList *tail = nullptr;

void insertarNodosFinal(int value)
{
    DoubleLinkedList *new_node = new DoubleLinkedList();
    new_node->dato = value;
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        head->dato = value;
        head->siguiente = nullptr;
        head->anterior = nullptr;
    }
    else
    {
        tail->siguiente = new_node;
        new_node->anterior = tail;
        tail = new_node;
        tail->siguiente = nullptr;
    }
}

void insertarDespues(int target, int value)
{
    DoubleLinkedList *new_node = new DoubleLinkedList();
    new_node->dato = value;
    DoubleLinkedList *tmp = head;
    if (tmp == nullptr)
    {
        printf("Lo siento, la lista está vacía");
        return;
    }
    while (tmp->dato != target)
    {
        if (tmp->siguiente == nullptr)
        {
            printf("Lo siento, elemento no encontado");
            return;
        }
        tmp = tmp->siguiente;
    }
    new_node->anterior = tmp;

    if (tmp->siguiente == nullptr)
    {
        new_node->siguiente = nullptr;
        tmp->siguiente = new_node;

        tail = new_node;
        // tail = new_node;
    }
    else
    {
        tmp->siguiente = new_node;

        new_node->siguiente = tmp->siguiente;
        tmp->siguiente->anterior = new_node;
    }
}

void imprimirLista()
{
    DoubleLinkedList *tmp = head;

    printf("\nLista:\n");
    while (tmp != nullptr)
    {
        printf("%d\n", tmp->dato);
        tmp = tmp->siguiente;
    }
}

void imprimirListaCola()
{
    DoubleLinkedList *tmp = tail;
    printf("\nLista:\n");
    while (tmp != nullptr)
    {
        printf("%d\n", tmp->dato);
        tmp = tmp->anterior;
    }
}

void deleteNode(int target)
{
    DoubleLinkedList *tmp = head;

    if(tmp == nullptr)
    {
        printf("\nLo siento, la lista está vacía\n");
        return;
    }

    while (tmp->dato != target)
    {
        tmp = tmp->siguiente;
    }
    tmp->anterior->siguiente = tmp->siguiente;

    if (tmp->siguiente != nullptr)
    {
        tmp->siguiente->anterior = tmp->anterior;
    }
    else
    {
        tail = tmp->anterior;
    }

    free(tmp);
}

int main(void)
{
    
    insertarNodosFinal(10);
    insertarNodosFinal(20);
    imprimirLista();

    printf("Lista con dos nodos:");
    imprimirLista();
    printf("Lista despues de insertar el nodo con dato 30 despues del nodo con dato 20");
    insertarDespues(20, 30);
    // imprimirListaCola();
    imprimirLista();
    printf("Se intenta eliminar el nodo con dato 20\n");
    deleteNode(30);
    imprimirLista();
    imprimirListaCola();
}