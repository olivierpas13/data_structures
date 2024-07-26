#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

const int SIZE = 5;

Node* queue[SIZE];

int dequeue()
{
    for(int i = 0; i < SIZE; i++)
        {
            Node* tmp = queue[i];
            if(tmp != nullptr)
            {
                int value = tmp->data;
                tmp = tmp->next;
                return value;
            }
        }
    return -1;
}

void addElement(int data, int priority)
{
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;

    Node *tmp = queue[priority];

    if(tmp == nullptr)
    {
        queue[priority] = node;
        return;
    }

    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = node;
}

void printQueue()
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Prioridad " << i << ": " << endl;
        Node *tmp = queue[i];
        while(tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    cout << endl;
}

void printPriority(int priority)
{
    Node* tmp = queue[priority];

    cout << "Lista de procesos de prioridad " << priority << endl;
    while(tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;

}

int main(void)
{
    cout << "Se inserta el elemento 10 con prioridad 0" << endl;
    addElement(10, 0);
    cout << "Se inserta el elemento 50 con prioridad 0" << endl;  
    addElement(50, 0);
    cout << "Se inserta el elemento 20 con prioridad 1" << endl;
    addElement(20, 1);
    cout << "Se inserta el elemento 30 con prioridad 2" << endl;
    addElement(30, 2);
    printQueue();   

    
    printPriority(0);

    cout << "Primer elemento desencolado" << endl;
    cout << dequeue() << endl;

}