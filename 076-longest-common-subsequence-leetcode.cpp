#include <bits/stdc++.h>
using namespace std;

// Today's Date - 15 Jan 2024
// Leetcode Question Name - Longest Common Subsequence

class Solution
{
public:
    int dp[1002][1002];
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp, -1, sizeof(dp));
        return lengthOfLCS(text1, text2, text1.size() - 1, text2.size() - 1);
    }

    int lengthOfLCS(string &text1, string &text2, int index1, int index2)
    {
        if (index1 < 0 || index2 < 0)
            return 0;
        
        if (dp[index1][index2] != -1)
            return dp[index1][index2];

        int result{};
        result = max(result, (lengthOfLCS(text1, text2, index1 - 1, index2 - 1) + (text1[index1] == text2[index2])));
        result = max(result, lengthOfLCS(text1, text2, index1 - 1, index2));
        result = max(result, lengthOfLCS(text1, text2, index1, index2 - 1));
        return dp[index1][index2] = result;
    }
};

int main()
{
    Solution solution;
    // string text1 = "example";
    // string text2 = "sample";

    string text1 = "abcde";
    string text2 = "ace";

    int result = solution.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}