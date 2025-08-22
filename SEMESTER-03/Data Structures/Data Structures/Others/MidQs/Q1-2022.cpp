#include <iostream>
#include <string>

using namespace std;

int SumOfDigits(int n)
{
    int sum = 0;

    while (n > 0)
    {

        sum += (n) % 10;
        // cout << n << endl;
        n /= 10;
    }

    return sum;
}

void SortAccToSumOfDigits(int *a, int len)
{
    int j, i;
    for (int i = 1; i < len; i++)
    {
        int temp = a[i];
        for (j = i - 1; j >= 0 && SumOfDigits(a[j]) > SumOfDigits(temp); j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = temp;
    }
}
int main()
{

    int arr[7] = {291, 124, 39, 231, 473, 601, 101};
    SortAccToSumOfDigits(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}