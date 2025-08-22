#include <iostream>
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

    void bfs(int s_vertex, bool *visited)
    {

        queue<int> q;
        q.push(s_vertex);
        visited[s_vertex] = true;

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

                temp = temp->next;
            }
        }
    }

    bool isConnected()
    {

        bool *visited = new bool[vertices]{false};
        bfs(0, visited);
        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
                return false;
        }

        return true;
    }
};

int main()
{
    int v, to = 0, from, w;
    cout << "Enter no of vertices: ";
    cin >> v;
    Graph g(v);

    /*


    0 1 0
    0 2 0
    1 2 0
    2 3 0
    3 4 0
    3 5 0
    4 5 0




*/
    while (to != -1)
    {
        cout << "Enter From :";
        cin >> from;
        cout << "Enter To: ";
        cin >> to;
        if (to == -1)
            break;
        cout << "Enter Weights: ";
        cin >> w;

        g.AddEdge(from, to, w, false);
        cout << endl;
    }

    g.Display();
    cout << endl;

    if (g.isConnected())
        cout << "Connected graph!" << endl;
    else
        cout << "Disconnected Graph!" << endl;
}