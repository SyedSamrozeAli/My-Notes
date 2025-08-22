#include <iostream>
#include <string>
#include <algorithm>
#include <random>

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
int FindMax(int *a, int len)
{
    int max = 0;

    for (int i = 0; i < len; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }

    return max + 1;
}
int main()
{
    stack A, B, C, D;
    stack deck;

    int arr[100];
    int a[4];
    int ctrA = 0, ctrB = 0, ctrC = 0, ctrD = 0;
    int winner[4];
    for (int i = 0; i < 100; ++i)
    {
        arr[i] = i + 1;
    }

    random_device rd;
    mt19937 g(rd());

    shuffle(arr, arr + 100, g);

    // Print the shuffled array
    for (int i = 0; i < 100; ++i)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < 100; ++i)
    {
        deck.push(arr[i]);
    }

    while (!deck.isEmpty())
    {
        for (int i = 0; i < 4; i++)
        {
            a[i] = deck.peek();
            deck.pop();
        }

        int max = FindMax(a, 4);
        if (max == 1)
        {
            winner[0]++;
            for (int i = 0; i < 4; i++)
                A.push(a[i]);
        }

        else if (max == 2)
        {
            winner[1]++;
            for (int i = 0; i < 4; i++)
                B.push(a[i]);
        }
        else if (max == 3)
        {
            winner[2]++;
            for (int i = 0; i < 4; i++)
                C.push(a[i]);
        }
        else if (max == 4)
        {
            winner[3]++;
            for (int i = 0; i < 4; i++)
                D.push(a[i]);
        }
    }

    int win = FindMax(winner, 4);
    cout << endl;
    cout << "\n\nA: ";
    A.display();
    cout << "\nB: ";
    B.display();
    cout << "\nC: ";
    C.display();
    cout << "\nD: ";
    D.display();
    cout << "\n\n:::::WINNER:::::\n\n";
    if (win == 1)
    {
        cout << "A wins!";
    }
    else if (win == 2)
    {
        cout << "B wins!";
    }
    else if (win == 3)
    {
        cout << "C wins!";
    }
    else if (win == 4)
    {
        cout << "D wins!";
    }
}