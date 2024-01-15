#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Dec 2023
// Leetcode Question Name - Longest Increasing Subsequence

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dummy_lis;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            auto it = lower_bound(dummy_lis.begin(), dummy_lis.end(), nums[i]);

            if (it == dummy_lis.end())
                dummy_lis.push_back(nums[i]);
            else
            {
                int index = distance(dummy_lis.begin(), it);
                dummy_lis[index] = nums[i];
            }
        }

        // cout << "\nPrinting the dummy_lis vector \n";
        // for (auto ele : dummy_lis)
        //     cout << ele << " ";
        // cout << endl;

        return dummy_lis.size();
    }
};

// O(nlogn)

int main()
{
    vector<int> vec = {2,5,3,7,11,9,10,13,6};
    Solution solution;
    cout << solution.lengthOfLIS(vec) << endl;
    return 0;
}