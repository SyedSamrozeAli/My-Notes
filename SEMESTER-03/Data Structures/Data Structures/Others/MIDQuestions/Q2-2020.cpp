#include <iostream>
#include <string>
#include <time.h>

using namespace std;
int count(int arr[4][4], int i, int j, int ctr)
{

    if (i >= 4)
    {
        return ctr;
    }

    if (j >= 4)
    {
        j = 0;
        i++;
    }
    if (arr[i][j] == 1)
    {
        ctr++;
    }

    j++;

    count(arr, i, j, ctr);
}
int main()
{
    int arr[4][4] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {1, 1, 0, 1},
                     {0, 0, 0, 0}};

    cout << " The total number of 1's are : " << count(arr, 0, 0, 0);
}
