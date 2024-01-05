#include <bits/stdc++.h>
using namespace std;

// Today's Date - 3 Jan 2024
// GFG Question Name - Sorted matrix

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        vector<int> temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());

        vector<vector<int>> sortedMat(N, vector<int>(N));
        int index = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                sortedMat[i][j] = temp[index++];
            }
        }

        return sortedMat;
    }
};

int main()
{
    vector<vector<int>> vec = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    Solution solution;
    vector<vector<int>> ans = solution.sortedMatrix(vec.size(), vec);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}