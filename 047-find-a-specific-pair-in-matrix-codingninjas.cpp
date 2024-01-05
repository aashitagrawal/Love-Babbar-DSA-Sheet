#include <bits/stdc++.h>
using namespace std;

// Today's Date - 4 Jan 2024
// Coding Ninjas Question Name -  Find A Specific Pair In Matrix

class Solution
{
public:
    int findMaxValue(vector<vector<int>> &mat, int n)
    {
        // creating a maxMat
        vector<vector<int>> maxMat(n, vector<int>(n));

        maxMat[n - 1][n - 1] = mat[n - 1][n - 1];

        // fill last row
        for (int col = n - 2; col >= 0; --col)
            maxMat[n - 1][col] = max(maxMat[n - 1][col+1], mat[n - 1][col]);

        // fill last col
        for (int row = n - 2; row >= 0; --row)
            maxMat[row][n - 1] = max(maxMat[row+1][n - 1], mat[row][n - 1]);

        // filling up whole matrix
        for (int row = n - 2; row >= 0; --row)
            for (int col = n - 2; col >= 0; --col)
                maxMat[row][col] = max({mat[row][col], maxMat[row + 1][col], maxMat[row][col + 1]});

        // print maxMat
        cout << "maxMat = " << endl;
        for (auto row : maxMat)
        {
            for (auto ele : row)
                cout << ele << " ";
            cout << endl;
        }

        // finding answer
        cout << "ans matrix = " << endl;
        int ans = INT_MIN;
        for (int row = 0; row < n - 1; ++row)
        {
            for (int col = 0; col < n - 1; ++col)
            {
                ans = max(ans, maxMat[row + 1][col + 1] - mat[row][col]);
                cout << maxMat[row + 1][col + 1] - mat[row][col] << " ";
            }
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    // vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> vec = {{47, 38, -8, 0}, {16, 11, 3, 40}, {-20, 16, 4, 43}, {5, 25, -1, -36}};
    // vector<vector<int>> vec = {{1, 2, -1, -4, -20}, {-8, -3, 4, 2, 1}, {3, 8, 6, 1, 3}, {-4, -1, 1, 7, -6}, {0, -4, 10, -5, 1}};
    cout << "maxtrix = " << endl;
    for (auto row : vec)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }
    Solution solution;
    cout << solution.findMaxValue(vec, vec.size());
    return 0;
}