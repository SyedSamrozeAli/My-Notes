#include <iostream>
#include <string>

using namespace std;
bool isSafe(int board[5][5], int row, int x, int y)
{
    if (x < row && x >= 0 && y < row && y >= 0)
        return true;

    return false;
};
bool findPath(int board[5][5], int n, int x, int y, int boardAns[5][5])
{
    if (x == 2 && y == 2 && board[x][y] == 0)
    {
        boardAns[x][y] = 1;
        return true;
    }

    if (isSafe(board, 5, x, y))
    {
        int num = board[x][y];
        boardAns[x][y] = 1;
        for (int i = 1; i < board[x][y] && i < n; i++)
        {
            if (findPath(board, 5, x, y + i, boardAns))
                return true;
            if (findPath(board, 5, x + i, y, boardAns))
                return true;
        }
        //     if (findPath(board, 5, x + num, y, boardAns))
        //         return true;
        // if (findPath(board, 5, x, y + num, boardAns))
        //     return true;
        // if (num == 2)
        // {

        //     if (findPath(board, 5, x + 1, y + 1, boardAns))
        //         return true;
        // }
        // if (num == 3)
        // {
        //     if (findPath(board, 5, x + 3, y, boardAns))
        //         return true;
        //     if (findPath(board, 5, x, y + 3, boardAns))
        //         return true;
        //     if (findPath(board, 5, x + 2, y + 1, boardAns))
        //         return true;
        //     if (findPath(board, 5, x + 1, y + 2, boardAns))
        //         return true;
        // }
        // if (num == 4)
        // {
        //     if (findPath(board, 5, x + 1, y + 3, boardAns))
        //         return true;
        //     if (findPath(board, 5, x + 3, y + 1, boardAns))
        //         return true;
        //     if (findPath(board, 5, x + 2, y + 2, boardAns))
        //         return true;
        // }
        boardAns[x][y] = 0;
        return false;
    }

    return false;
}
int main()
{
    int board[5][5] = {{2, 2, 4, 4, 3},
                       {3, 4, 3, 2, 2},
                       {1, 1, 0, 3, 2},
                       {3, 2, 2, 1, 2},
                       {3, 3, 4, 3, 1}};

    int boardAns[5][5] = {0};

    if (findPath(board, 5, 0, 0, boardAns))
        cout << "Solution Possible";
    else
        cout << "Not possible";

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << boardAns[i][j] << " ";
        cout << endl;
    }
}