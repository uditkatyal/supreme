#include <iostream>
#include <limits.h>
using namespace std;
#define d 256

void rabinKarp(string text, string ptr, int q)
{
    int n = text.size();
    int m = ptr.size();
    int h = 1;
    int p = 0; // hashcode for ptr
    int t = 0; // hashcode for text

    for (int i = 0; i < m - 1; i++)
    {
        h *= d;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + ptr[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (int i = 0; i < n - m + 1; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != ptr[j])
                    break;
            }
            if (j == m)
            {
                cout << "Pattern found at : " << i << endl;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
        }
    }
}

int main()
{

    string text;
    string ptr;
    cin >> text >> ptr;
    int q = INT_MAX;
    rabinKarp(text, ptr, q);
}