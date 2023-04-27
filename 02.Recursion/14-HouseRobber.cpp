// maximum sum of non-adjacent elements of array
// maximum sum of subsequence which do not have adjacent elements
// include exclude pattern

#include <iostream>
#include <vector>
using namespace std;

// // without sum variable
// more intuitive

//     // base case
//     if(start >= n) return 0;

//     // pick
//     int ans1 = nums[start] + maxAdjacentSum(nums, start+2);

//     // not pick
//     int ans2 = maxAdjacentSum(nums, start+1);

//     return max(ans1,ans2);

int maxAdjacentSum(vector<int> &nums, int start, int n, int sum)
{
    // base case
    if (start >= n)
    {
        return sum;
    }
    // ek case hum solve kr rhe baaki recursion smbhal lega
    int ans1 = maxAdjacentSum(nums, start + 2, n, sum + nums[start]);
    int ans2 = maxAdjacentSum(nums, start + 1, n, sum);

    return max(ans1, ans2);
}

int main()
{
    vector<int> nums{2, 7, 9, 3, 1};
    cout << maxAdjacentSum(nums, 0, nums.size(), 0);
    return 0;
}