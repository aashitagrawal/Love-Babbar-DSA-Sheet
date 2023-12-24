#include <bits/stdc++.h>
using namespace std;

// Today's Date - 20 Dec
// Leetcode Question Name - Maximum Subarray

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;
        for (int ele : nums)
        {
            currSum = max(ele, currSum + ele);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> vec = {5, 4, -1, 7, 8};
    Solution solution;
    cout << solution.maxSubArray(vec);
    return 0;
}