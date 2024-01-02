#include <bits/stdc++.h>
using namespace std;

// Today's Date - 1 Jan 2024
// Leetcode Question Name - Spiral Matrix

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        vector<int> ans;

        while (left < right && top < bottom)
        {
            // going left to right
            for (int i = left; i < right; ++i)
                ans.push_back(matrix[top][i]);
            top++;

            // going top to bottom
            for (int i = top; i < bottom; ++i)
                ans.push_back(matrix[i][right - 1]);
            right--;

            if (!(left < right && top < bottom)) // handling row and column matrices
                break;

            // going right to left
            for (int i = right - 1; i >= left; --i)
                ans.push_back(matrix[bottom - 1][i]);
            bottom--;

            // finally going bottom to top
            for (int i = bottom - 1; i >= top; --i)
                ans.push_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};

int main()
{
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution solution;
    vector<int> ans = solution.spiralOrder(vec);
    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}