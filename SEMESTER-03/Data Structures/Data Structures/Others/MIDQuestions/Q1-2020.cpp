#include <iostream>
#include <string>
#include <time.h>

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
        next = 0;
        prev = 0;
    }
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class DoublyList
{
public:
    node *head, *tail;

    DoublyList()
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

    void sort()
    {

        node *temp, *temp2;
        temp = head;

        int ctr = 1;
        int pos = 3;
        while (ctr < pos)
        {
            temp = temp->next;
            ctr++;
        }

        temp->prev->next = temp->next;
        temp->next->next->prev = temp;
        temp->next->prev = temp->prev;
        temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next = temp;
        temp->prev = temp2;
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

    DoublyList dl;
    dl.InsertAtEnd(1);
    dl.InsertAtEnd(2);
    dl.InsertAtEnd(3);
    dl.InsertAtEnd(4);
    dl.InsertAtEnd(5);
    dl.InsertAtEnd(6);

    dl.display();

    dl.sort();

    cout << endl;
    dl.display();
}