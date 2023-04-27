#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> vec, int start, int size)
{

    if (start == size - 1)
    {
        return true;
    }
    if (vec[start] > vec[start + 1])
    {
        return false;
    }

    return isSorted(vec, start + 1, size);
}

int main()
{

    vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    // while (cin >> a)
    // {
    //     vec.push_back(a);
    // }
    if (isSorted(vec, 0, vec.size()))
    {
        cout << "Sorted Array";
    }
    else
    {
        cout << "Not Sorted Array";
    }
}