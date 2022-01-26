#include <iostream>

using namespace std;

void insertionSort(int a[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        for (j = i - 1; j >= 0; j--)
            if (a[j] > key)
                a[j + 1] = a[j];
            else
                break;
        a[j + 1] = key;
    }
}

int main()
{
    int a[100], n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

//increment sort/element finds its correct position
//if dat is partially sorted it is best
//O(n2) fo all
//n-1 passes