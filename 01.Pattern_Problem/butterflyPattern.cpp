#include <iostream>
using namespace std;

void butterflyPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // lower half

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            continue;
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    butterflyPattern(n);
    return 0;
}