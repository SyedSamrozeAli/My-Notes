#include <iostream>
#include <string>

using namespace std;

template <class T>
class Qnode
{
public:
    T data;
    Qnode *next;

    Qnode(T d)
    {
        data = d;
        next = 0;
    }
};
template <class T>
class Queue
{

public:
    Qnode<T> *front, *rear;

    Queue()
    {
        front = rear = 0;
    }

    void enqueue(T d)
    {

        Qnode<T> *newQnode = new Qnode<T>(d);

        if (rear == 0)
        {
            front = rear = newQnode;
        }
        else
        {

            rear->next = newQnode;
            rear = newQnode;
        }
    }

    void dequeue()
    {

        if (front == 0)
        {
            cout << "Queue is Empty!";
        }
        else
        {

            Qnode<T> *temp = front;
            front = front->next;
            free(temp);
        }
    }

    T peek()
    {

        if (!isEmpty())
            return front->data;

        cout << "Queue is Empty!";
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }

        return false;
    }
    void display()
    {
        Qnode<T> *temp = front;

        while (temp != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    Queue<int> q;
    cout << "Queue is: ";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.display();
    cout << endl;
    q.dequeue();
    cout << "Queue is: ";
    q.display();
    cout << endl;

    cout << q.peek();
}