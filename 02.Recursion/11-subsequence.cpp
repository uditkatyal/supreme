// recursive pattern -> INCLUDE - EXCLUD
// Time Complexity -> O(2^N) EXPONENTIAL
// always recursive tree to have understanding of time complexity

// without recurison -> BITMasking se hoga (TODO)

#include <iostream>
#include <vector>
using namespace std;

void subsequence(vector<char> &vec, int start, int n, vector<string> &ans, string output)
{
    // base case
    if (start >= n)
    {
        ans.push_back(output);
        return;
    }
    // exclude

    subsequence(vec, start + 1, n, ans, output);

    // include
    output.push_back(vec[start]);
    subsequence(vec, start + 1, n, ans, output);

    // we must backtrack if we include first

    // also if we just do output+vec[start] then no need to backtrack even if we include
    // first coz output is not changed only its value is passed(pass by value)
}

int main()
{
    int n;
    cin >> n;
    vector<char> vec;
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        vec.push_back(a);
    }
    // can simply take a string as well
    // string input
    vector<string> ans;
    string output;
    subsequence(vec, 0, vec.size(), ans, output);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}