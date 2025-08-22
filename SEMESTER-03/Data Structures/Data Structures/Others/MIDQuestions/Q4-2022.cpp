#include <iostream>
#include <string>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *p, int size)
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(p + j) > *(p + j + 1))
                swap((p + j), (p + j + 1));
        }
    }
}

int main()
{
    int arr[4][5] = {{2, 4, 6, 1, 5},
                     {34, 65, 12, 77, 22},
                     {22, 56, 45, 12, 3},
                     {88, 98, 67, 55, 1}};
    int t = 0, i, j, k;

    // print the sorted matrix
    cout << "Unsorted: " << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    bubblesort(*arr, 5);

    cout << "sorted: " << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
