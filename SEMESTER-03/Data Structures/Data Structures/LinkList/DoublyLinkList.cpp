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
    void InsertAfter(int d, int pos)
    {

        node *temp = head;

        int ctr = 1;
        int length = getLength();

        if (pos >= 1 && pos <= length)
        {

            while (ctr < pos)
            {

                temp = temp->next;
                ctr++;
            }

            node *newnode = new node(d);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
        }
        else
        {

            cout << "Invalid Position!" << endl
                 << endl;
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

    void DeleteNodeByValue(int val)
    {
        node *temp = head;
        node *prev = NULL;
        if (head->data == val)
        {
            head = head->next;
        }
        else if (tail->data == val)
        {
            temp->prev->next = head;
        }
        else
        {

            while (temp->data != val)
            {
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
    }

    void UpdateValue(int val, int updatedVal)
    {
        node *temp = head;
        int ctr = 1;
        while (temp->data != val)
        {
            temp = temp->next;
            ctr++;
        }
        if (ctr > getLength())
            cout << "Value doesnot exist!";
        else
            temp->data = updatedVal;
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

    DoublyLinkList dl;
    dl.InsertAtEnd(1);
    dl.InsertAtEnd(2);
    dl.InsertAtEnd(3);
    dl.InsertAtEnd(4);
    dl.InsertAtEnd(5);
    dl.InsertAtBeginning(22);
    dl.display();
    cout << endl;
    dl.InsertAfter(45, 3);
    dl.display();
    dl.DeleteNodeByValue(5);
    cout << endl;
    dl.display();
    dl.UpdateValue(2, 88);
    cout << endl;
    dl.display();
}