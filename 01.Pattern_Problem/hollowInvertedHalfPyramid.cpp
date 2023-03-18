#include <iostream>
using namespace std;

void printhollowInvertedHalfPyramid(int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0 || i == n - 1)
    //     {
    //         for (int j = 0; j < n - i; j++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     else
    //     {
    //         cout << "* ";
    //         for (int j = 0; j < n - i - 2; j++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << "*";
            }
            else
            {
                if (j == 0 || j == n - i - 1)
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
    printhollowInvertedHalfPyramid(n);
    return 0;
}