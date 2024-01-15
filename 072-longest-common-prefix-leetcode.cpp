#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Leetcode Question Name - Longest Common Prefix

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans;
        int min_len = INT_MAX;

        for (auto ele : strs)
        {
            int temp = ele.size();
            min_len = min(min_len, temp);
        }

        for (int len = 0; len < min_len; ++len)
        {
            char toMatch = strs[0][len];
            bool matched = true;
            for(auto ele:strs)
            {
                if(!(ele[len]==toMatch))
                    matched &= false;
            }
            if(matched)
                ans+=strs[0][len];
            else
                return ans;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    // vector<string> strs = {"apple", "application", "app"};
    vector<string> strs = {"flower","flow","flight"};
    string commonPrefix = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << commonPrefix << endl;

    return 0;
}