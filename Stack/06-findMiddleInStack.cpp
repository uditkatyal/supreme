// this pattern of problems is famous for solving stack problems using recursion
#include <iostream>
#include <stack>
using namespace std;

void middleStack(stack<int> &s, int &totalSize)
{
    // empty case
    if (s.size() == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }
    // base case
    if (s.size() == totalSize / 2 + 1)
    {
        cout << "Middle element is : " << s.top() << endl;
        return;
    }
    // remove ele from stack
    int temp = s.top();
    s.pop();
    middleStack(s, totalSize);

    // backtrack
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);

    int totalSize = s.size();
    middleStack(s, totalSize);
    return 0;
}