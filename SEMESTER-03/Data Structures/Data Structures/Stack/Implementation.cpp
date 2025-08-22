#include <iostream>
#include <string>

using namespace std;

template <class T>
class Snode
{
public:
    T data;
    Snode *next;

    Snode(T d)
    {
        data = d;
        next = 0;
    }
};

template <class T>
class stack
{
public:
    Snode<T> *top;

    stack()
    {
        top = 0;
    }

    void push(T d)
    {
        Snode<T> *newSnode = new Snode<T>(d);

        if (top == 0)
        {
            top = newSnode;
        }
        else
        {
            newSnode->next = top;
            top = newSnode;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty!";
        }
        else
        {

            Snode<T> *temp = top;
            top = top->next;
            free(temp);
        }
    }

    T peek()
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
        Snode<T> *temp = top;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.display();
    cout << endl;
    s.pop();
    s.display();
    cout << endl;
    s.pop();
    s.display();
    cout << endl;
    cout << s.peek();
}