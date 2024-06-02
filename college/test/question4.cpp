#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *link;

    Node(string nombre)
    {
        name = nombre;
        link = nullptr;
    }
};

Node *head = nullptr;

void insertarNodo(string nombre)
{
    Node *new_node = new Node(nombre);
    if (head == nullptr)
    {
        head = new_node;
        head->link = head;
    }
    else
    {
        new_node->link = head->link;
        head->link = new_node;
    }
}

void printList()
{
    Node *tmp = head;

    cout << tmp->name << endl;

    tmp = tmp->link;

    while (tmp != head)
    {
        cout << tmp->name << endl;
        tmp = tmp->link;
    }
}

int repeatedName(string name)
{
    int total = 0;
    Node *tmp = head;

    while (tmp->link != head)
    {
        if(tmp->name == name)
        {
            total++;
        }
        tmp = tmp->link;
    }
    if(tmp->name == name)
    {
        total++;
    }
    return total;
};
int main(void)
{
    // apellido_nombre.zip
    cout << "Olivier Paspuel - Pregunta 4" << endl;
    cout << "Primero, se crea una lista de nombres, la lista es la siguiente: " << endl;
    insertarNodo("Vier");
    insertarNodo("Vier");
    insertarNodo("Vier");
    insertarNodo("Vier");
    insertarNodo("Fred");
    insertarNodo("Pam");
    insertarNodo("Pam");
    insertarNodo("Charles");
    printList();
    cout << "Ahora se trata de contar cuantas veces el nombre Vier se repite en la lista" << endl;
    int repeated = repeatedName("Vier");
    cout << "Cantidad de veces que se repite Vier: " << repeated << endl;
}