#include <bits/stdc++.h>
using namespace std;

// Today's Date - 2 Jan 2024
// Leetcode Question Name -  Row With Maximum Ones

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int max_count = INT_MIN;
        int row_index = 0;

        for (int i = 0; i < mat.size(); ++i)
        {
            int temp = count(mat[i].begin(), mat[i].end(), 1);
            if (temp > max_count)
            {
                max_count = temp;
                row_index = i;
            }
        }

        return {row_index, max_count};
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 0}, {1, 1}, {0, 0}};
    Solution solution;
    vector<int> ans = solution.rowAndMaximumOnes(mat);
    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}