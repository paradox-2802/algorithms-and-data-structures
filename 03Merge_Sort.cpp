#include <iostream>
using namespace std;

int a[11] = {60, 20, 40, 80, 60, 30, 80, 90, 30, 70, 40};
int b[11] = {0};

void merge_fun(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    if (i > mid)
    {
        for (int x = j; x <= high; x++)
        {
            b[k] = a[x];
            k++;
        }
    }
    else
    {
        for (int x = i; x <= mid; x++)
        {
            b[k] = a[x];
            k++;
        }
    }

    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }

    cout << "\nAfter merging: ";

    for (int x = 0; x < 11; x++)
    {
        cout << a[x] << " ";
    }
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge_fun(low, mid, high);
    }
}

int main()
{
    cout << "Before sorting: ";
    for (int i = 0; i < 11; i++)
    {
        cout << a[i] << " ";
    }
    int n = 11;
    merge_sort(0, n - 1);
    cout << "\nAfter sorting: ";
    for (int i = 0; i < 11; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)