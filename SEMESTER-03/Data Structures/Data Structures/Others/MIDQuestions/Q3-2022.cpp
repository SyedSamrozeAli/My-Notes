
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
    void reverse(int start, int end)
    {
        node *temp1 = head;
        node *prev1 = 0;
        node *temp2 = head;
        int ctr = 1;

        while (ctr < start)
        {
            prev1 = temp1;
            temp1 = temp1->next;
            ctr++;
        }

        ctr = 1;
        while (ctr < end)
        {
            temp2 = temp2->next;
            ctr++;
        }
        if (start == 1)
            head = temp2;
        else
            prev1->next = temp2;

        node *current = temp1;
        node *nextnode = current->next;
        current->next = temp2->next;

        while (current != temp2)
        {
            prev1 = current;
            current = nextnode;
            nextnode = nextnode->next;
            current->next = prev1;
        }
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
    sl.InsertAtEnd(1);
    sl.InsertAtEnd(2);
    sl.InsertAtEnd(3);
    sl.InsertAtEnd(4);
    sl.InsertAtEnd(5);
    sl.InsertAtEnd(6);
    sl.InsertAtEnd(7);

    sl.display();
    sl.reverse(2, 7);
    cout << endl;
    sl.display();
}