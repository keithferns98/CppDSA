#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int count = 0;

    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // placed pivot at right index
    int pivotIndex = si + count;
    arr[si] = arr[pivotIndex];
    arr[pivotIndex] = pivot;

    // Check if condition satisfy i.e. store left side lesser than pivot
    // and right side greater than the pivot
    int i = si;
    int j = ei;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quicksort(int arr[], int si, int ei)
{
    // Base case
    if (si >= ei)
    {
        return;
    }
    // Partition function which selects a pivot value and stores
    // lesser than values on left and greater than values on right.
    int p = partition(arr, si, ei);
    // left sort
    quicksort(arr, si, p - 1);
    quicksort(arr, p + 1, ei);
    // right sort
}
int main()
{
    int arr[] = {2, 4, 1, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for (int i; i < n; i++)
    {
        cout << " " << arr[i];
    }
}