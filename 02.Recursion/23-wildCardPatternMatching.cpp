#include <iostream>
using namespace std;

bool isMatchHelper(string &s, int si, string &p, int pi)
{
    // base case
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }

    // single character  matches
    if (s[si] == p[pi] || p[pi] == '?')
    {
        return isMatchHelper(s, si + 1, p, pi + 1);
    }

    // * come in pattern
    if (p[pi] == '*')
    {
        // treat * as null or empty
        bool caseA = isMatchHelper(s, si, p, pi + 1);

        // * consumes one character of s
        bool caseB = isMatchHelper(s, si + 1, p, pi);

        return caseA || caseB;
    }

    // char doesnt match
    return false;
}
bool isMatch(string s, string p)
{

    int si = 0; // pointer index to s string
    int pi = 0; // pointer index to p string

    return isMatchHelper(s, si, p, pi);
}

int main()
{
    string s = "abcdefg";
    string p = "ab*fg";
    if (isMatch(s, p))
    {
        cout << "Matching Pattern" << endl;
    }
    else
    {
        cout << "Not Matching Pattern" << endl;
    }
    return 0;
}