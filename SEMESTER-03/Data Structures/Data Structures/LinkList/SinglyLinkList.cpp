
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

    // void DeleteNodeByValue(int val)
    // {
    //     node *temp = head;
    //     node *prev = NULL;
    //     if (head->data == val)
    //     {
    //         head = head->next;
    //     }
    //     else
    //     {

    //         while (temp->data != val)
    //         {
    //             prev = temp;
    //             temp = temp->next;
    //         }

    //         prev->next = temp->next;
    //     }
    //     free(temp);
    // }

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

    sl.UpdateValue(1, 66); // 1= which value we want to update, 66=what value we want to add after updation

    sl.display();
}