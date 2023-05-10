#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int> &s, int target)
{
    // edge case
    if (s.size() == 0)
    {
        // if stack is empty (we are already at bottom - so INSERT)
        s.push(target);
        return;
    }
    // base case
    if (s.size() == 0)
    {
        s.push(target);
        return;
    }
    // operations on stack
    int temp = s.top();
    s.pop();

    // recursive call
    insertBottom(s, target);

    // backtrack
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    int target = 100;
    insertBottom(s, target);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}