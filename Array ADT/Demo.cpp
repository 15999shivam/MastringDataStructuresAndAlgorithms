#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    cout << endl;
    int i;
    cout << "Elements are:\n";
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
    {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
}

int LinearSearch(struct Array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//improve by transposition
int LinearSearchImprovedTranposition(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i - 1], &arr->A[i]);
            return i - 1;
        }
    }
    return -1;
}

//move to front/head technique
int LinearSearchImprovedFront(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[0], &arr->A[i]);
            return i;
        }
    }
    return -1;
}

int main()
{

    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 10);
    Insert(&arr, 0, 120);
    cout << Delete(&arr, 1) << endl;
    cout << LinearSearch(arr, 2) << endl;
    display(arr);
    cout << "element: " << arr.A[LinearSearchImprovedTranposition(&arr, 6)] << endl;
    display(arr);
    cout << LinearSearchImprovedFront(&arr, 6) << endl;
    display(arr);
    return 0;
}