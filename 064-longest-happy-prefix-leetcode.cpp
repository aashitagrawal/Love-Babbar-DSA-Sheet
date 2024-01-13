#include <bits/stdc++.h>
using namespace std;

// Today's Date - 10 Jan 2024
// Leetcode Question Name - Longest Happy Prefix

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> lps(n, 0); // Longest Proper Prefix which is also Suffix

        // Preprocess the lps array
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;
        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Return the longest happy prefix
        return s.substr(0, lps[n - 1]);
    }
};

int main()
{
    string s = "levelevel";
    Solution solution;
    cout<<solution.longestPrefix(s)<<endl;
    return 0;
}