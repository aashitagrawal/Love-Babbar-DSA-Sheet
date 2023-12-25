#include <bits/stdc++.h>
using namespace std;

// Today's Date - 25 Dec 2023
// Leetcode Question Name - Max Number of K-Sum Pairs

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = n - 1, ans = 0;
        while (i < j)
        {
            int sum = nums[i] + nums[j];

            if (sum < k)
                i++;
            else if (sum > k)
                j--;
            else
            {
                i++;
                j--;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    Solution solution;
    cout << solution.maxOperations(vec, 5);
    return 0;
}