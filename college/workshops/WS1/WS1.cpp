#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int arr200[200] = {};
int arr100[100] = {};
int arr300[300] = {};

void initializeArray(int size, int arr[])
{
    for (int i = 0; i < size + 1; i++)
    {

        arr[i] = 1 + (rand() % 100);

        if (arr[i] == 0)
        {
            arr[i] = 1;
        }
    }
}

void printVector(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "-";
    }
    cout << endl;
}

int calculateGap(int length)
{
    int index = (length) / 2;
    return index;
}

void swapElements(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int size, int arr[], string type)
{
    int len = size;
    int iterations = 0;
    for (int i = 0; i < len; i++)
    {
        int target = arr[i];
        for (int j = i - 1; j > -1; j--)
        {
            int cmp = arr[j];
            if (target < cmp)
            {
                swapElements(&arr[j], &arr[j + 1]);
                target = arr[j];
            }
        }{}

        iterations++;
    }
    if (type == "normal")
    {
        cout << "Iteraciones " << iterations << endl;
    }
}

void shellSort(int size, int arr[])
{
    int len = size;
    int gap = calculateGap(len);
    int iterations = 0;

    while (gap > 0)
    {
        for (int i = gap; i < len; i++)
        {
            int first = arr[i - gap];
            int second = arr[i];
            if (first > second)
            {
                swapElements(&arr[i - gap], &arr[i]);
            }
        }
        gap = calculateGap(gap);
        iterations++;
    }
    insertionSort(size, arr, "aux");
    cout << "Iteraciones " << iterations << endl;
}

void bubbleSort(int arr[], int size)
{
    int iterations = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
        iterations++;
    }
    cout << "Iteraciones " << iterations << endl;
}

int quickIts = 0;
void quickSort(int arr[], int first, int last)
{
    int central = (first + last) / 2;
    int pivote = arr[central];
    int i = first;
    int j = last;

    if (first >= j)
    {
        return;
    }
    do
    {
        while (arr[i] < pivote)
        {
            i++;
        }
        while (arr[j] > pivote)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    quickIts++;

    quickSort(arr, first, j);
    quickSort(arr, i++, last);
}

void executeFunction(string function, int size, int arr[])
{
    if (function == "shell")
    {

        auto start = high_resolution_clock::now();

        shellSort(size, arr);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Tiempo de ejecución de shellSort: " << duration.count() << " microsegundos" << endl;
    }
    else if (function == "bubble")
    {
        auto start = high_resolution_clock::now();
        bubbleSort(arr, size);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Tiempo de ejecución de bubble sort: " << duration.count() << " microsegundos" << endl;
    }
    else if (function == "quick")
    {
        auto start = high_resolution_clock::now();

        quickSort(arr, 0, size);
        cout << "Iteraciones" << quickIts << endl;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Tiempo de ejecución de quick sort: " << duration.count() << " microsegundos" << endl;
    }
    else if (function == "insertion")
    {
        auto start = high_resolution_clock::now();
        insertionSort(size, arr, "normal");

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Tiempo de ejecución de insertion sort: " << duration.count() << " microsegundos" << endl;
    }
    else
    {
        cout << "Funcion no encontrada, lo siento" << endl;
    }
}

int main(void)
{

    initializeArray(200, arr200);
    cout << "El vector inicial de 200 elementos es: " << endl;
    printVector(200, arr200);
    cout << "Algoritmo quicksort: " << endl;
    executeFunction("quick", 200, arr200);
    cout << "Algoritmo bubbleSort: " << endl;
    executeFunction("bubble", 200, arr200);
    cout << "Algoritmo shellSort: " << endl;
    executeFunction("shell", 200, arr200);
    cout << "Algoritmo insertionSort: " << endl;
    executeFunction("insertion", 200, arr200);
    printVector(200, arr200);
    cout << "-- EXPERIMENTOS --" << endl;
    initializeArray(100, arr100);
    cout << "El vector inicial de 100 elementos es: " << endl;
    printVector(100, arr100);
    cout << "Algoritmo quicksort: " << endl;
    executeFunction("quick", 100, arr100);
    cout << "Algoritmo bubbleSort: " << endl;
    executeFunction("bubble", 100, arr100);
    cout << "Algoritmo shellSort: " << endl;
    executeFunction("shell", 100, arr100);
    cout << "Algoritmo insertionSort: " << endl;
    executeFunction("insertion", 100, arr100);
    printVector(100, arr100);
    cout << "El vector inicial de 300 elementos es: " << endl;
    initializeArray(300, arr300);

    printVector(300, arr300);
    cout << "Algoritmo quicksort: " << endl;
    executeFunction("quick", 300, arr300);
    cout << "Algoritmo bubbleSort: " << endl;
    executeFunction("bubble", 300, arr300);
    cout << "Algoritmo shellSort: " << endl;
    executeFunction("shell", 300, arr300);
    cout << "Algoritmo insertionSort: " << endl;
    executeFunction("insertion", 300, arr300);
    printVector(300, arr300);
    return 0;
}