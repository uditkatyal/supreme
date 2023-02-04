#include <iostream>
using namespace std;

void solidDiamond(int n)
{
    // upper half
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
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
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0)
            {
                break;
            }
            else
            {
                cout << "* ";
            }
        }
        if (i != 0)
        {
            cout << endl;
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    solidDiamond(n);
}