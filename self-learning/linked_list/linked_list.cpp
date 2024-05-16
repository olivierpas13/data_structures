// Linked list implementation;
// in C
#include <cstdlib>
#include <cstdio>

struct Node
{
    int data;
    Node* link;
};

int main()
{
    Node *A;
    A = nullptr;

    // allocate memory for a node and cast it to node pointer type;
    //   Node *temp = (Node*)malloc(sizeof(Node));
    Node *temp = new Node();
    temp->data = 2;
    temp->link = nullptr;
    A = temp;

    temp = new Node();
    temp->data = 3;
    temp->link = nullptr;


    // add new element at the end of the list;
    Node *tmp1 = A;

    // traverse list;
    while(tmp1->link != nullptr)
    {
        tmp1 = tmp1->link;
    }
    tmp1->link = temp;
    printf("last element: %d\n", tmp1->link->data);
}