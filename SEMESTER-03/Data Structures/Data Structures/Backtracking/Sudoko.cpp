#include <iostream>
#include <string>

using namespace std;
void print(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool traverse(int board[9][9])
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

bool isSafe(int board[9][9], int num, int row, int col)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    int initial_row = row - row % 3;
    int initial_col = col - col % 3;

    for (int i = initial_row; i < initial_row + 3; i++)
    {
        for (int j = initial_col; j < initial_col + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSuduko(int board[9][9])
{
    if (traverse(board))
    {
        return true;
    }
    int j;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {

                    if (isSafe(board, num, i, j))
                    {
                        board[i][j] = num;
                        if (solveSuduko(board))
                        {
                            return true;
                        }
                        board[i][j] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
}
int main()
{

    int board[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    print(board);
    if (solveSuduko(board))
    {
        cout << endl;
        cout << "Solved: " << endl;
        print(board);
    }
    else
    {
        cout << "Not Solved!";
    }
}