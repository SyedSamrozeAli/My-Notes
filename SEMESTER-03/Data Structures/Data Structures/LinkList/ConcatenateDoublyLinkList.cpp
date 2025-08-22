#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkList
{

public:
    node *head, *tail;

    DoublyLinkList()
    {
        head = NULL;
        tail = NULL;
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
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void InsertAtBeginning(int d)
    {

        node *newnode = new node(d);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    int getLength()
    {

        node *temp = head;
        int ctr = 1;
        while (temp->next != 0)
        {
            temp = temp->next;
            ctr++;
        }

        return ctr;
    }

    void concatenate(DoublyLinkList d)
    {
        tail->next = d.head;
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
    DoublyLinkList d1;
    DoublyLinkList d2;

    d1.InsertAtEnd(1);
    d1.InsertAtEnd(2);
    d1.InsertAtEnd(3);
    d1.InsertAtEnd(4);
    d1.InsertAtEnd(5);
    cout << "1st Link List: ";
    d1.display();
    cout << endl;

    d2.InsertAtEnd(10);
    d2.InsertAtEnd(20);
    d2.InsertAtEnd(30);
    d2.InsertAtEnd(40);
    d2.InsertAtEnd(50);
    cout << "2nd Link List: ";
    d2.display();
    cout << endl;

    d1.concatenate(d2);
    cout << "Concatenated Link List: ";
    d1.display();
}
