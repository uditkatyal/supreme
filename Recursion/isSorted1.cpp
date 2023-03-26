#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> ans, int start, int n)
{
    if (start == n - 1)
    {
        return true;
    }
    if (ans[start] > ans[start + 1])
    {
        return false;
    }
    return isSorted(ans, start + 1, n);
}

int main()
{
    vector<int> ans;
    for (auto it : ans)
    {
        cin >> it;
    }
    cout << isSorted(ans, 0, ans.size());
    return 0;
}