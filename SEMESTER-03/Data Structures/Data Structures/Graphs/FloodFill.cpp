#include <iostream>
#include <queue>

using namespace std;
int **FloodFill(int matrix[3][3], int x, int y, int color)
{
}

int main()
{

    int matrix[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int x = 1, y = 1;
    int **ans = FloodFill(matrix, x, y, 2);
}