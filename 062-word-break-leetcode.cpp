#include <bits/stdc++.h>
using namespace std;

// Today's Date - 9 Jan 2024
// Leetcode Question Name - Word Break

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i=n-1; i>=0; --i)
        {
            for(auto&word:wordDict)
            {
                int len_word = word.size();
                if(i+len_word<=n && s.substr(i,len_word)==word && dp[i+len_word])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    // string s = "leetcode";
    // string s = "applepenapple";
    string s = "catsandog";
    // vector<string> wordDict = {"leet", "code"};
    // vector<string> wordDict = {"apple", "pen"};
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution solution;

    bool result = solution.wordBreak(s, wordDict);
    cout << "Solution: " << (result ? "true" : "false") << endl;

    return 0;
}