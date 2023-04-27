#include <iostream>
using namespace std;

bool palindromeCheck(string &input, int start)
{
    // base case
    if (start >= input.size() - start - 1)
    {
        return true;
    }
    // ek case hum solve krnege
    if (input[start] != input[input.size() - start - 1])
        return false;
    // baaki recursion sambhal lega
    return palindromeCheck(input, start + 1);
}

int main()
{
    string input;
    cin >> input;
    if (palindromeCheck(input, 0))
    {
        cout << "It's a Palindrome" << endl;
    }
    else
    {
        cout << "It's not Palindrome" << endl;
    }
    return 0;
}