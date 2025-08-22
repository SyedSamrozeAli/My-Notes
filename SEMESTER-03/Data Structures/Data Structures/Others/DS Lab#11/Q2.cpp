#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class HashTable
{
public:
    int size;
    int *arr;
    HashTable(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void Insert(int val)
    {
        int key = HashFunction(val);
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

    int Search(int val)
    {
        int key = HashFunction(val);
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

    int HashFunction(int val)
    {

        return val % size;
    }
    int countNoOfElements()
    {
        int ctr = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0)
                ctr++;
        }

        return ctr;
    }
    int *extractArray(HashTable *table)
    {
        int arrSize = countNoOfElements();
        int *array = new int[arrSize + 1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0 && arr[i] % 10 == i)
            {
                array[j] = arr[i];
                j++;
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (arr[i] != 0 && arr[i] % 10 != i)
            {
                array[j] = arr[i];
                j++;
            }
        }

        return array;
    }
};

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    HashTable HT(size);
    HashTable HT2(size);
    HT.Insert(9);
    HT.Insert(25);
    HT.Insert(33);
    HT.Insert(49);
    HT.Insert(15);
    HT.Insert(18);
    HT.Insert(89);
    HT.Insert(80);
    cout << endl;
    HT.Display();
    cout << endl;

    int *arr = HT.extractArray(&HT);
    cout << "Extracted Array:";
    for (int i = 0; i < 8; i++)
    {

        cout << arr[i] << " ";
        HT2.Insert(arr[i]);
    }
    cout << endl;
    HT2.Display();
}
