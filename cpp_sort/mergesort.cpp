#include <iostream>
using namespace std;

void merge(int *arr, int si, int ei)
{
    int mid = (si + ei) / 2;
    int len1 = mid - si + 1;
    int len2 = ei - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int k = si;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    int f = mid + 1;
    for (int j = 0; j < len2; j++)
    {
        second[j] = arr[f++];
    }
    // merge the new arrays
    int index1 = 0;
    int index2 = 0;
    int mainarrayindex = si;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainarrayindex++] = first[index1++];
        }
        else
        {
            arr[mainarrayindex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainarrayindex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainarrayindex++] = second[index2++];
    }
}

void mergesort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;

    mergesort(arr, si, mid);
    mergesort(arr, mid + 1, ei);
    merge(arr, si, ei);
}
int main()
{
    int arr[] = {5, 1, 2, 5, 0, 77, 9, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int si = 0;
    int ei = n;
    mergesort(arr, si, ei);
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}