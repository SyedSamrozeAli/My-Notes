#include <iostream>
#include <string.h>
using namespace std;

int FindMax(int *a, int val1, int val2, int n)
{
    if (val1 <= n && val2 <= n)
    {
        if (a[val1] > a[val2])
            return val1;
        else
            return val2;
    }
    else if (val1 <= n)
    {
        return val1;
    }
    else if (val2 <= n)
    {
        return val2;
    }
    else
    {

        return 0;
    }
}
void Heapify(int *a, int n, int i)
{
    // ye hamesha upper se neeche jata hai

    while (i < n)
    {

        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= n && rightChild <= n && a[i] > a[leftChild] && a[i] > a[rightChild])
            return;
        else
        {

            int maxChild = FindMax(a, leftChild, rightChild, n);
            if (maxChild)
            {
                swap(a[maxChild], a[i]);
                i = maxChild;
            }
            else
            {
                return;
            }
        }
    }
}

void DeleteMaxHeap(int *a, int *size)
{
    int i = 1;
    swap(a[1], a[*size]);
    (*size)--;
    while (i < (*size))
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int maxChild = FindMax(a, left, right, *size);

        if (maxChild)
        {
            if (a[maxChild] > a[i])
            {
                swap(a[maxChild], a[i]);
                i = maxChild;
            }
            else
            {
                return;
            }
        }
    }
};

void HeapSort(int *a, int size)
{

    while (size > 1)
    {

        DeleteMaxHeap(a, &size);
    }
}
void HeapifyUp(int *a, int child)
{
    if (child <= 1)
        return;

    int parent = child / 2;
    if (a[parent] > a[child])
        return;
    else
    {
        swap(a[parent], a[child]);
        // child = parent;
        HeapifyUp(a, parent);
    }
}
void InsertHeap(int *a, int size, int val)
{
    size = size + 1;
    a[size] = val;
    int i = size;

    HeapifyUp(a, i);
    // while (i > 1)
    // {
    //     int parent = i / 2;
    //     if (a[parent] < a[i])
    //     {
    //         swap(a[parent], a[i]);
    //         i = parent;
    //     }
    //     else
    //     {
    //         return;
    //     }
    // }
}
int main()
{

    int arr[6] = {-1, 5, 53, 55, 200, 56};
    int heap[6];
    int n = 5;
    int size = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < 6; i++)
    {
        InsertHeap(heap, size, arr[i]);
        size++;
    }

    // for (int i = n / 2; i > 0; i--)
    // {
    //     Heapify(arr, n, i);
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;

    // HeapSort(arr, n);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}
