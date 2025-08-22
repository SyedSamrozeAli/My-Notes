#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
template <class T>
class node2
{
public:
    T data;
    node2 *next;

    node2(T d)
    {
        data = d;
        next = 0;
    }
};

template <class U>
class Queue
{

public:
    node2<U> *front, *rear;

    Queue()
    {
        front = rear = 0;
    }

    void enqueue(U d)
    {

        node2<U> *newnode = new node2<U>(d);

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

            node2<U> *temp = front;
            front = front->next;
            free(temp);
        }
    }

    U peek()
    {

        if (!isEmpty())
            return front->data;

        cout << "Queue is Empty!";
        return NULL;
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
        node2<U> *temp = front;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = 0;
    }

    node *CreateTree()
    {

        int x;

        cout << "Enter data: ";
        cin >> x;

        if (x == -1)
        {
            return NULL;
        }

        node *newnode = new node(x);
        cout << "Enter left of " << x << endl;
        newnode->left = CreateTree();
        cout << "Enter right of " << x << endl;
        newnode->right = CreateTree();

        return newnode;
    }

    void levelOrderTraversal()
    {

        Queue<node *> q;
        q.enqueue(root);
        q.enqueue(NULL);

        while (!q.isEmpty())
        {
            node *temp = q.peek();
            q.dequeue();

            if (temp == NULL) // using NULL as a seperator taake jab jab NULL aye to hum next line par chale jayenge
            {
                cout << endl;
                if (!q.isEmpty()) // agr queue empty nhi iska matlab ek level or bacha wa ha to uske aage bhi NULL laga denge
                {
                    q.enqueue(NULL);
                }
            }
            else
            {

                cout << temp->data << " ";

                if (temp->left != NULL)
                {
                    q.enqueue(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.enqueue(temp->right);
                }
            }
        }
    }

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void PostOrder(node *root)
    {
        if (root == NULL)
            return;

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

    void InOrder(node *root)
    {
        if (root == NULL)
            return;

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
};

int main()
{
    BinaryTree b;
    b.root = b.CreateTree();
    b.levelOrderTraversal();
}