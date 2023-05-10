// this depicts nature of stack (if we push ele in stack
// and pop them back they will be obtained in reverse order)
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string my_name = "udit";
    stack<char> s;

    for (int i = 0; i < my_name.size(); i++)
    {
        s.push(my_name[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}