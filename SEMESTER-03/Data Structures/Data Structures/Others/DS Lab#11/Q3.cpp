#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class HashTable
{
public:
    int size;
    char *arr;
    HashTable(char s)
    {
        size = s;
        arr = new char[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void Insert(char val)
    {
        char key = HashFunction(val);
        int i = 0;
        if (arr[key] == 0)
        {
            arr[key] = val;
        }
        else
        {
            i = (key + 1) % size;
            while (i != key)
            {
                if (arr[i] == 0)
                {
                    arr[i] = val;
                    break;
                }
                else
                {
                    i = (i + 1) % size;
                }
            }
        }
    }

    int Search(char val)
    {
        char key = HashFunction(val);
        int i = 1;

        return arr[key];
    }

    void Display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    char HashFunction(char val)
    {
        return precedence(val);
    }
    int precedence(char ch)
    {

        switch (ch)
        {
        case '!':
            return 0;
        case '#':
            return 1;
        case '$':
            return 2;
        case '%':
            return 3;
        case '&':
            return 4;
        case '*':
            return 5;
        case '^':
            return 6;
        case '~':
            return 7;
        }
    }
    int countNoOfElements(HashTable *table)
    {
        int ctr = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
                ctr++;
        }

        return ctr;
    }
};
void StoreResult(HashTable nuts, HashTable bolts, int size)
{
    int resultSize = nuts.countNoOfElements(&nuts);
    char *result = new char[resultSize];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (nuts.arr[i] && bolts.arr[i])
        {
            result[j] = nuts.arr[i];
            j++;
        }
    }

    for (int i = 0; i < resultSize; i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    HashTable nuts(size);
    HashTable bolts(size);
    nuts.Insert('@');
    nuts.Insert('%');
    nuts.Insert('$');
    nuts.Insert('#');
    nuts.Insert('^');

    bolts.Insert('%');
    bolts.Insert('@');
    bolts.Insert('$');
    bolts.Insert('#');
    bolts.Insert('^');
    cout << endl;
    bolts.Display();
    cout << endl;
    nuts.Display();
    cout << endl;
    StoreResult(nuts, bolts, size);
}
