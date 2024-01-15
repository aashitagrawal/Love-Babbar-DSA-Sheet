#include <bits/stdc++.h>
using namespace std;

// Today's Date - 10 October 2023
// Topic - Subset sum problem

// que link - https://www.interviewbit.com/problems/subset-sum-problem/
// approach - this is a 0-1 knapsack problem, so we need a index factor

bool top_down_dp(vector<int> &nums, int sum, int index, signed char dp[][100005]) // returns if the sum is possible considering till 'index' elements
{
    if (sum == 0)
        return true;
    if (index < 0)
        return false;
    if (dp[index][sum] != -1)
        return dp[index][sum];

    bool ans = false;
    // choose the index
    if (sum - nums[index] >= 0)
        ans |= top_down_dp(nums, sum - nums[index], index - 1, dp);

    // didn't choose the index
    ans |= top_down_dp(nums, sum, index - 1, dp);

    return dp[index][sum] = ans;
}

int solve(vector<int> &A, int B)
{
    signed char dp[105][100005];
    memset(dp, -1, sizeof(dp));
    return top_down_dp(A, B, A.size() - 1, dp);
}

int main()
{
    vector<int> check = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // cout<<"size of vector  = "<<check.size()<<endl;
    int sum = 100000;
    cout << "Ans = " << solve(check, sum) << endl;
}