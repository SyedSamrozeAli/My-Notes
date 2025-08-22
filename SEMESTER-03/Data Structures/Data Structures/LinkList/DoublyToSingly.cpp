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

class DoublyCircularLinkList
{

public:
    node *head, *tail;

    DoublyCircularLinkList()
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
            newnode->next = head;
            tail = newnode;
        }
    }

    void display()
    {
        node *temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
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

    void operator=(DoublyCircularLinkList dl)
    {
        node *temp = dl.head;

        do
        {

            InsertAtEnd(temp->data);
            temp = temp->next;

        } while (temp != dl.head);
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

    DoublyCircularLinkList dl;
    dl.InsertAtEnd(1);
    dl.InsertAtEnd(2);
    dl.InsertAtEnd(3);
    dl.InsertAtEnd(4);
    dl.InsertAtEnd(5);
    SinglyList sl;
    sl = dl;
    sl.display();
}