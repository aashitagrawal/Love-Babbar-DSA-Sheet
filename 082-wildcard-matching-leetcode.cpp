#include <bits/stdc++.h>
using namespace std;

// Today's Date - 3 Feb 2024
// Leetcode Question Name - Wildcard Matching

class Solution
{
public:
    bool isMatch(string s, string p)
    {
    }

    /**
     * @brief Checks if a given text matches a wildcard pattern using a recursive approach.
     * 
     * @param i The current index in the text.
     * @param j The current index in the pattern.
     * @param text The text to be matched.
     * @param pattern The wildcard pattern.
     * @return true if the text matches the pattern, false otherwise.
     */
    bool matchWildcard(int i, int j, string &text, string &pattern)
    {
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0)
        {
            if
        }

        if(pattern[i]=='*')
            return matchWildcard(i-1,j,text,pattern) | matchWildcard(i,j-1,text,pattern);
        else if(text[i]==pattern[j] || pattern[j]='?')
            return matchWildcard(i-1, j-1,text,pattern);
        else
            return false;
    }
};

int main()
{
    Solution solution;
    string s = "abcde";
    string p = "a*d";
    bool result = solution.isMatch(s, p);
    cout << "Matching result: " << (result ? "true" : "false") << endl;
    return 0;
}