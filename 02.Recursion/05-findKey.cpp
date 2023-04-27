// find key
// find number of occurrences of key
// find index at which key is present

#include <iostream>
using namespace std;

void findKeyOccurrences(int *arr, int start, int n, int key)
{
    if (start >= n)
    {
        return;
    }
    if (arr[start] == key)
    {
        cout << "Ele is present at : " << start << endl;
    }
    return findKeyOccurrences(arr, start + 1, n, key);
}

int findNumberOfOccurrences(int *arr, int n, int key, int count)
{
    if (n == 0)
    {
        return count;
    }
    // sirf 1 case krnege
    if (arr[0] == key)
    {
        count++;
    }
    return findNumberOfOccurrences(arr + 1, n - 1, key, count);
}

bool findKey(int *arr, int n, int key)
{
    // base case
    if (n == 0)
    {
        return false;
    }
    // 1 case hum solve krnege
    if (arr[0] == key)
    {
        return true;
    }
    // baaki recursion sambhal lega
    return findKey(arr + 1, n - 1, key);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << findKey(arr, n, key);
    cout << endl;
    cout << findNumberOfOccurrences(arr, n, key, 0); // returns number of occurrences
    cout << endl;
    findKeyOccurrences(arr, 0, n, key); // returning index at which key is present

    return 0;
}