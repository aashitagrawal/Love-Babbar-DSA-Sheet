#include <bits/stdc++.h>
using namespace std;

// Today's Date - 8 Jan 2023
// Leetcode Question Name - Split the binary string into substrings with equal number of 0s and 1s

class Solution
{
public:
    int maxSubStr(string str)
    {
        int n = str.length();
        int count0 = 0, count1 = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                count0++;
            else
                count1++;
            if (count0 == count1)
                cnt++;
        }
        if (count0 != count1)
            return -1;
        return cnt;
    }
};

int main()
{
    // string s = "0100110101";
    // string s = "001110010";
    string s = "00011011";
    Solution solution;
    cout << solution.maxSubStr(s);
    return 0;
}