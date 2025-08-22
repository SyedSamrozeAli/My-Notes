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
            tail->next = newnode;
        }
    }
    void InsertAfter(int d, int pos)
    {

        node *temp = head;

        int ctr = 1;
        int length = getLength();

        if (pos >= 1 && pos <= length)
        {
            if (pos == length)
                InsertAtEnd(d);
            else
            {
                while (ctr < pos)
                {

                    temp = temp->next;
                    ctr++;
                }

                node *newnode = new node(d);
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next->prev = newnode;
                temp->next = newnode;
            }
        }
        else
        {

            cout << "Invalid Position!" << endl
                 << endl;
        }
    }

    void DeleteNodeByValue(int val)
    {
        node *temp = head;
        node *prev = NULL;
        if (head->data == val)
        {
            head = head->next;
            tail->next = head;
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
    int getLength()
    {

        node *temp = head;
        int ctr = 1;
        do
        {
            temp = temp->next;
            ctr++;
        } while (temp->next != head);

        return ctr;
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

int main()
{

    DoublyCircularLinkList dl;
    dl.InsertAtEnd(1);
    dl.InsertAtEnd(2);
    dl.InsertAtEnd(3);
    dl.InsertAtEnd(4);
    dl.InsertAtEnd(5);
    dl.InsertAtBeginning(22);
    dl.display();
    cout << endl;
    dl.InsertAfter(45, 5); // inserting 45 after 5th position
    dl.display();
    dl.DeleteNodeByValue(5); // Deleting node having value 5
    cout << endl;
    dl.display();
    dl.UpdateValue(2, 88); // updating value 2 by 88
    cout << endl;
    dl.display();
}
