#include <iostream>
#include <stack>
using namespace std;

// Stack nature -> agar hum koi bhi data stack mai push krke pop kre then it will be
// percieved in reverse order.

// so suppose question comes reverse a string (just add into stack and remove it)
// it will come out in reverse order becoz of stacks nature!
int main()
{
    stack<int> s;

    // insertion in stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // deletion in stack
    s.pop();

    // peek element in stack
    cout << s.top();
    cout << endl;

    // size of stack
    cout << s.size();
    cout << endl;

    // printing stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}