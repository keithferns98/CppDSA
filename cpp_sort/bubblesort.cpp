#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                ;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
}
int main()
{
    int arr[] = {64, 33, 25, 12, 99, 11, 27, 27, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, n);
    printArray(arr, n);
    cout << "HelloWorld";
    return 0;
}