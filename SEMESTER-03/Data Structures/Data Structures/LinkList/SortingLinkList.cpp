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

    // void InsertAtBeginning(int d)
    // {

    //     node *newnode = new node(d);
    //     if (head == NULL)
    //     {
    //         head = tail = newnode;
    //     }
    //     else
    //     {
    //         newnode->next = head;
    //         head = newnode;
    //     }
    // }
    // void InsertAfter(int d, int pos)
    // {

    //     node *temp = head;

    //     int ctr = 1;
    //     int length = getLength();

    //     if (pos <= 1 && pos >= length)
    //     {

    //         while (ctr < pos)
    //         {

    //             temp = temp->next;
    //             ctr++;
    //         }

    //         node *newnode = new node(d);
    //         newnode->next = temp->next;
    //         temp->next = newnode;
    //     }
    //     else
    //     {

    //         cout << "Invalid Position!" << endl
    //              << endl;
    //     }
    // }

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
        else
        {

            while (temp->data != val)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
        }
        free(temp);
    }

    void Sort()
    {
        SinglyList odd;

        node *temp = head;
        node *temp2 = NULL;
        int ctr = 1;
        while (temp != 0)
        {
            if (temp->data % 2 != 0)
            {
                odd.InsertAtEnd(temp->data);
                temp2 = temp->next;
                DeleteNodeByValue(temp->data);
                temp = temp2;
            }
            else
            {
                temp = temp->next;
            }
        }

        tail->next = odd.head;
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
    sl.InsertAtEnd(17);
    sl.InsertAtEnd(15);
    sl.InsertAtEnd(8);
    sl.InsertAtEnd(12);
    sl.InsertAtEnd(10);
    sl.InsertAtEnd(5);
    sl.InsertAtEnd(4);

    sl.display();

    sl.Sort();
    cout << endl;
    sl.display();
}