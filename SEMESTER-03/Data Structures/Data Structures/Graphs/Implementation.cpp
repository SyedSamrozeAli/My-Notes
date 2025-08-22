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

    Graph(int v)
    {
        vertices = v;
        AdjList.Intialize(v);
    }
    // a ----> b && bool indicates directed or undirected
    void AddEdge(int a, int b, bool directed)
    {
        AdjList.Insert(a, b);
        if (!directed)
            AdjList.Insert(b, a);
    }

    void BFSTraversal(int s_vertex)
    {
        queue<int> q;
        bool *visited = new bool[vertices]{false};

        q.push(s_vertex);
        visited[s_vertex] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            cout << temp << " ";
            node *temp2 = AdjList.links[temp];
            while (temp2 != 0)
            {
                if (!visited[temp2->data])
                {
                    q.push(temp2->data);
                    visited[temp2->data] = true;
                }
                temp2 = temp2->next;
            }
        }
    }

    // using loops
    void DFSTraversal(int s_vertex)
    {
        stack<int> s;
        s.push(s_vertex);
        bool *visited = new bool[vertices]{false};
        visited[s_vertex] = true;
        cout << s.peek() << " ";
        while (!s.isEmpty())
        {
            int temp = s.peek();
            node *temp2 = AdjList.links[temp];
            while (temp2 != 0)
            {

                if (!visited[temp2->data])
                {
                    s.push(temp2->data);
                    cout << temp2->data << " ";
                    visited[temp2->data] = true;
                    break;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }

            if (temp2 == 0)
                s.pop();
        }
    }

    // using recursion
    void DFFSTraversal(int curr, bool *visited)
    {
        if (!(visited[curr]))
        {
            node *temp = AdjList.links[curr];
            visited[curr] = true;
            cout << curr << " ";
            while (temp != 0)
            {
                DFFSTraversal(temp->data, visited);
                temp = temp->next;
            }
        }

        return;
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
 0 3
 1 2
 1 3
 2 3
 2 4
 3 4
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
        g.AddEdge(from, to, false);
        cout << endl;
    }
    cout << endl;
    g.AdjList.Display();
    stack<int> s;
    bool *visited = new bool[v]{false};

    g.DFFSTraversal(0, visited);
}