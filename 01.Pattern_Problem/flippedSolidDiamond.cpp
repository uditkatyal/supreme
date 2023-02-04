#include <iostream>
using namespace std;

void flippedSolidDiamond(int n)
{
    // upperhalf
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (2 * i + 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // lowerHalf
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (2 * n - 2 * i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
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

    flippedSolidDiamond(n);
    return 0;
}