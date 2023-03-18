#include <iostream>
using namespace std;

void hollowDiamond(int n)
{
    // even pattern
    // upper half
    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         if (j == 0 || j == i)
    //         {
    //             cout << "* ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     cout << endl;
    // }
    // // lower half
    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         if (i == 0)
    //         {
    //             break;
    //         }
    //         if (j == 0 || j == n - i - 1)
    //         {

    //             cout << "* ";
    //         }
    //         else
    //         {
    //             cout << "  ";
    //         }
    //     }
    //     if (i != 0)
    //     {
    //         cout << endl;
    //     }
    //     else
    //     {
    //         continue;
    //     }
    // }

    // keep odd pattern
    // upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j == 0 || j == 2 * i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    // lower half

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            if (j == 0 || j == 2 * n - 2 * i - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    hollowDiamond(n);
}