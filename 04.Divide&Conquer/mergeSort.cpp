#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int sizeOfArr1 = mid - start + 1;
    int sizeOfArr2 = end - mid;
    int *arr1 = new int[sizeOfArr1];
    int *arr2 = new int[sizeOfArr2];

    for (int i = 0; i < sizeOfArr1; i++)
    {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < sizeOfArr2; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }

    int k = start;
    int i = 0, j = 0;

    // merge shuru krta
    while (i < sizeOfArr1 && j < sizeOfArr2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < sizeOfArr1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < sizeOfArr2)
    {
        arr[k++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;

    // sort on half
    mergeSort(arr, start, mid);
    // sort other half
    mergeSort(arr, mid + 1, end);

    // merge two sorted arrays
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = n - 1;
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, start, end);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}