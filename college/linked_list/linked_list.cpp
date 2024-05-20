#include <stdio.h>
#include <stdlib.h>
#include <exception>

struct Node
{
    // int id;
    int dato;
    Node *siguiente;
};

Node *head = nullptr;

void insertarNodosLista(int dato)
{
    Node *nuevo_nodo = (Node *)malloc(sizeof(Node));

    nuevo_nodo->dato = dato;

    nuevo_nodo->siguiente = head;

    head = nuevo_nodo;
}

void insertarNodoFinal(int data)
{

    Node *new_node = new Node();
    new_node->dato = data;

    Node *tmp = head;

    if (head == nullptr)
    {
        head = new_node;
        new_node->siguiente = nullptr;
    }
    else
    {
        while (tmp->siguiente != nullptr)
        {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = new_node;
        new_node->siguiente = nullptr;
    }
}

void insertarDespues(int target, int data)
{
    Node *new_node = new Node();

    new_node->dato = data;

    Node *tmp = head;

    if (head == nullptr)
    {
        printf("Lo siento, lista vacía");
        return;
    }

    while (tmp->dato != target)
    {
        if (tmp->siguiente == nullptr)
        {
            printf("Elemento no encontrado\n");
            break;
        }
        tmp = tmp->siguiente;
    }
    if (tmp->siguiente != nullptr)
    {
        new_node->siguiente = tmp->siguiente;
        tmp->siguiente = new_node;
    }
};

void modificarNodo(int target, int dato)
{
    Node *tmp = head;

    if (head == nullptr)
    {
        printf("Lo siento, lista vacía");
        return;
    }
    while (tmp != nullptr)
    {
        if (tmp->dato == target)
        {
            tmp->dato = dato;
            break;
        }
        else
        {
            printf("Elemento no encontrado, lo siento\n");
            break;
        }
        tmp = tmp->siguiente;
    }
}

void imprimirLista()
{
    if (head == nullptr)
    {
        printf("\nLa lista está vacía\n");
        return;
    }
    else
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            printf("%d\n", tmp->dato);
            tmp = tmp->siguiente;
        }
    }
}

void deleteFirstNode()
{
    if (head == nullptr)
    {
        printf("No se puede eliminar la cabeza, la lista está vacía, lo siento.\n");
        return;
    }
    else
    {
        Node *tmp = head;
        head = head->siguiente;
        free(tmp);
        return;
    }
}

int main(void)
{

    int target, value;
    target = 7;
    value = 11;
    insertarNodoFinal(7);
    insertarNodoFinal(10);
    imprimirLista();
    printf("Insertando elemento %d despues del elemento con dato: %d\n", value, target);
    insertarDespues(target, value);
    imprimirLista();
};
