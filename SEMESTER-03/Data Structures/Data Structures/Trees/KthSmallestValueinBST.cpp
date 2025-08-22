
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BSnode
{
public:
    int data;
    BSnode *left;
    BSnode *right;

    BSnode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    BSnode *root;

    BST()
    {
        root = NULL;
    }

    BSnode *Insert(BSnode *root, int val)
    {

        if (root == NULL)
        {
            root = new BSnode(val);
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

    void PreOrder(BSnode *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void KthSmallestValue(BSnode *root, int *i, int k)
    {

        if (root == NULL)
            return;
        KthSmallestValue(root->left, i, k);

        (*i)++;
        if ((*i) == k)
        {

            cout << root->data;
            return;
        }

        KthSmallestValue(root->right, i, k);
    }
};

int main()
{

    BST b;
    int index = 0;
    b.root = b.Insert(b.root, 11);
    b.root = b.Insert(b.root, 6);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 19);
    b.root = b.Insert(b.root, 4);
    b.root = b.Insert(b.root, 10);
    b.root = b.Insert(b.root, 5);
    b.root = b.Insert(b.root, 16);
    b.root = b.Insert(b.root, 17);
    b.root = b.Insert(b.root, 43);
    b.root = b.Insert(b.root, 49);
    b.root = b.Insert(b.root, 31);
    b.root = b.Insert(b.root, 9);
    b.PreOrder(b.root);
    cout << endl;
    int i;
    for (int k = 1; k <= 13; k++) // total no.of node is 13 so it will tell all smallest values
    {
        i = 0;
        cout << "The " << k << "th smallest element in BST is: ";
        b.KthSmallestValue(b.root, &i, k);

        cout << endl;
        cout << endl;
    }
}