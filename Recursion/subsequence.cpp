// interative --> bitmasking
// recursion --> // include and exclude pattern problem

#include <iostream>
#include <vector>
using namespace std;

void subSequence(vector<string> &ans, string input, string output, int start, int size)
{
    if (start == size)
    {
        ans.push_back(output);
        return;
    }
    // exclude
    subSequence(ans, input, output, start + 1, size);

    // include
    output.push_back(input[start]);
    subSequence(ans, input, output, start + 1, size);
}

int main()
{

    string input;
    cin >> input;
    string output;
    vector<string> ans;
    subSequence(ans, input, output, 0, input.size());

    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}
