#include <iostream>
#include <string>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    int weight;
    node *next;

    node()
    {
        data = 0;
        weight = 0;
        next = NULL;
    }

    node(int d, int w)
    {
        data = d;
        weight = w;
        next = 0;
    }
};

class Graph
{
public:
    int vertices;
    node **adjList;

    Graph(int v)
    {
        vertices = v;
        adjList = new node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = NULL;
        }
    }

    void AddEdge(int a, int b, int w, bool directed)
    {

        node *newnode = new node(b, w);
        if (adjList[a] == 0)
            adjList[a] = newnode;
        else
        {
            newnode->next = adjList[a];
            adjList[a] = newnode;
        }

        if (!directed)
        {
            node *newnode2 = new node(a, w);
            if (adjList[b] == 0)
                adjList[b] = newnode2;
            else
            {
                newnode2->next = adjList[b];
                adjList[b] = newnode2;
            }
        }
    }

    void Display()
    {

        for (int i = 0; i < vertices; i++)
        {
            cout << "link[" << i << "] ---> ";
            node *temp = adjList[i];

            do
            {
                if (temp == 0)
                {
                    cout << "NULL";
                    break;
                }
                else
                {

                    cout << "(" << temp->data << "," << temp->weight << ") --->";
                }
                temp = temp->next;
            } while (temp != 0);

            cout << endl;
        }
    }

    void shortestPath(int s_vertex, int **distance)
    {

        for (int i = 0; i < vertices; i++)
        {
            distance[s_vertex][i] = 10000;
        }
        bool *visited = new bool[vertices]{false};
        queue<int> q;
        distance[s_vertex][s_vertex] = 0;
        visited[s_vertex] = true;
        q.push(s_vertex);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            node *temp = adjList[curr];
            while (temp != 0)
            {

                if (!visited[temp->data])
                {

                    visited[temp->data] = true;
                    q.push(temp->data);
                }

                if (distance[s_vertex][curr] + temp->weight < distance[s_vertex][temp->data])
                {
                    distance[s_vertex][temp->data] = distance[s_vertex][curr] + temp->weight;
                }
                temp = temp->next;
            }
        }
    }

    void FindCentralNode()
    {

        int **distance = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            distance[i] = new int[vertices];
            shortestPath(i, distance);
        }

        int min = 100000;
        int min_index = 0;
        for (int i = 0; i < vertices; i++)
        {
            int sum = 0;
            for (int j = 0; j < vertices; j++)
            {
                sum += distance[i][j];
            }
            if (sum < min)
            {

                min = sum;
                min_index = i;
            }
        }

        cout << "The Central Node is: " << min_index;
    }
};

int main()
{
    int v, to = 0, from, w;
    cout << "Enter no of vertices: ";
    cin >> v;
    Graph g(v);

    /*  0 1 4
        1 3 3
        2 3 4
        2 0 5
        4 0 3
        4 1 2
        4 2 1
        4 3 1
*/
    while (to != -1)
    {
        cout << "Enter From :";
        cin >> from;
        cout << "Enter To: ";
        cin >> to;
        cout << "Enter Weights: ";
        cin >> w;
        g.AddEdge(from, to, w, false);
        cout << endl;
    }

    g.Display();
    cout << endl;
    g.FindCentralNode();
}