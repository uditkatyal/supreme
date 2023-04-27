#include <iostream>
using namespace std;

int n1 = 0, n2 = 1;

// fibonacci number

// int fibonacci(int n)
// {
//     if (n == 1 || n == 2)
//     {
//         return n - 1;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// printing fibonacci series
void fibonacci(int n)
{
    // base case
    if (n == 0)
        return;
    // small calculation
    int n3 = n1 + n2;
    cout << n3 << " ";
    n1 = n2;
    n2 = n3;
    // recursive call
    fibonacci(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << 0 << " " << 1 << " ";
    fibonacci(n - 2);
    return 0;
}