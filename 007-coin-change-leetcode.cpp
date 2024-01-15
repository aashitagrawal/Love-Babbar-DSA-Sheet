#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Dec 2023
// Leetcode Question Name - Coin Change 1

class Solution
{
public:
    static const int N = 1e4 + 5;
    int dp[N];

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int answer = min_coins(coins, amount);
        if (answer == INT_MAX)
            return -1;
        else
            return answer;
    }

    int min_coins(vector<int> &coins, int amount) // min coins needed for 'amount' input
    {
        if (amount == 0)
            return 0;
        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); ++i)
        {
            if (amount - coins[i] >= 0)
                ans = min(ans + 0LL, min_coins(coins, amount - coins[i]) + 1LL);
        }
        return dp[amount] = ans;
    }
};

int main()
{
    vector<int> vec = {1,2,3,5};
    Solution solution;
    cout << "Answer = " << solution.coinChange(vec, 19);
    return 0;
}