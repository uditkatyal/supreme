#include <iostream>
using namespace std;

void hollowFullPyramid(int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i - 1; j++)
    //     {
    //         cout << "  ";
    //     }
    //     // for (int j = 0; j < (2 * i + 1); j++)
    //     // {
    //     //     cout << "* ";
    //     // }
    //     if (i != 0 && i != n - 1)
    //     {
    //         cout << "* ";
    //         for (int j = 0; j < (2 * i - 1); j++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << "*";
    //     }
    //     else
    //     {
    //         for (int j = 0; j < (2 * i + 1); j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << "*";
            }
            else
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
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    hollowFullPyramid(n);
}