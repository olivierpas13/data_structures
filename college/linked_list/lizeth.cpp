#include <stdio.h>
#include <iostream>

using namespace std;

class Node{
	public:
		Node* siguiente;
		int value;
};

Node* head= NULL;


void add(int valor) 
{
	Node* new_node=new Node();
	new_node->siguiente =NULL;
	new_node->value=valor;
	Node* punterito=head;
	
	if(punterito==NULL)
	{
		punterito=new_node;
		return;
	}
	
	while(punterito->siguiente!=NULL)
	{
		punterito=punterito->siguiente;
	}
	punterito->siguiente= new_node;
}
void imprimir()
{
	Node* punterito=head;
	while(punterito!=NULL)
	{
		cout << punterito->value << endl;
//		printf("%d ", punterito->value);
		punterito=punterito->siguiente;
	}
}
int main(void)
{
	add(5);
	add(7);
	add(6);
	add(3);
	imprimir();
}