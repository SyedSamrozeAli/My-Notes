#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Lnode
{
public:
    int data;
    Lnode *next;

    Lnode()
    {
        data = 0;
        next = 0;
    }

    Lnode(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkList
{
public:
    Lnode *head, *tail;

    LinkList()
    {
        head = tail = NULL;
    }

    void InsertAtTail(int val)
    {
        Lnode *newLnode = new Lnode(val);

        if (head == NULL)
        {
            head = tail = newLnode;
        }
        else
        {
            tail->next = newLnode;
            tail = newLnode;
        }
    }

    void display()
    {
        Lnode *temp = head;
        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class Hnode
{
public:
    int data;
    Hnode *next;

    Hnode()
    {
        data = 0;
        next = 0;
    }

    Hnode(int d)
    {
        data = d;
        next = 0;
    }
};

class HashTable
{
public:
    Hnode **links;
    int size;

    HashTable()
    {
        size = 10;
        links = new Hnode *[size];
        for (int i = 0; i < size; i++)
        {
            links[i] = NULL;
        }
    }

    void Insert(int val)
    {
        int key = HashFunction(val);
        Hnode *newHnode = new Hnode(val);

        if (links[key] == NULL)
        {
            links[key] = newHnode;
        }
        else
        {
            newHnode->next = links[key];
            links[key] = newHnode;
        }
    }

    void Delete(int val)
    {
        int key = HashFunction(val);

        Hnode *curr = links[key];
        Hnode *prev = NULL;
        while (curr != 0 && curr->data != val)
        {
            prev = curr;
            curr = curr->next;
        }

        // Deletion at Head
        if (curr == links[key])
        {
            links[key] = curr->next;
            delete curr;
            return;
        }

        // Deletion at Specific position or At END
        Hnode *temp = curr;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    bool Search(int val)
    {
        int key = HashFunction(val);
        Hnode *temp = links[key];
        while (temp != 0 && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == 0)
            return false;
        else
        {
            return true;
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "link[" << i << "] ---> ";
            Hnode *temp = links[i];
            do
            {
                if (temp == 0)
                {
                    cout << "NULL";
                }
                else
                {
                    cout << temp->data << " ---> ";
                    temp = temp->next;
                }

            } while (temp != 0);

            cout << endl;
        }
    }
    int HashFunction(int val)
    {

        return val % size;
    }
};
void InsertInHashTable(HashTable *table, LinkList *l)
{
    Lnode *temp = l->head;

    while (temp != 0)
    {
        table->Insert(temp->data);
        temp = temp->next;
    }
}

void FindIntersection(LinkList *l, LinkList *intersection, HashTable *table)
{
    Lnode *temp = l->head;

    while (temp != 0)
    {
        bool found = table->Search(temp->data);
        if (found)
            intersection->InsertAtTail(temp->data);
        temp = temp->next;
    }
}
int main()
{
    srand(time(0));
    LinkList l1;
    LinkList l2;
    LinkList intersetion;
    HashTable h;
    for (int i = 1; i <= 8; i++)
    {
        l1.InsertAtTail((rand() % 100) + 1);
    }
    // l1.InsertAtTail(10);
    // l1.InsertAtTail(20);
    // l1.InsertAtTail(35);
    // l1.InsertAtTail(23);
    // l1.InsertAtTail(39);
    // l1.InsertAtTail(12);
    // l1.InsertAtTail(25);

    // l2.InsertAtTail(1);
    // l2.InsertAtTail(25);
    // l2.InsertAtTail(39);
    // l2.InsertAtTail(8);
    // l2.InsertAtTail(5);
    // l2.InsertAtTail(1);
    // l2.InsertAtTail(35);

    InsertInHashTable(&h, &l1);
    l1.display();
    cout << endl;
    cout << endl;
    h.Display();
    cout << endl;

    for (int i = 1; i <= 8; i++)
    {
        l2.InsertAtTail((rand() % 100) + 1);
    }

    l2.display();
    cout << endl;

    FindIntersection(&l2, &intersetion, &h);
    cout << endl;
    intersetion.display();
}
