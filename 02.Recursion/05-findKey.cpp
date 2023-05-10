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

// findNumberOfOccurences

// 1st style -> passing the ans in parameter (here)
// --> updating answer as we go down the recursive calls and then by the time we reach base case
//  answer is formed and that is being returned from all the recursive functions to the final call
// ans builds(from top to bottom) and then same final ans is returned back from the recursive calls.

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

//  2nd style --> not passing the answer as the parameter
// answer is in the waiting stage as we go down the recursive calls and it starts to form
// after the base case hits. from(down to up) ans builds, so every recursive call does not
// return the final answer but jitne us smaller problem se bna vo return krta hai

int findNumberOfOccurrences(int *arr, int n, int target)
{
    if (n == 0)
    {
        return 0;
    }
    if (arr[0] == target)
    {
        return 1 + findNumberOfOccurrences(arr + 1, n - 1, target);
    }
    else
    {
        return findNumberOfOccurrences(arr + 1, n - 1, target);
    }
    // ternary operatr
    // int c = (arr[0] == target) ? 1 : 0;
    // return c + findNumberOfOccurrences(arr + 1, n - 1, target);
}

// 3rd style pass what is storing our ans by reference (much better and faster) (less memory waste)
// return type of recursive fucntion is void
void findNumberOfOccurrences3(int *arr, int n, int key, int &count)
{
    if (n == 0)
    {
        return;
    }
    // sirf 1 case krnege
    if (arr[0] == key)
    {
        count++;
    }
    return findNumberOfOccurrences3(arr + 1, n - 1, key, count);
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
    cout << "no. of occurrences : ";
    cout << findNumberOfOccurrences(arr, n, key); // returns number of occurrences
    cout << endl;
    findKeyOccurrences(arr, 0, n, key); // returning index at which key is present

    return 0;
}