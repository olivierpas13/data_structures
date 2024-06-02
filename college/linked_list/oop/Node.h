#pragma once

class Node
{
public:
    int dato;
    Node *link;

    Node(int d)
    {
        dato = d;
        link = nullptr;
    }
    Node(int d, Node *e)
    {
        dato = d;
        link = e;
    }
};