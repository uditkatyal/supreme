#include <iostream>
using namespace std;

void solidHalfDiamond(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            continue;
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

    solidHalfDiamond(n);

    return 0;
}