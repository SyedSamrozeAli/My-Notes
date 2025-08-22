#include <iostream>
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

    node *Insert(node *root, int val)
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
                    break;
                }
                else
                {
                    q.push(temp->left);
                }

                if (temp->right == NULL)
                {
                    temp->right = new node(val);
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

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void CalcPathsKsum(node *root, int *sum, int *ctr)
    {
        if (root == NULL)
            return;

        (*sum) += root->data;
        cout << "sum: " << (*sum) << endl;

        if ((*sum) > 5)
        {
            (*sum) -= root->data;
            return;
        }

        if ((*sum) == 5)
        {

            (*ctr)++;
            (*sum) -= root->data;
            return;
        }

        CalcPathsKsum(root->left, sum, ctr);
        CalcPathsKsum(root->right, sum, ctr);

        (*sum) -= root->data;
    }

    void Calculate(node *root, int *sum, int *ctr)
    {
        if (root == NULL)
            return;
        CalcPathsKsum(root, sum, ctr);
        Calculate(root->left, sum, ctr);
        Calculate(root->right, sum, ctr);
    }
};

int main()
{

    BinaryTree bt;

    bt.root = bt.Insert(bt.root, 1);
    bt.root = bt.Insert(bt.root, 3);
    bt.root = bt.Insert(bt.root, -1);
    bt.root = bt.Insert(bt.root, 2);
    bt.root = bt.Insert(bt.root, 1);
    bt.root = bt.Insert(bt.root, 4);
    bt.root = bt.Insert(bt.root, 5);
    bt.root->left->right->left = new node(1);
    bt.root->right->left->left = new node(1);
    bt.root->right->left->right = new node(2);
    bt.root->right->right->right = new node(6);

    bt.PreOrder(bt.root);

    int ctr = 0, sum = 0;
    bt.Calculate(bt.root, &sum, &ctr);
    cout << endl;
    cout << ctr;
}