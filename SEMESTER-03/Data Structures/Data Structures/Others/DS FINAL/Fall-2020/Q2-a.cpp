#include <iostream>

using namespace std;

class node
{
public:
    int coefficent;
    int power;
    node *next;

    node(int d, int p)
    {
        coefficent = d;
        power = p;
        next = 0;
    }

    node()
    {
        coefficent = 0;
        power = 0;
        next = 0;
    }
};

class SinglyList
{
public:
    node *head, *tail;

    SinglyList()
    {
        tail = head = 0;
    }

    void Insert(int val, int p)
    {

        node *newnode = new node(val, p);

        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = newnode;
        }
    }

    void display()
    {

        node *temp = head;
        do
        {
            cout << temp->coefficent << " ";
            temp = temp->next;

        } while (temp != 0);
    }
};

SinglyList SumTwoList(SinglyList *l1, SinglyList *l2)
{

    SinglyList result;

    node *tempL1 = l1->head;
    node *tempL2 = l2->head;

    while (tempL1 != 0 && tempL2 != 0)
    {
        if (tempL1->power == tempL2->power)
        {
            result.Insert(tempL1->coefficent + tempL2->coefficent, tempL1->power);
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        }
        else if (tempL1->power > tempL2->power)
        {
            result.Insert(tempL1->coefficent, tempL1->power);
            tempL1 = tempL1->next;
        }
        else if (tempL1->power < tempL2->power)
        {
            result.Insert(tempL2->coefficent, tempL2->power);
            tempL2 = tempL2->next;
        }
    }

    while (tempL1 != 0)
    {
        result.Insert(tempL1->coefficent, tempL1->power);
        tempL1 = tempL1->next;
    }

    while (tempL2 != 0)
    {
        result.Insert(tempL2->coefficent, tempL2->power);
        tempL2 = tempL2->next;
    }
    return result;
}

int main()
{

    SinglyList l1, l2;

    l1.Insert(3, 8);
    l1.Insert(2, 7);
    l1.Insert(1, 6);
    l1.Insert(5, 5);
    l1.Insert(6, 4);
    l1.Insert(1, 0);
    l1.display();

    cout << endl;
    l2.Insert(4, 6);
    l2.Insert(3, 5);
    l2.Insert(2, 4);
    l2.Insert(7, 3);

    l2.display();
    cout << endl;

    SinglyList result = SumTwoList(&l1, &l2);
    result.display();
}
