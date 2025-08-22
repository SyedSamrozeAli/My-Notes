#include <iostream>
#include <string>
#include <queue>

using namespace std;
template <class T>
class Snode
{
public:
    T data;
    Snode *next;

    Snode(T d)
    {
        data = d;
        next = 0;
    }
};

template <class T>
class stack
{
public:
    Snode<T> *top;

    stack()
    {
        top = 0;
    }

    void push(T d)
    {
        Snode<T> *newSnode = new Snode<T>(d);

        if (top == 0)
        {
            top = newSnode;
        }
        else
        {
            newSnode->next = top;
            top = newSnode;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty!";
        }
        else
        {

            Snode<T> *temp = top;
            top = top->next;
            free(temp);
        }
    }

    T peek()
    {

        if (!isEmpty())
            return top->data;

        cout << "Stack is Empty!";
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }

        return false;
    }
    void display()
    {
        Snode<T> *temp = top;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = 0;
    }

    node(int d)
    {
        data = d;
        next = 0;
    }
};

class HashTable
{
public:
    node **links;
    int size;

    HashTable()
    {
        size = 0;
    }
    void Intialize(int s)
    {
        size = s;
        links = new node *[size];
        for (int i = 0; i < size; i++)
        {
            links[i] = NULL;
        }
    }

    void Insert(int a, int b)
    {
        int key = a;
        node *newnode = new node(b);

        if (links[key] == NULL)
        {
            links[key] = newnode;
        }
        else
        {
            newnode->next = links[key];
            links[key] = newnode;
        }
    }

    void Delete(int val)
    {
        int key = HashFunction(val);

        node *curr = links[key];
        node *prev = NULL;
        while (curr != 0 && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        // Deletion at Head
        if (curr == links[key])
        {
            links[key] = curr->next;
            delete curr;
            return;
        }

        // Deletion at Specific position or At END
        node *temp = curr;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    void Search(int val)
    {
        int key = HashFunction(val);
        node *temp = links[key];
        while (temp != 0 && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == 0)
            cout << "Value Not Found!";
        else
        {

            cout << "Value is found!";
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "link[" << i << "] ---> ";
            node *temp = links[i];
            do
            {
                if (temp == 0)
                {
                    cout << "NULL";
                }
                else
                {
                    cout << temp->data << " ---> ";
                    temp = temp->next;
                }

            } while (temp != 0);

            cout << endl;
        }
    }
    int HashFunction(int val)
    {

        return val % size;
    }
};

class Graph
{
public:
    int vertices;
    HashTable AdjList;
    int *inDegArr;

    Graph(int v)
    {
        vertices = v;
        AdjList.Intialize(v);
        inDegArr = new int[vertices]{0};
    }
    // a ----> b && bool indicates directed or undirected
    void AddEdge(int a, int b, bool directed)
    {
        AdjList.Insert(a, b);
        inDegArr[b]++;
        if (!directed)
            AdjList.Insert(b, a);
    }

    // Cycle detection in Undirected graph using BFS
    bool CycleDetectionBFS_Undirected(int s_vertex)
    {

        queue<int> q;
        bool *visited = new bool[vertices]{false};
        int *parent = new int[vertices];

        for (int i = 0; i < vertices; i++)
            parent[i] = -1;

        q.push(s_vertex);
        parent[s_vertex] = -2;
        visited[s_vertex] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // cout << curr << "";
            node *temp = AdjList.links[curr];
            while (temp != 0)
            {

                // if (parent[temp->data] == -1)
                // {
                //     parent[temp->data] = curr;
                // }

                if (parent[curr] != temp->data && visited[temp->data])
                {
                    return false;
                }
                if (!visited[temp->data])
                {
                    q.push(temp->data);
                    visited[temp->data] = true;
                    parent[temp->data] = curr;
                }

                temp = temp->next;
            }
        }
        return true;
    }
    bool CycleDetectionBFSDirected(int s_vertex)
    {
        int *result = new int[vertices]{0};
        int ctr = 0;
        int *indegree = new int[vertices]{0};
        for (int i = 0; i < vertices; i++)
            indegree[i] = inDegArr[i];

        queue<int> q;

        // pushing all vertices having indegree 0
        for (int i = 0; i < vertices; i++)
        {
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {

            int curr = q.front();
            ctr++;
            q.pop();

            node *temp = AdjList.links[curr];
            while (temp != 0)
            {
                indegree[temp->data]--;
                if (!indegree[temp->data])
                {

                    q.push(temp->data);
                }

                temp = temp->next;
            }
        }

        // no.ofelements in topo sort is equal to total verices then a valid topolofical sort which mean no cycle
        if (ctr == vertices)
            return false;
        else
            return true;
    }
    // Cycle detection in Undirected graph using DFS
    bool CycleDetectionDFS_Undirected(int s_vertex)
    {
        stack<int> s;
        bool *visited = new bool[vertices]{false};
        int *parents = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            parents[i] = -1;
        }
        s.push(s_vertex);
        visited[s_vertex] = true;
        cout << s.peek() << " ";

        while (!s.isEmpty())
        {

            int curr = s.peek();
            node *temp = AdjList.links[curr];

            while (temp != 0)
            {

                if (parents[curr] != temp->data && visited[temp->data] && parents[temp->data] != curr)
                    return false;

                if (!visited[temp->data])
                {
                    s.push(temp->data);
                    cout << temp->data << " ";
                    visited[temp->data] = true;
                    parents[temp->data] = curr;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }

            if (temp == 0)
            {

                s.pop();
            }
        }

        return true;
    }

    bool CycleDetectionDFS_Directed(int s_vertex)
    {

        stack<int> s;
        bool *visited = new bool[vertices]{false};
        bool *DFSvisited = new bool[vertices]{false};
        s.push(s_vertex);
        visited[s_vertex] = true;
        DFSvisited[s_vertex] = true;

        while (!s.isEmpty())
        {
            int curr = s.peek();
            node *temp = AdjList.links[curr];
            while (temp != 0)
            {
                if (visited[temp->data] && DFSvisited[temp->data])
                    return false;

                if (!visited[temp->data])
                {
                    s.push(temp->data);
                    visited[temp->data] = true;
                    DFSvisited[temp->data] = true;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }

            if (temp == 0)
            {
                DFSvisited[curr] = false;
                s.pop();
            }
        }
        return true;
    }
};
int main()
{
    int v;
    int from, to;
    cout << "Enter no.of Vertices: ";
    cin >> v;
    Graph g(v);
    /*
 0 1
 1 2
 1 3
 2 4
 3 4
 4 5

for directed
 0 1
 1 2
 1 3
 2 4
 4 3
 5 4
 */
    /*
     0 1
     0 3
     1 5
     1 6
     1 2
     1 3
     2 3

     2 4
     2 5
     3 4
     4 6
     */
    while (to != -1)
    {
        cout << "Enter From :";
        cin >> from;
        cout << "Enter To: ";
        cin >> to;
        g.AddEdge(from, to, true);
        cout << endl;
    }
    cout << endl;
    g.AdjList.Display();
    if (g.CycleDetectionDFS_Directed(0))
    {
        cout << "Cycle not detected!" << endl;
    }
    else
    {
        cout << "Cycle Detected!" << endl;
    }
}