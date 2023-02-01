#include <iostream>
using namespace std;

void printFullPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // to print spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // to print stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    printFullPyramid(n);
    return 0;
}