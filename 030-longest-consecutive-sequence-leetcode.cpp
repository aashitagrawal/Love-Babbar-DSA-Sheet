#include <bits/stdc++.h>
using namespace std;

// Today's Date - 27 Dec 2023
// Leetcode Question Name - Longest Consecutive Sequence
// Main key point in this question was - time complexity of insertion, count, and erase in unordered set is O(1)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto ele : nums)
            s.insert(ele);

        int longest = 0;
        for (int ele : s)
        {
            if (!s.count(ele - 1))
            {
                int length = 1;
                while (s.count(ele + length))
                {
                    s.erase(ele + length);
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> vec = {100, 4, 200, 1, 3, 2};
    Solution solution;
    cout << solution.longestConsecutive(vec) << endl;
    return 0;
}