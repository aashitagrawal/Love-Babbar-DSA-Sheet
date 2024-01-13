#include <bits/stdc++.h>
using namespace std;

// Today's Date - 9 Jan 2024
// Leetcode Question Name - Next Permutation

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        // find the breakpoint
        int ele = nums[n - 1];
        int breakpoint_index = n - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (ele > nums[i])
            {
                breakpoint_index = i;
                break;
            }
            ele = nums[i];
        }

        if (breakpoint_index == n-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find next greater ele and swap
        for (int i = n - 1; i > breakpoint_index; --i)
        {
            if (nums[i] > nums[breakpoint_index])
            {
                swap(nums[i], nums[breakpoint_index]);
                break;
            }
        }

        // reverse the array
        reverse(nums.begin() + breakpoint_index + 1, nums.end());
    }
};

int main()
{
    vector<int> vec = {2,3,5,1,8,7,9,10};
    for (auto &ele : vec)
        cout << ele << " ";
    cout << endl;
    Solution solution;
    solution.nextPermutation(vec);
    for (auto &ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}