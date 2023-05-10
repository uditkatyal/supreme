#include <iostream>
using namespace std;

void removeOCC(string &s, string &part)
{

    // when part becomes bigger
    // base case
    if (s.size() < part.size())
    {
        return;
    }
    // for loop recursion
    // we call recursion only when part existed in s otherwise there is no need

    // ek case hum solve krenge -> will find one such substring and then baaki recursion sambhal lega

    for (int i = 0; i < s.size(); i++)
    {
        if (s.substr(i, part.size()) == part)
        {
            s.erase(i, part.size());
            removeOCC(s, part);
        }
    }
}

// Time complexity -> O(N^2)

// time complexity for finding one substring in worst case -> O(m*n)
// time complexity of one case is O(m*n) and recursive call is made n/m times in worst case
// worst case will be s consists of substrings only "abcabcabcabc"
// so O(m*n) * n/m = O(N^2)

// 2nd approach
//  void removeOCC(string &s, string part){
//         // search for part in s, find returns starting index of part in s
//         int found = s.find(part);
//         if(found != string::npos){
//             // erase the part
//            string left_part = s.substr(0,found);
//            string right_part = s.substr(found+part.size(), s.size());

//            s = left_part+right_part;
//            removeOCC(s,part);
//         }
//     }

// 3rd approach -> iterative
// string removeOccurrences(string s, string part) {
//         // iterative approach
//         int found = s.find(part);
//         while(found != string::npos){
//             s.erase(found,part.size());
//             found = s.find(part);
//         }
//         return s;
//     }

int main()
{
    string s = "aabcabdabcbda";
    string part = "abc";

    cout << s << endl;
    removeOCC(s, part);
    cout << s << endl;
    return 0;
}