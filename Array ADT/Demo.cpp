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

void InsertInSortedArray(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        int i = arr->length - 1;
        while (arr->A[i] > x)
        {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        if (i < 0)
            arr->A[0] = x;
        else
            arr->A[i + 1] = x;
        arr->length++;
    }
}

int IsSorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void NegativeOnLeftMaintainOrder(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] > 0)
        {
            int index = -1;
            for (int j = i + 1; j < arr->length; j++)
            {
                if (arr->A[j] < 0)
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
            {
                int temp = arr->A[index];
                for (int m = index; m > i; m--)
                {
                    arr->A[m] = arr->A[m - 1];
                }
                arr->A[i] = temp;
            }
            else
                break;
        }
    }
}

void NegativeOnLeftNotMaintainOrder(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] > 0)
        {
            int index = -1;
            for (int j = i + 1; j < arr->length; j++)
            {
                if (arr->A[j] < 0)
                {
                    index = j;
                    break;
                }
            }
            if (index != -1)
            {
                swap(&arr->A[i], &arr->A[index]);
            }
            else
                break;
        }
    }
}

void reArrangeArray(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    // cout << i << " " << j << endl;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
        i++;
    }
}

struct Array *Merge(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;
    struct Array *arr3 = new struct Array;
    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    while (i < arr1.length)
    {
        arr3->A[k++] = arr1.A[i++];
    }
    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }
    arr3->length = arr1.length + arr2.length;
    arr3->size = 10;
    return arr3;
}

int main()
{

    struct Array arr = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10};
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

    // display(arr);
    // // LeftRotate(&arr);
    // LeftShift(&arr);
    // display(arr);

    // cout << IsSorted(arr);
    // InsertInSortedArray(&arr, 0);
    // InsertInSortedArray(&arr, 1);
    // display(arr);
    // reArrangeArray(&arr);
    // NegativeOnLeftMaintainOrder(&arr);
    // NegativeOnLeftNotMaintainOrder(&arr);
    // display(arr);

    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};

    struct Array *arr3 = Merge(arr1, arr2);
    display(*arr3);
    return 0;
}