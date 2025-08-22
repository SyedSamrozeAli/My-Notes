#include <iostream>

using namespace std;

class Book
{
private:
    string name;
    int key;         // 0 for DS, 1 for PF and 2 for OOP
    string category; // DS, OOP, PF
    float price;

    void MergeSort(Book *b, int lb, int ub)
    {
        if (lb < ub)
        {
            int mid = lb + ((ub - lb) / 2);
            MergeSort(b, lb, mid);
            MergeSort(b, mid + 1, ub);
            Merge(b, lb, ub, mid);
        }
    };

    void Merge(Book *b, int lb, int ub, int mid)
    {

        int i = lb, j = mid + 1, k = 0, size = ub - lb + 1;
        Book *temp = new Book[size];
        while (i <= mid && j <= ub)
        {

            if (b[i].key < b[j].key)
            {
                temp[k] = b[i];
                i++;
            }
            else
            {
                temp[k] = b[j];
                j++;
            }

            k++;
        }

        while (i <= mid)
        {
            temp[k] = b[i];
            i++;
            k++;
        }

        while (j <= ub)
        {
            temp[k] = b[j];
            j++;
            k++;
        }

        k = 0;
        for (int i = lb; i <= ub; i++)
        {
            b[i] = temp[k];
            k++;
        }

        delete[] temp;
    }

public:
    Book(){};
    Book(string pName, string pCat, float pPrice, int k) : name(pName), category(pCat), price(pPrice), key(k){};
    string getCategory() { return this->category; }

    void SortBook(Book *b, int n)
    {
        MergeSort(b, 0, n);
    }

    void display(Book *b)
    {

        for (int i = 0; i < 7; i++)
        {

            cout << "Name: " << b[i].name << " Cate: " << b[i].category << " Key: " << b[i].key << " Price: " << b[i].price;
            cout << endl;
        }
    }
};

int main()
{
    Book b[7] = {Book("samroze", "PF", 500, 1), Book("basil", "DS", 5400, 0), Book("uszair", "PF", 600, 1), Book("hassan", "DS", 800, 0), Book("beig", "DS", 100, 0), Book("shaheer", "PF", 5300, 1), Book("anas", "OOP", 589, 2)};

    b->display(b);
    b->SortBook(b, 7);
    cout << endl;
    b->display(b);
}