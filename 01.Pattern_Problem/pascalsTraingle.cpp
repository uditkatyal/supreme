#include <iostream>
using namespace std;

void pascalsTriangle(int n)
{

    for (int line = 1; line <= n; line++)
    {
        int c = 1;
        for (int j = 1; j <= line; j++)
        {
            cout << c << " ";
            c = c * (line - j) / j;
        }
        cout << endl;
    }
}

// void pascalsTriangle(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int c = 1;
//         for (int j = 0; j < i + 1; j++)
//         {
//             if (j == 0 || j == i)
//             {
//                 cout << 1 << " ";
//             }
//             else
//             {
//                 c = c * (i - j) / j;
//                 cout << c << " ";
//             }
//         }
//         cout << endl;
//     }
// }

int main()
{
    int n;
    cin >> n;
    pascalsTriangle(n);
    return 0;
}