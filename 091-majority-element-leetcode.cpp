#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Feb 2024
// Leetcode Question Name - Majority Element

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        const int n = nums.size();
        int ele=nums[0];
        int count=1;

        for(int i = 1; i<n; ++i)
        {
            if(nums[i]==ele)
                count++;
            else
            {
                if(count>1)
                    count--;
                else
                {
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
    }
};

int main()
{
    Solution solution;

    // Input: nums = [3,2,3]
    // Output: 3
    vector<int> nums1 = {3, 2, 3};
    cout << solution.majorityElement(nums1) << endl;

    // Input: nums = [2,2,1,1,1,2,2]
    // Output: 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << solution.majorityElement(nums2) << endl;
    return 0;
}