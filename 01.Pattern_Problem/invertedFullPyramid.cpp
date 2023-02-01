#include <iostream>
using namespace std;

void printInvertedFullPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // to print spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // to print stars
        for (int j = 0; j < n - i; j++)
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
    printInvertedFullPyramid(n);
    return 0;
}