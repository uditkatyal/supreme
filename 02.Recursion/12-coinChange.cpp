#include <iostream>
#include <limits.h>
using namespace std;

int coinChange(int *arr, int n, int sum, int mini)
{
    // base case
    if (sum == 0)
        return 0;
    if (sum < 0)
        return INT_MAX;

    // ek case hum solve krenge
    // for loop recursion pattern
    for (int i = 0; i < n; i++)
    {
        // recursion smbhal rha baaki
        int ans = coinChange(arr, n, sum - arr[i], mini);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
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
    int sum;
    cin >> sum;
    int mini = INT_MAX;
    int ans = coinChange(arr, n, sum, mini);
    int ans1 = (ans == INT_MAX) ? -1 : ans;
    cout << ans1;
    return 0;
}