#include <iostream>
#include <queue>

using namespace std;

// template <class T, class U>
// class pairs
// {

// public:
//     T first;
//     U second;

//     pair(T f, U s)
//     {
//         first = f;
//         second = s;
//     }

//     pair()
//     {
//         first = 0;
//         second = 0;
//     }
// };

void noOfIslands(int matrix[8][8], int n)
{

    bool **visited = new bool *[n];
    int ctr = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n]{false};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (matrix[i][j] != 0 && !visited[i][j])
            {

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                ctr++;
                while (!q.empty())
                {

                    int c_row = q.front().first;
                    int c_col = q.front().second;
                    q.pop();

                    for (int delRow = -1; delRow <= 1; delRow++)
                    {
                        for (int delCol = -1; delCol <= 1; delCol++)
                        {
                            if (c_row + delRow < n && c_row + delRow >= 0 && c_col + delCol < n && c_col + delCol >= 0 && matrix[c_row + delRow][c_col + delCol] != 0 && !visited[c_row + delRow][c_col + delCol])
                            {
                                visited[c_row + delRow][c_col + delCol] = true;
                                q.push(make_pair(c_row + delRow, c_col + delCol));
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No.of Islands: " << ctr;
};
int main()
{

    int matrix[8][8] = {{1, 0, 1, 1, 0, 0, 1, 1},
                        {1, 1, 0, 0, 0, 0, 1, 1},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 1, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 1, 0, 0, 0, 0},
                        {1, 0, 1, 1, 0, 1, 1, 1}};

    noOfIslands(matrix, 8);
}