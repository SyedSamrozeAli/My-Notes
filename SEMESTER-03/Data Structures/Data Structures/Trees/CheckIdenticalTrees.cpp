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

class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = 0;
    }

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
};

bool CheckIdenticalTrees(node *root1, node *root2)
{
    bool c1 = false, c2 = false;

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    c1 = CheckIdenticalTrees(root1->left, root2->left);
    c2 = CheckIdenticalTrees(root1->right, root2->right);

    if (c1 & c2)
        return true;
    else
        return false;
}
int main()
{
    BinaryTree b1, b2;
    b1.root = new node(1);
    b1.root->left = new node(2);
    b1.root->right = new node(3);
    b1.root->left->left = new node(4);
    b1.root->left->right = new node(5);
    b1.root->right->left = new node(6);
    b1.root->right->right = new node(7);
    b1.root->right->left->left = new node(10);
    cout << endl;
    b1.PreOrder(b1.root);

    cout << endl;
    b2.root = new node(1);
    b2.root->left = new node(2);
    b2.root->right = new node(3);
    b2.root->left->left = new node(4);
    b2.root->left->right = new node(5);
    b2.root->right->left = new node(6);
    b2.root->right->right = new node(7);
    b2.root->right->left->left = new node(10);
    b2.root->right->left->right = new node(100);
    cout << endl;
    b2.PreOrder(b2.root);

    if (CheckIdenticalTrees(b1.root, b2.root))
    {
        cout << "\nTress are identical!" << endl;
    }
    else
    {
        cout << "\nTress are not identical!" << endl;
    }
}