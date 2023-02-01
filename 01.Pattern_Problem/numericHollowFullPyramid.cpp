#include <iostream>
using namespace std;

void numericFullPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // to print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }

        if (i != 0 && i != n - 1)
        {
            cout << 1;
            for (int j = 0; j < i * 2; j++)
            {
                cout << "  ";
            }
            cout << i + 1;
        }
        else
        {
            for (int j = 0; j <= i; j++)
            {
                cout << j + 1 << "   ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    numericFullPyramid(n);
    return 0;
}