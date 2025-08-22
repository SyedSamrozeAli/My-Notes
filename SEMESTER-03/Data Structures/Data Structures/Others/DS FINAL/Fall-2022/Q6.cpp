#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

class node
{

public:
    int data;
    node *parent;
    node *left;
    node *right;

    node()
    {
        data = 0;
        parent = 0;
        left = NULL;
        right = NULL;
    }

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Heap
{
public:
    int size;
    node *root;

    Heap()
    {

        size = 0;
    }

    node *InsertMaxHeapify(node *root, int val)
    {
        if (root == NULL)
        {
            root = new node(val);
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
                    temp->left = new node(val);

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

                    temp->right = new node(val);
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

    node *InsertMinHeapify(node *root, int val)
    {
        if (root == NULL)
        {
            root = new node(val);
        }
        else
        {
            cout << "here";
            queue<node *> q;
            q.push(root);
            while (!q.empty())
            {
                node *temp = q.front();
                q.pop();

                if (temp->left == NULL)
                {
                    temp->left = new node(val);

                    temp->left->parent = temp;
                    MinHeapifyUp(temp->left);
                    break;
                }
                else
                {
                    q.push(temp->left);
                }

                if (temp->right == NULL)
                {

                    temp->right = new node(val);
                    temp->right->parent = temp;
                    MinHeapifyUp(temp->right);
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

    void MinHeapifyUp(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->parent != NULL && root->data < root->parent->data)
        {
            swap(root->data, root->parent->data);
            MinHeapifyUp(root->parent);
        }
        else
        {
            return;
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

    int Peek()
    {
        if (!root)
            return root->data;
    }
    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void levelOrderTraversal()
    {

        queue<node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp == NULL) // using NULL as a seperator taake jab jab NULL aye to hum next line par chale jayenge
            {
                cout << endl;
                if (!q.empty()) // agr queue empty nhi iska matlab ek level or bacha wa ha to uske aage bhi NULL laga denge
                {
                    q.push(NULL);
                }
            }
            else
            {

                cout << temp->data << " ";

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
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

    node *MaxHeapifyDown(node *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        node *MaxChild = FindMaxNode(root->left, root->right);

        if (MaxChild)
        {

            node *temp = root;
            root = swapNodes(root, MaxChild);
            if (temp == root->left)
                root->left = MaxHeapifyDown(temp);
            else
                root->right = MaxHeapifyDown(temp);
        }

        return root;
    }

    node *MinHeapifyDown(node *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        node *MinChild = FindMinNode(root->left, root->right);

        if (MinChild)
        {

            node *temp = root;
            root = swapNodes(root, MinChild);
            if (temp == root->left)
                root->left = MinHeapifyDown(temp);
            else
                root->right = MinHeapifyDown(temp);
        }

        return root;
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

    node *FindMinNode(node *LeftChild, node *RightChild)
    {
        if (LeftChild && RightChild)
        {
            if (LeftChild->data < RightChild->data)
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

    int ValidHeight(node *root)
    {

        if (root == NULL)
            return -1;

        if ((root->left && root->data > root->left->data) || (root->right && root->data > root->right->data))
            return 1;

        int left = ValidHeight(root->left);
        int right = ValidHeight(root->right);

        if (left > right)
            return ++left;
        else
            return ++right;
    }

    int getHeight(node *root)
    {

        if (root == NULL)
            return -1;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        if (left > right)
            return left++;
        else
            return right++;
    }
};

int main()
{

    Heap h;
    h.root = 0;
    h.root = h.InsertMinHeapify(h.root, 14);
    h.root = h.InsertMinHeapify(h.root, 34);
    h.root = h.InsertMinHeapify(h.root, 27);
    h.root = h.InsertMinHeapify(h.root, 40);
    h.root = h.InsertMinHeapify(h.root, 37);
    h.root = h.InsertMinHeapify(h.root, 54);
    h.root = h.InsertMinHeapify(h.root, 30);
    h.root->left->left->left = new node(13);
    h.root->left->left->right = new node(50);
    h.root->left->right->left = new node(21);
    h.root->left->right->right = new node(39);
    h.root->right->left->left = new node(56);
    h.root->right->left->right = new node(89);

    h.levelOrderTraversal();
    cout << endl;
    cout << h.ValidHeight(h.root);
}