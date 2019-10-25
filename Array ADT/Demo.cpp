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

//binary  - iterative
int BinarySearchIterative(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

//binary search reccursive
int BinarySearchRecursive(struct Array arr, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            return BinarySearchRecursive(arr, mid + 1, h, key);
        else
            return BinarySearchRecursive(arr, l, mid - 1, key);
    }
    else
    {
        return -1;
    }
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        arr->A[index] = x;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

int SumIterative(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int SumRecursive(struct Array arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    return SumRecursive(arr, n - 1) + arr.A[n];
}

float Avg(struct Array arr)
{

    return (float)SumIterative(arr) * 1.0 / arr.length;
}

void ReverseAuxilary(struct Array *arr)
{
    int *B;
    B = new int[arr->length];
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void RightShift(struct Array *arr)
{
    for (int i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}
void RightRotate(struct Array *arr)
{
    int temp = arr->A[arr->length - 1];
    for (int i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = temp;
}

void LeftShift(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}
void LeftRotate(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

int main()
{

    struct Array arr = {{2, 3, 14, 25, 6}, 10, 5};
    // Append(&arr, 10);
    // Insert(&arr, 0, 120);
    // cout << Delete(&arr, 1) << endl;
    // cout << LinearSearch(arr, 2) << endl;
    // display(arr);
    // cout << "element: " << arr.A[LinearSearchImprovedTranposition(&arr, 6)] << endl;
    // display(arr);
    // cout << LinearSearchImprovedFront(&arr, 6) << endl;
    // display(arr);

    // cout << BinarySearchIterative(arr, 6) << endl;

    // cout << BinarySearchRecursive(arr, 0, arr.length, 6);

    // cout << Get(arr, 9);
    // Set(&arr, 0, 15);
    // display(arr);
    // cout << Max(arr) << endl;
    // cout << Min(arr);
    // cout << SumRecursive(arr, arr.length - 1);
    // cout << Avg(arr);

    // display(arr);
    // ReverseAuxilary(&arr);
    // Reverse(&arr);
    // display(arr);

    // display(arr);
    // RightRotate(&arr);
    // RightShift(&arr);
    // display(arr);

    display(arr);
    // LeftRotate(&arr);
    LeftShift(&arr);
    display(arr);

    return 0;
}