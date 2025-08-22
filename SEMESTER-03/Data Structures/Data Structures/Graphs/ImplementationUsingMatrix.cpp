#include <iostream>
#include <queue>
using namespace std;

// sir meri queue ki class me masla aarha tha is waja se stl waali use krli
template <class T>
class Queue
{

public:
    class node
    {
    public:
        int data;
        node *next;

        node(int d)
        {
            data = d;
            next = 0;
        }
    };
    node *front, *rear;

    Queue()
    {
        front = rear = 0;
    }

    void push(T d)
    {

        node *newnode = new node(d);

        if (rear == 0)
        {
            front = rear = newnode;
        }
        else
        {

            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue()
    {

        if (front == 0)
        {
            cout << "Queue is Empty!";
        }
        else
        {

            node *temp = front;
            front = front->next;
            free(temp);
        }
    }

    T peek()
    {

        if (!isEmpty())
            return front->data;

        cout << "Queue is Empty!";
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }

        return false;
    }
    void display()
    {
        node *temp = front;

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

    node(int d)
    {
        data = d;
        next = 0;
    }
};
template <class T>
class stack
{
public:
    class node
    {
    public:
        int data;
        node *next;

        node(int d)
        {
            data = d;
            next = 0;
        }
    };
    node *top;

    stack()
    {
        top = 0;
    }

    void push(T d)
    {
        node *newnode = new node(d);

        if (top == 0)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
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

            node *temp = top;
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
        node *temp = top;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class graph
{
private:
    int vertices;
    int adjMatrix[4][4];

public:
    graph(int v)
    {
        vertices = v;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int x, int y)
    {
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    void BFS(int vertex)
    {
        bool visited[4] = {false};
        queue<int> q;
        q.push(vertex);
        while (!q.empty())
        {
            int temp = q.front();
            visited[temp] = true;
            q.pop();

            cout << temp << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[temp][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void DFS(int vertex)
    {
        bool visited[4] = {false};
        stack<int> s;
        s.push(vertex);
        while (!s.isEmpty())
        {
            int temp = s.peek();
            visited[temp] = true;
            s.pop();

            cout << temp << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[temp][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
    }
};

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << "BFS : ";
    g.BFS(0);
    cout << endl;
    cout << "DFS : ";
    g.DFS(0);

    return 0;
}
