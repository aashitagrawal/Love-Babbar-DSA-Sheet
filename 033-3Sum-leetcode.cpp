#include <bits/stdc++.h>
using namespace std;

// Today's Date - 28 Dec 2023
// Leetcode Question Name - 3Sum

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left]==nums[left-1] && left < right)
                        left++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution solution;
    vector<vector<int>> ans = solution.threeSum(vec);
    for (auto vector : ans)
    {
        for (int ele : vector)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}