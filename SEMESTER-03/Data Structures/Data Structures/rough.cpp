#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    int weight;
    Node() : data(0), weight(0) {}
    Node(int a, int b) : data(a), weight(b) {}
};

void Heapify_Min(Node **arr, int size, int index)
{
    int smallest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && arr[leftChild]->weight < arr[smallest]->weight)
    {
        smallest = leftChild;
    }
    if (rightChild <= size && arr[rightChild]->weight < arr[smallest]->weight)
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        swap(arr[index], arr[smallest]);
        Heapify_Min(arr, size, smallest);
    }
}

class Priority_Queue
{
public:
    Node **arr;
    int size;

    // Constructor to allocate memory for the array and initialize size
    Priority_Queue(int a)
    {

        size = 0;
        arr = new Node *[a];
        for (int i = 0; i < a; i++)
        {
            arr[i] = new Node(0, 0);
        }
    }

    // Push a new Node onto the priority queue
    void Push(int a, int b)
    {
        Node *newNode = new Node(a, b);
        arr[++size] = newNode;
        int ind = size;
        while (ind > 1 && arr[ind]->weight < arr[ind / 2]->weight)
        {
            swap(arr[ind], arr[ind / 2]);
            ind = ind / 2;
        }
    }

    int pop()
    {
        if (size == 0)
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        Node *temp = arr[1];
        swap(arr[1], arr[size--]);
        Heapify_Min(arr, size, 1);
        return temp->data;
    }

    // Check if the priority queue is empty
    bool isEmpty()
    {
        return (size == 0) ? true : false;
    }
};
class Node1
{
public:
    int data{};
    int weight{};
    Node1 *next;
    Node1() {}
    Node1(int a, int b) : data(a), weight(b), next(NULL) {}
};
class HashTable
{
public:
    Node1 **table;
    int size;
    HashTable(int a) : size(a), table(new Node1 *[size])
    {
        for (int i = 0; i < size; i++)
        {
            table[i] = new Node1;
        }
    }

    void Insert(int a, int b, int w)
    {
        int key = a;
        Node1 *newnode = new Node1(b, w);

        if (table[key] == NULL)
        {
            table[key] = newnode;
        }
        else
        {
            newnode->next = table[key];
            table[key] = newnode;
        }
    }
    void Print()
    {

        for (int i = 0; i < size; i++)
        {
            cout << "link[" << i << "] ---> ";
            Node1 *temp = table[i];
            do
            {
                if (temp == 0)
                {
                    cout << "NULL";
                }
                else
                {
                    cout << temp->data << "," << temp->weight << " ---> ";
                    temp = temp->next;
                }

            } while (temp != 0);

            cout << endl;
        }
    }
};
class Graph
{
public:
    HashTable *list;
    int vertices;
    Graph(int a) : vertices(a), list(new HashTable(a)) {}
    // assuming Undirected Graph
    void addEdge(int a, int b, int c)
    {
        list->Insert(a, b, c);
        list->Insert(b, a, c);
    }
    void Print()
    {
        list->Print();
    }
    void PrimsAlgorithm(int startingVertex)
    {
        int MST = 0;
        int *dis = new int[vertices];
        int *parent = new int[vertices];
        bool *visited = new bool[vertices]{false};
        for (int i = 0; i < vertices; i++)
        {
            dis[i] = INT_MAX;
            parent[i] = -1;
        }
        Priority_Queue pq(vertices);
        pq.Push(startingVertex, 0);
        dis[startingVertex] = 0;
        visited[startingVertex] = true;
        while (!pq.isEmpty())
        {

            int cur = pq.pop();
            if (cur == 0)
            {
                break;
            }
            Node1 *temp = list->table[cur];

            while (temp != NULL)
            {
                if ((!visited[temp->data]) && (dis[cur] + temp->weight < dis[temp->data]))
                {
                    dis[temp->data] = dis[cur] + temp->weight;
                    visited[temp->data] = true;
                    parent[temp->data] = cur;
                    MST += temp->weight;
                    pq.Push(temp->data, dis[temp->data]);
                }
            }
            temp = temp->next;
        }
        cout << "Minimum Spanning Tree Size is: " << MST << endl;
    }
};

int main()
{

    Graph graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 4, 2);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 1);
    cout << "Adjacency List:\n";
    graph.Print();
    // graph.PrimsAlgorithm(0);
}
