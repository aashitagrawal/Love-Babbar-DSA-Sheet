#include <bits/stdc++.h>
using namespace std;

// Today's Date - 3 Feb 2024
// Leetcode Question Name - Wildcard Matching

/**
 * @class Solution
 * @brief Class that implements wildcard matching algorithm.
 */
class Solution
{
public:
    /**
     * @brief Checks if a given string matches a wildcard pattern.
     * @param s The input string.
     * @param p The wildcard pattern.
     * @return True if the string matches the pattern, false otherwise.
     */
    bool isMatch(string s, string p)
    {
        const int n = s.size();
        const int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return matchWildcard(n-1, m-1, s, p, dp);
    }

private:
    /**
     * @brief Recursive helper function to match the wildcard pattern.
     * @param i The current index in the text string.
     * @param j The current index in the pattern string.
     * @param text The input text string.
     * @param pattern The wildcard pattern.
     * @param dp The memoization table for dynamic programming.
     * @return True if the string matches the pattern, false otherwise.
     */
    bool matchWildcard(int i, int j, string &text, string &pattern, vector<vector<int>> &dp)
    {
        // Base Cases
        if (i < 0 && j < 0) // both text and pattern are exhausted
            return true;
        if (i < 0 && j >= 0) // only pattern is exhausted
        {
            while (j >= 0)
                if (pattern[j--] != '*')
                    return false;
            return true; // pattern containing only '*'
        }
        if (i >= 0 && j < 0) // only text is exhausted
            return false;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        // Main code
        if (pattern[j] == '*')
            return dp[i][j] = matchWildcard(i - 1, j, text, pattern, dp) | matchWildcard(i, j - 1, text, pattern, dp);
        else if (text[i] == pattern[j] || pattern[j] == '?')
            return dp[i][j] = matchWildcard(i - 1, j - 1, text, pattern, dp);
        else
            return dp[i][j] = false;
    }
};

int main()
{
    Solution solution;
    string s = "abcde";
    string p = "a*de";
    bool result = solution.isMatch(s, p);
    cout << "Matching result: " << (result ? "true" : "false") << endl;
    return 0;
}