// Minimum count of numbers required from given array to represent Sum

// 2nd pattern pattern -> for loop mai (recursion)

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int helperCoinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = helperCoinChange(coins, amount - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return mini;
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = helperCoinChange(coins, amount);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{

    vector<int> coins;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    int target;
    cin >> target;
    cout << coinChange(coins, target);
}
