#include <bits/stdc++.h>
using namespace std;

// Today's Date - 22 Dec 2023
// Leetcode Question Name - Merge Intervals

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= end)
            {
                if (intervals[i][1] < end)
                    continue;
                else
                    end = intervals[i][1];
            }
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 3}, {5, 20}, {7, 17}, {10, 30}, {25, 50}, {35, 40}, {37, 55}, {47, 60}, {65, 70}, {100, 101}, {105, 105}};
    Solution solution;
    vector<vector<int>> ans = solution.merge(vec);
    for (auto vector : ans)
    {
        for (auto ele : vector)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}