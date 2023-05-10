#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        profit = max(profit, prices[i] - mini);
    }
    return profit;
}

void maxProfit2(vector<int> &prices, int i, int &mini, int &profit)
{

    // base case
    if (i >= prices.size())
        return;

    // ek case hum solve krnege
    mini = min(mini, prices[i]);
    profit = max(profit, prices[i] - mini);

    // baaki recursion sambhal lega

    maxProfit2(prices, i + 1, mini, profit);
}

int main()
{
    vector<int> prices = {7, 1, 3, 4, 5, 6};

    // iterative
    cout << maxProfit(prices) << endl;

    // recursive
    int mini = INT_MAX;
    int profit = 0;
    maxProfit2(prices, 0, mini, profit);
    cout << profit << endl;
    return 0;
}