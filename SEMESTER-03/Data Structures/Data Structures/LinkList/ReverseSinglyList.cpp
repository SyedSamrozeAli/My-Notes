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
};

class SinglyCircularList
{
public:
    node *head, *tail;

    SinglyCircularList()
    {
        head = NULL;
        tail = NULL;
    }

    SinglyCircularList(node *ptr)
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

        newnode->next = head;
    }
    void reverse()
    {

        node *current = head;
        node *prev = NULL;
        node *nextnode = head;
        prev = tail;

        while (current != tail)
        {
            nextnode = current->next;
            current->next = prev;
            prev = current;
            current = nextnode;
        }
        tail->next = prev;

        node *temp2 = tail;
        tail = head;
        head = temp2;
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
    SinglyCircularList sl;
    sl.InsertAtEnd(1);
    sl.InsertAtEnd(2);
    sl.InsertAtEnd(3);
    sl.InsertAtEnd(4);
    cout << "Link List: ";
    sl.display();
    sl.reverse();
    cout << endl;
    cout << "Reversed Link List: ";
    sl.display();
}
