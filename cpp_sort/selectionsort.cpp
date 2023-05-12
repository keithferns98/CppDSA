#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    int arr[] = {12, 8, 19, 20, 22, 0, 1, 45, 5, 99, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
