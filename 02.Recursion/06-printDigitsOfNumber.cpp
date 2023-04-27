#include <iostream>
using namespace std;

void printDigits(int n)
{
    if (n == 0)
    {
        return;
    }
    // recursion sambhal lega
    printDigits(n / 10);
    // 1 case hum solve krdeye
    cout << n % 10 << " ";
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        printDigits(n);
    }
    return 0;
}