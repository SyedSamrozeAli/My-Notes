
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
    void InsertionSort()
    {
        SinglyList sorted;

        node *newnode = new node();
        sorted.head = newnode; // making a dummy node
        newnode->next = head;
        head = head->next;
        newnode->next->next = NULL; // assigning NULL to the first node after the dummy node to break its   connection with previous node

        cout << "helloo";
        while (head != 0)
        {
            cout << "here1";
            node *temp = sorted.head;
            while (temp->next != 0)
            {
                cout << "here2";
                if (head->data < temp->next->data)
                {
                    cout << "here3";
                    node *temp2 = temp->next;
                    temp->next = head;
                    head = head->next;
                    temp->next->next = temp2;
                    break;
                }
                cout << "here4";
                temp = temp->next;
            }
            if (temp->next == NULL) // if we donot get any value which is lesser in sorted link list than our original list then we assign  the original list value to thelast of sorted list
            {
                cout << "here5";
                temp->next = head;
                head = head->next;
                temp->next->next = 0;
            }
        }

        sorted.head = sorted.head->next; // deleting dummy variable
        head = sorted.head;
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
    sl.InsertionSort();
    cout << endl;
    sl.display();
}