#include <stdio.h>

// recorrido de un array
void print_array(int arr[], int size ){
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// inserción en especificio indice
void insert_specific_index(int arr[], int size, int index, int value)
{
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void insert_after_specific_index(int arr[], int size, int index, int value)
{
    for (int i = size - 1; i > index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index + 1] = value;
}


void insert_before_specific_index(int arr[], int size, int index, int value)
{
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void find_element(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}

void delete_element(int arr[], int size, int value)
{

    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Element not found\n");
        return;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

// inserción al inicio del array
void insert_element_at_start(int arr[], int size, int value)
{
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = value;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int array_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array\n");
    print_array(arr, array_size);

    int new_var = 10;

    printf("Inserting 10 at index 2\n");
    insert_specific_index(arr, array_size, 2, new_var);
    print_array(arr, array_size + 1);
    printf("Inserting 10 after index 2\n");
    new_var = 20;
    insert_after_specific_index(arr, array_size, 2, new_var);
    print_array(arr, array_size + 1);
    printf("Inserting 10 before index 2\n");
    new_var = 30;
    insert_before_specific_index(arr, array_size, 2, new_var);
    print_array(arr, array_size + 1);
    printf("Finding element 10\n\n");
    find_element(arr, array_size + 1, new_var);
    printf("Deleting element 10\n");
    delete_element(arr, array_size + 1, 30);
    print_array(arr, array_size);
}
