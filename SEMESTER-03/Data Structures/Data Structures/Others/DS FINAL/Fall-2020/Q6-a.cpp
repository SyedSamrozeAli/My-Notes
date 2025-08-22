#include <iostream>

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

    int largerValueThanX(node *root, int x, int *find, bool *flag)
    {

        if (x == root->data)
        {

            if (root->right)
            {
                *flag = false;
                return *find = root->right->data;
            }
            else
            {
                *flag = true;
                return 0;
            }
        }

        if (x < root->data)
            largerValueThanX(root->left, x, find, flag);

        else
            largerValueThanX(root->right, x, find, flag);

        if (root->data > x && *flag == true)
        {
            *flag = false;
            return *find = root->data;
        }
        else
            return *find;
    }
    int FindNextHigher(node *root, int X)
    {
        node *next = 0;
        node *curr = root;
        while (curr != 0)
        {
            if (curr->data > X)
            {
                next = curr;
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        return next->data;
    }
};
int main()
{

    BST b;
    b.root = b.Insert(b.root, 15);
    b.root = b.Insert(b.root, 10);
    b.root = b.Insert(b.root, 20);
    b.root = b.Insert(b.root, 16);
    b.root = b.Insert(b.root, 25);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 12);

    b.PreOrder(b.root);
    cout << endl;
    bool flag = false;
    int find = 0;
    cout << b.largerValueThanX(b.root, 8, &find, &flag) << endl;
    cout << b.FindNextHigher(b.root, 10);
}