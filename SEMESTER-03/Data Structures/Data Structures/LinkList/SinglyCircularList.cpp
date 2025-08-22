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
            head = newnode;
        }

        tail->next = head;
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
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
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
            cout << "position doesnot exist!";
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

    SinglyCircularList sl;
    sl.InsertAtEnd(1);
    sl.InsertAtEnd(2);
    sl.InsertAtEnd(3);
    sl.InsertAtEnd(4);

    sl.InsertAtBeginning(44);
    sl.InsertAtBeginning(46);

    sl.InsertAfter(35, 3);

    sl.display();

    sl.DeleteNodeByValue(4);
    cout << endl;
    sl.display();
    sl.UpdateValue(1, 65);
    cout << endl;
    sl.display();
}
