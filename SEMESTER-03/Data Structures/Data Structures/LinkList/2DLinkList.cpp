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

class NODE
{
public:
    node *headptrs;
    NODE *next;

    NODE()
    {
        headptrs = NULL;
        next = NULL;
    }
    NODE(node *ptr)
    {
        headptrs = ptr;
        next = NULL;
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
};

class LinkedList2D
{

public:
    NODE *head, *tail;

    LinkedList2D()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertAtEnd(node *d)
    {
        NODE *newnode = new NODE(d);
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
    void InsertAtHead(node *d)
    {
        NODE *newnode = new NODE(d);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void InsertAtIndex(int x, int y, node *newnode) //(insert a new node at index(x, y))
    {

        NODE *temp1 = head;

        node *temp2;

        int row_ctr = 1;
        int col_ctr = 1;

        while (row_ctr < x) // To reach the required row
        {
            temp1 = temp1->next;
            row_ctr++;
        }

        temp2 = temp1->headptrs;

        while (col_ctr < y) // To reach the required Column
        {
            temp2 = temp2->next;
            col_ctr++;
        }

        temp2->prev->next = newnode;
        temp2->next->prev = newnode;
        newnode->next = temp2->next;
        newnode->prev = temp2->prev;

        free(temp2);
    }

    void DeleteAtIndex(int x, int y)
    {
        NODE *temp1 = head;

        node *temp2;

        int row_ctr = 1;
        int col_ctr = 1;

        while (row_ctr < x)
        {
            temp1 = temp1->next;
            row_ctr++;
        }

        temp2 = temp1->headptrs;

        while (col_ctr < y)
        {
            temp2 = temp2->next;
            col_ctr++;
        }

        temp2->prev->next = temp2->next;
        temp2->next->prev = temp2->prev;

        free(temp2);
    }

    void UpdateAtIndex(int x, int y, int value)
    {
        NODE *temp1 = head;

        node *temp2;

        int row_ctr = 1;
        int col_ctr = 1;

        while (row_ctr < x)
        {
            temp1 = temp1->next;
            row_ctr++;
        }

        temp2 = temp1->headptrs;

        while (col_ctr < y)
        {
            temp2 = temp2->next;
            col_ctr++;
        }

        temp2->data = value;
    }
    void display()
    {
        NODE *temp1 = head;

        node *temp2;

        while (temp1 != NULL)
        {
            temp2 = temp1->headptrs;
            node *null = temp2;

            do
            {
                cout << temp2->data << " ";
                temp2 = temp2->next;
            } while (temp2 != null);

            cout << endl;
            temp1 = temp1->next;
        }
    }
};
int main()
{

    DoublyCircularLinkList d1;
    d1.InsertAtEnd(1);
    d1.InsertAtEnd(2);
    d1.InsertAtEnd(3);
    d1.InsertAtEnd(4);
    d1.InsertAtEnd(5);
    DoublyCircularLinkList d2;
    d2.InsertAtEnd(6);
    d2.InsertAtEnd(7);
    d2.InsertAtEnd(8);
    d2.InsertAtEnd(9);
    d2.InsertAtEnd(10);
    DoublyCircularLinkList d3;
    d3.InsertAtEnd(11);
    d3.InsertAtEnd(12);
    d3.InsertAtEnd(13);
    d3.InsertAtEnd(14);
    d3.InsertAtEnd(15);
    DoublyCircularLinkList d4;
    d4.InsertAtEnd(16);
    d4.InsertAtEnd(17);
    d4.InsertAtEnd(18);
    d4.InsertAtEnd(19);
    d4.InsertAtEnd(20);

    LinkedList2D l;
    l.InsertAtEnd(d1.head);
    l.InsertAtEnd(d2.head);
    l.InsertAtEnd(d3.head);
    l.InsertAtHead(d4.head);
    l.display();

    node *newnode = new node(88);
    l.InsertAtIndex(3, 3, newnode); //(insert a new node at index (3,3))
    cout << endl;
    l.display();

    l.DeleteAtIndex(4, 3); // node at 4th row & 3rd column will be deleted
    cout << endl;
    l.display();

    l.UpdateAtIndex(2, 4, 45); // update the value at 2nd row and 4th column to 45
    cout << endl;
    l.display();
}
