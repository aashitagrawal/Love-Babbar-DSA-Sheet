#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Question Name - Count of number of given string in 2D character array

class Solution
{
public:
    vector<pair<int, int>> countOfWord(vector<vector<char>> &mat, const string &str)
    {
        int row = mat.size();
        int col = mat[0].size();
        char target = str[0];

        vector<pair<int, int>> ans;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (mat[i][j] == target && patternMatch(mat, str, i, j, str.size(), 0))
                    ans.push_back({i, j});
        return ans;
    }

    bool patternMatch(vector<vector<char>> &mat, const string &str, int i, int j, int target_size, int index)
    {
        if (index == target_size)
            return true;

        if (str[index] == mat[i][j])
        {
            char temp = mat[i][j];
            mat[i][j] = '0';

            if (patternMatch(mat, str, i + 1, j, target_size, index + 1) ||
                patternMatch(mat, str, i - 1, j, target_size, index + 1) ||
                patternMatch(mat, str, i, j + 1, target_size, index + 1) ||
                patternMatch(mat, str, i, j - 1, target_size, index + 1))
            {
                mat[i][j] = temp;
                return true;
            }

            mat[i][j] = temp;
        }
        return false;
    }
};


int main()
{
    Solution solution;

    vector<vector<char>> mat = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};
    string str = "abc";

    vector<pair<int, int>> result = solution.countOfWord(mat, str);

    // Print the result
    for (auto pair : result)
    {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    return 0;
}