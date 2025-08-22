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
    node *Deleete(node *root, int val)
    {
        if (root == NULL)
            return 0;

        if (val == root->data)
            return DeleteNode(root);

        if (val < root->data)
        {

            root->left = Deleete(root->left, val);
            return root;
        }
        else
        {
            root->right = Deleete(root->right, val);
            return root;
        }
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

    node *max(node *root)
    {
        int val1;
        val1 = root->data;
        if (root->right == NULL)
        {

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
            return 0;
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
    b.root = b.Insert(b.root, 16);
    b.root = b.Insert(b.root, 17);
    b.root = b.Insert(b.root, 43);
    b.root = b.Insert(b.root, 49);
    b.root = b.Insert(b.root, 31);
    b.root = b.Insert(b.root, 9);

    cout << endl;
    b.PreOrder(b.root);
    cout << endl;

    // b.root = b.Deleete(b.root, 6);
    // b.root = b.Update(b.root, 17, 18);
    // b.search(b.root, 91);
    // cout << b.min(b.root)->data;
    // cout << b.max(b.root)->data;
    // cout << "Predecessor: " << b.FindPredecessor(b.root, 11)->data << endl;
    // cout << "Sucessor:" << b.FindSucessor(b.root, 19)->data;
    // cout << b.FindHeight(b.root);
    // cout << b.GetSize(b.root);
    // cout << endl;
    // b.PreOrder(b.root);
}