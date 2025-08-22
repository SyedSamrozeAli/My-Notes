#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <queue>

using namespace std;
int CPUstorage = 0;
class process
{

public:
    int priority;
    int RAM;
    int runningTime;
    int TimeToComplete;
    bool state;

    process()
    {
        priority = 0;
        RAM = 0;
        runningTime = 0;
        TimeToComplete = 0;
        state = 0;
    }
    process(int p, int r, int t, bool s)
    {
        priority = p;
        RAM = r;
        runningTime = 0;
        TimeToComplete = t;
        state = s;
    }
};

class node
{
public:
    process p;
    int data;
    node *left;
    node *right;
    node *parent;
    int priority;

    node(process p)
    {
        this->p = p;
        priority = p.priority;
        left = 0;
        right = 0;
        parent = 0;
    }
};

class PriorityQueue
{

public:
    node *root;

    PriorityQueue()
    {
        root = 0;
    }

    node *InsertMaxHeapify(process p)
    {
        if (root == NULL)
        {
            root = new node(p);
        }
        else
        {
            queue<node *> q;
            q.push(root);
            while (!q.empty())
            {
                node *temp = q.front();
                q.pop();

                if (temp->left == NULL)
                {
                    temp->left = new node(p);

                    temp->left->parent = temp;
                    MaxHeapifyUp(temp->left);
                    break;
                }
                else
                {
                    q.push(temp->left);
                }

                if (temp->right == NULL)
                {

                    temp->right = new node(p);
                    temp->right->parent = temp;
                    MaxHeapifyUp(temp->right);
                    break;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }

        return root;
    }
    void MaxHeapifyUp(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->parent != NULL && root->data > root->parent->data)
        {
            swap(root->data, root->parent->data);
            MaxHeapifyUp(root->parent);
        }
        else
        {
            return;
        }
    }
    node *Delete(node *root)
    {

        if (root == NULL)
            return NULL;

        root = DeleteNode(root);
        root = MaxHeapifyDown(root);
        // root = MinHeapifyDown(root);
        return root;
    }

    node *DeleteNode(node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete (root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete (root);
            return temp;
        }
        else
        {

            // This code is for deleting a node by swapping nodes
            node *temp = ReturnLastNode(root);
            if (temp != root->left)
                temp->left = root->left;

            if (temp != root->right)
                temp->right = root->right;

            if (temp->parent->right)
                temp->parent->right = NULL;
            else
                temp->parent->left = NULL;

            delete (root);
            return temp;
        }
    }
    node *ReturnLastNode(node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            queue<node *> q;
            q.push(root);
            node *prev = 0;

            while (!q.empty())
            {

                node *temp = q.front();
                q.pop();

                if (temp == NULL)
                {
                    return prev;
                }

                if (temp->left == NULL)
                {
                    q.push(NULL);
                }
                else
                {
                    q.push(temp->left);
                }

                if (temp->right == NULL)
                {
                    q.push(NULL);
                }
                else
                {
                    q.push(temp->right);
                }

                prev = temp;
            }
        }

        return root;
    }
    node *MaxHeapifyDown(node *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        node *MaxChild = FindMaxNode(root->left, root->right);

        if (MaxChild)
        {
            cout << MaxChild->data << endl;
            // if (MaxChild->data > root->data)
            // {

            node *temp = root;
            root = swapNodes(root, MaxChild);
            if (temp == root->left)
                root->left = MaxHeapifyDown(temp);
            else
                root->right = MaxHeapifyDown(temp);
            //}
        }

        return root;
    }
    node *swapNodes(node *A, node *B)
    {
        node *temp;
        temp->left = B->left;
        temp->right = B->right;

        if (B != A->left)
        {
            B->left = A->left;
        }
        else
        {
            B->left = A;
        }

        if (B != A->right)
        {
            B->right = A->right;
        }
        else
        {
            B->right = A;
        }

        A->left = temp->left;
        A->right = temp->right;

        return B;
    }
    node *FindMaxNode(node *LeftChild, node *RightChild)
    {
        if (LeftChild && RightChild)
        {
            if (LeftChild->data > RightChild->data)
                return LeftChild;
            else
                return RightChild;
        }
        if (LeftChild)
        {
            return LeftChild;
        }

        if (RightChild)
        {
            return RightChild;
        }

        return NULL; /// if both left and right child are NULL
    }
    node *peek()
    {

        if (root == NULL)
            return root;

        cout << "Queue is Empty!";
    }

    bool incrementProcess(node *root)
    {

        bool flag = false;

        if (root->p.runningTime < root->p.TimeToComplete)
        {
            root->p.runningTime++;
        }
        else
        {

            Delete(root);

            flag = true;
        }

        incrementProcess(root->left);
        incrementProcess(root->right);

        return flag;
    }
    void display(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {

            cout << "Priority: " << root->p.priority << endl;
            cout << "RAM: " << root->p.RAM << endl;
            cout << "Running Time: " << root->p.runningTime << endl;
            cout << "Time To Complete: " << root->p.TimeToComplete << endl;
            cout << endl;
            display(root->left);
            display(root->right);
        }
    }
};
PriorityQueue waitingQ;
PriorityQueue runningQ;

int main()
{
    srand(time(0));
    int RAM, priority, time;
    for (int i = 1; i <= 50; i++)
    {

        int n = (rand() % 100) + 1;

        //  Check if the process should spawn
        if (n <= 50)
        {
            // cout << "here";
            RAM = (rand() % 500) + 1;
            time = (rand() % 10) + 1;
            priority = (rand() % 20) + 1;

            process p(priority, RAM, time, 1);

            cout << p.priority << endl;
            cout << p.RAM << endl;
            cout << endl;

            if (CPUstorage + p.RAM > 500)
            {
                if (p.priority < runningQ.root->p.priority)
                {
                    cout << "here1" << endl;
                    node *temp = runningQ.Delete(runningQ.root);
                    CPUstorage -= temp->p.RAM;
                    waitingQ.InsertMaxHeapify(temp->p);
                    runningQ.InsertMaxHeapify(p);
                    CPUstorage += p.RAM;

                    delete temp;
                }
                else
                {
                    cout << "here2" << endl;
                    waitingQ.InsertMaxHeapify(p);
                }
            }
            else
            {
                if (waitingQ.root)
                {
                    cout << "here3" << endl;
                    node *temp = waitingQ.Delete(waitingQ.root);
                    cout << temp->p.RAM << endl;
                    runningQ.InsertMaxHeapify(temp->p);
                    CPUstorage += temp->p.RAM;
                    waitingQ.InsertMaxHeapify(p);
                    delete temp;
                }
                else
                {
                    cout << "here4" << endl;
                    runningQ.InsertMaxHeapify(p);
                    CPUstorage += p.RAM;
                }
            }
        }

        runningQ.incrementProcess(runningQ.root);
        cout << "CPU Storage: " << CPUstorage << endl;
        cout << "RUNNING QUEUE: " << endl
             << endl;
        runningQ.display(runningQ.root);

        cout << "WAITING QUEUE: " << endl
             << endl;

        waitingQ.display(waitingQ.root);
    }
}