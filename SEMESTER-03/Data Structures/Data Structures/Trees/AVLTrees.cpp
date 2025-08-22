#include <iostream>
#include <string>
#include <queue>

using namespace std;

class node
{
public:
    char data;
    int height;
    node *left;
    node *right;

    node()
    {
        data = 0;
        height = 0;
        left = NULL;
        right = NULL;
    }
    node(char d, int h)
    {
        data = d;
        height = h;
        left = NULL;
        right = NULL;
    }

    void SetHeight(int h)
    {
        height = h;
    }
};

class AVL_Tree
{
public:
    node *root;

    AVL_Tree()
    {
        root = NULL;
    }

    node *Insert(node *root, char val)
    {

        if (root == NULL)
        {
            root = new node(val, 0);
            return root;
        }

        if (val < root->data)
        {
            root->left = Insert(root->left, val);
            if (!CheckBalanceFactor(root))
            {
                if (val < root->left->data) // LL Case
                {
                    // rotate right
                    return RotateRight(root);
                }
                else if (val > root->left->data) // LR Case
                {
                    // rotate left then rotate right
                    root->left = RotateLeft(root->left);
                    return RotateRight(root);
                }
            }
        }
        else
        {
            root->right = Insert(root->right, val);
            if (!CheckBalanceFactor(root))
            {
                if (val > root->right->data) // RR Case
                {
                    // rotate left
                    return RotateLeft(root);
                }
                else if (val < root->right->data) // RL Case
                {
                    // rotate right then rotate left
                    root->right = RotateRight(root->right);
                    return RotateLeft(root);
                }
            }
        }

        return root;
    }

    node *RotateLeft(node *root)
    {

        node *temp1 = root->right->left;
        node *temp2 = root->right;
        root->right->left = root;
        root->right = temp1;

        return temp2;
    }

    node *RotateRight(node *root)
    {

        node *temp1 = root->left->right;
        node *temp2 = root->left;
        root->left->right = root;
        root->left = temp1;

        return temp2;
    }
    node *Deleete(node *root, int val)
    {
        if (root == NULL)
            return 0;

        if (val == root->data)
            return DeleteNode(root);

        if (val < root->data)
        {

            root->left = Deleete(root->left, val);
            if (!CheckBalanceFactor(root))
            {

                if (GetBalanceFactor(root->right) < 0)
                {
                    // rotate left
                    return RotateLeft(root);
                }
                else
                {
                    root->right = RotateRight(root->right);
                    return RotateLeft(root);
                }
            }
        }
        else
        {
            root->right = Deleete(root->right, val);
            if (!CheckBalanceFactor(root))
            {

                if (GetBalanceFactor(root->left) < 0)
                {

                    root->left = RotateLeft(root->left);
                    return RotateRight(root);
                }
                else
                {
                    return RotateRight(root);
                }
            }
        }
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
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }
        else
        {
            // this will delete it by value means values will be swapped
            node *val = max(root->left);
            int val2 = val->data;
            root = Deleete(root, val->data);
            root->data = val2;
            return root;
            // This code is for deleting a node by swapping nodes
            // node *prep, *pre;

            // prep = root;
            // pre = root->left;
            // while (pre->right != NULL)
            // {
            //     prep = pre;
            //     pre = pre->right;
            // }

            // if (prep != root)
            //     prep->right = pre->left;
            // else
            //     prep->left = pre->right;

            // pre->right = root->right;
            // pre->left = root->left;

            // delete (root);
            // return pre;
        }
    }
    int GetBalanceFactor(node *root)
    {
        return (FindHeight(root->left) + 1) - (FindHeight(root->right) + 1);
    }

    node *max(node *root)
    {
        int val1;
        val1 = root->data;
        if (root->right == NULL)
        {
            // node *temp = root;

            return root;
        }

        return max(root->right);
    }

    node *min(node *root)
    {
        int value = root->data;
        if (root->left == NULL)
            return root;

        return min(root->left);
    }

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    node *Update(node *root, int val, int upd_val)
    {
        if (root->data == val)
        {

            if ((root->left != NULL && val > root->left->data) || (root->left != NULL && val < root->right->data) || (root->left == NULL || root->right == NULL))
            {
                root->data = upd_val;
                return root;
            }
            else
            {
                cout << "Values cannot be updated!";
            }
        }
        if (val < root->data)
        {

            root->left = Update(root->left, val, upd_val);
            return root;
        }
        else
        {

            root->right = Update(root->right, val, upd_val);
            return root;
        }
    }

    node *search(node *root, int val)
    {
        if (root == NULL)
        {
            cout << "Value is not found in the TREE!" << endl;
            return NULL;
        }
        if (root->data == val)
        {
            cout << "value found!" << endl;
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

    node *FindPredecessor(node *root, int val)
    {
        node *reqNode = search(root, val);
        return max(reqNode->left);
    }

    node *FindSucessor(node *root, int val)
    {
        node *reqNode = search(root, val);
        return min(reqNode->right);
    }

    int FindHeight(node *root)
    {

        if (root == NULL)
        {
            return -1;
        }

        int left_height = FindHeight(root->left);
        int right_height = FindHeight(root->right);

        if (left_height > right_height)
            return ++left_height;
        else
            return ++right_height;
    }

    int GetSize(node *root)
    {

        if (root == NULL)
            return 0;

        int left_no_of_nodes = GetSize(root->left);
        int right_no_of_node = GetSize(root->right);

        return (left_no_of_nodes + right_no_of_node) + 1;
    }

    bool CheckBalanceFactor(node *root)
    {

        int balance_factor = (FindHeight(root->left) + 1) - (FindHeight(root->right) + 1);
        if (balance_factor > 1 || balance_factor < -1)
            return false;
        return true;
    }
};

int main()
{
    AVL_Tree b;
    b.root = b.Insert(b.root, 'H');
    b.root = b.Insert(b.root, 'I');
    b.root = b.Insert(b.root, 'J');
    b.root = b.Insert(b.root, 'B');
    b.root = b.Insert(b.root, 'A');
    b.root = b.Insert(b.root, 'E');
    b.root = b.Insert(b.root, 'C');
    b.root = b.Insert(b.root, 'F');
    b.root = b.Insert(b.root, 'D');
    b.root = b.Insert(b.root, 'G');

    cout << endl;
    b.PreOrder(b.root);
    cout << endl;
}