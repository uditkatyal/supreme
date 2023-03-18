#include <iostream>
using namespace std;

void printHollowRect(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {

                if (j == 0 || j == m - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}

// void printHollowRect(int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0 || i == n - 1)
//         {
//             for (int i = 0; i < m; i++)
//             {
//                 cout << "* ";
//             }
//             cout << endl;
//         }
//         else
//         {
//             cout << "* ";
//             for (int i = 0; i < m - 2; i++)
//             {
//                 cout << "  ";
//             }
//             cout << "* ";
//             cout << endl;
//         }
//     }
// }
int main()
{
    int n;
    int m;
    cin >> n >> m;
    printHollowRect(n, m);
    return 0;
}