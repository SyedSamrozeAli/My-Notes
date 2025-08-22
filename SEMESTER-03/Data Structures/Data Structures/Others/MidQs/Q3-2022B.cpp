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

    node *CreateTree()
    {

        int x;

        cout << "Enter data: ";
        cin >> x;

        if (x == -1)
        {
            return NULL;
        }

        node *newnode = new node(x);
        cout << "Enter left of " << x << endl;
        newnode->left = CreateTree();
        cout << "Enter right of " << x << endl;
        newnode->right = CreateTree();

        return newnode;
    }
    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    // Sir mene is function mei STL waaali QUEUE use ki hai q k merii waali ptaa nhi q nhi chal rhi thi kaafi try kra lekn error smjh nhi aarha tha
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
    bool CheckBST(node *root)
    {
        bool check1, check2;
        if (root == NULL)
        {
            // cout << "Tree is empty!" << endl;
            return true;
        }
        // base case (agr dono right left null ha iska matlab end par pohnch gaye hai or end par pohnchne ka matlab hai k upper ki sab nodes shi hai to jabhi true return krdia)
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        // agr left null nhi hai or right null hai to sirf left k liye check kiya or right wale k liye true return krdia
        if (root->left != NULL && root->right == NULL)
        {
            if (root->left->data < root->data)
            {
                check1 = CheckBST(root->left);
            }
            else
            {
                return false;
            }

            check2 = true;
        }
        // agr right null nhi hai or left null hai to sirf right k liye check kiya or left wale k liye true return krdia
        else if (root->left == NULL && root->right != NULL)
        {

            if (root->right->data > root->data)
            {
                check2 = CheckBST(root->right);
            }
            else
            {
                return false;
            }

            check1 = true;
        }
        // agr left right dono null nhi hai to dono k liye chchk kiya
        else
        {
            if (root->left->data < root->data)
            {

                check1 = CheckBST(root->left);
            }
            else
            {

                return false;
            }
            if (root->right->data > root->data)
            {

                check2 = CheckBST(root->right);
            }
            else
            {
                return false;
            }
        }

        // agr koi ek bhi check false hoa to false return krida
        if (check1 && check2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ValidBSTsInA_BinaryTree(node *root, int *ctr)
    {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
        {
            cout << "Here1" << endl;
            (*ctr)++;
            return true;
        }
        else if (!root->right)
        {
            if (root->left->data < root->data)
            {
                if (ValidBSTsInA_BinaryTree(root->left, ctr))
                {
                    (*ctr)++;
                    return true;
                }
            }
            ValidBSTsInA_BinaryTree(root->left, ctr);
            return false;
        }
        else if (!root->left)
        {
            if (root->right->data > root->data)
            {
                if (ValidBSTsInA_BinaryTree(root->right, ctr))
                {
                    (*ctr)++;
                    return true;
                }
            }
            ValidBSTsInA_BinaryTree(root->right, ctr);
            return false;
        }
        else
        {

            if (root->left->data < root->data && root->right->data > root->data)
            {
                if (ValidBSTsInA_BinaryTree(root->left, ctr) && ValidBSTsInA_BinaryTree(root->right, ctr))
                {
                    cout << "Here2" << endl;
                    (*ctr)++;
                    return true;
                }
                else
                {
                    cout << "Here3" << endl;
                    return false;
                }
            }
            else
            {
                cout << "Here4" << endl;
                ValidBSTsInA_BinaryTree(root->left, ctr);
                ValidBSTsInA_BinaryTree(root->right, ctr);
                return false;
            }
        }
        // if (root->left->data < root->data && root->right->data > root->data)
        // {
        //     if (CheckBST(root->left) && CheckBST(root->right))
        //     {
        //         (*ctr)++;
        //     }
        // }
        // ValidBSTsInA_BinaryTree(root->left, ctr);
        // ValidBSTsInA_BinaryTree(root->right, ctr);
    }
};

int main()
{
    BinaryTree b;
    b.root = b.Insert(b.root, 50);
    b.root = b.Insert(b.root, 25);
    b.root = b.Insert(b.root, 7);
    b.root = b.Insert(b.root, 10);
    b.root = b.Insert(b.root, 38);
    b.root = b.Insert(b.root, 1);
    b.root = b.Insert(b.root, 8);
    b.root = b.Insert(b.root, 4);
    b.root = b.Insert(b.root, 11);
    b.root = b.Insert(b.root, 30);
    b.Insert(b.root, 50);
    b.PreOrder(b.root);
    int ctr = 0;
    b.ValidBSTsInA_BinaryTree(b.root, &ctr);
    cout << endl;
    cout << ctr;
}
