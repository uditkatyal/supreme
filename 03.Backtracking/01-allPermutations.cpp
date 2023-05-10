#include <iostream>
using namespace std;

// hur ek character hur ek postion pe ana chata hai (OBSERVATION HERE)
void permutation(string &s, int i)
{
    // base case
    if (i >= s.length())
    {
        cout << s << " ";
        return;
    }
    // start loop from current indexing of string becoz previous positions are fixed,
    // they will now remain and wont be swapped
    for (int j = i; j < s.length(); j++)
    {
        // swap
        swap(s[i], s[j]);
        // rec call
        permutation(s, i + 1);
        // swap -> to recreate the original string
        swap(s[i], s[j]);
    }
}

int main()
{
    string s = "abc";
    permutation(s, 0);
    return 0;
}

// Time compelxity -> O(N!) to get all permuations

// Note for this question
// if we pass string by reference then modifications will be made to it within the function calls
// hence we will swap it back to make it original string before further calls

// if we pass by value
// the s string in the permute function is a copy of the original string, so any modifications made to it within the function will not affect the original string outside the function.
// but, we still need to swap the characters back to their original positions so that the loop can continue with the next iteration and generate all possible permutations of the original string.

// fun fact -> in pass by value its even working wihout swapping becoz its generating all possible permuation (even submitted on leetcode)

// without swapping -> abc acb bac bca cab cba
// with swapping -> abc acb bac bca cba cab
