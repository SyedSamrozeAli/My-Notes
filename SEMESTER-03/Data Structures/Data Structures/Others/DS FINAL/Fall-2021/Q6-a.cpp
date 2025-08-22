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

    bool isMirror(node *r1, node *r2)
    {
        if (!r1 && !r2) // both are null
            return true;

        if ((!r1 && r2) || (r1 && !r2)) // if any one of them is null
            return false;

              if (r1 && r2 && r1->data != r2->data) // if both not null then check data
            return false;

        bool left = isMirror(r1->left, r2->right);
        bool right = isMirror(r1->right, r2->left);

        if (right && left)
            return true;
        else
            return false;
    }
};

int main()
{

    BinaryTree bt1, bt2;
    bt1.root = bt1.Insert(bt1.root, 1);
    bt1.root = bt1.Insert(bt1.root, 2);
    bt1.root = bt1.Insert(bt1.root, 3);
    bt1.root = bt1.Insert(bt1.root, 4);
    bt1.root = bt1.Insert(bt1.root, 5);
    bt1.PreOrder(bt1.root);
    cout << endl;
    bt2.root = bt2.Insert(bt2.root, 1);
    bt2.root = bt2.Insert(bt2.root, 3);
    bt2.root = bt2.Insert(bt2.root, 2);
    bt2.root->right->left = new node(5);
    bt2.root->right->right = new node(4);
    bt2.PreOrder(bt2.root);
    cout << endl;
    if (bt1.isMirror(bt1.root, bt2.root))
    {
        cout << "Mirror!" << endl;
    }
    else
    {
        cout << "Not Mirror!" << endl;
    }
}