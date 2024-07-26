#include <bits/stdc++.h>

using namespace std;

void quickSort(int arr[], int first, int last)
{
    int central = (first + last) / 2;
    int pivote = arr[central];
    int i = first;
    int j = last;

    if (first >= last)
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

    quickSort(arr, first, j);
    quickSort(arr, i++, last);
}
void printVector(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "-";
    }
    cout << endl;
}

int main(void)
{
    int arr[] = {79,21,15,99,88,65,75,85,76,46,84,24};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    printVector(12, arr);
}