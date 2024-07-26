#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

// Definimos una pila con un tamaño máximo de 100 elementos
int pile[100] = {};
int cima = -1; // Índice de la cima de la pila, inicialmente -1 para indicar que está vacía

using namespace std;

// Función para insertar un elemento en la pila
void push(char a)
{
    if (cima < 99) // Verifica si hay espacio en la pila
    {
        pile[++cima] = a; // Incrementa el índice de la cima y almacena el elemento
    }
    else
    {
        printf("La pila está llena, lo siento\n"); // Mensaje de error si la pila está llena
    }
}

// Función para sacar un elemento de la pila
char pop()
{
    if (cima >= 0) // Verifica si la pila no está vacía
    {
        return pile[cima--]; // Retorna el elemento en la cima y decrementa el índice
    }
    else
    {
        printf("La pila está vacía, lo siento\n"); // Mensaje de error si la pila está vacía
        return 0;
    }
}

// Función para obtener la precedencia de un operador
int getPrecedence(char a)
{
    if (a == '+' || a == '-')
    {
        return 1; // Precedencia de suma y resta es 1
    }
    else if (a == '*' || a == '/')
    {
        return 2; // Precedencia de multiplicación y división es 2
    }
    else
    {
        return 0; // Otros caracteres tienen precedencia 0
    }
}

// Función para convertir una expresión infija a postfija
string convertInfixToPostfix(string infix)
{
    string res = ""; // Cadena para almacenar el resultado
    for (char a : infix) // Recorre cada carácter de la expresión infija
    {
        if (a == '+' || a == '-' || a == '*' || a == '/')
        {
            // Si el carácter es un operador, desempila y añade al resultado mientras la precedencia del operador en la cima sea mayor o igual
            while (getPrecedence(pile[cima]) >= getPrecedence(a))
            {
                res += pop();
            }
            push(a); // Empila el operador actual
        }
        else if (a == '(')
        {
            push(a); // Empila el paréntesis izquierdo
        }
        else if (a == ')')
        {
            // Desempila y añade al resultado hasta encontrar un paréntesis izquierdo
            while (pile[cima] != '(')
            {
                res += pop();
            }
            pop(); // Elimina el paréntesis izquierdo de la pila
        }
        else
        {
            res += a; // Si es un operando, lo añade directamente al resultado
        }
    }
    while (cima >= 0) // Añade cualquier operador restante en la pila al resultado
    {
        res += pop();
    }
    return res; // Retorna la expresión postfija
}

// Función para convertir una expresión infija a prefija
string convertInfixToPrefix(string infix)
{
    string res = ""; // Cadena para almacenar el resultado
    reverse(infix.begin(), infix.end()); // Invierte la expresión infija
    for (char a : infix) // Recorre cada carácter de la expresión invertida
    {
        if (a == ')')
        {
            push(a); // Empila el paréntesis derecho
        }
        else if (a == '+' || a == '-' || a == '*' || a == '/')
        {
            // Si el carácter es un operador, desempila y añade al resultado mientras la precedencia del operador en la cima sea mayor o igual
            while (cima >= 0 && getPrecedence(pile[cima]) >= getPrecedence(a))
            {
                res += pop();
            }
            push(a); // Empila el operador actual
        }
        else if (a == '(')
        {
            // Desempila y añade al resultado hasta encontrar un paréntesis derecho
            while (cima >= 0 && pile[cima] != ')')
            {
                res += pop();
            }
            if (cima >= 0)
            {
                pop(); // Elimina el paréntesis derecho de la pila
            }
        }
        else
        {
            res += a; // Si es un operando, lo añade directamente al resultado
        }
    }
    while (cima >= 0) // Añade cualquier operador restante en la pila al resultado
    {
        res += pop();
    }
    reverse(res.begin(), res.end()); // Invierte el resultado para obtener la expresión prefija
    return res; // Retorna la expresión prefija
}

int main(void)
{
    cout << "Olivier Paspuel" << endl; 

    cout << "Transformación de una expresión infija a postfija y prefija\n" << endl;

    cout << "La cadena infija es (A+B)/(C-D)-(E*F)" << endl;

    string infix = "(A+B)/(C-D)-(E*F)";
    string postfix = convertInfixToPostfix(infix); // Convierte la expresión infija a postfija
    cout << "La cadena postfija es: ";
    cout << postfix << endl;
    infix = "(A+B)*(C+D)";

    cout << "La cadena infija es: " << infix << endl;

    string prefix = convertInfixToPrefix(infix); // Convierte la expresión infija a prefija
    cout << "La cadena prefija es: ";
    cout << prefix << endl;
    return 0; 
}