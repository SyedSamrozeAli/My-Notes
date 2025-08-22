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
    int weight;
    node *next;

    node()
    {
        data = 0;
        weight = 0;
        next = 0;
    }

    node(int d, int w)
    {
        data = d;
        weight = w;
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

    void Insert(int a, int b, int w)
    {
        int key = a;
        node *newnode = new node(b, w);

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
                    cout << "(" << temp->data << ", " << temp->weight << ")"
                         << " ---> ";
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
    void AddEdge(int a, int b, bool directed, int weight)
    {
        AdjList.Insert(a, b, weight);
        inDegArr[b]++;
        if (!directed)
            AdjList.Insert(b, a, weight);
    }

    // in undirected graph
    void ShortestPath(int src, int dest)
    {
        int *parent = new int[vertices];

        bool *visited = new bool[vertices]{false};

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            node *temp = AdjList.links[curr];

            while (temp != 0)
            {

                if (!visited[temp->data])
                {
                    visited[temp->data] = true;
                    q.push(temp->data);
                    parent[temp->data] = curr;
                }

                temp = temp->next;
            }
        }

        stack<int> s;
        int index = dest;
        s.push(index);
        while (index != src)
        {
            index = parent[index];
            s.push(index);
        }

        // result hamara reverse order mein hoga jabhi stack mei store kia taake reverse kr sakein
        int shortestPath[10];
        int i = 0;
        while (!s.isEmpty())
        {
            shortestPath[i] = s.peek();
            s.pop();
            i++;
        }

        for (int j = 0; j < i; j++)
            cout << shortestPath[j] << " ";
    }

    void shortesPathinDAG(int s_vertex)
    {
        int *distance = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            distance[i] = 10000;
        }
        bool *visited = new bool[vertices]{false};
        queue<int> q;
        distance[s_vertex] = 0;
        visited[s_vertex] = true;
        q.push(s_vertex);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            node *temp = AdjList.links[curr];
            while (temp != 0)
            {

                if (!visited[temp->data])
                {

                    visited[temp->data] = true;
                    q.push(temp->data);
                }

                if (distance[curr] + temp->weight < distance[temp->data])
                {
                    distance[temp->data] = distance[curr] + temp->weight;
                }
                temp = temp->next;
            }
        }

        for (int i = 0; i < vertices; i++)
        {
            cout << distance[i] << " ";
        }
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

 0 1
 0 5
 0 6
 1 2
 2 3
 3 4
 4 9
 6 7
 7 8
 8 9
 5 10
 10 11
 11 12
 12 4


for shortestpathDAG
    0 1 2
    0 2 1
    1 3 3
    2 3 2
    3 4 3
    3 5 -1
    4 5 2

 */
    /*
    for shortestpathDAG
    0 1 5
    0 2 3
    1 2 2
    1 3 6
    2 3 7
    2 4 4
    2 5 2
    3 4 -1
    4 5 -2
     */
    while (to != -1)
    {
        int weight;
        cout << "Enter From :";
        cin >> from;
        cout << "Enter To: ";
        cin >> to;
        cout << "Enter weight: ";
        cin >> weight;
        g.AddEdge(from, to, true, weight);
        cout << endl;
    }
    cout << endl;
    g.AdjList.Display();
    g.shortesPathinDAG(0);
}