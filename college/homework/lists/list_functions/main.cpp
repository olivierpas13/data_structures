#include <iostream>
#include <cmath>

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;
Node *tail = nullptr;

void insertNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(Node *list_head)
{
    using namespace std;
    Node *tmp = list_head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void deleteRepeated()
{
    using namespace std;
    Node *tmp = head;
    Node *tmp1 = head;

    while (tmp != nullptr)
    {
        tmp1 = tmp->next;
        while (tmp1 != nullptr)
        {
            if (tmp1->data == tmp->data)
            {
                tmp1->prev->next = tmp1->next;

                tmp1->next->prev = tmp1->prev;
                tmp1 = tmp1->next;
            }
            else
            {
                tmp1 = tmp1->next;
            }
        }

        tmp = tmp->next;
    }
}

// void deleteRepeated()
// {
//     Node *tmp = head;
//     Node *tmp2 = head;
//     while (tmp != nullptr)
//     {
//         tmp2 = tmp->next;
//         while (tmp2 != nullptr)
//         {
//             if (tmp->data == tmp2->data)
//             {
//                 if (tmp2->next != nullptr)
//                 {
//                     tmp2->next->prev = tmp2->prev;
//                 }
//                 else
//                 {
//                     tail = tmp2->prev;
//                 }
//                 if (tmp2->prev != nullptr)
//                 {
//                     tmp2->prev->next = tmp2->next;
//                 }
//                 else
//                 {
//                     head = tmp2->next;
//                 }
//             }
//             tmp2 = tmp2->next;
//         }
//         tmp = tmp->next;
//     }
// }

Node *squares()
{
    Node *tmp = head;

    Node *squares = nullptr;

    Node *last_node = nullptr;

    while (tmp != nullptr)
    {
        Node *new_node = new Node();
        new_node->next = nullptr;
        new_node->prev = nullptr;
        new_node->data = pow(tmp->data, 2);
        if (squares == nullptr)
        {
            squares = new_node;
            last_node = squares;
        }
        else
        {
            last_node->next = new_node;
            new_node->prev = last_node;
            new_node->next = nullptr;
            last_node = new_node;
        }
        tmp = tmp->next;
    }
    return squares;
}

int totalSum()
{
    int total = 0;
    Node *tmp = head;
    while (tmp != nullptr)
    {
        total += tmp->data;
        tmp = tmp->next;
    }
    return total;
}

int main()
{
    using namespace std;

    int numbers[] = {1, 2, 3, 4, 2, 4, 3, 10};

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        insertNode(numbers[i]);
    }

    cout << "Lista original" << endl;
    printList(head);

    cout << "Se eliminan los elementos repetidos" << endl;
    deleteRepeated();

    cout << "Lista sin elementos repetidos" << endl;
    printList(head);

    cout << "Suma de todos los elementos de la nueva lista" << endl;
    printf("Total: %d\n", totalSum());

    cout << "Se crea una lista de cuadrados de la lista previa" << endl;
    Node *new_list = squares();
    printList(new_list);
    return 0;
}