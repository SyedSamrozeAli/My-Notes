
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

    void checkPalindrome()
    {
        node *temp = head;
        node *temp2 = head;
        int ctr = 1;
        int flag = 0;
        int i = 0;
        while (temp != 0)
        {
            int valueToCheck = temp->data;
            while (ctr < getLength() - i)
            {
                temp2 = temp2->next;
                ctr++;
            }
            if (valueToCheck != temp2->data)
            {
                flag = 1;
                break;
            }
            // incrementing the temp variable to check next value
            temp = temp->next;
            i++;
            // reseting the values
            temp2 = head;
            ctr = 1;
        }

        if (flag == 0)
        {
            cout << "It is a palindrome";
        }
        else
        {
            cout << "Not a Palindrome";
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
    sl.InsertAtEnd('B');
    sl.InsertAtEnd('O');
    sl.InsertAtEnd('R');
    sl.InsertAtEnd('R');
    sl.InsertAtEnd('O');
    sl.InsertAtEnd('W');
    sl.InsertAtEnd('O');
    sl.InsertAtEnd('R');
    sl.InsertAtEnd('R');
    sl.InsertAtEnd('O');
    sl.InsertAtEnd('B');
    sl.display();
    cout << endl;
    sl.checkPalindrome();
}