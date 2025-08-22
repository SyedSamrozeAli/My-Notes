#include <iostream>
#include <string>

using namespace std;

void printBoard(int **board, int n, int row)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int **board, int col, int row)
{

    int i, j;

    for (i = row; i >= 0; i--) // chcking upper columns
    {
        if (board[i][col] == 1)
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) // checking upper left diagonal
    {
        if (board[i][j] == 1)
            return false;
    }

    for (i = row, j = col; i >= 0 && j < col; i--, j++) // checking  upper right diagonal
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}
bool solveNQueen(int **board, int n, int row)
{
    if (row == n)
    {
        printBoard(board, n, row);
        cout << endl;
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, row))
        {
            board[row][i] = 1;
            if (solveNQueen(board, n, row + 1))
            {
                board[row][i] = 0;
                // return true;
            }
            else
            {
                board[row][i] = 0; // backtrack
            }
        }
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

    if (solveNQueen(board, n, 0))
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