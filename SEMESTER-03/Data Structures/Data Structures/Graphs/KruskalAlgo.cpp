#include <iostream>
#include <string>

using namespace std;

class Pairs
{
public:
    int src;
    int dest;
    int weight;

    Pairs(int s, int d, int w)
    {
        src = s;
        dest = d;
        weight = w;
    }
    Pairs()
    {
        src = 0;
        dest = 0;
        weight = 0;
    }
};
int Partition(Pairs *arr, int lb, int ub)
{

    int pivot = arr[lb].weight;
    int start = lb;
    int end = ub;

    while (start < end)
    {

        while (arr[start].weight <= pivot)
            start++;

        while (arr[end].weight > pivot)
            end--;

        if (start < end)
            swap(arr[start], arr[end]);
    }

    swap(arr[lb], arr[end]);

    return end;
}
void QuickSort(Pairs *arr, int lb, int ub)
{

    if (lb < ub)
    {
        int loc = Partition(arr, lb, ub);
        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
}

class DisjointSet
{
public:
    int *size;
    int *parent;
    int totalsize;

    DisjointSet(int s)
    {

        totalsize = s;
        size = new int[s];
        parent = new int[s];

        for (int i = 0; i < totalsize; i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int FindUltimateParent(int node)
    {

        if (node == parent[node])
            return node;

        return parent[node] = FindUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v)
    {

        int up_u = FindUltimateParent(u);
        int up_v = FindUltimateParent(v);

        if (up_u == up_v)
            return;

        if (size[up_u] < size[up_v])
        {

            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
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
    Pairs *Pairarr;
    int pairSize;
    Graph(int v)
    {
        vertices = v;
        adjList = new node *[vertices];
        Pairarr = new Pairs[vertices];
        pairSize = 0;
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = NULL;
        }
    }

    void AddEdge(int a, int b, int w, bool directed)
    {

        node *newnode = new node(b, w);

        Pairarr[pairSize].dest = b;
        Pairarr[pairSize].src = a;
        Pairarr[pairSize].weight = w;

        cout << Pairarr[pairSize].dest << endl;
        cout << Pairarr[pairSize].src << endl;
        cout << Pairarr[pairSize].weight << endl;
        pairSize++;

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

            Pairarr[pairSize].dest = a;
            Pairarr[pairSize].src = b;
            Pairarr[pairSize].weight = w;

            cout << endl;
            cout << Pairarr[pairSize].dest << endl;
            cout << Pairarr[pairSize].src << endl;
            cout << Pairarr[pairSize].weight << endl;
            pairSize++;

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

    void KruskalAlgo_MST()
    {
        QuickSort(Pairarr, 0, pairSize - 1);
        DisjointSet d(vertices);
        int MST = 0;
        for (int i = 0; i < vertices; i++)
        {
            int src = Pairarr[i].src;
            int dest = Pairarr[i].dest;

            if (d.FindUltimateParent(src) != d.FindUltimateParent(dest))
            {
                d.UnionBySize(src, dest);
                MST += Pairarr[i].weight;
            }
        }

        cout << "\n\nMST:" << MST;
    }
};

int main()
{

    int v, to = 0, from, w;
    cout << "Enter no of vertices: ";
    cin >> v;
    Graph g(v);

    /*

    0 3 6
    0 1 2
    1 2 3
    1 4 5
    1 3 8
    2 4 7


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
    g.KruskalAlgo_MST();
}