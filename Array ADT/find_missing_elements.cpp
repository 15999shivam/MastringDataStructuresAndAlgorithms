#include <iostream>
using namespace std;

int FindMissingOne(int arr[], int n)
{
    int diff = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            return i + diff;
        }
    }
    return -1;
}

void FindAndPrintMissingMultiple(int arr[], int n)
{
    int diff = arr[0];
    // int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
    cout << endl;
    // return -1;
}

void FindAndPrintMissingMultipleHash(int arr[], int n, int l, int h)
{
    int diff = arr[0];
    int hash[h + 1];
    for (int i = l; i <= h; i++)
    {
        hash[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = l; i <= h; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 7, 9};
    // cout << FindMissingOne(arr, 7);
    // FindAndPrintMissingMultiple(arr, 7);
    FindAndPrintMissingMultipleHash(arr, 7, 0, 9);
    return 0;
}