
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Lnode
{
public:
    int data;
    Lnode *next;
    Lnode()
    {
        data = 0;
        next = NULL;
    }
    Lnode(int d)
    {
        data = d;
        next = NULL;
    }
    ~Lnode()
    {
        if (next != 0)
        {
            delete next;
            next = 0;
        }
    }
};

class SinglyList
{
public:
    Lnode *head, *tail;

    SinglyList()
    {
        head = NULL;
        tail = NULL;
    }

    SinglyList(Lnode *ptr)
    {
        head = tail = ptr;
    }

    void InsertAtEnd(int d)
    {

        Lnode *newLnode = new Lnode(d);

        if (head == NULL)
        {
            head = tail = newLnode;
        }
        else
        {
            tail->next = newLnode;
            tail = newLnode;
        }
    }

    int getLength()
    {

        Lnode *temp = head;
        int ctr = 1;
        while (temp->next != 0)
        {
            temp = temp->next;
            ctr++;
        }

        return ctr;
    }
    int FindSum()
    {
        Lnode *temp = head;
        int sum = 0;
        while (temp != 0)
        {
            sum += temp->data;
            temp = temp->next;
        }

        return sum;
    }
    void DeleteAtEnd()
    {

        Lnode *temp = head;
        if (temp == tail) // means only one element left in list
        {
            tail = head = 0;
        }
        else
        {
            while (temp->next != tail)
            {
                temp = temp->next;
            }

            delete tail;
            temp->next = 0;
            tail = temp;
        }
    }
    void display()
    {
        Lnode *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

void CopyElements(SinglyList l1, SinglyList *l2)
{

    Lnode *temp = l1.head;
    while (temp != 0)
    {
        l2->InsertAtEnd(temp->data);
        temp = temp->next;
    }
}
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

    void BSTFindPaths(BSnode *root, SinglyList SinglePath, int *index, SinglyList *paths)
    {
        SinglePath.InsertAtEnd(root->data);

        if (root->left == NULL && root->right == NULL) // hum jese hi leaf node par pohnchenge to hum jo linklist mein path save hoga usko array mei copy krlenge phir array k index ko increment krdia
        {
            CopyElements(SinglePath, &paths[*index]);
            (*index)++;
            SinglePath.DeleteAtEnd(); // ab jab hum backtrack krte hoe peeche jaynge to hum apni single path k har node ko delete krte hoe chalenge jab tak koi doosra rasta nhi mil jata

            return;
        }

        if (root->left)
        {
            BSTFindPaths(root->left, SinglePath, index, paths);
        }

        if (root->right)
        {
            BSTFindPaths(root->right, SinglePath, index, paths);
        }

        SinglePath.DeleteAtEnd(); /// backtracking delete a node before every return call;

        return;
    }
};

int main()
{

    SinglyList singlePath;
    SinglyList paths[10];
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
    b.BSTFindPaths(b.root, singlePath, &index, paths);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Path-" << i + 1 << ": ";
        paths[i].display();
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (paths[j].FindSum() > paths[j + 1].FindSum())
                swap(paths[j], paths[j + 1]);
        }
    }
    cout << "After sorting: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Path-" << i + 1 << ": ";
        paths[i].display();
        cout << endl;
    }
}