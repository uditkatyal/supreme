// TimeComplexity - worstcase -> O(N*M) && BestCase -> O(M)

#include <iostream>
using namespace std;

void naiveMatch(string text, string ptr)
{

    int n = text.size();
    int m = ptr.size();

    for (int i = 0; i < n - m + 1; i++)
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
}

int main()
{
    string text;
    string ptr;
    cin >> text >> ptr;
    naiveMatch(text, ptr);
    return 0;
}
