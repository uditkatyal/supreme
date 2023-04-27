#include <iostream>
#include <string.h>
using namespace std;

// RIGHT TO LEFT
void lastOccurrenceRTL(string input, int start, char key, int &ans)
{
    // base case
    if (start >= input.length())
    {
        return;
    }

    // ek case solve krna
    if (input[start] == key)
    {
        ans = start;
        return;
    }
    lastOccurrenceRTL(input, start - 1, key, ans);
}

// LEFT TO RIGHT
void lastOccurrenceLTR(string input, int start, char key, int &ans)
{
    // base case
    if (start < 0)
    {
        return;
    }

    // ek case solve krna
    if (input[start] == key)
    {
        ans = start;
    }
    lastOccurrenceLTR(input, start + 1, key, ans);
}

int main()
{
    // char input[] = "ABBABBAB";
    string input;
    cin >> input;
    char key;
    cin >> key;
    int ans = -1;
    lastOccurrenceLTR(input, 0, key, ans);
    lastOccurrenceRTL(input, input.size() - 1, key, ans);

    // STL FUNCTION STRRCHAR
    // we also have strchar for first occurence

    // strrchr works only array of characters becoz this fucntion is taken into c++ from
    // old c
    // char input[] = "ABBABAB";
    // char *ptr = strrchr(input, key);

    // ptr is the pointer to last occurence of key and input points to the first ele of
    //  array so, ptr - input gives index of last occurence of key

    // cout << ptr << endl;
    // cout << ptr - input;
    return 0;
}