#include <bits/stdc++.h>
using namespace std;

// Today's Date - 15 Jan 2024
// Leetcode Question Name - Restore IP Addresses

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
    }
};

int main()
{
    Solution solution;
    string input = "25525511135";
    vector<string> result = solution.restoreIpAddresses(input);
    
    for (const string& ip : result) {
        cout << ip << endl;
    }

    return 0;
}