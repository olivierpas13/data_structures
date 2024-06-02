#include <iostream>
#include <string> // Include the <string> header file
#include <random>

using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

Node *head = nullptr;

void insertNode(string data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        head->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        Node *tmp = head->prev;
        tmp->next = newNode;
        newNode->prev = tmp;
        newNode->next = head;
        head->prev = newNode;
    }
}

void printList()
{
    using namespace std;
    Node *tmp = head->next;
    cout << "\n" << endl;
    cout << head->data << endl;

    while (tmp != head)
    {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
    cout << "\n" << endl;
}

void spinRoulette()
{
    Node* tmp = head;

    cout << "Orden incial de la ruleta:" << endl;

    printList();

    cout << "Se gira la ruleta" << endl;
    cout << "Se está tomando viada..." << endl;
    head = head->prev;
    cout << "Orden de los premios despues de tomar viada" << endl;
    printList();

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> dis(2, 7);

    int random_number = dis(gen);
    
    for (int i = 0; i < random_number; i ++)
    {
        head = head->next;
    }
    cout << "Se girará esta cantidad de veces: " << random_number << endl;
    cout << "Estado de la ruleta despues de girarla" << endl;

    printList();

    cout << "Felicitaciones, has ganado: " << head->data << endl;
    head = tmp;
}

int main(void)
{
    insertNode("1. Teclado gamer");
    insertNode("2. Disco duro SSD");
    insertNode("3. Mouse inalámbrico");
    insertNode("4. Viaje a Colombia");
    spinRoulette();
};