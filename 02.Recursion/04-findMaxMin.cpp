// Time complexity - O(N)
#include <iostream>
#include <limits.h>
using namespace std;

// either send mini and maxi by refernce then we can just have void functions
// or we can return maxi and mini after every recurive call then we can pass by value

void findMin(int *arr, int n, int &mini)
{
    if (n == 0)
    {
        return;
    }
    mini = min(arr[0], mini);
    findMin(arr + 1, n - 1, mini);
}
void findMax(int *arr, int n, int &maxi)
{
    // base case
    if (n == 0)
    {
        return;
    }
    // small calculation
    maxi = max(arr[0], maxi);
    // recursive call
    findMax(arr + 1, n - 1, maxi);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxi = INT_MIN;
    int mini = INT_MAX;
    findMax(arr, n, maxi);
    findMin(arr, n, mini);
    cout << "Max ele is : " << maxi << endl;
    cout << "Min ele is : " << mini << endl;
    return 0;
}