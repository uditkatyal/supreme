// quick sort -> taking 1st element as pivot
#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivotIndex = start; // taking 1st element as pivot
    int pivotElement = arr[pivotIndex];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[pivotIndex])
        {
            count++;
        }
    }
    swap(arr[pivotIndex], arr[start + count]);
    pivotIndex = start + count;

    int i = start;
    int j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
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

void quickSort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // find partition index
    int p = partition(arr, start, end);

    // left part ko sort recursion krdega
    quickSort(arr, start, p - 1);

    // right part sort recursion kdega
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[] = {2, 8, 8, 2, 5, 4};
    int n = 6;
    int start = 0;
    int end = n - 1;
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, start, end);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}