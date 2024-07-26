#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

Node *head = nullptr;

Node *bucket[10] = {nullptr};

void insertNode(int number)
{
    Node *new_node = new Node(number);
    if (head == nullptr)
    {
        head = new_node;
        return;
    };
    Node *tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

int getNodeDigit(int number, int iter)
{
    return int(number / pow(10, iter)) % 10;
}

void classifyNode(Node *node, int iter)
{
    int digit = getNodeDigit(node->value, iter);
    Node *toAdd = node;
    toAdd->next = nullptr;
    Node *space = bucket[digit];
    if (space == nullptr)
    {

        bucket[digit] = toAdd;
        return;
    }
    while (space->next != nullptr)
    {
        space = space->next;
    }
    space->next = toAdd;
}

void printList()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    };
    cout << endl;
}

void printBucket()
{
    for (int i = 0; i < 10; i++)
    {
        Node *tmp = bucket[i];
        cout << i << ": ";
        while (tmp != nullptr)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

int getIterations()
{
    Node *tmp = head;
    int max = 0;
    while (tmp != nullptr)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    int digit = max;
    int iters = 0;
    while (digit != 0)
    {
        iters++;
        digit = digit / 10;
    }
    return iters;
}

void emptyBucket()
{
    for(int i = 0; i < 10; i++)
    {
        bucket[i] = nullptr;
    };
}

void bucketToList()
{
    head = nullptr;
    for (int i = 0; i < 10; i++)
    {
        Node *tmp = bucket[i];
        while (tmp != nullptr)
        {
            insertNode(tmp->value);
            tmp = tmp->next;
        }
    }
    emptyBucket();
}

void radixSort()
{
    Node *tmp = head;
    int iter = getIterations();

    for (int i = 0; i < iter; i++)
    {
        while (tmp != nullptr)
        {
            Node *node = new Node(tmp->value);
            classifyNode(node, i);
            tmp = tmp->next;
        }
        printBucket();
        bucketToList();
        tmp = head;
    }
    // while (tmp != nullptr)
    // {
    //     Node *node = new Node(tmp->value);
    //     classifyNode(node, iter);
    //     tmp = tmp->next;
    // }
    // iter++;
}

int main(void)
{
    insertNode(62);
    insertNode(3);
    insertNode(35);
    insertNode(56);
    insertNode(16);
    printList();
    radixSort();
    printList();
}