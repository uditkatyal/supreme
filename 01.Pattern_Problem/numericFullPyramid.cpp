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
        // to print numbers
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + j + 1 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << i + j << " ";
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