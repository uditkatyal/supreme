// for loop recursion pattern mai ek bari recurisive tree bnalo (to see the flow easier to code)
#include <iostream>
#include <limits.h>
using namespace std;

int coinChange(int *arr, int n, int sum)
{
    // base case
    if (sum == 0)
        return 0;
    if (sum < 0)
        return INT_MAX;

    int mini = INT_MAX;
    // ek case hum solve krenge
    // for loop recursion pattern
    for (int i = 0; i < n; i++)
    {
        // recursion smbhal rha baaki
        int ans = coinChange(arr, n, sum - arr[i]);
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
    // int mini = INT_MAX;
    int ans = coinChange(arr, n, sum);
    int ans1 = (ans == INT_MAX) ? -1 : ans;
    cout << ans1;
    return 0;
}

// style 1 of solving this problem --> reduce target at every rec call and check when it becomes 0 that is one of the answers
// and if it gets negative (not a answer)

// style 2 of solving this problem --> taking extra variable sum and making it to target there if target == sum
// one of the answers and sum > target (not a an answer)