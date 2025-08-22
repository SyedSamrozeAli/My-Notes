#include <iostream>
#include <string>
#include <queue>

using namespace std;
#include <iostream>
#include <string>

using namespace std;
class node2
{
public:
    int data;
    node2 *next;

    node2(int d)
    {
        data = d;
        next = 0;
    }
};

class stack
{
public:
    node2 *top;

    stack()
    {
        top = 0;
    }

    void push(int d)
    {
        node2 *newnode = new node2(d);

        if (top == 0)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty!";
        }
        else
        {

            node2 *temp = top;
            top = top->next;
            return temp->data;
        }
    }

    int peek()
    {

        if (!isEmpty())
            return top->data;

        cout << "Stack is Empty!";
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }

        return false;
    }
    void display()
    {
        node2 *temp = top;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class node
{
public:
    char data;
    node *left;
    node *right;

    node(char d)
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
    int precendence(char symbol)
    {

        switch (symbol)
        {

        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
        }
    }
    node *ConvertEqnToExpressionTree(string exp, node *root, int lb, int ub)
    {
        if (lb >= ub)
        {
            root = new node(exp[lb]);
            return root;
        }
        char symbol = '*';
        int index = 0;
        for (int i = lb; i <= ub; i++)
        {

            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
            {

                if (precendence(exp[i]) <= precendence(symbol))
                {
                    symbol = exp[i];
                    index = i;
                }
            }
        }

        root = new node(symbol);
        root->left = ConvertEqnToExpressionTree(exp, root->left, lb, index - 1);
        root->right = ConvertEqnToExpressionTree(exp, root->right, index + 1, ub);

        return root;
    }

    int EvaluatingExpression(node *root, int len, stack *s)
    {
        if (root == NULL)
            return 0;

        EvaluatingExpression(root->left, len, s);
        EvaluatingExpression(root->right, len, s);

        char symbol = root->data;
        if (symbol >= '0' && symbol <= '9')
        {
            s->push(symbol - 48);
        }
        else
        {
            int a = s->pop();
            int b = s->pop();
            switch (symbol)
            {

            case '+':
                s->push(b + a);
                break;
            case '-':
                s->push(b - a);
                break;
            case '*':
                s->push(b * a);
                break;
            case '/':
                s->push(b / a);
                break;
            case '^':
                s->push(b ^ a);
                break;
            }
        }
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
};

int main()
{
    BinaryTree b;
    cout << endl;
    string exp = "2*4/2+8/2*3+4-5*2";
    b.root = b.ConvertEqnToExpressionTree(exp, b.root, 0, exp.length() - 1);
    // b.PreOrder(b.root);
    // cout << endl;
    b.PostOrder(b.root);
    cout << endl;
    stack s;
    b.EvaluatingExpression(b.root, exp.length(), &s);
    int ans = s.pop();
    cout << "Answer is: " << ans;
    // b.PreOrder(b.root);
    // cout << endl;
    // b.InOrder(b.root);
}