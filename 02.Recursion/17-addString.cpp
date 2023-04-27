#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// leetcode question 415.

void solve(string &num1, int i, string &num2, int j, int carry, string &ans)
{
    // base case
    if (i < 0 && j < 0)
    {
        if (carry)
        {
            ans.push_back(carry + '0');
        }
        return;
    }
    // ek case mai solve kroonga
    int ans1 = (i >= 0 ? num1[i] : '0') - '0';
    int ans2 = (j >= 0 ? num2[j] : '0') - '0';

    ans.push_back((carry + ans1 + ans2) % 10 + '0');
    carry = (carry + ans1 + ans2) / 10;

    solve(num1, i - 1, num2, j - 1, carry, ans);
}
string addStrings(string num1, string num2)
{
    // jo create krna hai
    string ans = "";
    solve(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}
// we can do both the ways either by passing ans as referrence(better sol) or
// by creating ans again and again and merging one case solved with recursive solutions(takes hell amount of memory)
