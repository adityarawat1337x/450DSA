#include <iostream>

using namespace std;

void selectionSort(int a[], int n)
{
    int min, pos;

    for (int i = 0; i < n; i++)
    {
        min = a[i];
        pos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        if (pos != i)
            swap(a[i], a[pos]);
    }
}

int main()
{
    int a[100], n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    selectionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

//in place swapping algo
//best, avg, worst case O(n2)
//n-1 passes