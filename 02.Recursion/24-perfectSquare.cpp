#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int perfectSquare(int n, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    // no need as if n goes beyond zero it will not go insside for loop
    // hence returning INT_MAX always
    // and we are always checking ans before finding min
    // if (n < 0)
    //     return INT_MAX
    if (dp[n] != -1)
        return dp[n];
    int mini = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {
        int ans = perfectSquare(n - (i * i), dp);
        if (ans != INT_MAX)
        {

            mini = min(mini, ans + 1);
        }
    }
    return dp[n] = mini;
}

int main()
{
    int n = 999;
    vector<int> dp(n + 1, -1);

    cout << perfectSquare(n, dp);
    return 0;
}