#include <bits/stdc++.h>
using namespace std;

// Today's Date - 17 Jan 2024
// Leetcode Question Name - Minimum Window Substring

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return "";
        const int n = s.size();
        unordered_map<char, int> target;
        unordered_map<char, int> currWindow;

        for (auto ele : t)
            target[ele]++;
        const int need = target.size();
        int have = 0;

        int left = 0;
        for (int right = 0; right < n; right++)
        {
            char currChar = s[right];
            currWindow[currChar]++;
            if (need > have && target.count(s[left]))
            {
                currWindow[s[left]]++;
            }
        }
    }
};

int main()
{
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = solution.minWindow(s, t);
    cout << "Result : " << result;

    return 0;
}