#include <iostream>
using namespace std;

void numericHollowInvertedHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {

            for (int j = 0; j < n - i; j++)
            {
                cout << j + 1;
            }
        }
        else
        {
            cout << i + 1;
            for (int j = 0; j < n - i - 2; j++)
            {
                cout << " ";
            }
            cout << n;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    numericHollowInvertedHalfPyramid(n);
    return 0;
}