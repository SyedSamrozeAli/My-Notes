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

template <class U>
class Queue
{

public:
    class node2
    {
    public:
        U data;
        node2 *next;

        node2(U d)
        {
            data = d;
            next = 0;
        }
    };
    node2 *front, *rear;

    Queue()
    {
        front = rear = 0;
    }

    void enqueue(U d)
    {
        node2 *newnode = new node2(d);

        if (rear == 0)
        {
            front = rear = newnode;
        }
        else
        {

            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue()
    {

        if (front == 0)
        {
            cout << "Queue is Empty!";
        }
        else
        {

            node2 *temp = front;
            front = front->next;
            free(temp);
        }
    }

    U peek()
    {

        if (!isEmpty())
            return front->data;

        cout << "Queue is Empty!";
        return NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }

        return false;
    }
    void display()
    {
        node2 *temp = front;
        if (temp == 0)
        {
            cout << "Empty";
        }
        while (temp != 0)
        {
            cout << temp->data->data << " ";
            temp = temp->next;
        }
    }

    bool Check()
    {

        node2 *temp = front;
        while (temp != 0)
        {
            if (temp->data->data != -1)
                return true;

            temp = temp->next;
        }

        return false;
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

    bool CheckBST(node *root)
    {
        bool check1, check2;
        if (root == NULL)
        {
            cout << "Tree is empty!" << endl;
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

    bool CheckFullBinartTree(node *root)
    {

        // base case
        if (root == NULL)
            return true;

        if ((root->left == NULL && root->right == NULL) || (root->left != NULL && root->right != NULL))
        {

            if (CheckFullBinartTree(root->left))
            {

                if (CheckFullBinartTree(root->right))
                {
                    return true;
                }
                else
                    return false;
            }
            return false;
        }
    }
    void levelOrderTraversal()
    {

        Queue<node *> q;
        q.enqueue(root);
        q.enqueue(NULL);

        while (!q.isEmpty())
        {
            node *temp = q.peek();
            q.dequeue();

            if (temp == NULL) // using NULL as a seperator taake jab jab NULL aye to hum next line par chale jayenge
            {
                cout << endl;
                if (!q.isEmpty()) // agr queue empty nhi iska matlab ek level or bacha wa ha to uske aage bhi NULL laga denge
                {
                    q.enqueue(NULL);
                }
            }
            else
            {

                cout << temp->data << " ";

                if (temp->left != NULL)
                {
                    q.enqueue(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.enqueue(temp->right);
                }
            }
        }
    }
    bool CheckCompleteBinaryTree(node *root)
    {
        if (root == nullptr)
        {
            return true; // An empty tree is complete by definition
        }

        queue<node *> q;
        q.push(root);
        bool encounteredNull = false;

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            if (temp == nullptr)
            {
                encounteredNull = true;
            }
            else
            {
                if (encounteredNull)
                {
                    return false; // agr koi non-null node aajye null node k baad to matlab complete tree nhi h
                }

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return true; // If we reach here, the tree is complete
    }

    // bool CheckCompleteBinaryTree(node *root)
    // {

    //     Queue<node *> q;
    //     q.enqueue(root);
    //     q.enqueue(NULL);
    //     node *checkNode = new node(-1);

    //     while (!q.isEmpty())
    //     {
    //         node *temp = q.peek();
    //         cout << q.peek()->data << endl;
    //         q.dequeue();

    //         if (temp->data == -1)
    //         {
    //             if (q.Check())
    //             {
    //                 cout << "here6" << endl;
    //                 return false;
    //             }
    //             else
    //             {
    //                 cout << "here7";
    //                 return true;
    //             }
    //         }

    //         if (temp->left != NULL)
    //         {
    //             cout << "here1" << endl;
    //             q.enqueue(temp->left);
    //             cout << q.peek()->data << endl;
    //             // q.display();
    //         }

    //         else
    //         {
    //             cout << "here2" << endl;
    //             q.enqueue(checkNode);
    //         }

    //         if (temp->right != NULL)
    //         {

    //             cout << "here3" << endl;
    //             q.enqueue(temp->right);
    //             cout << q.peek()->data << endl;
    //             // q.display();
    //         }

    //         else
    //         {
    //             cout << "here4" << endl;
    //             q.enqueue(checkNode);
    //         }

    //         q.display();
    //     }
    // }

    bool CheckPerfectBinaryTree(node *root)
    {

        queue<node *> q;
        q.push(root);
        q.push(NULL);
        int ctr = 1;  // storing max no.of nodes at each level
        int ctr2 = 0; // for storing no.of nodes at each level

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {

                if (!q.empty())
                {
                    q.push(NULL);
                }
                else
                    return true;

                ctr = ctr * 2;   // getting max no.of nodes at each level i.e 1,2,4,8,16....
                if (ctr2 != ctr) // perfect mei har level par max no.of nodes hote hai to agr ye dono unequal hai to not a valid binary tree!
                {
                    return false;
                }
                ctr2 = 0; // reseting no.of nodes at each level when ever we encounter new level
            }
            else
            {

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                    ctr2++;
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                    ctr2++;
                }
            }
        }
        // ab agr poora loop traverse krlia to iska matlab k har level par maximum nodes hai to true
        return true;
    }

    bool CheckDegenrateBinaryTree(node *root)
    {

        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        if (root->left != NULL && root->right == NULL)
        {
            return CheckDegenrateBinaryTree(root->left);
        }
        else if (root->left == NULL && root->right != NULL)
        {
            return CheckDegenrateBinaryTree(root->right);
        }

        return false;
    }
};

int main()
{
    BinaryTree b;

    // For Binary Search Tree
    //  b.root = new node(50);
    //  b.root->left = new node(40);
    //  b.root->right = new node(80);
    //  b.root->left->left = new node(30);
    //  b.root->left->right = new node(44);
    //  b.root->left->left->left = new node(20);
    //  b.root->left->left->right = new node(31);
    //  b.root->right->left = new node(7);
    //  b.root->right->right = new node(90);
    //  b.root->right->right->right = new node(100);
    //  b.root->right->left->left = new node(60);

    // if (b.CheckBST(b.root))
    //     cout << "Valid Binary Search Tree!" << endl;
    // else
    //     cout << "Invalid Binary Search Tree!" << endl;

    // For Full Binary Tree
    // b.root = new node(1);
    // b.root->left = new node(40);
    // b.root->right = new node(80);
    // b.root->left->left = new node(30);
    // b.root->left->right = new node(44);
    // b.root->right->left = new node(7);
    // b.root->right->right = new node(90);
    // b.root->right->left->left = new node(60);
    // b.root->right->left->right = new node(200);

    // if (b.CheckFullBinartTree(b.root))
    //     cout << "Valid Full Binary Tree!" << endl;
    // else
    //     cout << "Invalid Full Binary Tree!" << endl;

    // For Complete Binary Tree
    // b.root = new node(1);
    // b.root->left = new node(2);
    // b.root->right = new node(3);
    // b.root->left->left = new node(4);
    // b.root->left->right = new node(5);
    // b.root->left->left->left = new node(8);
    // b.root->right->left = new node(6);
    // // b.root->right->left->left = new node(60);
    // b.root->right->right = new node(7);

    // if (b.CheckCompleteBinaryTree(b.root))
    //     cout << "Valid Complete Binary Tree!" << endl;
    // else
    //     cout << "Invalid Complete Binary Tree!" << endl;

    // For Perfect Binary Tree
    //  b.root = new node(1);
    //  b.root->left = new node(2);
    //  b.root->right = new node(3);
    //  b.root->left->left = new node(4);
    //  b.root->left->right = new node(5);
    //  b.root->right->left = new node(6);
    //  b.root->right->right = new node(7);
    //  b.root->right->right->left = new node(70);

    // cout << endl;
    // b.levelOrderTraversal();
    // cout << endl;

    // if (b.CheckPerfectBinaryTree(b.root))
    //     cout << "Valid Perfect Binary Tree!" << endl;
    // else
    //     cout << "Invalid Perfect Binary Tree!" << endl;

    // For Degenrate Binary Tree
    b.root = new node(1);
    b.root->left = new node(2);
    b.root->left->left = new node(3);
    b.root->left->left->left = new node(4);
    b.root->left->left->left->right = new node(5);
    b.root->left->left->left->right->left = new node(6);

    cout << endl;
    b.levelOrderTraversal();
    cout << endl;

    if (b.CheckDegenrateBinaryTree(b.root))
        cout << "Valid Degenerate Binary Tree!" << endl;
    else
        cout << "Invalid Degenerate Binary Tree!" << endl;
}
