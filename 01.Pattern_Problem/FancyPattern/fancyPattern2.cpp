#include <iostream>
using namespace std;

void fancyPattern2(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == i)
            {
                cout << i + 1;
            }
            else
            {
                cout << i + 1 << "*";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (j == n - i - 1)
            {
                cout << n - i;
            }
            else
            {
                cout << n - i << "*";
            }
        }
        cout << endl;
    }
}
int main()
{

    int n = 0;
    cin >> n;
    fancyPattern2(n);
}