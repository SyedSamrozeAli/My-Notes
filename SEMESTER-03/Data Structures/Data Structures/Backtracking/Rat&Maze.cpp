#include <iostream>
#include <string>
#include <time.h>

using namespace std;
bool isSafe(int **maze, int row, int x, int y)
{
    if (x < row && x >= 0 && y < row && y >= 0 && maze[x][y] == 0)
        return true;

    return false;
};

bool findPath(int **maze, int row, int x, int y, int **mazeAns)
{

    if (x == row - 2 && y == 0 && maze[x][y] == 0)
    {
        mazeAns[x][y] = 0;
        return true;
    }

    if (isSafe(maze, row, x, y))

    {
        if (mazeAns[x][y] != 0)
        {
            mazeAns[x][y] = 0;
            if (findPath(maze, row, x, y - 1, mazeAns)) // move left
                return true;
            if (findPath(maze, row, x, y + 1, mazeAns)) // move right
                return true;
            if (findPath(maze, row, x - 1, y, mazeAns)) // move up
                return true;
            if (findPath(maze, row, x + 1, y, mazeAns)) // move down
                return true;

            mazeAns[x][y] = 1; // backtracking
            return false;
        }

        return false;
    }
}
int main()
{
    srand(time(0));
    int row, col;

    cout << "Enter the no.of rows of board: ";
    cin >> row;

    cout << "Enter the no.of rows of board: ";
    cin >> col;

    int **maze = new int *[row];
    int **mazeAns = new int *[row];

    for (int i = 0; i < row; i++)
    {
        maze[i] = new int[col];
        mazeAns[i] = new int[col];

        for (int j = 0; j < col; j++)
        {
            int n = rand() % 5;
            if (n <= 3)
            {
                maze[i][j] = 0;
            }
            else
            {
                maze[i][j] = 1;
            }

            mazeAns[i][j] = 1;
        }
    }

    cout << endl;
    maze[1][col - 1] = 0;
    maze[row - 2][0] = 0;

    // mazeAns[1][col - 1] = 1;
    // mazeAns[row - 2][0] = 1;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    if (findPath(maze, row, 1, col - 1, mazeAns))
        cout << "Solution Possible";
    else
        cout << "Not possible";

    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << mazeAns[i][j] << " ";
        cout << endl;
    }
}

/*

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void print(int **maze, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
}

bool findPath(int **maze, int row, int x, int y, int **mazeAns)
{

    if (x == row - 2 && y == 0 && maze[x][y] == 0)
    {
        mazeAns[x][y] = 0;
        return true;
    }

    if (y - 1 < row && y - 1 >= 0 && maze[x][y - 1] == 0)
    { /// for moving left

        if (mazeAns[x][y - 1] != 0) // checking visited agr visited nhi ha to waha par 0 place krdega
        {

            mazeAns[x][y - 1] = 0;
            if (findPath(maze, row, x, y - 1, mazeAns))
                return true;
        }
    }

    if (y + 1 < row && y + 1 >= 0 && maze[x][y + 1] == 0)
    { /// for moving right
        if (mazeAns[x][y + 1] != 0)
        {

            mazeAns[x][y + 1] = 0;
            if (findPath(maze, row, x, y + 1, mazeAns))
                return true;
        }
    }

    if (x - 1 < row && x - 1 >= 0 && maze[x - 1][y] == 0)
    { /// for moving up
        if (mazeAns[x - 1][y] != 0)
        {

            mazeAns[x - 1][y] = 0;
            if (findPath(maze, row, x - 1, y, mazeAns))
                return true;
        }
    }

    if (x + 1 < row && x + 1 >= 0 && maze[x + 1][y] == 0)
    { /// for moving down
        if (mazeAns[x + 1][y] != 0)
        {

            mazeAns[x + 1][y] = 0;
            if (findPath(maze, row, x + 1, y, mazeAns))
                return true;
        }
    }

    mazeAns[x][y] = 1; // backtracking
    return false;
}

int main()
{
    srand(time(0));
    int row, col;

    cout << "Enter the no.of rows of board: ";
    cin >> row;

    cout << "Enter the no.of rows of board: ";
    cin >> col;

    int **maze = new int *[row];
    int **mazeAns = new int *[row];

    for (int i = 0; i < row; i++)
    {
        maze[i] = new int[col];
        mazeAns[i] = new int[col];

        for (int j = 0; j < col; j++)
        {
            int n = rand() % 5;
            if (n <= 3)
            {
                maze[i][j] = 0;
            }
            else
            {
                maze[i][j] = 1;
            }

            mazeAns[i][j] = 1;
        }
    }

    cout << endl;
    maze[1][col - 1] = 0;
    maze[row - 2][0] = 0;

    mazeAns[1][col - 1] = 0;
    // mazeAns[row - 2][0] = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    if (findPath(maze, row, 1, col - 1, mazeAns))
        cout << "Solution Possible";
    else
        cout << "Not possible";

    cout << endl;

    print(mazeAns, row, col);
}

*/
