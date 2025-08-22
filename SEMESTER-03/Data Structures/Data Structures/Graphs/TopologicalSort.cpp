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

    void TopologicalSortDFS(int s_vertex)
    {

        stack<int> s;
        stack<int> sort;

        bool *visited = new bool[vertices]{false};
        visited[s_vertex] = true;
        s.push(s_vertex);

        while (!s.isEmpty())
        {
            int curr = s.peek();
            node *temp = AdjList.links[curr];

            while (temp != 0)
            {

                if (!visited[temp->data])
                {
                    s.push(temp->data);
                    visited[temp->data] = true;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }

            if (temp == 0)
            {
                sort.push(s.peek());
                s.pop();
            }
        }

        while (!sort.isEmpty())
        {
            cout << sort.peek() << " ";
            sort.pop();
        }
    }

    void TopologicalSortBFS_KahnsAlgo()
    {

        int *result = new int[vertices]{0};
        int index = 0;
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
            result[index] = curr;
            index++;
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

        for (int i = 0; i < vertices; i++)
        {
            cout << result[i] << " ";
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
    0 2
    1 3
    2 3
    3 4
    3 5
    4 5
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
    // g.TopologicalSortDFS(0);
    g.TopologicalSortBFS_KahnsAlgo();
}