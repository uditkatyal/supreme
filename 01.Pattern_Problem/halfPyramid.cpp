#include <iostream>
using namespace std;

void printHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
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
    printHalfPyramid(n);
    return 0;
}