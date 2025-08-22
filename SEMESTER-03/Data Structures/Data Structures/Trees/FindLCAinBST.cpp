#include <iostream>
#include <string>
#include <queue>

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

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node *Insert(node *root, int val)
    {

        if (root == NULL)
        {
            root = new node(val);
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

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
    node *CheckValuesThenFindLCA(node *root, int value1, int value2)
    {
        if (search(root, value1) && search(root, value2))
        {
            return FindingLCA(root, value1, value2);
        }
        else
            return NULL;
    }
    node *FindingLCA(node *root, int value1, int value2)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (value1 > root->data && value2 > root->data)
        {
            return FindingLCA(root->right, value1, value2);
        }
        else if (value1 < root->data && value2 < root->data)
        {
            return FindingLCA(root->left, value1, value2);
        }

        else
        {
            return root;
        }
    }
    node *search(node *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->data == val)
        {
            return root;
        }

        if (val < root->data)
        {
            return search(root->left, val);
        }
        else
        {
            return search(root->right, val);
        }
    }
};

int main()
{
    BST b;
    b.root = b.Insert(b.root, 11);
    b.root = b.Insert(b.root, 6);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 19);
    b.root = b.Insert(b.root, 4);
    b.root = b.Insert(b.root, 10);
    b.root = b.Insert(b.root, 5);
    b.root = b.Insert(b.root, 17);
    b.root = b.Insert(b.root, 43);
    b.root = b.Insert(b.root, 49);
    b.root = b.Insert(b.root, 31);

    cout << endl;
    b.PreOrder(b.root);
    cout << endl;
    node *lca = b.CheckValuesThenFindLCA(b.root, 10, 31);
    if (lca)
    {
        cout << "LCA is: " << lca->data << endl;
    }
    else
    {
        cout << "LCA not found !" << endl;
    }
}