// Time complexity - O(N)
#include <iostream>
using namespace std;

// tail recursion
// 5 4 3 2 1
void printCounting(int n)
{
    // base case
    if (n == 0)
        return;

    cout << n << " ";
    return printCounting(n - 1);
}

// head recursion
// 1 2 3 4 5
void printCounting1(int n)
{
    // base case
    if (n == 0)
        return;

    printCounting1(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    printCounting(n);
    cout << endl;
    printCounting1(n);
    return 0;
}