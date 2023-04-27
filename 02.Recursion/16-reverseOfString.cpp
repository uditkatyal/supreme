#include <iostream>
using namespace std;

void reverseOfString(string &input, int start)
{
    // base case
    if (start >= input.size() - start - 1)
    {
        return;
    }
    // ek case mai solve kroonga
    swap(input[start], input[input.size() - start - 1]);

    // baaki recursion sambhal lega
    reverseOfString(input, start + 1);
}

int main()
{
    string input;
    cin >> input;
    reverseOfString(input, 0);
    cout << input << endl;

    return 0;
}