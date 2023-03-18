#include <iostream>
using namespace std;

void alphabeticPalindrome(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int a = 64;
            char ch = j + 1 + a;
            cout << ch;
        }
        for (int j = i; j > 0; j--)
        {
            int a = 64;
            char ch = j + a;
            cout << ch;
        }
        cout << endl;
    }
}
int main()
{

    int n;
    cin >> n;

    alphabeticPalindrome(n);
    return 0;
}