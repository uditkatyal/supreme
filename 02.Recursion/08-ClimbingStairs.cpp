// leetcode
// Time complexity - O(2^N) exponential
#include <iostream>
using namespace std;

// for n == 0 ans will be 1
// think logically to reach 0th stair if number of ways are zero then how can we possibly go ahead therefore number of ways to reach oth stair is one.

int climbStairs(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << climbStairs(n);

    return 0;
}