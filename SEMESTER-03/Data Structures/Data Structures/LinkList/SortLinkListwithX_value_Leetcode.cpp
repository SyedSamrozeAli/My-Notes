#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int d)
    {
        data = d;
        next = NULL;
    }
    ~node()
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
    node *head, *tail;

    SinglyList()
    {
        head = NULL;
        tail = NULL;
    }

    SinglyList(node *ptr)
    {
        head = tail = ptr;
    }

    void InsertAtEnd(int d)
    {

        node *newnode = new node(d);

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void VSorting(int val)
    {
        node *temp = head;
        node *prev = head;
        node *prev2 = head;
        node *temp2 = head;

        while (temp->data < val)
        {
            prev = temp;
            temp = temp->next;
        }

        while (temp2 != 0)
        {

            if (temp2->data < val && temp2 != prev)
            {
                prev->next = temp2;
                prev = prev->next;
                prev2->next = temp2->next;
                temp2->next = temp;
                temp2 = prev2;
            }

            prev2 = temp2;
            temp2 = temp2->next;
        }

        head = prev;
    }
    void display()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{

    SinglyList sl;
    sl.InsertAtEnd(2);
    sl.InsertAtEnd(1);
    // sl.InsertAtEnd(3);
    // sl.InsertAtEnd(2);
    // sl.InsertAtEnd(2);
    // sl.InsertAtEnd(5);
    sl.display();
    sl.VSorting(2);
    cout << endl;
    sl.display();
}