// imp -> two different recursive calls ONE -> to reverse stack and second to insertAtBottom
#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int> &s, int target)
{

    // base case
    if (s.size() == 0)
    {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();

    insertBottom(s, target);

    s.push(temp);
}

void reverseStack(stack<int> &s)
{

    // base case
    if (s.empty())
    {
        return;
    }
    // ek case hum krnege solve
    // ek element nikal ke insertAtBottom
    int temp = s.top();
    s.pop();

    // reverse stack
    reverseStack(s);

    // reversed stack mai insert at bottom krdeya
    insertBottom(s, temp);
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

    reverseStack(s);
    return 0;
}