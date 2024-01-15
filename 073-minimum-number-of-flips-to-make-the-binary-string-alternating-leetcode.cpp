#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Leetcode Question Name - Minimum Number of Flips to Make the Binary String Alternating

class Solution
{
public:
    int minFlips(std::string s)
    {
        int n = s.size();
        s += s;
        string a1, a2;

        for (int i = 0; i < 2 * n; i++)
        {
            a1 += (i % 2 == 0) ? '0' : '1';
            a2 += (i % 2 == 0) ? '1' : '0';
        }

        int diff_a1 = 0, diff_a2 = 0, result = n;

        for (int right = 0, left = 0; right < 2 * n; ++right)
        {
            diff_a1 += (s[right] != a1[right]);
            diff_a2 += (s[right] != a2[right]);

            if (right - left + 1 > n)
            {
                diff_a1 -= (s[left] != a1[left]);
                diff_a2 -= (s[left] != a2[left]);
                left++;
            }
            if (right - left + 1 == n)
                result = min({result, diff_a1, diff_a2});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    // string s = "010101";
    // string s = "111000";
    // string s = "1110";
    string s = "10001100101000000";
    int flips = solution.minFlips(s);
    cout << "Minimum number of flips: " << flips << endl;
    return 0;
}