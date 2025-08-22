#include <iostream>
#include <string>

using namespace std;

void printBoard(int **board, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int **board, int x, int y, int n)
{

    if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 0)
    {
        // cout << "hereee1";
        if (x - 2 >= 0 && y + 1 < n && board[x - 2][y + 1] == 1)
        {
            // cout << "hereee2";
            return false;
        }
        if (x - 2 >= 0 && y - 1 >= 0 && board[x - 2][y - 1] == 1)
        {
            // cout << "hereee222";
            return false;
        }
        if (x + 2 < n && y + 1 < n && board[x + 2][y + 1] == 1)
        {
            // cout << "hereee3";
            return false;
        }
        if (x + 2 < n && y - 1 >= 0 && board[x + 2][y - 1] == 1)
        {
            // cout << "hereee4";
            return false;
        }
        if (x + 1 < n && y - 2 >= 0 && board[x + 1][y - 2] == 1)
        {
            // cout << "hereee5";
            return false;
        }
        if (x + 1 < n && y + 2 < n && board[x + 1][y + 2] == 1)
        {
            // cout << "hereee6";
            return false;
        }
        if (x - 1 >= 0 && y + 2 < n && board[x - 1][y + 2] == 1)
        {
            // cout << "hereee7";
            return false;
        }
        if (x - 1 >= 0 && y - 2 >= 0 && board[x - 1][y - 2] == 1)
        {
            // cout << "hereee8";
            return false;
        }

        // cout << "hereeett";
        return true;
    }
    // cout << "hereeeR";
    return false;
}

bool solveNKnight(int **board, int n, int col, int r)
{

    if (r == ((n * n) / 2))
        return true;

    if (col >= n)
        col = 0;

    for (int i = 0; i < n; i++)
    {
        // cout << "hereee";
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            cout << endl;
            // cout << "hereee";

            r++;
            if (solveNKnight(board, n, col + 1, r))
                return true;
            else
            {
                board[i][col] = 0;
                r--;
            }
        }
    }

    return false;
}

// board[i][j] = 1;
// board[i + 2][j + 1] = 1;
// board[i + 1][j + 2] = 1;
// board[i - 2][j + 1] = 1;
// board[i + 1][j - 2] = 1;
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

    solveNKnight(board, n, 0, 0);
    cout << endl;
    printBoard(board, n, n);
}