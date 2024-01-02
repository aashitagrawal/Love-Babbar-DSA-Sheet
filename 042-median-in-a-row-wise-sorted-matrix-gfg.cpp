#include <bits/stdc++.h>
using namespace std;

// Today's Date - 2 Jan 2024
// GFG Question Name - Median in a row-wise sorted Matrix

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; ++i)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        int check_ele = low + (high - low) / 2;
        int desired_count = (R * C) / 2;
        while (low < high)
        {
            int count = 0;
            for (int i = 0; i < R; ++i)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), check_ele) - matrix[i].begin();

            if (count > desired_count)
                high = check_ele;
            else
                low = check_ele + 1;
            check_ele = low + (high - low) / 2;
        }
        return low;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    // vector<vector<int>> matrix = {{1}, {2}, {3}};
    Solution solution;
    cout << solution.median(matrix, matrix.size(), matrix[0].size());
    return 0;
}