#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Feb 2024
// Leetcode Question Name - Find Missing and Repeated Values

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        long long int sum_of_squares = (n * (n + 1) * ((2 * n) + 1)) / 6;
        int sum = (n * (n + 1)) / 2;

        long long int grid_sos = 0;
        int grid_sum = 0;

        for (const auto &vec : grid)
        {
            for (const auto &ele : vec)
            {
                grid_sos += (1LL * ele * ele);
                grid_sum += ele;
            }
        }

        // x = repepated, y = missing
        long long int val1 = grid_sum - sum; // x-y
        long long int val2 = grid_sos - sum_of_squares;
        val2 = val2 / val1; // x+y
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {{1, 2, 2, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> ans = solution.findMissingAndRepeatedValues(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}