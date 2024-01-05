#include <bits/stdc++.h>
using namespace std;

// Today's Date - 5 Jan 2024
// Leetcode Question Name - Rotate Image

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (auto &vec : matrix)
            reverse(vec.begin(), vec.end());

        for (int k = 0; k < n; ++k)
            for (int i = k; i < n; ++i)
                swap(matrix[k][n - 1 - i], matrix[i][n - k - 1]);
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // Print the vec vector
    cout << "Before : " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << "\t";
        cout << endl;
    }

    Solution solution;
    solution.rotate(vec);

    // Print the vec vector
    cout << "After 90 degree rotation : " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << "\t";
        cout << endl;
    }

    return 0;
}