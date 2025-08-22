#include <iostream>

using namespace std;

int main()
{
    int j = 0;
    int arr[5] = {13, 29, 91, 34, 56};
    int Y[5] = {0, 1, 2, 3, 4};
    for (int i = 1; i < 5; i++)
    {
        int temp = Y[i];

        for (j = i - 1; j >= 0 && arr[Y[j]] > arr[temp]; j--)
        {
            Y[j + 1] = Y[j];
        }

        Y[j + 1] = temp;
    }

    for (int i = 0; i < 5; i++)
        cout << Y[i] << " ";
}