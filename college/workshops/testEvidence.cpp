#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    double data;
    Node* next;
};

double matriz[10] ={0.7, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
Node* bucket[10] = {nullptr};

void printBucket()
{
    for(int i = 0; i<10; i++)
    {
        cout << "Bucket "<<i<<": ";
        Node* tmp = bucket[i];
        while(tmp != nullptr)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
    
}



Node* getMaxNode(Node* end, Node* list)
{
    Node* max = list;
    Node* tmp = list;
    
    if(list == nullptr)
    {
        return nullptr;
    }

    if(list->next == nullptr)
    {
        return nullptr;
    }

    while(tmp != end)
    {
        if(tmp->data > max->data)
        {
            max = tmp;
        }
        tmp = tmp->next;
    }
    return max;
}

Node* getNewLastNode(Node* last, Node* list)
{
    Node* tmp = list;
    Node* new_last = nullptr;

    while(tmp->next != last->next)
    {
        new_last = tmp;
        tmp = tmp->next;
    }
    return new_last;
}

void ordenarLista(Node* list)
{
    Node* tmp = list;
    Node* max = getMaxNode(nullptr, list);

    if(max == nullptr)
    {
        return;
    }
    if(tmp == nullptr)
    {
        return;
    }

    while(tmp->next !=  nullptr)
    {
        tmp = tmp->next;
    }
    Node* new_last = tmp;

    swap(max->data, new_last->data);
    while(getMaxNode(new_last, list) != nullptr && getNewLastNode(new_last, list) != nullptr)
    {
        max = getMaxNode(new_last, list);
        new_last = getNewLastNode(new_last, list);
        swap(max->data, new_last->data);
    }
}

void insertarEnBucketPosicion(float num, int pos)
{
    Node* new_node = new Node();
    new_node->data = num;
    new_node->next = nullptr;
    if(bucket[pos] == nullptr)
    {
        bucket[pos] = new_node;
    }
    else
    {
        Node* tmp = bucket[pos];
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

void matrizABucket()
{
    for(int i = 0; i<10; i++)
    {
        int num = int(matriz[i]*10);
        insertarEnBucketPosicion(matriz[i], num);

    }
}


void bucketAMatriz()
{
    int els = 0;
    for(int i = 0; i<10; i++)
    {
        Node* tmp = bucket[i];
        while(tmp != nullptr)
        {
            matriz[els] = tmp->data;
            tmp = tmp->next;
            els++;
        }
    }
}

int main(void)
{
    matrizABucket();
    printBucket();
    for(int i = 0; i<10; i++)
    {
        ordenarLista(bucket[i]);
    }
    bucketAMatriz();
    for(int i = 0; i<10; i++)
    {
        cout<<matriz[i]<<" ";
    }
    cout << endl;
    return 0;

}