
#include <iostream>
#include <string>

using namespace std;
void merge(int A[], int B[], int C[])
{
    int j = 5, i = 0;
    // for (int i = 0; i < 10; i++)
    // {

    //     if (i < 4)
    //     {
    //         C[i] = A[i];
    //     }
    //     else
    //     {
    //         C[i] = B[j];
    //         j++;
    //     }
    // }
    for (int k = 0; k < 10; k++)
    {

        if (i < 4 && A[i] < B[j])
        {
            C[k] = A[i];
            i++;
        }
        else if (j >= 0 && A[i] > B[j])
        {
            C[k] = B[j];
            j--;
        }
        else
        { // if(i<4)
            C[k] = A[i];
            C[k + 1] = B[j];
            i++;
            j--;
            k++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << C[i] << " ";
    }
}
int main()
{

    int A[4] = {1, 12, 32, 40};
    int B[6] = {60, 50, 40, 30, 20, 10};
    int C[10] = {0};

    merge(A, B, C);
}