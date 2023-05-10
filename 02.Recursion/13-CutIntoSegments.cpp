// . You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z.
// your total number of cut segments must be maximum.
#include <iostream>
#include <limits.h>
using namespace std;

// 1st approach
int cutIntoSegment(int x, int y, int z, int length)
{
    // base case
    if (length == 0)
        return 0;
    if (length < 0)
        return INT_MIN;

    int ans1 = cutIntoSegment(x, y, z, length - x) + 1;
    int ans2 = cutIntoSegment(x, y, z, length - y) + 1;
    int ans3 = cutIntoSegment(x, y, z, length - z) + 1;

    return max(ans1, max(ans2, ans3));
    // return 1 + max(ans1, max(ans2,ans3));
}

// 2nd approach -> isme -ve keleye call hi nhi jane derhe

// int cutIntoSegments(int x, int y , int z, int target){
//   // base case
//   if(target == 0){
//     return 0;
//   }
//   int a = INT_MIN;
//   if(x <= target){
//     a = cutIntoSegments(x,y,z, target-x);
//   }
//   int b = INT_MIN;
//   if(y <= target){
//     b = cutIntoSegments(x,y,z, target-y);
//   }

//   int c = INT_MIN;
//   if(z <= target){
//     c = cutIntoSegments(x,y,z, target-z);
//   }

//   return 1 + max(a,max(b,c));
// }



// this if we pass x,y,z in an array

// // base case
// if (length == 0)
// {
//     return 0;
// }
// if (length < 0)
// {
//     return INT_MIN;
// }
// int maxi = INT_MIN;
// for (int i = 0; i < n; i++)
// {
//     int ans = cutIntoSegment(arr, n, length - arr[i]);
//     if (ans != INT_MIN)
//     {
//         maxi = max(maxi, ans + 1);
//     }
// }
// return maxi;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int length;
    cin >> length;
    int mini = INT_MAX;
    int ans = cutIntoSegment(x, y, z, length);
    int ans1 = (ans < 0) ? 0 : ans;
    cout << ans1;
    return 0;
}