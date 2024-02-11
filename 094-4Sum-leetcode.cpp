#include <bits/stdc++.h>
using namespace std;

// Today's Date - 10 Feb 2024
// Leetcode Question Name - 4Sum

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        const int n = nums.size();
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));

        for (int i = 0; i <= n - 4; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j <= n - 3; ++j)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1, l = n - 1;
                while (k < l)
                {
                    long long sum = 0LL + nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<int> nums = {1, -2, -5, -4, -3, 3, 3, 5};
    // int target = 0;
    int target = -11;
    vector<vector<int>> result = solution.fourSum(nums, target);
    for (vector<int> r : result)
    {
        for (int i : r)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}