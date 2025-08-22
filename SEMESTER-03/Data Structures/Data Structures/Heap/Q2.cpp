#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

class BSTnode
{
public:
    int data;
    BSTnode *left;
    BSTnode *right;

    BSTnode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    BSTnode *root;

    BST()
    {
        root = NULL;
    }

    BSTnode *Insert(BSTnode *root, int val)
    {

        if (root == NULL)
        {
            root = new BSTnode(val);
            return root;
        }

        if (val < root->data)
        {
            root->left = Insert(root->left, val);
        }
        else
        {
            root->right = Insert(root->right, val);
        }
    }

    BSTnode *MaxHeapifyDown(BSTnode *root)
    {

        if (root == NULL)
        {
            return NULL;
        }

        BSTnode *MaxChild = FindMaxBSTNode(root->left, root->right);

        if (MaxChild)
        {
            cout << MaxChild->data << endl;
            BSTnode *temp = root;
            root = swapHNodes(root, MaxChild);
            if (temp == root->left)
                root->left = MaxHeapifyDown(temp);
            else
                root->right = MaxHeapifyDown(temp);
        }

        return root;
    }

    BSTnode *swapHNodes(BSTnode *A, BSTnode *B)
    {
        BSTnode *temp;
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
    BSTnode *FindMaxBSTNode(BSTnode *LeftChild, BSTnode *RightChild)
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
    void levelOrderTraversal()
    {

        queue<BSTnode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            BSTnode *temp = q.front();
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

    BSTnode *BST_To_MaxHeap(BSTnode *root)
    {

        if (root == NULL)
        {
            return NULL;
        }
        root->left = BST_To_MaxHeap(root->left);
        root->right = BST_To_MaxHeap(root->right);

        root = MaxHeapifyDown(root);

        // BSTnode *MaxChild = FindMaxBSTNode(root->left, root->right);

        // if (MaxChild)
        // {
        //     BSTnode *temp = root;
        //     root = swapHNodes(root, MaxChild);
        //     if (temp == root->left)
        //         root->left = MaxHeapifyDown(temp);
        //     else
        //         root->right = MaxHeapifyDown(temp);
        // }

        return root;
    }
};

void Inorder(BSTnode *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    Inorder(root->left);
    Inorder(root->right);
}
int main()
{

    BST b;
    b.root = b.Insert(b.root, 11);
    b.root = b.Insert(b.root, 6);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 19);
    b.root = b.Insert(b.root, 4);
    b.root = b.Insert(b.root, 17);
    b.root = b.Insert(b.root, 43);

    Inorder(b.root);
    cout << endl;
    b.root = b.BST_To_MaxHeap(b.root);
    Inorder(b.root);
}