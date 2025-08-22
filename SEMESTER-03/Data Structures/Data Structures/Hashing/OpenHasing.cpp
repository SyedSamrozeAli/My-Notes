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
        next = 0;
    }

    node(int d)
    {
        data = d;
        next = 0;
    }
};

class HashTable
{
public:
    node **links;
    int size;

    HashTable()
    {
        size = 10;
        links = new node *[size];
        for (int i = 0; i < size; i++)
        {
            links[i] = NULL;
        }
    }

    void Insert(int val)
    {
        int key = HashFunction(val);
        node *newnode = new node(val);

        if (links[key] == NULL)
        {
            links[key] = newnode;
        }
        else
        {
            newnode->next = links[key];
            links[key] = newnode;
        }
    }

    void Delete(int val)
    {
        int key = HashFunction(val);

        node *curr = links[key];
        node *prev = NULL;
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
        node *temp = curr;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    void Search(int val)
    {
        int key = HashFunction(val);
        node *temp = links[key];
        while (temp != 0 && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == 0)
            cout << "Value Not Found!";
        else
        {

            cout << "Value is found!";
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "link[" << i << "] ---> ";
            node *temp = links[i];
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

int main()
{
    int size = 10;
    HashTable HT;
    HT.Insert(9);
    HT.Insert(25);
    HT.Insert(33);
    HT.Insert(49);
    HT.Insert(15);
    HT.Insert(18);
    HT.Insert(94);
    HT.Insert(85);
    cout << endl;
    HT.Display();
    cout << endl;

    HT.Delete(85);
    cout << endl;
    HT.Display();
    cout << endl;

    HT.Search(68);
}