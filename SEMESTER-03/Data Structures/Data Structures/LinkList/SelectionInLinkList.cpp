
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
    void swaping(node *n1, node *n2)
    {

        node *temp = head;
        node *prev2 = 0; // previous node of n2
        node *prev1 = 0; // previous node of n1

        if (n1 == n2) // If n1 and n2 are the same, no need to swap
            return;

        while (temp != n1) // finding previous of n1
        {
            prev1 = temp;
            temp = temp->next;
        }
        cout << prev1->data << endl;
        temp = head;

        while (temp != n2) // finding previous of n2
        {
            prev2 = temp;
            temp = temp->next;
        }
        cout << prev2->data << endl;

        if (n1 == head && n2->next != 0) // if n1 is head and n2 is not tail
        {
            cout << "here1";
            prev2->next = n1;
            node *n1next = n1->next;
            n1->next = n2->next;
            n2->next = n1next;
            head = n2;
        }

        else if (n1 == head && n2->next == 0) // if n1 is head node and n2 is tail
        {
            cout << "here2";
            prev2->next = n1;
            n2->next = n1->next;
            n1->next = 0;
            head = n2;
            tail = n1;
        }

        else if (n1 != head && n2->next == 0) // if n1 is not head but n2 is tail
        {
            cout << "here3";
            prev1->next = n2;
            n2->next = n1->next;
            prev2->next = n1;
            n1->next = 0;
            tail = n1;
        }

        else if (n1 != head && n2->next != 0) // if n1 is not head and n2 is not tail
        {
            cout << "here4";
            prev2->next = n1;
            node *n1next = n1->next;
            n1->next = n2->next;
            prev1->next = n2;
            n2->next = n1next;
        }
        else if (n1->next == n2)
        {
            cout << "here5";
            prev1->next = n2;
            n1->next = n2->next;
            n2->next = n1;
        }
    }
    void swapnode(node *&head, int x, int y)
    {
        if (x == y)
        {
            return;
        }
        node *currX = head;
        node *prevX = NULL;
        while (currX && currX->data != x)
        {
            prevX = currX;
            currX = currX->next;
        }

        node *prevY = NULL;
        node *currY = head;
        while (currY && currY->data != y)
        {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY)
        {
            return;
        }

        if (prevX != NULL)
        {
            prevX->next = currY;
        }
        else
        {
            head = currY;
        }

        if (prevY != NULL)
        {
            prevY->next = currX;
        }
        else
        {
            head = currX;
        }

        node *temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    void SelectionSort()
    {
        node *temp = head;
        node *temp3 = 0;
        int ctr = 1;
        while (temp != 0)
        {

            node *min = temp;
            node *temp2 = temp->next;
            while (temp2 != 0)
            {

                if (temp2->data < min->data)
                {
                    min = temp2;
                }
                temp2 = temp2->next;
            }
            temp3 = temp->next;
            if (temp != min)
            {

                swaping(temp, min);
            }

            temp = temp3;
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
    sl.InsertAtEnd(5);
    sl.InsertAtEnd(6);
    sl.InsertAtEnd(8);
    sl.InsertAtEnd(3);
    sl.InsertAtEnd(2);

    sl.display();
    cout << endl;
    cout << endl;
    sl.SelectionSort();
    cout << endl;
    sl.display();
}