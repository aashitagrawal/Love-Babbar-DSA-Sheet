#include <bits/stdc++.h>
using namespace std;

// Today's Date - 14 Feb 2024
// Leetcode Question Name - Find Pivot Index

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        const int n = nums.size();
        int left=0;
        int right=0;

        for(int i=0; i<n; ++i)
            right+=nums[i];
        
        for(int i=0; i<n; ++i)
        {
            right-=nums[i];
            if(left==right)
                return i;
            left+=nums[i];
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << endl
         << solution.pivotIndex(nums);
    return 0;
}