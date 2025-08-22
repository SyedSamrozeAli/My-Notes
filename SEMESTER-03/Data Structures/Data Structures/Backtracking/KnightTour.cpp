#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool isSafe(int **board, int n, int x, int y)
{
    if (x < n && x >= 0 && y < n && y >= 0 && board[x][y] == 0)
        return true;

    return false;
};

void printBoard(int **board, int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool traverse(int **board)
{
    bool flag = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }

    return flag;
}
bool KnightTour(int **board, int n, int x, int y, int num)
{

    // if (traverse(board))
    // {
    //     return true;
    // }
    if (num == n * n)
    {
        return true;
    }

    if (isSafe(board, n, x, y))
    {

        board[x][y] = num;
        // cout << endl;
        // printBoard(board, n, n);
        if (KnightTour(board, n, x - 2, y - 1, num + 1))
            return true;
        if (KnightTour(board, n, x - 2, y + 1, num + 1))
            return true;
        if (KnightTour(board, n, x + 2, y - 1, num + 1))
            return true;
        if (KnightTour(board, n, x + 2, y + 1, num + 1))
            return true;
        if (KnightTour(board, n, x + 1, y - 2, num + 1))
            return true;
        if (KnightTour(board, n, x - 1, y - 2, num + 1))
            return true;
        if (KnightTour(board, n, x - 1, y + 2, num + 1))
            return true;
        if (KnightTour(board, n, x + 1, y + 2, num + 1))
            return true;

        board[x][y] = 0;
        return false;
    }
    return false;
}
int main()
{

    int n;

    cout << "Enter the  dimensions  of board: ";
    cin >> n;

    int **board = new int *[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];

        for (int j = 0; j < n; j++)
        {

            board[i][j] = 0;
        }
    }

    printBoard(board, n, n);

    if (KnightTour(board, n, 0, 0, 1))
    {
        cout << "Possible";
        cout << endl;
        printBoard(board, n, n);
    }
    else
    {
        cout << "Not Possible";
    }
}