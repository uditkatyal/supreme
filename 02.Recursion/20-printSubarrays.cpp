#include <iostream>
#include <vector>
using namespace std;

// recursive approach
// Time complexity -> O(N^2)
void printArray_Util(vector<int> &vec, int start, int end)
{
    // base case
    if (end >= vec.size())
    {
        return;
    }
    // ek case hum solve krenge
    for (int i = start; i <= end; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // baaki recursion sambhal lega
    printArray_Util(vec, start, end + 1);
}

void printSubArray(vector<int> &vec)
{
    for (int start = 0; start < vec.size(); start++)
    {
        int end = start;
        // range bhej rhe
        printArray_Util(vec, start, end);
    }
}

// iterative approach
// Time complexity -> O(N^2)
void fun(string &s)
{

    for (int i = 0; i < s.size(); i++)
    {
        for (int len = 1; len <= s.size() - i; len++)
        {
            cout << s.substr(i, len) << " ";
            cout << endl;
        }
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    // recursive way
    printSubArray(vec);

    // iterative way
    string s = "abc";
    fun(s);
    return 0;
}