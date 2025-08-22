
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
    node *deletenvalue(int value, node *prev, node *temp)
    {

        if (head->data == value)
        {
            head = head->next;
            free(temp);
            return head;
        }
        if (temp->data == value)
        {
            prev->next = temp->next;
            temp->next = 0;
            free(temp);
            return head;
        }

        // prev = temp;
        // temp = temp->next;
        return deletenvalue(value, temp, temp->next);
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
    sl.InsertAtEnd(5);
    sl.InsertAtEnd(6);
    sl.InsertAtEnd(2);

    sl.display();
    sl.head = sl.deletenvalue(1, 0, sl.head);
    cout << endl;
    sl.display();
}