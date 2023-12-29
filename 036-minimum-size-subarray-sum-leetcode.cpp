#include <bits/stdc++.h>
using namespace std;

// Today's Date - 29 Dec 2023
// Leetcode Question Name - Minimum Size Subarray Sum

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // sliding window
        int i = 0;
        int j = 0;

        int sum = nums[i];
        int len = INT_MAX;
        while (i <= j && j != nums.size())
        {
            if (sum < target)
            {
                j++;
                if (j != nums.size())
                    sum += nums[j];
            }
            else
            {
                len = min(len, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};


int main()
{
    vector<int> vec = {2, 3, 1, 7, 2, 4, 3};
    int target = 7;
    Solution solution;
    cout << solution.minSubArrayLen(target, vec) << endl;
    return 0;
}