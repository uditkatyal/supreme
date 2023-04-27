#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (v[mid] == target)
    {
        return mid;
    }
    return (v[mid] < target) ? binarySearch(v, mid + 1, end, target) : binarySearch(v, start, mid - 1, target);
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
    int target;
    cin >> target;
    cout << "Element is present at index : " << binarySearch(vec, 0, vec.size() - 1, target);
}