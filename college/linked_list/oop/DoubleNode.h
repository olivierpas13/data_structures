#pragma once
class DoubleNode
{
public:
    int dato;
    DoubleNode *next;
    DoubleNode *before;
    DoubleNode(int data)
    {
        dato = data;
        next = nullptr;
        before = nullptr;
    }
    DoubleNode(int data, DoubleNode *n, DoubleNode *b)
    {
        dato = data;
        next = n;
        before = b;
    }
};