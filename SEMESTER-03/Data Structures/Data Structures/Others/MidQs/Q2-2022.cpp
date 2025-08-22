#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = 0;
    }
};

class stack
{
public:
    node *top;

    stack()
    {
        top = 0;
    }

    void push(int d)
    {
        node *newnode = new node(d);

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

            node *temp = top;
            top = top->next;
            free(temp);
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
        node *temp = top;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

stack SortingStack(stack result, int val)
{

    if (result.isEmpty())
    {
        result.push(val);
    }
    else
    {
        if (result.peek() < val)
        {
            result.push(val);
        }
        else
        {
            int temp = result.peek();
            result.pop();
            result = SortingStack(result, val);
            result.push(temp);
        }
    }

    return result;
}

int main()
{
    stack s;
    stack result;
    s.push(10);
    s.push(2);
    s.push(8);
    s.push(1);
    s.push(9);

    s.display();

    cout << endl;
    while (!s.isEmpty())
    {
        result = SortingStack(result, s.peek());
        s.pop();
    }

    result.display();
}
