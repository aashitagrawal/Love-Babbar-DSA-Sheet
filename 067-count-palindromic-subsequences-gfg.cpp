#include <bits/stdc++.h>
using namespace std;

// Today's Date - 12 Jan 2024
// GFG Question Name - Count Palindromic Subsequences

class Solution
{
public:
    int m = 1e9 + 7;

    long long int countPS(string str)
    {
        int n = str.size();
        vector<vector<long long int>> dp(n, vector<long long int>(n, -1));
        return count(0, n - 1, str, dp);
    }

    long long count(int i, int j, string &str, vector<vector<long long int>> &dp)
    {
        if (i == j)
            return 1;
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        long long result;
        if (str[i] == str[j])
            result = (1 + count(i + 1, j, str, dp) + count(i, j - 1, str, dp)) % m;
        else
            result = (0LL + count(i + 1, j, str, dp) + count(i, j - 1, str, dp) - count(i + 1, j - 1, str, dp) + m) % m;
        return dp[i][j] = result;
    }
};

int main()
{
    string s = "abcd";
    Solution solution;
    cout << solution.countPS(s) << endl;
    return 0;
}