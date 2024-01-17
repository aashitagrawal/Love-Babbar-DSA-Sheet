#include <bits/stdc++.h>
using namespace std;

// Today's Date - 17 Jan 2024
// Leetcode Question Name - Minimum Window Substring

class Solution
{
public:
    string minWindow(string s, string t)
    {
        
    }

    bool isIncluded(string substring, string target)
    {
        size_t found = substring.find(target);
        return (found != std::string::npos) ? true : false;
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