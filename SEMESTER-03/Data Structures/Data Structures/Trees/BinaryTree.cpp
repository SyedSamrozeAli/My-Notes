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
template <class T>
class node2
{
public:
    T data;
    node2 *next;

    node2(T d)
    {
        data = d;
        next = 0;
    }
};

template <class U>
class Queue
{

public:
    node2<U> *front, *rear;

    Queue()
    {
        front = rear = 0;
    }

    void enqueue(U d)
    {

        node2<U> *newnode = new node2<U>(d);

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

            node2<U> *temp = front;
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
        node2<U> *temp = front;
        if (temp == 0)
        {
            cout << "Empty";
        }
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
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
    void BuildFromLevelOrderTraversal()
    {
        int data;
        cout << "Enter data: ";
        cin >> data;

        root = new node(data);
        queue<node *> q;

        q.push(root);

        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();

            cout << "Enter left of " << temp->data << endl;
            int left;
            cin >> left;
            if (left != -1)
            {
                temp->left = new node(left);
                q.push(temp->left);
            }

            cout << "Enter right of " << temp->data << endl;
            int right;
            cin >> right;
            if (right != -1)
            {
                temp->right = new node(right);
                q.push(temp->right);
            }
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

    void PreOrder(node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void PostOrder(node *root)
    {
        if (root == NULL)
            return;

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

    void InOrder(node *root)
    {
        if (root == NULL)
            return;

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    node *BuildTreeFromPreorderAndInorder(int lb, int ub, int *inorder, int *preorder, int preorderlen)
    {
        if (lb > ub)
        {
            return NULL;
        }

        if (lb == ub)
        {
            node *newnode = new node(inorder[lb]);
            return newnode;
        }

        int minindex = 100;
        int index = 0;

        for (int i = lb; i <= ub; i++)
        {
            for (int j = 0; j <= preorderlen; j++)
            {
                if (inorder[i] == preorder[j])
                {
                    if (j < minindex)
                    {
                        minindex = j;
                        index = i;
                    }
                    break;
                }
            }
        }
        // cout << preorder[minindex] << endl;
        // cout << "lb: " << lb << " ub: " << ub << endl;
        // cout << "minindex: " << minindex << " index: " << index << endl;
        node *newnode = new node(inorder[index]);

        newnode->left = BuildTreeFromPreorderAndInorder(lb, index - 1, inorder, preorder, preorderlen);
        newnode->right = BuildTreeFromPreorderAndInorder(index + 1, ub, inorder, preorder, preorderlen);

        return newnode;
    }

    node *BuildTreeFromPostorderAndInorder(int lb, int ub, int *inorder, int *postorder, int postorderlen)
    {
        int minindex = -1;
        int index = 0;
        if (lb > ub)
        {
            return NULL;
        }
        if (lb == ub)
        {
            cout << " here" << endl;
            node *newnode = new node(inorder[lb]);
            // cout << inorder[lb] << endl;
            // cout << "lb: " << lb << " ub: " << ub << endl;
            // cout << "minindex: " << minindex << " index: " << index << endl;
            return newnode;
        }

        for (int i = lb; i <= ub; i++)
        {
            for (int j = 0; j <= postorderlen; j++)
            {
                if (inorder[i] == postorder[j])
                {
                    if (j > minindex)
                    {
                        minindex = j;
                        index = i;
                    }
                    break;
                }
            }
        }
        cout << inorder[index] << endl;
        // cout << "lb: " << lb << " ub: " << ub << endl;
        // cout << "minindex: " << minindex << " index: " << index << endl;
        // getchar();
        node *newnode = new node(inorder[index]);

        newnode->left = BuildTreeFromPostorderAndInorder(lb, index - 1, inorder, postorder, postorderlen);
        newnode->right = BuildTreeFromPostorderAndInorder(index + 1, ub, inorder, postorder, postorderlen);

        return newnode;
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

    node *Delete(node *root, int val)
    {

        if (root == NULL)
            return NULL;

        if (root->data == val)
        {
            return DeleteNode(root);
        }

        root->left = Delete(root->left, val);
        root->right = Delete(root->right, val);
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
            // // this will delete it by value means values will be swapped
            // node *val = max(root->left);
            // int val2 = val->data;
            // root = Delete(root, val->data);
            // root->data = val2;
            // return root;

            // This code is for deleting a node by swapping nodes
            node *prep, *pre;

            prep = root;
            pre = root->left;
            while (pre->right != NULL)
            {
                prep = pre;
                pre = pre->right;
            }

            if (prep != root)
                prep->right = pre->left;
            else
                prep->left = pre->right;

            pre->right = root->right;
            pre->left = root->left;

            delete (root);
            return pre;
        }
    }
    node *search(int val)
    {

        if (root == NULL)
            cout << "Tree is empty!" << endl;

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {

            node *temp = q.front();
            q.pop();

            if (temp->data == val)
            {
                return temp;
            }

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        return NULL;
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
    BinaryTree b;
    // int inorder[] = {8, 4, 10, 9, 11, 2, 5, 1, 6, 3, 7};
    // int preorder[] = {1, 2, 4, 8, 9, 10, 11, 5, 3, 6, 7};
    // b.root = b.BuildTreeFromPreorderAndInorder(0, 10, inorder, preorder, 10);
    // b.levelOrderTraversal();

    int inorder[] = {9, 5, 1, 7, 2, 12, 8, 4, 3, 11};
    int postorder[] = {9, 1, 2, 12, 7, 5, 3, 11, 4, 8};
    b.root = b.BuildTreeFromPostorderAndInorder(0, 9, inorder, postorder, 9);
    b.levelOrderTraversal();
}
